#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Macierz
{
private:
  double **macierz;
  int lw = 0, lk = 0;

public:
  Macierz(){};
  Macierz(int kolumny, int wiersze)
  {
    int w = wiersze;
    int k = kolumny;
    lw = w;
    lk = k;

    srand(time(NULL));

    macierz = new double *[w];
    for (int i = 0; i < w; i++)
    {
      macierz[i] = new double[k];
    }
    for (int i = 0; i < w; i++)
      for (int j = 0; j < k; j++)
        macierz[i][j] = rand() % 9;
  }
  void set(int x, int y, double val)
  {
    macierz[x][y] = val;
  }
  double get(int w, int k)
  {
    double val;
    val = macierz[w][k];
    return val;
  }
  Macierz operator+(Macierz &obj)
  {
    Macierz wyn(lk, lw);
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        wyn.set(i, j, macierz[i][j] + obj.get(i, j));
      }
    }
    return wyn;
  }

  Macierz operator-(Macierz &obj)
  {
    Macierz wyn(lk, lw);
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        wyn.set(i, j, macierz[i][j] - obj.get(i, j));
      }
    }
    return wyn;
  }

  Macierz operator*(Macierz &obj)
  {
    Macierz wyn(obj.lk, lw);
    double wart;
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < obj.lk; j++)
      {
        wart = 0;
        for (int l = 0; l < lk; l++)
        {
          wart += macierz[i][l] * obj.macierz[l][j];
        }
        wyn.set(i, j, wart);
      }
      cout << endl;
    }
    return wyn;
  }

  friend void operator<<(ofstream &f, Macierz &obj)
  {
    f << obj.lk << " " << obj.lw << endl;
    for (int i = 0; i < obj.lw; i++)
    {
      for (int j = 0; j < obj.lk; j++)
      {
        f << obj.macierz[i][j] << " ";
      }
      f << endl;
    }
  }

  int operator==(Macierz &obj)
  {
    int flag = 1;
    if (lk == obj.lk && lw == obj.lw)
    {
      for (int i = 0; i < lw; i++)
      {
        for (int j = 0; j < lk; j++)
        {
          if (macierz[i][j] != obj.macierz[i][j])
          {
            flag = 0;
          }
        }
      }
    }
    else
    {
      flag = 0;
    }
    return flag;
  }

  double *operator[](int n)
  {
    if (n < 0 || n > lw)
    {
      n = 0;
    }
    return macierz[n];
  }

  void operator+=(Macierz &obj)
  {
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        macierz[i][j] += obj.get(i, j);
      }
    }
  }

  void operator-=(Macierz &obj)
  {
    for (int i = 0; i < lw; i++)
    {
      for (int j = 0; j < lk; j++)
      {
        macierz[i][j] -= obj.get(i, j);
      }
    }
  }

  void operator>(Macierz &obj)
  {
    if (lk > obj.lk && lw > obj.lw)
    {
      cout << "Macierz wieksza" << endl;
    }
    if (lw > obj.lw)
    {
      cout << "Macierz posiada wiecej wierszy" << endl;
    }
    else
    {
      cout << "Macierz posiada mniej wierszy" << endl;
    }
    if (lk > obj.lk)
    {
      cout << "Macierz posiada wiecej kolumn" << endl;
    }
    else
    {
      cout << "Macierz posiada mniej kolumn" << endl;
    }
  }
  const double cols()
  {
    return lk;
  }
  void print(string dzialanie)
  {
    cout << "Macierz zmieniona za pomoca " << dzialanie << ", i wyswietlona metoda print: " << endl;
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

  void destruktor()
  {
    for (int i = 0; i < lw; i++)
    {
      delete[] macierz[i];
    }
    delete[] macierz;
  }
};
