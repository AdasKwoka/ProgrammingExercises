#include <iostream>
#include <algorithm>

using namespace std;

void zmiana(int *arg1, int *arg2)
{
    //Zmienna *arg1 i *arg2 nie sa kopiami
    //Operowanie na nich zmienia ich wartosci w "calym" programie
    if (*arg1 > *arg2)
    {
        cout << "Dokonano zmiany wartosci argumentow!" << endl;
        swap(*arg1, *arg2);
    }
}

int main(int argc, char *argv[])
{
    //Zmienne
    int a, b;

    //Pobranie wartosci do zmiennych
    cout << "Podaj wartosc pierwszego argumentu: " << endl;
    cin >> a;
    cout << "Podaj wartosc drugiego argumentu: " << endl;
    cin >> b;

    //Wskazniki do zmiennych
    int *p = &a;
    int *q = &b;

    //Wywolanie funkcji
    zmiana(p, q);

    //Wyswietlenie wartosci
    cout << "Wartosc pierwszego argumentu: " << a << endl
         << "Wartosc drugiego argumentu: " << b << endl;
}
