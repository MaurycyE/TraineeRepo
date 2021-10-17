#include "Uzytkownik.h"
#include <iostream>

using namespace std;

Uzytkownik::Uzytkownik(string nazwa, string haslo, int idUzytkownika)
{
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
