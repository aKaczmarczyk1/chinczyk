#include <iostream>
using namespace std;


int main() {

	//wpisanie liczb do AA
	cout << "Podaj 10 liczb: ";
	int AA[10];
	for (int i = 0; i < 10; i++) {
		int nr;
		cin >> nr;
		AA[i] = nr;
	}

	//zliczanie liczb ujemnych
	int count = 0;
	for (int i = 0; i < 10; i++) {
		if (AA[i] < 0) {
			count++;
		}
	}
	int* BB = new int[count];
	count = 0;
	for (int i = 0; i < 10; i++) {
		if (AA[i] < 0) {
			BB[count] = AA[i];
			count++;
		}
	}

	//wypisz liczby z BB
	cout << "Liczby ujemne: " << endl;
	for (int i = 0; i < count; i++) {
		cout << BB[i] << endl;
	}

	return 0;
}