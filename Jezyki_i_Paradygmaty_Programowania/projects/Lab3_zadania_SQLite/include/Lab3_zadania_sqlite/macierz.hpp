#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sqlite3/sqlite3.h>
#include <sstream>

using namespace std;

class Macierz
{
private:
  double **macierz;
  int lw = 0, lk = 0;

public:
  Macierz(int kolumny, int wiersze)
  {
    int w = wiersze;
    int k = kolumny;
    lw = w;
    lk = k;

    macierz = new double *[w];
    for (int i = 0; i < w; i++)
    {
      macierz[i] = new double[k];
    }
    for (int i = 0; i < w; i++)
      for (int j = 0; j < k; j++)
        macierz[i][j] = 0;

    cout << "Utworzona macierz to: " << endl;
    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < k; j++)
      {
        cout << "[ " << macierz[i][j] << " ] ";
      }
      cout << endl;
    }
  }
  ~Macierz()
  {
    delete[] macierz;
  }
  Macierz(int kwadrat)
  {
    int w = kwadrat;
    int k = kwadrat;
    lw = w;
    lk = k;
    macierz = new double *[w];
    for (int i = 0; i < w; i++)
    {
      macierz[i] = new double[k];
    }
    for (int i = 0; i < w; i++)
      for (int j = 0; j < k; j++)
        macierz[i][j] = 0;

    cout << "Utworzona macierz to: " << endl;
    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < k; j++)
      {
        cout << "[ " << macierz[i][j] << " ] ";
      }
      cout << endl;
    }
  }

  void set(int x, int y, double val)
  {
    if (x < 0 || x > (lw - 1))
    {
      throw "[Metoda set] Podano niepoprawny numer wiersza komorki macierzy";
    }
    if (y < 0 || y > (lk - 1))
    {
      throw "[Metoda set] Podano niepoprawny numer kolumny komorki macierzy";
    }
    cout << "Ustawiamy liczbe za pomoca metody set na pozycji " << x << " x " << y << " o wartosci : " << val << endl;
    macierz[x][y] = val;
  }

  void get(int w, int k)
  {
    if (w < 0 || w > (lw - 1))
    {
      throw "[Metoda get] Podano niepoprawny numer wiersza komorki macierzy";
    }
    if (k < 0 || k > (lk - 1))
    {
      throw "[Metoda get] Podano niepoprawny numer kolumny komorki macierzy";
    }
    double val;
    val = macierz[w][k];
    cout << "Podana wartosc pobrana za pomoca metody get na pozycji " << w << " x " << k << " jest rowna: " << val << endl;
  }

  void add(int k, int w, double *tab)
  {
    if (k != lk)
    {
      throw "[Metoda add] Nie mozna dodac macierzy. Niepoprawna liczba kolumn.";
    }
    if (w != lw)
    {
      throw "[Metoda add] Nie mozna dodac macierzy. Niepoprawna liczba wierszy.";
    }
    cout << "Dodajemy dwie macierze ... " << endl;
    double macierz_wyn[w][k];
    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < k; j++)
      {
        macierz_wyn[i][j] = macierz[i][j] + tab[i * k + j];
      }
    }
    cout << "Nowa macierz po dodawaniu: " << endl;
    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < k; j++)
      {
        cout << "[ " << macierz_wyn[i][j] << " ] ";
      }
      cout << endl;
    }
  }

  void subtract(int k, int w, double *tab)
  {
    if (k != lk)
    {
      throw "[Metoda substract] Nie mozna odjac macierzy. Niepoprawna liczba kolumn.";
    }
    if (w != lw)
    {
      throw "[Metoda substract] Nie mozna odjac macierzy. Niepoprawna liczba wierszy.";
    }
    cout << "Odejmujemy dwie macierze ... " << endl;
    double macierz_wyn[w][k];
    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < k; j++)
      {
        macierz_wyn[i][j] = macierz[i][j] - tab[i * k + j];
      }
    }
    cout << "Nowa macierz po odejmowaniu: " << endl;
    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < k; j++)
      {
        cout << "[ " << macierz_wyn[i][j] << " ] ";
      }
      cout << endl;
    }
  }

  void multiply(int k, int w, double *tab)
  {
    if (lk != w)
    {
      throw "[Metoda multiply] Nie mozna pomnozyc macierzy. Niepoprawna liczba wierszy w macierzy.";
    }
    double macierz_wyn[lw][k];
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < k; j++)
      {
        macierz_wyn[i][j] = 0;
        for (int l = 0; l < lk; l++)
        {
          macierz_wyn[i][j] += macierz[i][l] * tab[i * k + j];
        }
      }
    }
    cout << "Nowa macierz po mnozeniu: " << endl;
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < k; j++)
      {
        cout << "[ " << macierz_wyn[i][j] << " ] ";
      }
      cout << endl;
    }
  }

  void cols()
  {
    cout << "Liczba kolumn danej macierzy to: " << lk << endl;
  }

  void rows()
  {
    cout << "Liczba wierszy danej macierzy to: " << lw << endl;
  }

  void print()
  {
    cout << "Macierz uzupelniona metoda set, i wyswietlona metoda print: " << endl;
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        cout << "[ " << macierz[i][j] << " ] ";
      }
      cout << endl;
    }
    cout << "___________________________________________________________________________ " << endl;
  }

  void store(string path, string filename)
  {
    sqlite3 *db;          // struktura bazy danych
    int test;             // zwracany status po wykonaniu kazdego polecenia
    char *error;          // komunikat zwrotny w przypadku wystapienia bledu
    string dane;          // dane do drugiej kwerendy
    unsigned char *bajty; // zamiana elementow macierzy na postac binarna
    stringstream strumien;
    char bajt[3];
    string executablePath = (path + filename);

    test = sqlite3_open(executablePath.c_str(), &db);

    if (test != SQLITE_OK)
    {
      cout << "Nie udalo sie otworzyc pliku \"" << executablePath << "\"!" << endl;
      return;
    }

    const char *kwerenda_1 =
        "CREATE TABLE IF NOT EXISTS macierze ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "cols INTEGER NOT NULL, "
        "rows INTEGER NOT NULL, "
        "cells BLOB NOT NULL"
        ");";

    const char *kwerenda_2 =
        "INSERT INTO macierze "
        "(cols, rows, cells) "
        "VALUES ";

    // utworzenie tabeli w bazie danych
    cout << "Wykonujemy kwerende: " << kwerenda_1 << endl;
    test = sqlite3_exec(db, kwerenda_1, NULL, NULL, &error);

    if (test != SQLITE_OK)
    {
      sqlite3_close(db);

      cout << "Nie udalo sie dodac tabeli do bazy danych!" << endl;
      cout << "Komunkat: " << error << endl;

      return;
    }

    // musimy zamienic dane z tej macierzy na tekst
    strumien << kwerenda_2 << "(" << lk << ", " << lw << ", x'";

    // zamieniamy tablice DOUBLE na strumien bajtow
    cout << "Zamiana elementow na strumien bajtow" << endl;

    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        bajty = (unsigned char *)&(macierz[i][j]);

        for (int k = 0; k < sizeof(double); k++)
        {
          sprintf(bajt, "%02X", bajty[k]);
          strumien << bajt;
        }
      }
    }

    strumien << "');";

    // dodanie macierzy do tabeli
    cout << "Wykonujemy kwerende: " << strumien.str() << endl;
    test = sqlite3_exec(db, strumien.str().c_str(), NULL, NULL, &error);

    if (test != SQLITE_OK)
    {
      sqlite3_close(db);

      cout << "Nie udalo sie dodac rekordu do tabeli w bazie danych!" << endl;
      cout << "Komunikat: " << error << endl;

      return;
    }

    // zamykamy plik z bazÄ danych
    sqlite3_close(db);
  }
};
