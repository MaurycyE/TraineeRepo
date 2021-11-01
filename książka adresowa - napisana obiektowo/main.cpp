#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Uzytkownik.h"
#include "Kontakty.h"

using namespace std;

int sprawdzNajwiekszaLiczbeID (vector<Kontakty> &kontakty) {

    int najwiekszaWartoscNumeruID;
    Kontakty zapisanyKontakt;

    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(ksiazkaAdresowa.good()==false)
        cout<<"!"<<endl;

    else {

        string linia;
        int licznikZnakuPrzerwy = 0;

        while(getline(ksiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if(linia[i]=='|') {
                    licznikZnakuPrzerwy++;

                    if (licznikZnakuPrzerwy%7==1) {
                        Kontakty zapisanyKontakt;
                        string danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);

                        zapisanyKontakt.setterIdKontaktu(atoi(numerIDkontaktu.c_str()));

                        najwiekszaWartoscNumeruID=zapisanyKontakt.getterIdKontaktu();

                    }
                }
            }
        }
        ksiazkaAdresowa.close();
    }

    return najwiekszaWartoscNumeruID;
}

void wczytajWszystkieOsobyZpliku (vector<Kontakty> &pelnaListaKontaktow) {

    fstream PelnaKsiazkaAdresowa;

    PelnaKsiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(PelnaKsiazkaAdresowa.good()==true) {

        int j=0;
        string linia="";
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";
        int idUzytkownika=0;
        int idKontaktu=0;
        string imie="";
        string nazwisko="";
        string nrTelefonu="";
        string email="";
        string adres="";

        while(getline(PelnaKsiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%7==1) {

                        danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);

                        idKontaktu=atoi(danaInformacja.c_str());
                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==2) {

                        idUzytkownika=atoi(danaInformacja.c_str());
                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==3) {

                        imie=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==4) {

                        nazwisko=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==5) {

                        nrTelefonu=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==6) {

                        email=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==0) {

                        adres=danaInformacja;
                        danaInformacja="";
                        Kontakty danyKontakt(idKontaktu, idUzytkownika, imie, nazwisko, nrTelefonu, email, adres);
                        pelnaListaKontaktow.push_back(danyKontakt);

                    }

                    i++;
                }

                danaInformacja+=linia[i];

            }

        }

    }

    PelnaKsiazkaAdresowa.close();
}


int wczytajOsobyZpliku (vector<Kontakty> &kontakty, int idZalogowanegoUzytkownika) {

    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(ksiazkaAdresowa.good()==false) {
        cout<<"Brak zapisanych kontaktow"<<endl;
        Sleep(1000);
    }

    else {

        int j=0;
        string linia;
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";
        int idUzytkownika=0;
        int idKontaktu=0;
        string imie="";
        string nazwisko="";
        string nrTelefonu="";
        string email="";
        string adres="";

        while(getline(ksiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%7==1) {

                        danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);
                        idKontaktu=atoi(danaInformacja.c_str());
                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==2) {

                        idUzytkownika=atoi(danaInformacja.c_str());
                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==3) {

                        imie=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==4) {

                        nazwisko=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==5) {

                        nrTelefonu=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==6) {

                        email=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==0) {

                        adres=danaInformacja;
                        danaInformacja="";
                        Kontakty danyKontakt(idKontaktu, idUzytkownika, imie, nazwisko, nrTelefonu, email, adres);
                        kontakty.push_back(danyKontakt);

                        if(kontakty[j].getterIdUzytkownika() != idZalogowanegoUzytkownika) {

                            kontakty.erase(kontakty.begin()+j);
                        }

                        else
                            j++;
                    }

                    i++;
                }

                danaInformacja+=linia[i];

            }

        }

    }

    ksiazkaAdresowa.close();

    int iloscKontaktow=kontakty.size();

    return iloscKontaktow;

}

void wczytajIdKontaktuPoDodaniuNowejOsoby (vector<Kontakty> &kontakty) {

    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(ksiazkaAdresowa.good()==false) {
        cout<<"Brak zapisanych kontaktow"<<endl;
        Sleep(1000);
    }

    else {

        int j=0;
        string linia;
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";

        while(getline(ksiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%7==1) {

                        string danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);

                        kontakty[j].setterIdKontaktu(atoi(numerIDkontaktu.c_str()));
                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==0) {

                        danaInformacja="";
                        j++;
                    }

                    i++;
                }

                danaInformacja+=linia[i];
            }

        }

    }
    ksiazkaAdresowa.close();
}

