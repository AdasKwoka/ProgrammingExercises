#include <iostream>

using namespace std;

// funckja quicksort do posortowania danej tablicy
void quicksort(int *tablica, int lewy, int prawy)
{
    int v = tablica[(lewy + prawy) / 2];
    int i, j, x;
    i = lewy;
    j = prawy;

    do
    {
        while (tablica[i] < v)
            i++;
        while (tablica[j] > v)
            j--;
        if (i <= j)
        {
            x = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = x;
            i++;
            j--;
        }

    } while (i <= j);
    if (j > lewy)
        quicksort(tablica, lewy, j);
    if (i < prawy)
        quicksort(tablica, i, prawy);
}
int main(int argc, char *argv[])
{
    // wczytanie liczb podanych do posortowania
    int ile, i;
    cout << "Podaj ilosc liczb do posortowania: " << endl;
    cin >> ile;
    int *tablica;
    tablica = new int[ile];

    cout << "Podaj liczby do posortowania: " << endl;
    for (i = 0; i < ile; i++)
    {
        cin >> tablica[i];
    }

    // wyswietlnie tablicy przed sortowaniem
    cout << "Tablica przed sortowaniem: " << endl;
    for (i = 0; i < ile; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;

    // uruchomienie funkcji sortujacej tablice
    quicksort(tablica, 0, ile - 1);

    // wyswitlenie posortowanej tablicy
    cout << "Tablica po sortowaniu: " << endl;
    for (i = 0; i < ile; i++)
    {
        cout << tablica[i] << " ";
    }
    delete[] tablica;
}