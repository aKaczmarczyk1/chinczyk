#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct Prezydent{
    string year_start;
    string year_end;
    string party;
    string full_name;
 
    // Prezydent(string y0, string y1, string p, string n){
    //     year_start=y0;
    //     year_end=y1;
    //     party = p;
    //     full_name = n;
    // }
    void getPresident(){
        cout << year_start << " - " << year_end << " " << party << " " << full_name <<  endl;
        cout << "---------------------------\n";
    }
    int getYearStart(){
        int year = stoi(year_start);
        return year;
    }
    int getYearEnd(){
        int year = stoi(year_end);
        return year;
    }
    string getParty(){
        return party;
    }
    Prezydent* next;
}* head = NULL;

class Odpowiedzi{
    public: 
    Prezydent prez;
    Odpowiedzi* next;
}*head1 = NULL;

void append(Prezydent** head, Prezydent* president){
    class Prezydent* newPrezydent = new Prezydent(*president);
    class Prezydent* last = *head;

    //newPrezydent = &president;
    newPrezydent->next = NULL;

    if(*head == NULL){
        *head = newPrezydent;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last -> next = newPrezydent;

    //newPrezydent->getPresident();
    return;
}
void addOdpowiedzi(Odpowiedzi*& head, Prezydent x) {
    Odpowiedzi* tmp = new Odpowiedzi;
    tmp->prez = x;
    tmp->next = head;
    head = tmp;
}
void loadData(string path);
string* split(string s, string delimiter);
void Display(Odpowiedzi* head1){
    Odpowiedzi* tmp = head1;
    while(tmp != NULL){
        tmp->prez.getPresident();
        tmp = tmp->next;
    }
        
}
void deleteList(Odpowiedzi** head1) {
    Odpowiedzi* tmp = *head1;
    Odpowiedzi* next;
    while (tmp != NULL) {
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    *head1 = NULL;
}

Odpowiedzi* findShortest(Prezydent* head){
    
    Prezydent* tmp = head;
    
    int difference;
    int shortestYear = INT_MAX;

    while(tmp != NULL){
        int yearStart = tmp->getYearStart();
        int yearEnd = tmp->getYearEnd();
         
        difference = yearEnd - yearStart;
        if(difference < shortestYear)
            shortestYear = difference;

        tmp = tmp->next;
    }

    cout << "a) Presidents with the shortest presidential term ( " << shortestYear << " ): " << endl;
    tmp = head;
    while(tmp != NULL){
        int yearStart = tmp->getYearStart();
        int yearEnd = tmp->getYearEnd();
        if((yearEnd - yearStart) == shortestYear){
            addOdpowiedzi(head1, *tmp);
        }
        tmp = tmp->next;
    }
    return head1;
}

Odpowiedzi* findTheParty(Prezydent* head, string party){
    Prezydent* tmp = head;

    cout << "b) Presidents from the " << party << " party: " << endl;
    while(tmp != NULL){
        if(tmp->getParty() == party){
            addOdpowiedzi(head1, *tmp);
        }
        tmp = tmp->next;
    }
    return head1;
}
Odpowiedzi* WhoRuledThen(Prezydent* head, int year){
    Prezydent* tmp = head;
    cout << "In " << year << " the US was ruled by: " << endl;

    while(tmp!=NULL){
        if(year >= tmp->getYearStart() && year <= tmp->getYearEnd()){
            addOdpowiedzi(head1, *tmp);
        }
        tmp = tmp->next;
    }
    return head1;
}
int main() {
    //class Prezydent* head = NULL;
    loadData("C:/Users/Wojtek/Desktop/STUDIA/SEMESTR 3/AiSD/Linked Lists/Laby/prezydenci.txt");
    
    Odpowiedzi* o1 = findShortest(head);
    Display(o1);
    deleteList(&head1);
    
    string party = "Democratic";
    unsigned short choice = 0; 
    
    cout << "Choose party:\n[0] - Democratic\n[1] - Whig\n[2] - Republican\n[3] - Federalist\n[4] - Unaffiliated\n[5] - Democratic-Republican\nYour choice: ";
    cin >> choice;
    switch(choice){
        case 0: party = "Democratic"; break;
        case 1: party = "Whig"; break;
        case 2: party = "Republican"; break;
        case 3: party = "Federalist"; break;
        case 4: party = "Unaffiliated"; break;
        case 5: party = "Democratic-Republican"; break;
        default: cout << "Wrong input, displaying for democratic\n";
    }
    Odpowiedzi* o2 = findTheParty(head, party);
    Display(o2);
    deleteList(&head1);
    
    unsigned short year = 0;
    cout << "Input year of ruling: "; cin >> year;
    Odpowiedzi* o3;
    if(year < 1789){
            cout << "no one, there was no US back then " << endl;
            cout << "---------------------------\n";
    }
    else if(year > 1901){
            cout << "TOP SECRET" << endl;
            cout << "---------------------------\n";
    }
    else{
        o3 = WhoRuledThen(head,year);
    }
    Display(o3);   
    
    return 0;
}
string* split(string s, string delimiter) {

    int pos_start = 0;
    int pos_end;
    int delim_len = delimiter.length();

    string token;
    static string buffer[10];

    int idx = 0;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {

        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        buffer[idx] = token;
        idx++;

        //cout << idx << endl;

    }

    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    buffer[idx] = token;

    //cout << buffer[0] << endl;

    return buffer;

}

void loadData(string path) {
	string line;
	std::ifstream myFile("" + path);
	if (myFile.is_open()) {
		while (std::getline(myFile, line)) {
			string* buffer = split(line, " ");
            Prezydent* president = new Prezydent;
            president->year_start = buffer[0];
            president->year_end = buffer[1];
            president->party = buffer[2];
            president->full_name = buffer[3] + " " + buffer[4];
            append(&head, president);
            
        }
		myFile.close();
	}
	else cout << "Error\n";
}