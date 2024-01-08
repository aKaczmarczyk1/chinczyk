#include <iostream>
#include <string>
using namespace std;


class System {
public:
    bool RozpocznijRozgrywke() {
        //tutaj rozpoczynaja sie wszystkie akcje zwiazane z rozpoczeciem gry, jezeli wszystko sie udaje, zwracana jest wartosc true
        //klasa ma dostêp do hosta, dlatego nie musz¹ byæ przesy³ane dane na temat wariantów i trybów, klasa sobie sama je "pobiera"
        bool jestOK = true;
        if (jestOK) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Host {
public:
    System system;
    string wariant_gry = "Brak";
    string tryb_gry = "Brak";

    void WybierzWariantGry(int wariant) {
        if (wariant == 1)
            wariant_gry = "Zbijanie";
        else
            wariant_gry = "BezZbijania";
    }

    void WybierzTrybGry(int tryb) {
        if (tryb == 1)
            tryb_gry = "Online";
        else
            tryb_gry = "Offline";
    }

    void WybierzDaneGry() {
        int tryb = 0;
        int wariant = 0;
        while (tryb <= 0 || tryb > 2 || wariant <= 0 || wariant > 2) {
            tryb = 0;
            wariant = 0;
            cout << "Podaj tryb gry: " << endl;
            cout << "1. Online" << endl;
            cout << "2. Offline" << endl;
            cin >> tryb;
            cout << "Podaj wariant gry: " << endl;
            cout << "1. Zbijanie" << endl;
            cout << "2. Brak zbijania" << endl;
            cin >> wariant;
            if (tryb <= 0 || tryb > 2 || wariant <= 0 || wariant > 2) {
                cout << "Podano nieprawidlowe dane, podaj jeszcze raz" << endl << endl;
            }
        }
        WybierzWariantGry(wariant);
        WybierzTrybGry(tryb);


        if (system.RozpocznijRozgrywke()) {
            cout << "Rozpoczeto rozgrywke";
        }
        else {
            cout << "Wystapil blad";
        }
    }
};



int main() {
    Host host;
    host.WybierzDaneGry();

    return 0;
}