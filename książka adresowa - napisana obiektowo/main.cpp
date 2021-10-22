#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Uzytkownik.h"

using namespace std;

struct kontakt {
    int idKontaktu, idUzytkownika;
    string imie, nazwisko, nrTelefonu, email, adres;

};
/*
struct Uzytkownik {
    int idUzytkownika;
    string nazwa, haslo;
};
*/

int sprawdzIloscKontaktow(vector<kontakt> &kontakty) {
    int iloscKontaktow=0;
    kontakt zapisanyKontakt;

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

                        kontakt zapisanyKontakt;
                        string danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);
                        zapisanyKontakt.idKontaktu=atoi(numerIDkontaktu.c_str());


                        kontakty.push_back(zapisanyKontakt);

                        iloscKontaktow++;
                    }

                }

            }

        }
        ksiazkaAdresowa.close();
    }

    return iloscKontaktow;
}

int sprawdzNajwiekszaLiczbeID (vector<kontakt> &kontakty) {

    int najwiekszaWartoscNumeruID;
    kontakt zapisanyKontakt;

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
                        kontakt zapisanyKontakt;
                        string danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);
                        zapisanyKontakt.idKontaktu=atoi(numerIDkontaktu.c_str());
                        najwiekszaWartoscNumeruID=zapisanyKontakt.idKontaktu;

                    }
                }
            }
        }
        ksiazkaAdresowa.close();
    }


    return najwiekszaWartoscNumeruID;
}

void wczytajWszystkieOsobyZpliku (vector<kontakt> &pelnaListaKontaktow) {

    fstream PelnaKsiazkaAdresowa;

    PelnaKsiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(PelnaKsiazkaAdresowa.good()==true) {

        int j=0;
        string linia="";
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";

        while(getline(PelnaKsiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%7==1) {

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==2) {

                        pelnaListaKontaktow[j].idUzytkownika=atoi(danaInformacja.c_str());

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==3) {

                        pelnaListaKontaktow[j].imie=danaInformacja;

                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==4) {

                        pelnaListaKontaktow[j].nazwisko=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==5) {

                        pelnaListaKontaktow[j].nrTelefonu=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==6) {

                        pelnaListaKontaktow[j].email=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==0) {

                        pelnaListaKontaktow[j].adres=danaInformacja;
                        danaInformacja="";

                        j++;

                    }

                    i++;
                }

                danaInformacja+=linia[i];

            }

        }

    }

    PelnaKsiazkaAdresowa.close();

}


