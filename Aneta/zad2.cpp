#include <iostream>
using namespace std;
int main() {
    int AA[10];
    int negativeCounter = 0;
    int positiveCounter = 0;
    for (int i = 0; i < 10; i++) {
        cout << "Podaj " << i + 1 << " liczbe: ";
        cin >> AA[i];
        if (AA[i] < 0)
            negativeCounter++;
    }
    int* BB = new int(negativeCounter);
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        if (AA[i] <0) {
            BB[counter] = AA[i];
            counter++;
        }
        else {
            positiveCounter++;
        }
            
    }
    cout << "Liczby ujemne: " << endl;
    for (int i = 0; i < negativeCounter; i++) {
        cout << BB[i] << " ";
    }
    cout << endl << "Liczb ujemnych jest: " << negativeCounter << ". Pominieto: " << positiveCounter << " liczb.";

    delete[] BB;
    return 0;
}