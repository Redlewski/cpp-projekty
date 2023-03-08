// Online C++ compiler to run C++ program online
//Redlewski 2023
#include <iostream>
#include <string>
#include <math.h>

//  Redlewski 2023
//  biuro@redlewski.edu.pl

using namespace std;

//n - liczba do konwertowania, s - system w jakim konwertujemy
int ConvertToDec(string n, int s);
string ConvertToSystem(string _n, int s);

int getHEXValue(char hex);
string getHEXChar(int hex);

int main() {
    cout<<"Podaj system: ";
    int s; cin>>s;
    if(s > 16) return 0;

    string n; cin>>n;
    cout<<ConvertToSystem(n, s)<<endl;

    cin>>n;
    cout<<ConvertToDec(n, s)<<endl;


    return 0;
}

//Konwerter na system docelowy 's'
string ConvertToSystem(string _n, int s) {
    int n = stoi(_n);
    string output = "";

    //Pętla wyznaczająca resztę
    while(n!=0) {
        int reszta = n % s;
        n = (int) (n / s);

        //Od razu "odwracamy", czyli wstawiamy wartość na początkowy index
        output.insert(0, getHEXChar(reszta));
    }

    return output;
}
//Konwerter z 's' na decymalne
int ConvertToDec(string n, int s) {
    int len = n.length();
    int output = 0;

    while(len > 0)
        output += getHEXValue(n[len-1]) * pow(s, n.length() - len--);

    return output;
}
//Konwertujemy znak HEX na wartość liczbową
int getHEXValue(char hex) {
    int value;

    hex = toupper(hex);

    switch(hex) {
        case 'A':
            value = 10;
            break;
        case 'B':
            value = 11;
            break;
        case 'C':
            value = 12;
            break;
        case 'D':
            value = 13;
            break;
        case 'E':
            value = 14;
            break;
        case 'F':
            value = 15;
            break;
        default:
            value = int(hex) - 48;
            break;
    }

    return value;
}
//Konwertujmy liczbę na wartość HEX
string getHEXChar(int hex) {
    string value;

    switch(hex) {
        case 10:
            value = 'A';
            break;
        case 11:
            value = 'B';
            break;
        case 12:
            value = 'C';
            break;
        case 13:
            value = 'D';
            break;
        case 14:
            value = 'E';
            break;
        case 15:
            value = 'F';
            break;
        default:
            value = to_string(hex);
            break;
    }

    return value;
}
