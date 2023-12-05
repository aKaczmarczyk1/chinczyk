#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Przeciwnik{};
class Komputer{};

class System{
    public:
    vector<string> nazwa_gracza;
    vector<string> kolor_gracza;
    vector<string> wykorzystane_kolory;
    vector<vector<string>> historia_chatu;
    vector<string> dostepne_kolory;
    int numer_lobby;
    vector<vector<int>> lokacje_graczy;
    Przeciwnik znajdzGracza();
    Komputer dodajBota();
    //funkcje dodane na biezaco na potrzeby diagramu sekwencji
    void zacznijGre();
    string stworzLobby(); //return lobby_id
};

class Gra{
    public:
    string tryb_rozgrywki;
    vector<vector<int>> lokacja_graczy;
    vector<Przeciwnik> przeciwnik;
    bool czy_gra_ropoczeta;
    string zmienTrybRozgrywki();
    void opuscRozgrywke();
    int rzucKostka();
    vector<int> poruszPionkiem();
    vector<int> zbijPionka();
    void przygotujInformacjeOGrze();
    void przeanalizujInformacje();
    
};
class Kolor{
    public:
    string wybierzKolor();
    bool czyKolorDostepny();
};
class Lobby{
    public:
    bool czyLobbyIstnieje(string);
    string zwrocInfo();
    Kolor ustawKolor();

};
bool Lobby::czyLobbyIstnieje(string lobby_id){
    
}



int main(){


    return 0;
}