int dodajKontakt (vector<Kontakty> &pelnaListaKontaktow, vector<Kontakty> &kontakty, int iloscKontaktow, int idUzytkownika) {

    string imie, nazwisko, nrTelefonu, email, adres;
    fstream ksiazkaAdresowa;

    cout<<"Podaj imie: ";
    cin>>imie;
    cout<<"Podaj nazwisko: ";
    cin>>nazwisko;
    cout<<"Podaj numer telefonu: ";
    cin>>nrTelefonu;
    cout<<"Podaj email: ";
    cin>>email;
    cout<<"Podaj adres: ";
    cin.sync();
    getline(cin, adres);

    Kontakty zapisanyKontakt(sprawdzNajwiekszaLiczbeID(kontakty)+1, idUzytkownika,imie,nazwisko,nrTelefonu,email,adres);

    pelnaListaKontaktow.push_back(zapisanyKontakt);

    ksiazkaAdresowa.open("Adresaci.txt", ios::out | ios::app);

    ksiazkaAdresowa<<sprawdzNajwiekszaLiczbeID(pelnaListaKontaktow)+1<<"|"<<idUzytkownika<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<email<<"|"<<adres<<"|";
    ksiazkaAdresowa<<endl;

    ksiazkaAdresowa.close();

    cout<<"Kontakt dodany";
    Sleep(1000);

    wczytajIdKontaktuPoDodaniuNowejOsoby(pelnaListaKontaktow);

    kontakty.erase(kontakty.begin(), kontakty.end());

    wczytajOsobyZpliku(kontakty, idUzytkownika);

    return iloscKontaktow+1;

}

void wyswietlWszystkieKontakty (vector<Kontakty> &kontakty, int iloscKontaktow) {

    if (kontakty.size()==0) {

        cout<<"Brak zapisanych kontaktow"<<endl;
        Sleep(1000);
        return ;

    }
    Kontakty kontaktyDoWyswietlenia;
    kontaktyDoWyswietlenia.wyswietlListeKontaktow(kontakty);

}


void znajdzPoImieniu (string imie, vector<Kontakty> &kontakty, int iloscKontaktow) {

    Kontakty danyKontakt;
    danyKontakt.sprawdzCzyPodaneImieJestWbazieDanych(imie, kontakty);

    cout<<endl<<"Nacisnij enter zeby powrocic do poprzedniego menu";
    getchar();
    getchar();
}

void znajdzPoNazwisku (string nazwisko, vector<Kontakty> &kontakty, int iloscKontaktow) {

    Kontakty danyKontakt;
    danyKontakt.sprawdzCzyPodaneNazwiskoJestWbazieDanych(nazwisko, kontakty);

    cout<<endl<<"Nacisnij enter zeby powrocic do poprzedniego menu";
    getchar();
    getchar();

}

int usunKontakty (vector<Kontakty> &kontakty, vector<Kontakty> &pelnaListaKontaktow, int iloscKontaktow) {

    int nrIdKontaktuDoUsuniecia=0;

    cout<<"Podaj numer id kontaktu do usuniecia: ";
    cin>>nrIdKontaktuDoUsuniecia;

    for (int i=0; i<iloscKontaktow; i++) {

        if(nrIdKontaktuDoUsuniecia==kontakty[i].getterIdKontaktu()) {
            cout<<"Znaleziono kontakt: "<<kontakty[i].getterImie()<<" "<<kontakty[i].getterNazwisko()<<endl;

            char odpowiedzUzytkownika;
            string liniaDoUsuniecia;

            cout<<"Czy na pewno chcesz usunac kontakt? Wcisnij t/n"<<endl;
            cout<<"Odpowiedz: ";
            cin>>odpowiedzUzytkownika;

            if (odpowiedzUzytkownika=='t') {

                Kontakty kontaktDoUsuniecia;
                kontaktDoUsuniecia.usunPozycjeZwektora(nrIdKontaktuDoUsuniecia, kontakty);

                kontaktDoUsuniecia.usunKontaktZplikuTekstowego (nrIdKontaktuDoUsuniecia, pelnaListaKontaktow);

                kontaktDoUsuniecia.usunPozycjeZwektora(nrIdKontaktuDoUsuniecia, pelnaListaKontaktow);

                iloscKontaktow = iloscKontaktow-1;
                cout<<"Kontakt usuniety"<<endl;
                Sleep(1500);

                return iloscKontaktow;

            } else {
                cout<<"Kontakt zostanie zachowany"<<endl;
                Sleep(1500);
                return iloscKontaktow;
            }

        }

    }

    cout<<"Nie ma kontaktu o takim numerze ID"<<endl;
    Sleep(1500);

    return iloscKontaktow;
}

void zapiszNoweInformacjeWPliku (vector<Kontakty> &kontakty, vector<Kontakty> &pelnaListaKontaktow, int nrIdKontaktuDoEdycji) {

    Kontakty kontaktDoEdycji;
    kontaktDoEdycji.zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji, pelnaListaKontaktow, kontakty);

}

