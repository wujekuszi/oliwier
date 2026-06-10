#include <iostream>
using namespace std;
int main() {

char plansza[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
void wyswietlPlansze() {
    cout << "\n";
    for (int i=0; i< 3; i++){
     cout << " ";
     for(int j=0; j<3; j++){
        cout << plansza[i][j];
        if (j<2) cout << " / ";
     }   
     cout << "\n";
     if (i<2) cout << "---+---+---\n";
    }
    cout << "\n";
}
bool sprawdzWygrana(char znak) {
    for (int i = 0; i < 3; i++) 
    if (plansza[i][0] == znak && plansza[i][1] == znak && plansza[i][2] == znak) {
        return true;
    }
    for (int i = 0; i< 3; i++){
        if (plansza[0][i] == znak && plansza[1][i] == znak && plansza[2][i] == znak) 
            return true;
        
    }
    if (plansza[0][0] == znak && plansza[1][1] == znak && plansza[2][2] == znak) 
        return true;
    
    if (plansza[0][2] == znak && plansza[1][1] == znak && plansza[2][0] == znak) 
        return true;
    
    return false;
    }
bool remis() {
    char gracz = 'x';
    int ruch;
    while (true) {
        wyswietlplansze();
        cout << "gracz " << gracz<< ", wybierz pole (1-9): ";
        cin >> ruch;if (ruch < 1 || ruch >9) {
            cout << "niepoprawny numer pola\n";
            continue;
        }
        int wiersz = (ruch - 1) / 3;
        int kolumna = (ruch - 1) % 3;
        if(plansza[wiersz][kolumna] == 'x' || plansza[wiersz][kolumna]== '0') {
            cout << "to pole jest juz zajete\n";
            continue;
        }
        plansza[wiersz][kolumna] = gracz;
        if (sprawdzwygrana(gracz)){
            wyswietlplansze();
            cout << "gracz " << gracz << " wygrywa!\n";
            break;
        }
        if (remis()) {
            wyswietlplansze();
            cout << "remis!\n";
            break;
        }
        gracz = (gracz == 'x') ? '0' : 'x';
    }
    return 0;
}
}
