#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //pobranie wartosci masa i wzrost i przypisanie do zmiennych
    double masa = 0, wzrost = 0;
    cout << "Podaj mase ciala w kg" << endl;
    cin >> masa;
    cout << "Podaj wzrost w m" << endl;
    cin >> wzrost;

    //obliczenie bmi wedlug wzoru
    double BMI;
    BMI = double(masa / (wzrost * wzrost));

    cout << "Twoje BMI wynosi: " << BMI << endl; // wypisanie wartosci bmi

    //warunki sprawdzajace poziom wartosci bmi do podanego statusu norm
    cout << "Twoj zakres wartosci BMI: ";
    if (BMI < 16)
    {
        cout << "wyglodzenie";
    }
    else if (BMI >= 16 && BMI < 17)
    {
        cout << "wychudzenie";
    }
    else if (BMI >= 17 && BMI < 18.5)
    {
        cout << "niedowaga";
    }
    else if (BMI >= 18.5 && BMI < 25)
    {
        cout << "wartosc prawidlowa";
    }
    else if (BMI >= 25 && BMI < 30)
    {
        cout << "nadwaga";
    }
    else if (BMI >= 30 && BMI < 35)
    {
        cout << "I stopien otylosci";
    }
    else if (BMI >= 35 && BMI < 40)
    {
        cout << "II stopien otylosci";
    }
    else if (BMI >= 40)
    {
        cout << "otylosc skrajna";
    }
}