void edytujKontakt(vector<Kontakty> &kontakty, vector<Kontakty> &pelnaListaKontaktow, int iloscKontaktow) {

    int nrIdKontaktuDoEdycji=0;

    cout<<"Podaj numer id kontaktu do edycji, lub wpisz 0 by wrocic do poprzedniego menu: ";
    cin>>nrIdKontaktuDoEdycji;

    Kontakty edytowanyKontakt;
    edytowanyKontakt.edytujKontakty(nrIdKontaktuDoEdycji, kontakty, pelnaListaKontaktow);

}

int wczytajUzytkownikowZpliku (vector <Uzytkownik> &uzytkownicy) {

    fstream listaUzytkownikow;
    int iloscUzytkownikow=0;

    uzytkownicy.erase(uzytkownicy.begin(), uzytkownicy.end());

    listaUzytkownikow.open("Uzytkownicy.txt", ios::in);

    if(listaUzytkownikow.good()==false) {
        cout<<"Nie ma jeszcze zapisanych uzytkownikow"<<endl;
        Sleep(1000);
    }

    else {

        string linia;
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";
        string nazwa ="";
        string haslo ="";
        int idUzytkownika =0;

        while(getline(listaUzytkownikow,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%3==1) {

                        danaInformacja=linia;
                        string numerIDuzytkownika = danaInformacja.erase(i, danaInformacja.length()-i);

                        idUzytkownika=atoi(numerIDuzytkownika.c_str());
                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%3==2) {

                        nazwa=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%3==0) {

                        haslo = danaInformacja;
                        danaInformacja="";
                        Uzytkownik zapisanyUzytkownik(nazwa, haslo, idUzytkownika);
                        uzytkownicy.push_back(zapisanyUzytkownik);
                        iloscUzytkownikow++;
                    }

                    i++;
                }

                danaInformacja+=linia[i];

            }

        }

    }

    listaUzytkownikow.close();
    return iloscUzytkownikow;
}

int rejestracja (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow ) {
    string nazwa, haslo;
    fstream wszyscyUzytkownicy;

    cout<<"Podaj nazwe uzytkownika: ";
    cin.sync();
    getline(cin, nazwa);

    Uzytkownik obiektUzytkownik;
    while (obiektUzytkownik.sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych(nazwa, uzytkownicy)==true) {

        cout<<"Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
        cin>>nazwa;
    }

    cout<<"Podaj haslo: ";
    cin>>haslo;

    iloscUzytkownikow++;
    Uzytkownik nowyUzytkownik(string nazwa, string haslo, int iloscUzytkownikow);

    wszyscyUzytkownicy.open("Uzytkownicy.txt", ios::out | ios::app);

    wszyscyUzytkownicy<<iloscUzytkownikow+1<<"|"<<nazwa<<"|"<<haslo<<"|";
    wszyscyUzytkownicy<<endl;

    wszyscyUzytkownicy.close();

    cout<<"Konto zalozone"<<endl;
    Sleep(1000);

    wczytajUzytkownikowZpliku (uzytkownicy);

    return iloscUzytkownikow+1;

}

int logowanie(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow) {

    string nazwa, haslo;
    cout<<"Podaj login: ";
    cin.sync();
    getline(cin, nazwa);
    int i = 0;

    Uzytkownik obiektUzytkownik;

    if (obiektUzytkownik.sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych(nazwa, uzytkownicy)==false) {
        cout<<"Nie ma uzytkownika z takim loginem"<<endl;
        Sleep(1000);
        return 0;

    }

    i=obiektUzytkownik.znajdzUzytkownika(nazwa, uzytkownicy);

    for (int proby=0; proby<3; proby++) {

        cout<<"Podaj haslo. Pozostalo prob "<<3-proby<<": ";
        cin>>haslo;

        if (obiektUzytkownik.sprawdzCzyHasloJestPoprawne (haslo, i, uzytkownicy)==true) {
            cout<<"Zalogowales sie."<<endl;
            Sleep(1000);

            return uzytkownicy[i].getterIdUzytkownika();
        }

    }
    cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
    Sleep(3000);
    return 0;

}

int logowanieUzytkownika (vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika) {

    int iloscUzytkownikow = wczytajUzytkownikowZpliku (uzytkownicy);

    char wybor;

    while (1) {
        if (idZalogowanegoUzytkownika ==0) {
            system("cls");
            cout<<"1. Rejestracja"<<endl;
            cout<<"2. Logowanie"<<endl;
            cout<<"3. Zakoncz program"<<endl;
            cin>>wybor;

            if (wybor == '1') {
                iloscUzytkownikow = rejestracja (uzytkownicy, iloscUzytkownikow);

            }

            else if (wybor=='2') {

                idZalogowanegoUzytkownika=logowanie(uzytkownicy, iloscUzytkownikow);
                return idZalogowanegoUzytkownika;

            }

            else if (wybor=='3') {
                exit(0);
            }
        }

    }

}

