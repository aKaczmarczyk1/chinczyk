	#include <iostream>
	#include <chrono>
	#include <ctime> 
	using namespace std;

	class Gracz : public Przeciwnik {
		bool czy_wyciszony;
	public:
		Gracz (){}
		ChatTekstowy napiszNaChacie(ChatTekstowy ct) {
			string wiadomosc;
			cout << "Wpisz wiadomosc:" << endl;
			cin >> wiadomosc;
			ct.wiadomosci[ct.licznik].tresc = wiadomosc;
			ct.wiadomosci[ct.licznik].nick = this->nazwa;
			ct.wiadomosci[ct.licznik].kolor_pionka = this->kolor_pionka;
			ct.wiadomosci[ct.licznik].godzina = chrono::system_clock::now();

			ct.licznik_wiadomosci++;
			return ct;
		}

		string wybierzKolorPionka(Serwer s) {
			cout << "Dostepne kolory: " << endl;
			for (int i = 0; i < 4; i++) {
				cout << s.dostepne_kolory[i] << endl;
			}

			string kolor;
			cout << "Wybierz kolor pionka." << endl;
			cin >> kolor;
			this->kolor_pionka = kolor;

			s.wykorzystane_kolory[0] = kolor;

			return kolor;
		}

		void podajNazwe(Serwer s) {
			cout << "Podaj nazwe." << endl;
			string nazwa;
			bool wolna;
			cin >> nazwa;
			int index;
		
			for (int i = 0; i < 3; i++) {
				if (s.nazwy_graczy[i] == nazwa) {
					cout << "Nazwa zajeta" << endl;
					wolna = 0;
				}
				else wolna = 1;
			}
			if (wolna) {
				this->nazwa = nazwa;
				s.nazwy_graczy[i] = nazwa;
			}
		}
	};


	//dodac moze licznik do chatu,
	//czy zwracane typy s¹ ok? wiadomosc zamiast chatu?
	//przeciwnik polaczony z serwerem zaleznoscia?
	//podaj nazwê???
	//metoda czynazwazajeta w serwerze?

	//gowno, jeszcze trzeba pozmieniac troche ale mi sie nie chce