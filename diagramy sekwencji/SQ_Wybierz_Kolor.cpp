#define PLAYERS 4
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Przeciwnik{};
class Komputer{};
class Lobby{};
class Kolor{};
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
    Lobby porzucLobby();  // return 
    
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
    bool Get_isLobby;
    vector<string> inUse;
    string color;

    string Set_statusInfo(bool isLobby);
  
    bool Set_isColorAvailable();
    string Set_pickColor(Lobby l,string name); // only when isColorAvailable == true

};
class Lobby{
    public:
    string Get_statusInfo; 
    bool Get_isColorAvailable;
    string Get_pickedColor;
    int timer;
    string names[4];
    string get_playerCurrentlyPicking;
    //bool Set_isLobby(Lobby*);
    string Set_ColorToPlayer();
    void timeTick();
    string Lobby::set_playerCurrentlyPicking(int id);
    Lobby(System s){
        names[0] = s.nazwa_gracza[0];
        names[1] = s.nazwa_gracza[1];
        names[2] = s.nazwa_gracza[2];
        names[3] = s.nazwa_gracza[3];
    }
};  
string Lobby::set_playerCurrentlyPicking(int id){
    return names[id];
}
bool Set_isLobby(Lobby* lobby){
    return (lobby !=  nullptr);
}
string Kolor::Set_statusInfo(bool isLobby){
    std::string retMessage;
    (isLobby) ? retMessage = "Lobby exists\n" : retMessage = "[ERROR]: Lobby doesn't exist or there are major problems with it. Further connections aborted.\n"; 
    return retMessage;
}
bool Kolor::Set_isColorAvailable(){
    for(int i = 0; i < inUse.size(); i++){
        if(color == inUse[i])
            return false;
    }
    return true;
}
string Kolor::Set_pickColor(Lobby l, string name){
    l.get_playerCurrentlyPicking = name;
    return color;
}
string Lobby::Set_ColorToPlayer(){
    return Get_pickedColor;
}

int main(){
    
    System server;
    Gra game;
    Kolor colorHandler;
    Lobby lobby(server);
    Przeciwnik opponent;
    Komputer cpu;

    colorHandler.Get_isLobby = Set_isLobby(&lobby); //1.CzyLobbyIstnieje()
    lobby.Get_statusInfo = colorHandler.Set_statusInfo(colorHandler.Get_isLobby); //1.1 ZwrocInfo()
    if(colorHandler.Get_isLobby){
        lobby.get_playerCurrentlyPicking = lobby.set_playerCurrentlyPicking(2); // gracz nr 3
        string name = lobby.get_playerCurrentlyPicking;
        colorHandler.color = colorHandler.Set_pickColor(lobby, name); //1.2 pickColor()
        lobby.Get_pickedColor = colorHandler.color;
        lobby.Get_isColorAvailable = colorHandler.Set_isColorAvailable(); //1.3isColorAvailable()

        if(lobby.Get_isColorAvailable && time > 0){
            for(int players = 0; players<PLAYERS; players++){
                server.nazwa_gracza.push_back(name);
                server.kolor_gracza.push_back(lobby.Set_ColorToPlayer()); //1.3.1 Set_ColorToPlayer()
            }

        }else{
            bool full = server.kolor_gracza.size() == 4;
            if(full){
                server.zacznijGre();
            }
        }
        
    }
    else{
        server.porzucLobby();
    }

    return 0;
}