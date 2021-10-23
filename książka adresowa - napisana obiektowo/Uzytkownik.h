#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H
#include <iostream>
#include <vector>

using namespace std;


class Uzytkownik {
public:
    Uzytkownik ();
    Uzytkownik(string nazwa, string haslo, int idUzytkownika);
    ~Uzytkownik();
    bool sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych (string nazwa,vector <Uzytkownik> uzytkownicy);
    string getterNazwa()const ;
    string getterHaslo() const;
    int getterIdUzytkownika() const;
    void setterHaslo(string haslo);
    bool sprawdzCzyHasloJestPoprawne (string haslo, int i, vector <Uzytkownik> uzytkownicy);
    int znajdzUzytkownika(string nazwa, vector <Uzytkownik> uzytkownicy);


private:
    int idUzytkownika;
    string nazwa;
    string haslo;
    vector<Uzytkownik> uzytkownicy;


};

#endif // UZYTKOWNIK_H