int wczytajOsobyZpliku (vector<kontakt> &kontakty, int idZalogowanegoUzytkownika, int iloscKontaktow) {

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

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==2) {

                        kontakty[j].idUzytkownika=atoi(danaInformacja.c_str());

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%7==3) {

                        kontakty[j].imie=danaInformacja;

                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==4) {

                        kontakty[j].nazwisko=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==5) {

                        kontakty[j].nrTelefonu=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==6) {

                        kontakty[j].email=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%7==0) {

                        kontakty[j].adres=danaInformacja;
                        danaInformacja="";


                        if(kontakty[j].idUzytkownika != idZalogowanegoUzytkownika) {

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

    iloscKontaktow=kontakty.size();

    return iloscKontaktow;

}

void wczytajIdKontaktuPoDodaniuNowejOsoby (vector<kontakt> &kontakty) {

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

                        kontakty[j].idKontaktu=atoi(numerIDkontaktu.c_str());

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

int dodajKontakt (vector<kontakt> &pelnaListaKontaktow, vector<kontakt> &kontakty, int iloscKontaktow, int idUzytkownika) {

    string imie, nazwisko, nrTelefonu, email, adres;
    fstream ksiazkaAdresowa;
    kontakt zapisanyKontakt;

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

    zapisanyKontakt.imie=imie;
    zapisanyKontakt.nazwisko=nazwisko;
    zapisanyKontakt.nrTelefonu=nrTelefonu;
    zapisanyKontakt.email=email;
    zapisanyKontakt.adres=adres;
    zapisanyKontakt.idKontaktu=sprawdzNajwiekszaLiczbeID(kontakty)+1;
    zapisanyKontakt.idUzytkownika=idUzytkownika;

    pelnaListaKontaktow.push_back(zapisanyKontakt);

    ksiazkaAdresowa.open("Adresaci.txt", ios::out | ios::app);

    ksiazkaAdresowa<<sprawdzNajwiekszaLiczbeID(pelnaListaKontaktow)+1<<"|"<<idUzytkownika<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<email<<"|"<<adres<<"|";
    ksiazkaAdresowa<<endl;

    ksiazkaAdresowa.close();

    cout<<"Kontakt dodany";
    Sleep(1000);

    wczytajIdKontaktuPoDodaniuNowejOsoby(pelnaListaKontaktow);

    kontakty=pelnaListaKontaktow;

    wczytajOsobyZpliku(kontakty, idUzytkownika, iloscKontaktow);

    return iloscKontaktow+1;

}

void wyswietlWszystkieKontakty (vector<kontakt> &kontakty, int iloscKontaktow) {

    for (int i=0; i<iloscKontaktow; i++) {
        cout<<kontakty[i].idUzytkownika<<endl;
        cout<<kontakty[i].imie<<endl;
        cout<<kontakty[i].nazwisko<<endl;
        cout<<kontakty[i].nrTelefonu<<endl;
        cout<<kontakty[i].email<<endl;
        cout<<kontakty[i].adres<<endl;
        cout<<kontakty[i].idKontaktu<<endl;
        cout<<endl;

    }

    cout<<endl<<"Nacisnij enter zeby powrocic do poprzedniego menu";
    getchar();
    getchar();

}


void znajdzPoImieniu (string imie, vector<kontakt> &kontakty, int iloscKontaktow) {

    int licznik=0;
    for (int i=0; i<iloscKontaktow; i++) {
        if (kontakty[i].imie==imie) {
            cout<<kontakty[i].imie<<endl;
            cout<<kontakty[i].nazwisko<<endl;
            cout<<kontakty[i].nrTelefonu<<endl;
            cout<<kontakty[i].email<<endl;
            cout<<kontakty[i].adres<<endl;
            cout<<endl;
            licznik=1;
        }

    }
    if (licznik==0) {
        cout<<"Nie ma kontaktow o takim imieniu"<<endl;
    }

    cout<<endl<<"Nacisnij enter zeby powrocic do poprzedniego menu";
    getchar();
    getchar();
}

void znajdzPoNazwisku (string nazwisko, vector<kontakt> &kontakty, int iloscKontaktow) {
    int licznik=0;
    for (int i=0; i<iloscKontaktow; i++) {
        if (kontakty[i].nazwisko==nazwisko) {
            cout<<kontakty[i].imie<<endl;
            cout<<kontakty[i].nazwisko<<endl;
            cout<<kontakty[i].nrTelefonu<<endl;
            cout<<kontakty[i].email<<endl;
            cout<<kontakty[i].adres<<endl;
            cout<<endl;
            licznik=1;
        }

    }

    if (licznik==0) {
        cout<<"Nie ma kontaktow o takim nazwisku"<<endl;
    }

    cout<<endl<<"Nacisnij enter zeby powrocic do poprzedniego menu";
    getchar();
    getchar();

}

int usunKontakty (vector<kontakt> &kontakty, vector<kontakt> &pelnaListaKontaktow, int iloscKontaktow) {

    int nrIdKontaktuDoUsuniecia=0;
/*
    while(1) {

        system("cls");
        string imieKontaktuDoUsuniecia="";
        int licznik=0;

        cout<<"Wpisz imie kontaktu do usuniecia: "<<endl;
        cin>>imieKontaktuDoUsuniecia;
        cout<<endl;

        for (int i=0; i<iloscKontaktow; i++) {
            if (kontakty[i].imie==imieKontaktuDoUsuniecia) {
                cout<<kontakty[i].imie<<endl;
                cout<<kontakty[i].nazwisko<<endl;
                cout<<kontakty[i].nrTelefonu<<endl;
                cout<<kontakty[i].email<<endl;
                cout<<kontakty[i].adres<<endl;
                cout<<"Numer ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
                cout<<endl;
                licznik=1;

            }

        }

        if (licznik==0) {
            cout<<"Nie ma kontaktow o takim imieniu"<<endl;
            cout<<"Wyszukac jeszcze raz? t/n"<<endl;
            char odpowiedz;
            cin>>odpowiedz;
            cout<<endl;

            if (odpowiedz=='t')
                continue;

            else
                return iloscKontaktow;
            Sleep(1500);


        } else {

            cout<<"Znaleziono kontakt(y)"<<endl;
            break;

        }

    }
*/
    cout<<"Podaj numer id kontaktu do usuniecia: ";
    cin>>nrIdKontaktuDoUsuniecia;

    for (int i=0; i<iloscKontaktow; i++) {

        if(nrIdKontaktuDoUsuniecia==kontakty[i].idKontaktu) {

            char odpowiedzUzytkownika;
            string liniaDoUsuniecia;

            cout<<"Czy na pewno chcesz usunac kontakt? Wcisnij t/n"<<endl;
            cout<<"Odpowiedz: ";
            cin>>odpowiedzUzytkownika;

            if (odpowiedzUzytkownika=='t') {

                for (auto i = kontakty.begin(); i!=kontakty.end(); i++) {

                    if(i->idKontaktu == nrIdKontaktuDoUsuniecia) {

                        kontakty.erase(i);
                        break;
                    }

                }

                ofstream ksiazkaAdresowa;

                ksiazkaAdresowa.open("Adresaci_tymczasowy.txt", ios::out|ios::app);


                for (auto &informacjeOkontakcie: pelnaListaKontaktow) {

                    if (informacjeOkontakcie.idKontaktu==nrIdKontaktuDoUsuniecia) {

                        ksiazkaAdresowa<<"";

                    }

                    else {

                        ksiazkaAdresowa<<informacjeOkontakcie.idKontaktu<<"|"<<informacjeOkontakcie.idUzytkownika<<"|"<<informacjeOkontakcie.imie<<"|"<<informacjeOkontakcie.nazwisko<<"|"<<informacjeOkontakcie.nrTelefonu<<"|"<<informacjeOkontakcie.email<<"|"<<informacjeOkontakcie.adres<<"|";
                        ksiazkaAdresowa<<endl;
                    }

                }
                ksiazkaAdresowa.close();

                                for (auto i = pelnaListaKontaktow.begin(); i!=pelnaListaKontaktow.end(); i++) {

                                    if(i->idKontaktu == nrIdKontaktuDoUsuniecia) {

                                        pelnaListaKontaktow.erase(i);
                                        break;
                                    }
                                }

                remove("Adresaci.txt");
                rename("Adresaci_tymczasowy.txt", "Adresaci.txt");

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

void zapiszNoweInformacjeWPliku (vector<kontakt> &kontakty, vector<kontakt> &pelnaListaKontaktow, int nrIdKontaktuDoEdycji) {

    ofstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci_tymczasowy.txt", ios::out|ios::app);

    for (auto &informacjeOkontakcie: pelnaListaKontaktow) {

        if (informacjeOkontakcie.idKontaktu==nrIdKontaktuDoEdycji) {

            for (auto i = kontakty.begin(); i!=kontakty.end(); i++) {

                if(i->idKontaktu == nrIdKontaktuDoEdycji) {

                    ksiazkaAdresowa<<i->idKontaktu<<"|"<<i->idUzytkownika<<"|"<<i->imie<<"|"<<i->nazwisko<<"|"<<i->nrTelefonu<<"|"<<i->email<<"|"<<i->adres<<"|";
                    ksiazkaAdresowa<<endl;

                }

            }

        } else {

            ksiazkaAdresowa<<informacjeOkontakcie.idKontaktu<<"|"<<informacjeOkontakcie.idUzytkownika<<"|"<<informacjeOkontakcie.imie<<"|"<<informacjeOkontakcie.nazwisko<<"|"<<informacjeOkontakcie.nrTelefonu<<"|"<<informacjeOkontakcie.email<<"|"<<informacjeOkontakcie.adres<<"|";
            ksiazkaAdresowa<<endl;
        }

    }
    ksiazkaAdresowa.close();

    remove("Adresaci.txt");

    rename("Adresaci_tymczasowy.txt", "Adresaci.txt");

}

void edytujKontakt(vector<kontakt> &kontakty, vector<kontakt> &pelnaListaKontaktow, int iloscKontaktow) {

    int nrIdKontaktuDoEdycji=0;
/*
    while(1) {

        system("cls");
        string imieKontaktuDoEdycji="";
        int licznik=0;

        cout<<"Wpisz imie kontaktu ktory chcesz edytowac: "<<endl;
        cin>>imieKontaktuDoEdycji;
        cout<<endl;

        for (int i=0; i<iloscKontaktow; i++) {
            if (kontakty[i].imie==imieKontaktuDoEdycji) {
                cout<<kontakty[i].imie<<endl;
                cout<<kontakty[i].nazwisko<<endl;
                cout<<kontakty[i].nrTelefonu<<endl;
                cout<<kontakty[i].email<<endl;
                cout<<kontakty[i].adres<<endl;
                cout<<"Numer ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
                cout<<endl;
                licznik=1;

            }

        }

        if (licznik==0) {
            cout<<"Nie ma kontaktow o takim imieniu"<<endl;
            cout<<"Wyszukac jeszcze raz? t/n"<<endl;
            char odpowiedz;
            cin>>odpowiedz;
            cout<<endl;

            if (odpowiedz=='t')
                continue;

            else
                break;

            Sleep(1500);


        } else {

            cout<<"Znaleziono kontakt(y)"<<endl;
            break;

        }

    }
*/
    cout<<"Podaj numer id kontaktu do edycji, lub wpisz 0 by wrocic do poprzedniego menu: ";
    cin>>nrIdKontaktuDoEdycji;

    for (int i=0; i<iloscKontaktow; i++) {

        if (nrIdKontaktuDoEdycji==0)
            break;

        if(nrIdKontaktuDoEdycji==kontakty[i].idKontaktu) {
            char wybor;
            system("cls");

            cout<<"1. Imie"<<endl;
            cout<<"2. Nazwisko"<<endl;
            cout<<"3. Numer telefonu"<<endl;
            cout<<"4. Email"<<endl;
            cout<<"5. Adres"<<endl;
            cout<<"6. Powrot do menu"<<endl;
            cout<<"Twoj wybor: ";
            cin>>wybor;

            if(wybor=='1') {
                string noweImie = "";
                cout<<"Wprowadz nowe imie:"<<endl;
                cin>>noweImie;
                kontakty[i].imie=noweImie;

                zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                cout<<"Imie kontaktu zostalo zmienione"<<endl;
                Sleep(1000);

            }

            else if(wybor=='2') {

                string noweNazwisko = "";
                cout<<"Wprowadz nowe nazwisko:"<<endl;
                cin>>noweNazwisko;
                kontakty[i].nazwisko=noweNazwisko;

                zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                cout<<"Nazwisko kontaktu zostalo zmienione"<<endl;
                Sleep(1000);
            }

            else if(wybor=='3') {

                string nowyNumerTelefonu = "";
                cout<<"Wprowadz nowy numer telefonu:"<<endl;
                cin>>nowyNumerTelefonu;
                kontakty[i].nrTelefonu=nowyNumerTelefonu;

                zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                cout<<"Numer telefonu kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='4') {

                string nowyEmail = "";
                cout<<"Wprowadz nowy email:"<<endl;
                cin>>nowyEmail;
                kontakty[i].email=nowyEmail;

                zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                cout<<"Email kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='5') {

                string nowyAdres = "";
                cout<<"Wprowadz nowy adres:"<<endl;
                cin.sync();
                getline(cin, nowyAdres);
                kontakty[i].adres=nowyAdres;

                zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                cout<<"Adres kontaktu zostal zmieniony"<<endl;
                Sleep(1000);

            }

            else if(wybor=='6') {

                break;

            }

        }
    }

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

       // int j=0;

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

                        //Uzytkownik zapisanyUzytkownik;

                        danaInformacja=linia;
                        string numerIDuzytkownika = danaInformacja.erase(i, danaInformacja.length()-i);

                        //zapisanyUzytkownik.idUzytkownika=atoi(numerIDuzytkownika.c_str());

                         idUzytkownika=atoi(numerIDuzytkownika.c_str());
                        //uzytkownicy.push_back(zapisanyUzytkownik);
                       // iloscUzytkownikow++;

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%3==2) {

                        //uzytkownicy[j].nazwa=danaInformacja;
                        nazwa=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%3==0) {

                        //uzytkownicy[j].haslo=danaInformacja;
                 haslo = danaInformacja;
                        danaInformacja="";
                        //j++;
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

    //Uzytkownik nowyUzytkownik;

    cout<<"Podaj nazwe uzytkownika: ";
    cin.sync();
    getline(cin, nazwa);

  //  int i = 0;


    Uzytkownik obiektUzytkownik;
    while (obiektUzytkownik.sprawdzCzyNazwaUzytkownikaJestJuzWbazieDanych(nazwa, uzytkownicy)==true) {
    //if(obiektUzytkownik.sprawdzCzyNazwaUzytkownikaJestJuzZajeta(nazwa, uzytkownicy)==true) {
        cout<<"Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>nazwa;
    }

/*
    while (i<iloscUzytkownikow) {
        if (uzytkownicy[i].nazwa == nazwa) {
            cout<<"Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>nazwa;
            i=0;
        }

        else i++;

    }
    */
    cout<<"Podaj haslo: ";
    cin>>haslo;

    iloscUzytkownikow++;
    Uzytkownik nowyUzytkownik(string nazwa, string haslo, int iloscUzytkownikow);
    //nowyUzytkownik.nazwa = nazwa;
    //nowyUzytkownik.haslo = haslo;
    //nowyUzytkownik.idUzytkownika = iloscUzytkownikow+1;

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

    //while (i<iloscUzytkownikow) {
       // if (uzytkownicy[i].nazwa == nazwa) {



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

                //if (uzytkownicy[i].haslo == haslo) {
                        if (obiektUzytkownik.sprawdzCzyHasloJestPoprawne (haslo, i, uzytkownicy)==true) {
                    cout<<"Zalogowales sie."<<endl;
                    Sleep(1000);

                    return uzytkownicy[i].getterIdUzytkownika();
                    //return uzytkownicy[i].idUzytkownika;
                }

            }
            cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
            Sleep(3000);
            return 0;
       // }

        //i++;

/*
    cout<<"Nie ma uzytkownika z takim loginem"<<endl;
    Sleep(1000);
    return 0;
    */
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

    //for (auto &informacjeOuzytkowniku: uzytkownicy) {
for (Uzytkownik obiektUzytkownik: uzytkownicy) {
        //wszyscyUzytkownicy<<informacjeOuzytkowniku.idUzytkownika<<"|"<<informacjeOuzytkowniku.nazwa<<"|"<<informacjeOuzytkowniku.haslo<<"|";
        //wszyscyUzytkownicy<<endl;

        wszyscyUzytkownicy<<obiektUzytkownik.getterIdUzytkownika()<<"|"<<obiektUzytkownik.getterNazwa()<<"|"<<obiektUzytkownik.getterHaslo()<<"|";
        wszyscyUzytkownicy<<endl;

    }
    wszyscyUzytkownicy.close();

}


void zmianaHasla(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika) {

    string haslo;
   // Uzytkownik obiektUzytkownik;

    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    for (int i=0; i<uzytkownicy.size(); i++) {

        if(uzytkownicy[i].getterIdUzytkownika()==idZalogowanegoUzytkownika) {
            //uzytkownicy[i].haslo=haslo;
           // cout<<uzytkownicy[i].getterHaslo()<<endl;
  //  system("Pause");
            uzytkownicy[i].setterHaslo(haslo);
            zapiszNoweInformacjeOuzytkowniku(uzytkownicy);
            //cout<<uzytkownicy[i].getterHaslo()<<endl;

            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1500);
        }

    }

}

int main() {

    vector<kontakt> kontakty;
    vector<kontakt> pelnaListaKontaktow;
    vector<Uzytkownik> uzytkownicy;


    int idZalogowanegoUzytkownika = 0;

    while (idZalogowanegoUzytkownika==0) {

        idZalogowanegoUzytkownika = logowanieUzytkownika(uzytkownicy,idZalogowanegoUzytkownika);
    }

    int idKontaktu = 0;
    int iloscKontaktow = sprawdzIloscKontaktow(kontakty);

    sprawdzIloscKontaktow(pelnaListaKontaktow);
    wczytajWszystkieOsobyZpliku (pelnaListaKontaktow);

    iloscKontaktow = wczytajOsobyZpliku(kontakty, idZalogowanegoUzytkownika, iloscKontaktow);

    string imie, nazwisko;
    char wybor;

    while (1) {


        if (idKontaktu ==0) {
            system("cls");
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
                iloscKontaktow = sprawdzIloscKontaktow (kontakty);

                iloscKontaktow = wczytajOsobyZpliku(kontakty, idZalogowanegoUzytkownika, iloscKontaktow);

            }

            else if (wybor=='9') {
                exit(0);
            }
        }

    }

    return 0;
}
