#include <iostream>
using std::cout;
using std::cin;

int main() {
	//podaj 10 liczb -? zapamietaj w tablicy statycznej AA
	// ile z tych liczb jest ujemnych
	// utworz tab dyn bb i zpaisz tam te liczby
	// cout te liczby ujemne i info ile ich bylo i ile pominieto
	int ujemne = 0;
	int pominiete = 0;
	int AA[10];
	int* BB = new int[10];
	cout << "Podaj liczby: \n";
	for (int i = 0; i < 10; i++) {
		int liczba;
		cout << "[" << i << "]: ";
		cin >> liczba;
		AA[i] = liczba;
	}
	for (int elem = 0; elem < 10; elem++) {
		if (AA[elem] < 0) {
			BB[ujemne] = AA[elem];
			ujemne++;
		}
		else {
			pominiete++;
		}
	}
	cout << "ilosc ujemnych: " << ujemne << " ilosc pominietych: " << pominiete;
	cout << "Liczby ujemne:\n ";
	for (int ujem = 0; ujem < ujemne; ujem++) {
		cout << BB[ujem] << "\n";
	}



	return 0;
}
