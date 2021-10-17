#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>
//#include <vector>

using namespace std;


class Uzytkownik
{
    public:
        Uzytkownik(string nazwa, string haslo, int idUzytkownika);
        ~Uzytkownik();

        //sprawdzNajwiekszaLiczbeIdUzytkownika();


    private:
        int idUzytkownika;
    string nazwa;
    string haslo;
    //vector<Uzytkownik> uzytkownicy;


};

#endif // UZYTKOWNIK_H
