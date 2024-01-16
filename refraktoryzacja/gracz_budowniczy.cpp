#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

// klasa serwer
class Serwer {

};

// klasa przeciwnik, rodzic
class Przeciwnik {
protected:
    string nazwa;
    string kolor_pionka;
    bool aktywny;
};

//klasa komputer, pochodna klasy przeciwnik, zawiera pole informujace o poziomie trudnosci komputera
class Komputer : Przeciwnik {
private:
    int trudnosc;
};

// klasa host, pochodna klasy gracz, posiada metode umozliwiajaca wyciszenie danego gracza
class Host : Gracz {
public:
    void wyciszGracza(Gracz g) { g.czy_wyciszony = true; }
};

// Klasa reprezentująca obiekt Gracz
class Gracz : Przeciwnik {
public:
    string nazwa;
    string kolor_pionka;
    bool czy_wyciszony = false;

    // Funkcja zwracająca gotowy obiekt ChatTekstowy
    ChatTekstowy zbudujWiadomosc() {
        ChatTekstowy ct;
        ct.wiadomosci[ct.licznik].nick = this->nazwa;
        ct.wiadomosci[ct.licznik].kolor_pionka = this->kolor_pionka;
        ct.wiadomosci[ct.licznik].godzina = chrono::system_clock::now();
        ct.licznik_wiadomosci++;
        return ct;
    }

    // Funkcja zwracająca wybrany kolor pionka
    string zbudujKolorPionka(Serwer s) {
        string kolor;
        cout << "Wybierz kolor pionka." << endl;
        cin >> kolor;
        this->kolor_pionka = kolor;
        s.wykorzystane_kolory[0] = kolor;
        return kolor;
    }

    // Funkcja zwracająca obiekt Gracz po podaniu nazwy
    static Gracz zbudujZPodanaNazwa(Serwer s, string nazwa) {
        Gracz gracz;
        gracz.nazwa = nazwa;
        s.nazwy_graczy[0] = nazwa;
        return gracz;
    }
};

// Klasa budowniczego dla obiektu Gracz
class GraczBuilder {
private:
    Gracz gracz;

public:
    virtual ~GraczBuilder (){}
    virtual void zbudujKolorPionka(Serwer s) const = 0;
    virtual void zbudujZPodanaNazwa(Serwer s, string nazwa) const = 0;
    virtual void pobierzGracza() const = 0;
    

    void zbudujKolorPionka(Serwer s) const override {
        // wybor koloru pionka
    }

    void zbudujZPodanaNazwa(Serwer s, string nazwa) const override {
        // budowa obiektu Gracz z podaną nazwą
    }

    void pobierzGracza() const override {
    }
};

class Director {
private:
    GraczBuilder* builder;
public:
    void setBuilder(GraczBuilder* b) {
        this->builder = b;
    }
    void buildPrzeciwnik() {
        this->builder->zbudujKolorPionka();
    }
};


int main() {
    // Przykładowe użycie budowniczego
    GraczBuilder builder;
    Serwer s;

    Gracz gracz1 = builder.zbudujKolorPionka(s).pobierzGracza();
    Gracz gracz2 = builder.zbudujZPodanaNazwa(s, "Gracz2").pobierzGracza();

    return 0;
}
