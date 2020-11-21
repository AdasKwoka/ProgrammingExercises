#include <iostream>
#include <LAB3_LAB4_ZADANIA/macierz.hpp>
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
  m1.set(1, 1, 10.4);
  m1.get(1, 1);

  cout << "Podaj ilosc kolumn: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy: " << endl;
  cin >> w;
  double macierz_dod[w][k];
  uzupelnij_macierz(k, w, &macierz_dod[0][0]);

  m1.add(k, w, &macierz_dod[0][0]);
  m1.subtract(k, w, &macierz_dod[0][0]);

  cout << "Podaj ilosc kolumn: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy: " << endl;
  cin >> w;
  double macierz_mn[w][k];
  uzupelnij_macierz(k, w, &macierz_mn[0][0]);

  m1.multiply(k, w, &macierz_mn[0][0]);
  m1.cols();
  m1.rows();
  m1.print();
  m1.store("macierz1.txt", "../");
  Macierz m2(4);
  m2.set(2, 3, 10.4);
  m2.get(2, 3);

  cout << "Podaj ilosc kolumn: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy: " << endl;
  cin >> w;
  uzupelnij_macierz(k, w, &macierz_dod[0][0]);

  m2.add(k, w, &macierz_dod[0][0]);
  m2.subtract(k, w, &macierz_dod[0][0]);

  cout << "Podaj ilosc kolumn: " << endl;
  cin >> k;
  cout << "Podaj ilosc wierszy: " << endl;
  cin >> w;
  uzupelnij_macierz(k, w, &macierz_mn[0][0]);

  m2.multiply(k, w, &macierz_mn[0][0]);
  m2.cols();
  m2.rows();
  m2.print();
  m2.store("macierz2.txt", "../");

  Macierz m3("../macierz1.txt");
  Macierz m4("../macierz2.txt");
}