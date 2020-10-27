#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    bool trueA = false, trueB = false; //flagi do potwierdzenia czy liczby sa przystające

    //pobranie liczb
    int a, b;
    cout << "Podaj pierwsza liczbe: " << endl;
    cin >> a;
    cout << "Podaj druga liczbe: " << endl;
    cin >> b;

    int i;
    int wynikA = 0;
    cout << "Dzielniki liczby: " << a << endl;
    for (i = 1; i < a; i++) //petla do wypisania dzielnikow pierwszej liczby
    {
        if (a % i == 0) // warunek sprawdzajacy czy dana liczba w dzieleniu modulo daje 0
        {
            cout << i << " ";
            wynikA += i; // suma dzielnikow pierwszej liczby
        }
    }
    cout << endl
         << "Suma dzielnikow wynosi: " << wynikA << endl;

    if (b + 1 == wynikA) // ustawienie flagi dla pierwszej liczby czy jest skojarzona do drugiej
        trueA = true;

    //analogicznie jak wyzej
    int wynikB = 0;
    cout << "Dzielniki liczby: " << b << endl;
    for (i = 1; i < b; i++)
    {
        if (b % i == 0)
        {
            cout << i << " ";
            wynikB += i;
        }
    }
    cout << endl
         << "Suma dzielnikow wynosi: " << wynikB << endl;
    if (a + 1 == wynikB)
        trueB = true;

    //warunek sprawdzajacy dane flagi jesli obie true znaczy ze liczby sa skojarzone
    if (trueA && trueB)
        cout << "Liczby " << a << " i " << b << " sa skojarzone";
    else
        cout << "Liczby " << a << " i " << b << " nie sa skojarzone";
}