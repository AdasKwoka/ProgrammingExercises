#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int a = 2, b = 3;
    int A[a][b], B[a][b], Wynik[a][b];
    int i, j;

    // wczytanie wartości pierwszej macierzy
    cout << "Podaj wartosci pierwszej macierzy: " << endl;
    for (i = 0; i < a; i++)
    { // pętla odpowiedzialna za ilość wierszy
        for (j = 0; j < b; j++)
        {                   // pętla odpowiedzialna za ilość liczb w wierszu
            cin >> A[i][j]; // wczytanie elementów pierwszej tablicy
        }
    }

    // wczytanie wartości drugiej macierzy
    cout << "Podaj wartosci drugiej macierzy: " << endl;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            cin >> B[i][j];
            Wynik[i][j] = A[i][j] + B[i][j]; // Dodanie do siebie macierzy A i B (mógłbym zrobić w osobnej pętli ale po co tworzyć kolejne pętle)
        }
    }

    //pokazanie wyniku
    cout << "Wynik dodawania macierzy : " << endl;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            cout << " [ " << Wynik[i][j] << " ] ";
        }
        cout << endl;
    }
}