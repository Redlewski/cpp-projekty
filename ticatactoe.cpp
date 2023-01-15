#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>

using namespace std;

/*
    #####################
    #### Tic Tac Toe ####
    #####################
    1. Pokazuje plansze (func)
    2. Wykonywanie ruchu
    3. Zmiana gracza (z 'x' na 'o')
    4. Sprawdza warunek wygranej i remisu
    5. Wyswietla wygranego
    6. Restartuje grę

    ZADANIE 1. - Napisz grę kółko i krzyżyk
    ZADANIE 2. - Dodaj menu, w którym gracz będzie miał możliwość wyboru trybu.
    ZADANIE 3. - Dodaj tryb. Wprowadź możliwość rozgrywki z komputerem.
    ZADANIE 4. - Wprowadź możliwość wyboru, jakim znakiem gracze chcą grać.
    (np. zamiast 'x' => '&' lub '6')

    biuro@redlewski.edu.pl

*/

char plansza[9];
bool isOn;
char player, players[2];
int moves;

void StartSingleplayer();
void StartMultiplayer();
void ChangePlayerChar();

void WyswietlPlansze();
void Reset();
char ZmienGracza(char p);
bool CzyKtosWygral(char * p, char pl);
void Wygrana(char p);

int main () {
    string pick;

    //Ustala startowe znaki
    players[0] = 'x';
    players[1] = 'o';

    //Menu rozgrywki
    while(true) {
        system("cls");
        cout<<"-----------------"<<endl;
        cout<<"   Tic Tac Toe   "<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1. Singleplayer"<<endl;
        cout<<"2. Multiplayer"<<endl;
        cout<<"3. Zmien znak"<<endl;
        cout<<"4. Wyjscie"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"Co robic?: ";
        cin>>pick;

        //Wybor opcji
        if(pick == "1") StartSingleplayer();
        else if(pick == "2") StartMultiplayer();
        else if (pick == "3") ChangePlayerChar();
        else if (pick == "4") break;
        else {
            cout<<"Nie ma takiej opcji!"<<endl;
            Sleep(1000);
        }
    }

    //Ekran pozegnalny
    cout<<endl;
    cout<<"Do zobaczenia!"<<endl;
    cout<<"TicTacToe by Adrian | Redlewski 2023 | Bye"<<endl<<endl;

    return 0;

}

//Menu rozgrywki
void StartSingleplayer() {
    Reset();
    char p;
    system("cls");

    //Gracz wybiera, jako kto chce zaczynac
    do {
        cout<<"Kim chcesz grac? ("<<string(1, players[0])<<"/"<<string(1, players[1])<<"): ";
        cin>>p;
    } while(!(p == players[0] || p == players[1]));

    //Rozgrywka trwa poki isOn = true
    while(isOn) {
        WyswietlPlansze();

        cout<<"Ruch gracza " << player << ": "<<endl<<endl;
        int move_num;

        //Warunek sprawdzajacy czy jest kolej gracza, czy komputera
        if(p == player) {
            do {
                cin>>move_num;
            } while(plansza[move_num-1] != ' ');
        }
        else {
            do  {
                //Losowanie liczby z przedzialu <0-9> + 1
                srand(time(NULL));
                move_num = rand()%9 + 1;
            } while (plansza[move_num-1] != ' ');

            //Czekamy 1s dla naturalnosci
            Sleep(1000);
        }

        //Robimy ruch
        plansza[move_num-1] = player;

        //Po 4 ruchu sprawdzamy czy ktos przypadkiem juz nie wygral
        if(moves > 4) {
            if(CzyKtosWygral(plansza, player)) {
                Wygrana(player);
                continue;
            }
        }

        //Jesli nie to zamieniamy gracza
        moves++;
        player = ZmienGracza(player);

    }

    //Czy rozpoczac rozgrywke jeszcze raz?
    char pick;
    cout<<"Czy chcesz zagrac jeszcze raz? (Y/n): ";
    cin>>pick;
    if(pick=='Y' || pick == 'y')
        StartSingleplayer();}  //Tryb z komputerem
void StartMultiplayer() {
    Reset();
    while(isOn) {
        WyswietlPlansze();

        //Pobieranie informacji gdzie wykonac ruch
        cout<<"Ruch gracza " << player << ": "<<endl<<endl;
        int move_num;
        cin>>move_num;

        //Jesli pole jest wolne to wykonujemy ruch
        if(plansza[move_num-1] == ' ')
            plansza[move_num-1] = player;
        else continue;


        //Po 4 ruchu sprawdzamy warunek wygranej
        if(moves > 4) {
            if(CzyKtosWygral(plansza, player)) {
                Wygrana(player);
                continue;
            }
        }

        moves++;
        player = ZmienGracza(player);

    }

    //Czy rozpoczac rozgrywke jeszcze raz?
    char pick;
    cout<<"Czy chcesz zagrac jeszcze raz? (Y/n): ";
    cin>>pick;
    if(pick=='Y' || pick == 'y')
        StartMultiplayer();
}   //Tryb zwykle kolko i krzyzyk
void ChangePlayerChar() {
    system("cls");

    char p;
    cout<<"--- Zmiana graczy ---"<<endl;

    cout<<"Podaj kto ma grac pod znakiem \'"<<string(1, players[0])<<"\': ";
    cin>>p;
    players[0] = p;

    cout<<"Podaj kto ma grac pod znakiem \'"<<string(1, players[1])<<"\': ";
    cin>>p;
    players[1] = p;

    cout<<"Gracze zostali zmienieni! Powrot do menu...";
    Sleep(1000);}   //Zmiana x i o na inne znaki

//Funkcje budujace
void Reset() {
    //Ustawia kazde pole planszy
    for(int i = 0; i < 9; i++)
        plansza[i] = ' ';

    //Resetuje wartosci poczatkowe
    isOn = true;
    player = players[0];
    moves = 1;}                               //Restartuje rozgrywkę
void WyswietlPlansze() {
    system("cls");
    cout<<" "<<plansza[6]<<" | "<<plansza[7]<<" | "<<plansza[8]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<plansza[3]<<" | "<<plansza[4]<<" | "<<plansza[5]<<" "<<endl;
    cout<<"-----------"<<endl;
    cout<<" "<<plansza[0]<<" | "<<plansza[1]<<" | "<<plansza[2]<<" "<<endl;
    cout<<endl; }                     //Wyswietla plansze
char ZmienGracza(char p) {
    if(p == players[0]) p = players[1];
    else p = players[0];
    return p;}                   //Zamienia gracza z 'x' na 'o' i odwrotnie
bool CzyKtosWygral(char * p, char pl) {
    if(p[6] == pl && p[7] == pl && p[8] == pl) return true;
    else if(p[3] == pl && p[4] == pl && p[5] == pl) return true;
    else if(p[0] == pl && p[1] == pl && p[2] == pl) return true;

    else if(p[0] == pl && p[3] == pl && p[6] == pl) return true;
    else if(p[1] == pl && p[4] == pl && p[7] == pl) return true;
    else if(p[2] == pl && p[5] == pl && p[8] == pl) return true;

    else if(p[0] == pl && p[4] == pl && p[8] == pl) return true;
    else if(p[2] == pl && p[4] == pl && p[6] == pl) return true;

    return false;}      //Sprawdza warunki wygranej
void Wygrana(char p) {
    system("cls");
    isOn = false;
    WyswietlPlansze();
    cout<<"Wygrywa gracz: "<<p<<endl;}                       //Procedura wygranej
