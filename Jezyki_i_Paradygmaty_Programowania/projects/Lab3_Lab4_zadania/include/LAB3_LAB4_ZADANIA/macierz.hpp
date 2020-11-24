#include <iostream>
#include <fstream>
#include <cstdlib>

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
    cout << "Ustawiamy liczbe za pomoca metody set na pozycji " << x << " x " << y << " o wartosci : " << val << endl;
    macierz[x][y] = val;
  }
  void get(int w, int k)
  {
    double val;
    val = macierz[w][k];
    cout << "Podana wartosc pobrana za pomoca metody get na pozycji " << w << " x " << k << " jest rowna: " << val << endl;
  }
  void add(int k, int w, double *tab)
  {
    cout << "Dodajemy dwie macierze ... " << endl;
    double macierz_wyn[w][k];
    if (lw == w && lk == k)
    {
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
    else
    {
      cout << "Nie mozna dodac macierzy. Zle wymiary macierzy wejsciowej. Wymiary poprawnej macierzy: " << lw << " x " << lk << endl;
    }
  }

  void subtract(int k, int w, double *tab)
  {
    cout << "Odejmujemy dwie macierze ... " << endl;
    double macierz_wyn[w][k];
    if (lw == w && lk == k)
    {
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
    else
    {
      cout << "Nie mozna odjac macierzy. Zle wymiary macierzy wejsciowej. Wymiary poprawnej macierzy: " << lw << " x " << lk << endl;
    }
  }

  void multiply(int k, int w, double *tab)
  {
    double macierz_wyn[lw][k];
    if (lk == w)
    {
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
    else
    {
      cout << "Nie mozna pomnozyc macierzy. Zle wymiary macierzy wejsciowej. Wymiary poprawnej macierzy: " << lk << " x dowolne" << endl;
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

  void store(string filename, string path)
  {
    fstream zapis;
    zapis.open(path + filename, ios::out);
    if (zapis.good() == false)
    {
      cout << "Blad otwarcia pliku!";
      exit(0);
    }
    zapis << lw << " " << lk << endl;
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        zapis << macierz[i][j] << " ";
      }
      zapis << endl;
    }

    zapis.close();
  }

  Macierz(string path)
  {
    fstream odczyt;
    odczyt.open(path, ios::in);
    int wiersze, kolumny;

    odczyt >> wiersze >> kolumny;
    double nowa_macierz[wiersze][kolumny];

    for (int i = 0; i < wiersze; i++)
    {
      for (int j = 0; j < kolumny; j++)
      {
        odczyt >> nowa_macierz[i][j];
      }
    }
    cout << "Macierz wyciagnieta z pliku ... " << path << endl;
    for (int i = 0; i < wiersze; i++)
    {
      for (int j = 0; j < kolumny; j++)
      {
        cout << "[ " << nowa_macierz[i][j] << " ] ";
      }
      cout << endl;
    }
  }
};
