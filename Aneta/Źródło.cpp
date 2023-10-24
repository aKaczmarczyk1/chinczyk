#include <iostream>
#include <string>
using namespace std;

int main() {
    string nazwa;
    bool zajeta = true;
    while (zajeta) {

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    if (nazwa == "ABC") {
        cout << "Nazwa jest zajeta." << endl;
    }
    else {
        zajeta = false;
        cout << "Poprawnie podano nazwe.";
    }
    }
    return 0;
}