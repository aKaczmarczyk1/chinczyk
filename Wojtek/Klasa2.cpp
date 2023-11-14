#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class ChatTekstowy{

    public:
        void WyslijWiadomosc(string tresc);
};
class Przeciwnik{
 public:
    string nazwa;
    string kolor_pionka;
    int numer_pionka;
    int lokacja_gracza;
    
    Gra obecnaGra;
    ChatTekstowy chat;
    Przeciwnik();
    Przeciwnik(string nazwa, string kolor, int pionek, int lokacja_tego_gracza, Gra rozgrywka){
        this->nazwa = nazwa;
        this->kolor_pionka = kolor;
        this->numer_pionka = pionek;
        // lokacja_tego gracza to wartosc zwracana przez funkcje int WyslijLokacjeGracza(string nazwa);
        this->lokacja_gracza = lokacja_tego_gracza;
        obecnaGra = rozgrywka;
    }
protected:
    int PoruszPionkiem(int indeks);
    bool ZbijLubNie(); // funkcja dla graczy nie bedacych komputerami
    bool CzyMozeszSiePoruszyc();    //funkcja dla graczy nie bedacych koomputerami
    int RzucKostka();
    void WyjdzZBazy(int indeks);
    void SprawdzCzyNieWBazie(int indeks);
};

/*
    Fragment kodu klasy Gra ze względu na połączenie przeciwnika z Grą
*/
class Gra{
    public:
        int ilosc_graczy;  
        int ile_w_bazie;                            // ilosc wszystkich graczy na serwerze (np. host moze chciec zagrac tylko i wylacznie z jednym przeciwnikiem)
        std::vector<Przeciwnik*> Gracze; // dwuwymiarowa tablica przyjmująca postać arr[][] = {nazwa1, kolor1, lokacja1}, {nazwa2, kolor2, lokacja2} itd
        int RzucKostka();
        int PobierzLokalizacjePionka(string lokalizacja); // specjalna funkcja ktora zwraca int dla pola Przeciwnik.lokalizacja_gracza przy podaniu lokalizacji zaszyfrowanej jako string (funkcja zamienia to na int)
};

class Komputer : Przeciwnik{
 public:
    uint8_t trudnosc; //trudnosc opisuje poziom AI (od 1 do 4, przy AI=1 istnieje 25% szans ze wykona bicie, AI=2 istnieje na to 50% szans, itd.)
    Komputer(string nazwa, string kolor,int pionek, int lokacja_tego_gracza, Gra rozgrywka, uint8_t trudnosc) : Przeciwnik(nazwa,kolor, pionek,lokacja_tego_gracza, rozgrywka){
        this->trudnosc = trudnosc;
    }
    bool ZdecydujCzyBic(){
         /*
            1. Komputer wchodzi na pole które jest już obecnie zajęte (sprawdź lokalizacje innych graczy)
            2. Komputer podejmuje decyzje czy zbić czy oszczędzić swojego przeciwnika/tuteż gracza
            3. Komputer wyświetla komunikat na czacie
        */
        bool czyKolizja = false;
        int lGraczy = obecnaGra.ilosc_graczy;
        int indeksBitegoGracza;
        
        for(int i = 0; i < lGraczy; i++){
            if(!czyKolizja){
                if(obecnaGra.Gracze[i]->nazwa == this->nazwa) //kompilator zgłasza w tym miejscu błąd ponieważ nie wie, że element [przedział 0-lGraczy][0] będzie stringiem
                    continue;
                if(obecnaGra.Gracze[i]->lokacja_gracza == this->lokacja_gracza){
                    czyKolizja = true;
                    indeksBitegoGracza = i;
                }
            }
            if(czyKolizja){
                int los = rand()%(trudnosc+1);
                if(los==1){
                    obecnaGra.Gracze[indeksBitegoGracza]->lokacja_gracza = 0;
                    chat.WyslijWiadomosc(this->nazwa + ": Haha!\n");
                    return true;
                }
                else{
                    chat.WyslijWiadomosc(this-> nazwa + ": Tym razem cie oszczedze.\n");
                    return false;
                }
            }
        }

    }
    int ZdecydujKtorymPionkiemSieRuszyc(){
        /*
            1. Sprawdz ile pionkow poza baza
                - jeśli żadnego a RzutKostka != 6 ---> nic nie rob
                - jeśli RzutKostka == 6 a jakis pionek jeszcze w bazie
                    --> zdecyduj czy wyprowadzic pionka czy isc dalej
                - 
        */
       if(obecnaGra.ile_w_bazie == 4){
            if(RzucKostka() == 6){
                int indeks = rand()%5;
                PoruszPionkiem(indeks);
            }
       }
      else if(obecnaGra.ile_w_bazie == 3 || obecnaGra.ile_w_bazie == 2 || obecnaGra.ile_w_bazie == 1){
            if(RzucKostka() == 6){
                uint8_t czy_wyjsc_z_bazy = rand()%2;
                if(czy_wyjsc_z_bazy == 1){
                    int indeks = rand()%(obecnaGra.ile_w_bazie+1);
                    SprawdzCzyNieWBazie(indeks);
                    WyjdzZBazy(indeks);
                }else{
                    int indeks = rand()%(4-obecnaGra.ile_w_bazie + 1);
                    SprawdzCzyNieWBazie(indeks);
                    PoruszPionkiem(indeks);
                }
            }
       }else{
            int indeks = rand()%5;
            PoruszPionkiem(indeks);
       }
    }
};
int main(){
    srand(time(NULL));
    /*
        ....
    */
}