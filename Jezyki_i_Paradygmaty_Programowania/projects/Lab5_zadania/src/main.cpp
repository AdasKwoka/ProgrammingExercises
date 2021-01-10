#include <iostream>
#include "../includes/header.hpp"
#include <fstream>

using namespace std;

int main()
{
  int k, w;

  Macierz m1(3, 5);
  Macierz m2(3, 5);

  Macierz m3(3, 5);
  m3 = m1 + m2;
  m3.print("operator+");

  m3 = m3 - m1;
  m3.print("operator-");

  Macierz m4(5, 3);
  Macierz m5(5, 5);
  m5 = m3 * m4;
  m5.print("operator*");

  ofstream f;
  f.open("./macierz.txt");
  f << m5;
  f.close();

  int isEquivalent = m5 == m2;
  if (isEquivalent)
  {
    cout << "Macierze rowne." << endl;
  }
  else
  {
    cout << "Macierze nie rowne." << endl;
    cout << "_____________________________" << endl;
  }

  int n = m5.cols();
  const double *list = m5[2];
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    cout << " [ " << list[i] << " ] ";
  }
  cout << endl;
  cout << "Dodatkowe operatory do przeladowania: " << endl;

  m3 += m1;
  m3.print("operator+=");

  m3 -= m3;
  m3.print("operator-=");

  //Porownanie wielkosci macierzy jesli lk lub lw w obu macierzach sa takie same wypisze ze jest mniej gdyz jest to ostra nierownosc
  cout << "Operator<" << endl;
  m3 > m5;
  m1.destruktor();
  m2.destruktor();
  m3.destruktor();
  m4.destruktor();
  m5.destruktor();
}