//#include <iostream>
//#include <string>
//using namespace std;
//
//bool czyNazwaZajeta(string nazwa) {
//    //Sprawdzenie na serwerze czy inny uzytkownik nie posiada takiej samej nazwy
//    return false;
//}
//
//int main() {
//    string nazwa;
//    bool czyNazwaOK = false;
//    while (!czyNazwaOK) {
//    cout << "Podaj nazwe uzytkownika: ";
//    cin >> nazwa;
//    if (!czyNazwaZajeta(nazwa)) {
//        if (nazwa.length() > 0 && nazwa.length() <= 25 && !(nazwa.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") != std::string::npos)) {
//            cout << "Poprawnie podano nazwe";
//            czyNazwaOK = true;
//        }
//        else {
//            cout << "Nazwa nie spelnia warunkow, podaj inna" << endl;
//        }
//    }
//    else {
//        cout << "Nazwa uzytkownika zajeta, podaj inna" << endl;
//    }
//    }
//    return 0;
//}