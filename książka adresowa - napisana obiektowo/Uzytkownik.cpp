#include "Uzytkownik.h"
#include <iostream>
#include <vector>

using namespace std;

Uzytkownik::Uzytkownik(string nazwa, string haslo, int idUzytkownika) {
    this->nazwa = nazwa;
    this->haslo = haslo;
    this->idUzytkownika=idUzytkownika;
}

Uzytkownik::Uzytkownik() {

}


Uzytkownik::~Uzytkownik() {
    //cout<<"destruktor uruchomiony"<<endl;
    //dtor
}


string Uzytkownik::getterNazwa () const {

    return nazwa;

}

string Uzytkownik::getterHaslo () const {

    return haslo;

}

void Uzytkownik::setterHaslo(string haslo) {

    this->haslo=haslo;
}

int Uzytkownik::getterIdUzytkownika() const {

    return idUzytkownika;
}



bool Uzytkownik::sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych (string nazwa, vector <Uzytkownik> uzytkownicy) {

    for (auto i=0; i<uzytkownicy.size(); i++) {


        if (uzytkownicy[i].getterNazwa()==nazwa) {

            return true;
        }
    }

    return false;
}

int Uzytkownik::znajdzUzytkownika (string nazwa, vector <Uzytkownik> uzytkownicy ) {


    for (auto i=0; i<uzytkownicy.size(); i++) {

        if (uzytkownicy[i].getterNazwa()==nazwa) {

            return i;
        }
    }
}

bool Uzytkownik:: sprawdzCzyHasloJestPoprawne (string haslo, int i, vector <Uzytkownik> uzytkownicy) {

    if (uzytkownicy[i].getterHaslo()==haslo) {
        return true;
    }

    else
        return false;
}


