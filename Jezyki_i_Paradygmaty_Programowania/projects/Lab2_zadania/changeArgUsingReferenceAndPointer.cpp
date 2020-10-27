#include <iostream>
#include <algorithm>

using namespace std;

void change(int *point, int &ref)
{
    //Modyfikujac referencje modyfikujemy tez zmienna oryginalna
    //Zmienna *point nie jest kopia, operowanie na niej zmienia wartosc w calym programie

    swap(*point, ref);
}

int main(int argc, char *argv[])
{

    //Zmienne
    int arg1, arg2;

    //Pobranie wartosci do zmiennych
    cout << "Podaj pierwszy argument: " << endl;
    cin >> arg1;
    cout << "Podaj drugi argument: " << endl;
    cin >> arg2;

    int *p = &arg1;

    //Wywolanie funkcji (referencja zmiennej arg2, wskaznika na zmienna arg1)
    change(p, arg2);

    //Wyswietlenie zmienionych wartosci
    cout << "Wartosc pierwszego argumentu: " << arg1 << endl;
    cout << "Wartosc drugiego argumentu: " << arg2 << endl;
}