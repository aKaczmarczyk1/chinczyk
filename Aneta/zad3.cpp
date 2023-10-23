#include <iostream>
using namespace std;

float toMM(float inKm) {
    return inKm * 0.54;
}
float toM(float inKm) {
    return inKm * 0.62;
}

int main() {
    float inKm;
    cout << "Podaj odleglosc w km: ";
    cin >> inKm;
    cout << "Jest to " << toMM(inKm) << " mil morskich." << endl;
    cout << "Jest to " << toM(inKm) << " mil ladowych.";

    return 0;
}