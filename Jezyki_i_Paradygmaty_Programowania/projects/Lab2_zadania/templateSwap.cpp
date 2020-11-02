#include <iostream>

using namespace std;

template <class T>
void swap(T &a, T &b, int i)
{
  b = (a * b) / (a = b);
}

int main(int argc, char *argv[])
{
  int a, b;
  cout << "Podaj pierwsza wartosc: " << endl;
  cin >> a;
  cout << "Podaj druga wartosc: " << endl;
  cin >> b;

  cout << "Wartosci przed zmiana: " << endl;
  cout << "Pierwsza wartosc: " << a << endl;
  cout << "Druga wartosc: " << b << endl;

  swap(a, b);

  cout << "Wartosci po zmianie: " << endl;
  cout << "Pierwsza wartosc: " << a << endl;
  cout << "Druga wartosc: " << b << endl;
}