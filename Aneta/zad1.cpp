#include <iostream>
using namespace std;
int main() {
    for (int i = 300; i <= 1200; i++) {
        if (i % 2 == 1) {
            cout << i;
            if ((i + 1) % 400 != 0 && (i + 1) % 100 != 0)
                cout << " ";
        }
        if (i % 400 == 0) {
            cout << endl;
        }
        else if (i % 100 == 0 && i != 300) {
            cout << " *** ";
        }
    }
    return 0;
}