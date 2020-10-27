// Dodanie potrzebnych bibliotek
#include <iostream>
#include <string>
#include <conio.h>

// Zainicjowanie używania przestrzeni znakow std
using namespace std;

//Funkcja usuwajaca z podanego stringa spacje
string usunSpacje(string Tekst, string TekstPoUsuwaniu)
{
    TekstPoUsuwaniu = ""; // Zainicjowanie pustej zmiennej typu string ktora ma przechowywac ciag bez spacji
    int i;                // inicjalizacja iterator
    unsigned bufor = 0;   // warunek stopu

    while (bufor == 0) // Glowna petla
    {
        for (i = 0; i < Tekst.length(); i++) // Petla ktora sprawdza kazdy znak ze stringa
        {
            if (Tekst.at(i) == ' ') //Jesli spacja nastepuje powtorzenie petli
                bufor = 1;
            else
                TekstPoUsuwaniu += Tekst.at(i); //Jesli nie to dodanie do drugiego stringu
        }
    }
    return (TekstPoUsuwaniu); // Zwrocenie tesktu bez spacji
}

string Czy_jest_palindrom(string tekst)
{
    int size = tekst.length() - 1; // Przypisanie dlugosci stringa (oczywiscie odjete 1 gdyz liczymy od 0)
    int k = size;
    int i;
    string NegativeMessage = "Podany ciag znakow nie jest palindromem";
    string PositiveMessage = "Podany ciag znakow jest palindromem";
    for (i = 0; i < int(size / 2); i++) // Petla ktora sprawdza kazdy znak ze stringa
    {
        if (tekst[i] != tekst[k]) // Jesli litery na okreslonych pozycjach sa rozne przypisujemy do k -1 i zatrzymujemy program
        {
            return NegativeMessage;
        }
        else
        {
            k--;
        }
    }

    return PositiveMessage;
}
int main(int argc, char *argv[])
{
    // Deklaracja i wczytanie
    string tekst;
    cout << "Podaj ciag znakow: " << endl;
    getline(cin, tekst);

    string tekst_bez_spacji;

    // Sprawdzenie wystepowania spacji w stringu
    bool isSpaceExist = false;
    for (int i = 0; i < tekst.length() - 1; i++)
    {
        if (tekst.at(i) == ' ')
        {
            isSpaceExist = true;
            break;
        }
    }

        if (isSpaceExist) // Jesli w stringu spacja uruchom funkcje usuwania i przypisz nowa wartosc bez
    {
        tekst_bez_spacji = usunSpacje(tekst, tekst_bez_spacji);
    }
    else // Jesli nie przypisz bez uruchamiania funkcji usuwania
    {
        tekst_bez_spacji = tekst;
    }

    string result = "";

    // Uruchomienie i przypisanie wartosci z funkcji sprawdzajacej czy podany ciag jest palindromem
    result = Czy_jest_palindrom(tekst_bez_spacji);
    cout << result;
}