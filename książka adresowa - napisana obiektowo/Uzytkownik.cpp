#include "Uzytkownik.h"
#include <iostream>
#include <vector>

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

bool sprawdzCzyNazwaUzytkownikaJestJuzZajeta (string nazwa, vector <Uzytkownik> &uzytkownicy) {


for (auto itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {

    if (itr.nazwa==nazwa) {

        return true;
    }

}

return false;


}
