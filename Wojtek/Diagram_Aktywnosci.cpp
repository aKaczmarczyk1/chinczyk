#include <iostream>
#include <fstream>
#include <string>
#define LOBBY_TIME 30
#define PRESCALER 2999
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

/*global timer */
float prescaler = 1999; //prescaler of timer
/*
    load all colors from database
*/
void loadData(string path, string colors_array[]) {
    string line;
    std::ifstream myfile;
    myfile.open(path);
    if (myfile.is_open())
    {
        for (int i = 0; i < 10; i++) {
            myfile >> colors_array[i];
            cout << colors_array[i] << endl;
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}
/*
    update list of colors that has been picked
        if you want to pick a color and it has already been picked -> display message, go back to picking
*/
void updateList(int player_id, string pickedcolors[], string pickedColor) {
    pickedcolors[player_id] = pickedColor;
}
string pickColor(string pickedColors[]) {
    string pickedColor;
    cin >> pickedColor;
    for (int j = 0; j < 4; j++) {
        if (pickedColor == pickedColors[j]) {
            cout << "Pick another color\n";
            pickedColor = "NAN";
            return pickedColor;
        }
    }
    return pickedColor;
}
/*
    server function - set Timer on lobby start;
*/
float setTimer() {
    float lobbyTime = LOBBY_TIME;
    return lobbyTime;
}
float tick(float* timer, bool* timeOut) {
    if (*timer - 1 < 0.f)
        *timeOut = true;
    return *timer - 1 / prescaler;
}
float getTimer(float* timer) {
    return *timer;
}

int main() {
    float timer;
    bool timeOut = false;
    bool allReady = true;
    string colors_array[10];
    string pickedColor;
    string pickedColors_array[4] = {"green, yellow", "NAN", "pink"}; // 4 players - index in array indicates index of a player
    int player_id = 3;
   
    //loadData("kolory.txt", colors_array);
    //pickedColor = pickColor(pickedColors_array);
    //cout << pickedColor;

    timer = setTimer();
    cout << getTimer(&timer);
    while (!timeOut) {
        timer = tick(&timer, &timeOut);
        cout << "Timer: " << getTimer(&timer) << endl;
    }
    if (timeOut) {
        for (int element = 0; element < 4; element++) {
            if (pickedColors_array[element] == "NAN") {
                cout << "[SERWER: Not all players are ready, abandoning lobby]\n";
                allReady = false;
            }
        }
    }
    if (allReady) {
        cout << "SERWER: All players are ready, starting lobby\n";
    }
    
    return 0;
    
}
