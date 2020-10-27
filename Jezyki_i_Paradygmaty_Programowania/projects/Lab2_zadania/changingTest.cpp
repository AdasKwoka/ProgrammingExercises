#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

//Funkcja losujaca, w ktorej argumenty przekazane sa przez referencje
void draw(int &result1, int &result2)
{
    //Do argumentow arg1 i arg2 przypisane sa liczby pseudolosowe z zakresu od 0 do 19
    result1 = rand() % 20;
    result2 = rand() % 20;
}

//Funkcja zmieniajaca argumenty, w ktorej argumenty przekazane sa przez referencje
void change(int &num1, int &num2)
{
    swap(num1, num2);
}
int main(int argc, char *argv[])
{
    //Zmienne
    int arg1, arg2, operation_nr = 1;

    //Wywolanie funkcji zwracajacej obecny czas na komputerze w postaci liczby
    srand(time(NULL));

    //petla warunkowa ktora wykona sie przynajmniej jeden raz
    do
    {
        //Warunek do losowania liczby
        if (operation_nr == 1)
        {
            //Wywolanie funkcji losujacej i podanie argumentow przez referencje
            draw(arg1, arg2);
            cout << "Pierwsza wylosowana liczba to : " << arg1 << endl
                 << "Druga wylosowana liczba to : " << arg2 << endl;
            //Wywolanie funkcji zmieniajacej liczby i podanie argumentow przez referencje
            change(arg1, arg2);
        }
        //Warunek do wpisywania argumentow
        else if (operation_nr == 2)
        {
            //Pobieranie wartosci od uzytkownika
            cout << "Podaj pierwsza liczbe: " << endl;
            cin >> arg1;
            cout << "Podaj druga liczbe: " << endl;
            cin >> arg2;
            //Wywolanie funkcji zmieniajacej liczby i podanie argumentow przez referencje
            change(arg1, arg2);
        }
        //Warunek kiedy uzytkownik wpisal bledny numer operacji
        else if (operation_nr != 0 && operation_nr != 1 && operation_nr != 2)
        {
            cout << "Podano zla wartosc koniec programu !" << endl;
            break;
        }
        //Wypisanie rezulatatu dzialania programu
        cout << "Liczby po zamianie: " << endl
             << "Pierwsza: " << arg1 << endl
             << "Druga: " << arg2 << endl;

        //Okreslenie numeru operacji ktora uzytkownik chce wykonac
        cout << "0 - koniec programu, 1 - wylosuj i zamien, 2 - wpisz i zamien" << endl;
        cout << "Podaj numer operacji" << endl;
        cin >> operation_nr;

    }
    //Warunek powtorzenia programu
    while (operation_nr == 1 || operation_nr == 2);
}