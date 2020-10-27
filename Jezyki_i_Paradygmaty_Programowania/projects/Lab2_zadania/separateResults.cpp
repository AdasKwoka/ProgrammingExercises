#include <iostream>
#include <algorithm>

using namespace std;

int calculations(int num1, int num2, int &sum)
{
    //Zmiana wartosci zmiennej sum przez referencje
    sum = num1 + num2;

    //Wynik zwracany z funkcji
    return num1 * num2;
}

int main(int argc, char *argv[])
{
    //Zmienne
    int arg1, arg2, product, sum;

    //Pobranie wartosci do zmiennych
    cout << "Podaj pierwszy argument: " << endl;
    cin >> arg1;
    cout << "Podaj drugi argument: " << endl;
    cin >> arg2;

    //Wywolanie fuunckji (referencja zmiennej sum), przypisanie zwroconej wartosci do zmiennej product
    product = calculations(arg1, arg2, sum);

    //Wyswielenie wynikow
    cout << "Wynik mnozenia: " << product << endl
         << "Wynik dodawania: " << sum << endl;
}