void zapiszNoweInformacjeOuzytkowniku (vector<Uzytkownik> &uzytkownicy) {

    ofstream wszyscyUzytkownicy;

    wszyscyUzytkownicy.open("Uzytkownicy.txt", ios::out);

    for (Uzytkownik obiektUzytkownik: uzytkownicy) {

        wszyscyUzytkownicy<<obiektUzytkownik.getterIdUzytkownika()<<"|"<<obiektUzytkownik.getterNazwa()<<"|"<<obiektUzytkownik.getterHaslo()<<"|";
        wszyscyUzytkownicy<<endl;

    }
    wszyscyUzytkownicy.close();
}


void zmianaHasla(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika) {

    string haslo;

    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    for (int i=0; i<uzytkownicy.size(); i++) {

        if(uzytkownicy[i].getterIdUzytkownika()==idZalogowanegoUzytkownika) {

            uzytkownicy[i].setterHaslo(haslo);
            zapiszNoweInformacjeOuzytkowniku(uzytkownicy);

            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1500);
        }

    }

}

int main() {

    vector<Kontakty> kontakty;
    vector<Kontakty> pelnaListaKontaktow;
    vector<Uzytkownik> uzytkownicy;

    int idZalogowanegoUzytkownika = 0;

    while (idZalogowanegoUzytkownika==0) {

        idZalogowanegoUzytkownika = logowanieUzytkownika(uzytkownicy,idZalogowanegoUzytkownika);
    }

    int idKontaktu = 0;

    wczytajWszystkieOsobyZpliku (pelnaListaKontaktow);

    int   iloscKontaktow = wczytajOsobyZpliku(kontakty, idZalogowanegoUzytkownika);

    string imie, nazwisko;
    char wybor;

    while (1) {
        Uzytkownik zalogowanyUzytkownik;

        if (idKontaktu ==0) {
            system("cls");
            cout<<"Zalogowany uzytkownik: "<<zalogowanyUzytkownik.wyswietlZalogowanegoUzytkownika(idZalogowanegoUzytkownika, uzytkownicy)<<endl<<endl;
            cout<<"1. Dodaj kontakt"<<endl;
            cout<<"2. Wyszukaj kontakt po imieniu"<<endl;
            cout<<"3. Wyszukaj kontakt po nazwisku"<<endl;
            cout<<"4. Wyswietl wszystkie kontakty"<<endl;
            cout<<"5. Usun kontakt"<<endl;
            cout<<"6. Edytuj kontakt"<<endl;
            cout<<"7. Zmiana hasla"<<endl;
            cout<<"8. Wylogowanie"<<endl;
            cout<<"9. Zakoncz program"<<endl;
            cout<<"Twoj wybor: ";
            cin>>wybor;
            cout<<endl;

            if (wybor == '1') {
                iloscKontaktow = dodajKontakt (pelnaListaKontaktow, kontakty, iloscKontaktow, idZalogowanegoUzytkownika);

            }

            else if (wybor=='2') {
                cout<<"Wpisz imie: ";
                cin>>imie;
                znajdzPoImieniu (imie, kontakty, iloscKontaktow);
            }

            else if (wybor=='3') {
                cout<<"Wpisz nazwisko: ";
                cin>>nazwisko;
                znajdzPoNazwisku (nazwisko, kontakty, iloscKontaktow);

            }

            else if (wybor=='4') {
                wyswietlWszystkieKontakty(kontakty, iloscKontaktow);
            }

            else if (wybor=='5') {
                iloscKontaktow = usunKontakty(kontakty,pelnaListaKontaktow, iloscKontaktow);

            }

            else if (wybor=='6') {
                edytujKontakt(kontakty, pelnaListaKontaktow, iloscKontaktow);
            }

            else if (wybor == '7') {
                zmianaHasla(uzytkownicy, idZalogowanegoUzytkownika);

            }

            else if (wybor=='8') {
                idZalogowanegoUzytkownika=0;
                while (idZalogowanegoUzytkownika==0) {

                    idZalogowanegoUzytkownika = logowanieUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);

                    kontakty.erase(kontakty.begin(), kontakty.end());

                }

                iloscKontaktow = wczytajOsobyZpliku(kontakty, idZalogowanegoUzytkownika);

            }

            else if (wybor=='9') {
                cout<<"ZAMYKANIE PROGRAMU"<<endl;
                exit(0);
            }
        }

    }

    return 0;
}
