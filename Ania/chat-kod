#include <iostream>
#include <string>

using namespace std;
#define TAB_SIZE 10

int main() {
	string wiadomosc;
	cout << "Wpisz wiadomość:" << endl;
	cin >> wiadomosc;

	string tab[TAB_SIZE] = { "przeklenstwo" };

	for (int i = 0; i < TAB_SIZE; i++) {
		if (wiadomosc == tab[i]) {
			cout << "Nie mozna wyslac wiadomosci. Niecenzuralne słowa";
		}
	}
	if (wiadomosc != tab[0]) {
		cout << "Wiadomosc wyslana.";
	}

	return 0;
}
