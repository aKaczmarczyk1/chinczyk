#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int DLUGOSC_TABLICY = 10;

void bubble_sort(int tab[DLUGOSC_TABLICY]) {
    bool is_swapped = true;
    int i = -1;
    while (is_swapped) {
        is_swapped = false;
        i++;
        for (int j = DLUGOSC_TABLICY - 1; j > i; j--) {
            if (tab[j] < tab[j - 1]) {
                int temp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = temp;
                is_swapped = true;
            }
        }
    }
}

float obliczMediane(int tab[DLUGOSC_TABLICY]) {
    bubble_sort(tab);
    if (DLUGOSC_TABLICY % 2 == 0) {
        float mediana = float((tab[(DLUGOSC_TABLICY - 1) / 2] + tab[DLUGOSC_TABLICY / 2])) / 2;
        return mediana;
    }
    else return tab[DLUGOSC_TABLICY / 2];
}

float ObliczLN(float liczba) {
    return log(liczba);
}
float obliczEksponent(float liczba) {
    return exp(liczba);
}


int main() {
    float liczba = 234;
    cout << "Logarytm naturalny liczby " << liczba << " wynosi " << ObliczLN(liczba) << endl;
    int tab[DLUGOSC_TABLICY] = {1, 76,3,2,8,6,7,3,55,10};
    cout << "Mediana wynosi " << obliczMediane(tab) << endl;
    cout << "Eksponent liczby " << 2 << " wynosi " << obliczEksponent(2);
    return 0;
}