
#include<iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

//logarytm naturalna
//mediana
//exp
const int E = 2.71828;
long double logNat(int val) {
    return log(val);
}

float mediana(vector<int> arr) {
    //1,2,3,4,5,6
    float med;
    std::sort(arr.begin(), arr.end());
    if (arr.size() % 2 == 0) {
        int pointer = arr.size() / 2;
        int pointer2 = pointer - 1;
        med = (pointer + pointer2) / 2;

    }
    else {
        //1,2,3,4,5
        int pointer = arr.size() / 2 - 1;
        med = pointer;

    }
    return med;
}
long double exponent(int val) {
    return pow(E, val);
}
int main() {
    srand(time(NULL));
    int choice;
    vector<int> array;
    cout << "Co chcesz policzyc:\n1-Mediana\t2-Logarytm Naturalny\t3-Eksponenta\n";
    cin >> choice;
    int value;
    int size = rand() % +10 + 5;

    switch (choice) {
    case 1:
        for (int i = 0; i < size; i++) {
            array.push_back(rand() % 20);
        }
        cout << "Mediana: " << mediana(array);
        break;
    case 2:
        cout << "Give value: "; cin >> value;
        cout << logNat(value);
        break;
    case 3:
        cout << "Give value: "; cin >> value;
        cout << exponent(value);
        break;
    }

    return 0;
}