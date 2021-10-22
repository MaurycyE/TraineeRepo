#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>
#include <vector>

using namespace std;


class Uzytkownik
{
    public:
        Uzytkownik ();
        Uzytkownik(string nazwa, string haslo, int idUzytkownika);
        ~Uzytkownik();
        bool sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych (string nazwa,vector <Uzytkownik> uzytkownicy);
        string getterNazwa ();
        string getterHaslo();
        int getterIdUzytkownika();
        bool sprawdzCzyHasloJestPoprawne (string haslo, int i, vector <Uzytkownik> uzytkownicy);
        int znajdzUzytkownika(string nazwa, vector <Uzytkownik> uzytkownicy);
        //sprawdzNajwiekszaLiczbeIdUzytkownika();
        //vector<Uzytkownik> uzytkownicy;

    private:
        int idUzytkownika;
    string nazwa;
    string haslo;
    vector<Uzytkownik> uzytkownicy;


};

#endif // UZYTKOWNIK_H
