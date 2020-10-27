#include <iostream>
#include <algorithm>

using namespace std;

void change(int &ref1, int &ref2)
{
    cout << "Zmiana przez referencje!" << endl;

    //Modyfikujac referencje modyfikujemy tez zmienna oryginalna

    swap(ref1, ref2);
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

    //Wywolanie funkcji (referencja zmiennych arg1, arg2)
    change(arg1, arg2);

    //Wyswietlenie zmienionych wartosci
    cout << "Wartosc pierwszego argumentu: " << arg1 << endl;
    cout << "Wartosc drugiego argumentu: " << arg2 << endl;
}