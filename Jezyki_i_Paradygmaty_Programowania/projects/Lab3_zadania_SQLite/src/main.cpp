#include <iostream>
#include <Lab3_zadania_sqlite/macierz.hpp>
#include <fstream>

using namespace std;

void uzupelnij_macierz(int k, int w, double *macierz)
{
  cout << "Podaj wartosci macierzy: " << endl;
  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < k; j++)
    {
      cin >> macierz[i * k + j];
    }
  }
}

int main()
{
  int k = 0, w = 0;
  Macierz m1(3, 5);
  try
  {
    m1.set(1, 1, 10.4);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  try
  {
    m1.get(4, 4);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  cout << "Podaj ilosc kolumn dla macierzy do dodawania i odejmowania: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy dla macierzy do dodawania i odejmowania: " << endl;
  cin >> w;
  double macierz_dod[w][k];
  uzupelnij_macierz(k, w, &macierz_dod[0][0]);

  try
  {
    m1.add(k, w, &macierz_dod[0][0]);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  try
  {
    m1.subtract(k, w, &macierz_dod[0][0]);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  cout << "Podaj ilosc kolumn dla macierzy do mnozenia: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy dla macierzy do mnozenia: " << endl;
  cin >> w;
  double macierz_mn[w][k];
  uzupelnij_macierz(k, w, &macierz_mn[0][0]);

  try
  {
    m1.multiply(k, w, &macierz_mn[0][0]);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  m1.cols();
  m1.rows();
  m1.print();

  try
  {
    m1.store("../", "baza1.db");
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  Macierz m2(4);
  try
  {
    m2.set(2, 3, 10.4);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  try
  {
    m2.get(2, 3);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  cout << "Podaj ilosc kolumn dla macierzy do dodawania i odejmowania: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy dla macierzy do dodawania i odejmowania: " << endl;
  cin >> w;
  uzupelnij_macierz(k, w, &macierz_dod[0][0]);

  try
  {
    m2.add(k, w, &macierz_dod[0][0]);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  try
  {
    m2.subtract(k, w, &macierz_dod[0][0]);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  cout << "Podaj ilosc kolumn dla macierzy do mnozenia: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy dla macierzy do mnozenia: " << endl;
  cin >> w;
  uzupelnij_macierz(k, w, &macierz_mn[0][0]);

  try
  {
    m2.multiply(k, w, &macierz_mn[0][0]);
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }

  m2.cols();
  m2.rows();
  m2.print();

  try
  {
    m2.store("../", "baza2.db");
  }
  catch (const char *e)
  {
    cout << "Message: " << e << endl;
  }
}