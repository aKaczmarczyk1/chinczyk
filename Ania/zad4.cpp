#include <iostream>
using namespace std;

/*
	ZADANIE 4:
*/

class Product {
	friend void najdrozszeDoNajtansze(Product tab[10]);
	friend ostream& operator<<(ostream& os, const Product& p);
	string nazwa;
	int cena;
public:
	Product(string n, int c) {
		nazwa = n;
		cena = c;
	}
	Product() {};
	string getNazwa() { return nazwa; }
	int getCena() {return cena;}
};
//przeci¹¿enie operatora <<
ostream& operator<<(ostream& os, const Product& p) {
	os << "Nazwa: " << p.nazwa << ", cena: " << p.cena << endl;
	return os;
}

//funkcja wypisuj¹ca produkty od najdro¿szych do najtañszych
void najdrozszeDoNajtansze(Product tab[10]) {
	//Product sort_tab[10];
	int tab_cen[10];
	for (int i = 0; i < 10; i++) {
		tab_cen[i] = tab[i].cena;
	}
	int i = tab_cen[0];
	int j = tab_cen[9];
	//int x = tab_cen[]


}

int main() {
	//Zadanie1();
	//Zadanie2();
	int cena;
	string nazwa;
	Product tab[10];

	//pobranie info o 10 produktach
	for (int i = 0; i < 10; i++) {
		cout << "Podaj informacje o " << i + 1 << " produkcie.\n";
		cout << "Nazwa: ";
		cin >> nazwa;
		cout << "Cena: ";
		cin >> cena;
		tab[i] = Product(nazwa, cena);
	}

	//wypisanie produktów od najtanszych do najdrozszych
	najdrozszeDoNajtansze(tab);


	return 0;
}