#include<iostream>
using namespace std;

class Serwer{
private:
	int nr_lobby;
	int czas_w_lobby;

public:
	void setNrLobby(int nr_lobby) { this->nr_lobby = nr_lobby; }
	Przeciwnik ZnajdzGraczy() {
		Przeciwnik p;
		return p;
	}
	
	Komputer DodajBota() {
		Komputer k;
		return k;
	}
};

class Przeciwnik {
protected:
	string nazwa;
	string kolor_pionka;
	bool aktywny;
};

class Gracz : Przeciwnik{
public: 
	bool czy_wyciszony = false;

};

class Komputer : Przeciwnik {
private:
	int trudnosc;
};

class Host : Gracz {
public:
	void wyciszGracza(Gracz g) {
		g.czy_wyciszony = true;
	}
};

class Gra {
public:
	string tryb_rozgrywki;
	Gracz gracze[3];
	Komputer boty[3];
	bool czy_rozpoczeta;
	int ilosc_graczy;

public:
	void zmienTrybRozgrywki(string tryb_rozgrywki) {
		this->tryb_rozgrywki = tryb_rozgrywki;
	}
};

class GraOnline : public Gra {
public:
	string link_do_zaproszenia;
	Komputer dodajBota(Komputer k) {
		boty [ilosc_graczy] = k;
		return k;
	}
};

