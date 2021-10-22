#include "Uzytkownik.h"
#include <iostream>
#include <vector>

using namespace std;

Uzytkownik::Uzytkownik(string nazwa, string haslo, int idUzytkownika) {
    this->nazwa = nazwa;
    this->haslo = haslo;
    this->idUzytkownika=idUzytkownika;
}

/*
Uzytkownik::~Uzytkownik()
{
    //dtor
}
*/

string Uzytkownik::getterNazwa () {

    return nazwa;

}

string Uzytkownik::getterHaslo () {

    return haslo;

}

int Uzytkownik::getterIdUzytkownika(){

return idUzytkownika;
}



bool sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych (string nazwa, vector <Uzytkownik> uzytkownicy) {


//for (auto itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {

    for (auto i=0; i<uzytkownicy.size(); i++) {


        if (uzytkownicy[i].getterNazwa()==nazwa) {

            return true;
        }
    }



    return false;


}

int znajdzUzytkownika (string nazwa, vector <Uzytkownik> uzytkownicy ) {


 for (auto i=0; i<uzytkownicy.size(); i++) {


        if (uzytkownicy[i].getterNazwa()==nazwa) {

            return i;
        }
    }
}

bool sprawdzCzyHasloJestPoprawne (string haslo, int i, vector <Uzytkownik> uzytkownicy) {

    if (uzytkownicy[i].getterHaslo()==haslo) {
            return true;



    }
    else
        return false;


}


