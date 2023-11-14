#include <iostream>
#include <string>
using namespace std;
class Gracz : public Przeciwnik {
public:
    bool czyWyciszony = false;
    //kod
};
class Przeciwnik {
public:
    string nazwa = "";
    bool aktywny = false;
    //kod
};

class Gra {
public:
    bool czyRozpoczeta = false;
    Przeciwnik przeciwnicy[4];
    //kod
};

class Host : public Gracz {
public:
    void WyrzucGracza(Gracz g , Gra gra) {
        for (int i = 0; i < 4; i++) {
            if (gra.przeciwnicy[i].nazwa == g.nazwa) {
                gra.przeciwnicy[i].aktywny = false;
            }
        }
    }
    void WyciszGracza(Gracz g) {
        g.czyWyciszony = !g.czyWyciszony;

    }
    void RozpocznijRozgrywke(Gra gra) {
        gra.czyRozpoczeta = true;
    }
};
int main() {
    return 0;
}