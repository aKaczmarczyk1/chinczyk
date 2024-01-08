#include <iostream>
#include <time.h>
using namespace std;

//funkcja generujaca losowy ciag znakow
std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

// klasa przeciwnik, zawiera nazwe, swoj kolor i informacje o tym czy jest aktywny
class Przeciwnik {
protected:
    string nazwa;
    string kolor_pionka;
    bool aktywny;
};

// klasa gracz, pochodna klasy przeciwnik, zawiera informacje czy gracz jest wyciczony
class Gracz : Przeciwnik {
public:
    bool czy_wyciszony = false;
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

// klasa gra, zawiera informacje o trybie rozgrywki oraz o poszczegolnych graczach
class Gra {
public:
    string tryb_rozgrywki;
    Gracz gracze[4];
    Komputer boty[4];
    bool czy_rozpoczeta;
    int ilosc_graczy;

public:
    // metoda ustalajaca tryb rozgrywki
    void zmienTrybRozgrywki(string tryb_rozgrywki) {
        this->tryb_rozgrywki = tryb_rozgrywki;
    }
};

// klasa gra online, pochodna klasy gra, zawiera link do zaproszenia oraz metody dodajace graczy i generujace link do zaproszenia
class GraOnline : public Gra {
public:
    // pole zawierajace link do zaproszenia do gry
    string link_do_zaproszenia;

    //konstruktor klasy gra online 
    GraOnline() {
        tryb_rozgrywki = "None";
        czy_rozpoczeta = 0;
        ilosc_graczy = 1;
    }

    // metoda dodajaca bota do gry,
    void dodajBota(Komputer komputer) {
        // warunek 1: ilosc graczy nie przekracza 4
        if (ilosc_graczy < 4) {
            // warunek 2: tryb gry jest odpowiednio ustawiony
            if (tryb_rozgrywki == "Uzupelnij botami") {
                // dodanie bota do listy botow
                boty[ilosc_graczy] = komputer;
                cout << "Pomyslnie dodano bota." << endl;
                // zwiekszenie licznika graczy
                ilosc_graczy++;
            }
            else
                cout << "Zmien tryb gry, aby moc dodac boty" << endl;
        }
        else
            cout << "Zbyt duzo graczy, nie mozna dodac." << endl;
    };

    // metoda dodajaca gracza do gry,
    void dodajGracza(Gracz gracz) {
        // warunek: ilosc graczy nie przekracza 4
        if (ilosc_graczy < 4) {
            // dodanie danego gracza do listy graczy
            gracze[ilosc_graczy] = gracz;
            cout << "Pomyslnie dodano gracza." << endl;
            // zwiekszenie licznika graczy
            ilosc_graczy++;
            
        }
        else
            cout << "Zbyt duzo graczy, nie mozna dodac." << endl;
    }

    // metoda generujaca link do zaproszenia
    string WygenerujLink() {
        link_do_zaproszenia = gen_random(15);
        return link_do_zaproszenia;
    }
};

// klasa serwer, zawierajaca informacje o hoscie, nr lobby, czasie w lobby i ilosci graczy
class Serwer {
private:
    Host host;
    int ilosc_graczy;
    int nr_lobby;
    int czas_w_lobby;

public:
    //metoda ustalajaca czas w lobby
    void setCzasWLobby(int czas_w_lobby) { this->czas_w_lobby = czas_w_lobby; }

    // metoda tworzaca gre online
    GraOnline StworzGreOnline(Host host) {
        GraOnline gra;
        ilosc_graczy = 0;
        ilosc_graczy++;
        this->host = host;
        nr_lobby = rand() % 100000 + 1;
        return gra;
    }
};


//====================MAIN===================//
int main() {
    srand(time(NULL));

    // powstanie hosta
    Host host;

    // stworzenie serwera
    Serwer serwer;

    //STWORZENIE GRY ONLINE
    cout << "Wcisnij 1 aby stworzyc gre" << endl;
    int wybor_hosta;
    cin >> wybor_hosta;
    
    if (wybor_hosta == 1) {
        // tworzenie rozgrywki online przypisanej do danego serwera i hosta
        GraOnline gra;
        gra = serwer.StworzGreOnline(host);

        //generowanie linku do zaproszenia
        string link = gra.WygenerujLink();
        cout << "Link do zaproszenia: " << link << endl;
   

    //WYBRANIE TRYBU GRY
    //host ma mozliwosc wybrania trybu gry
    cout << "Wybierz tryb gry: " << endl << "[1] - uzupelniaj botami" << endl << "[2] - graj bez botow" << endl;
    cin >> wybor_hosta;
    string tryb_gry;
    
    //ustalenie trybu gry
    switch (wybor_hosta)
    {
    case 1: tryb_gry = "Uzupelnij botami"; break;
    case 2: tryb_gry = "Nie uzupelniaj botami"; break;
    default:
        cout << "Zle dane." << endl;
        break;
    }

    // ustawienie trybu gry, na taki jaki wybral host
    gra.zmienTrybRozgrywki(tryb_gry);


    //DOBIERANIE GRACZY
    //host ma mozliwosc dobrania graczy
    cout << "Dobierz graczy: " << endl << "[1] - dodaj gracza" << endl << "[2] - dodaj bota" << endl << "[3] - rozpocznij rozgrywke" << endl;
      
    // przykladowi gracze, ktorzy dolacza do rozgrywki
        Gracz gracz;
        Komputer bot;

    while (true) {
        cin >> wybor_hosta;
        switch (wybor_hosta)
        {
        case 1: 
            //dodanie gracza do rozgrywki
            gra.dodajGracza(gracz); 
            break;
        case 2: 
            //dodanie bota do rozgrywki (jesli tryb sie zgadza)
            gra.dodajBota(bot); 
            break;
        case 3: 
            //rozpoczecie rozgrywki
            gra.czy_rozpoczeta = 1;
            cout << "Rozpoczynanie rozgrywki."; 
            exit(0);
        default:
            cout << "Zle dane" << endl;
            break;
        }
    }
    }
    else cout << "Gra nie zostala utworzona."; exit(0);

    return 0;
}
