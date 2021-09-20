#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

struct kontakt {
    int idKontaktu, idUzytkownika;
    string imie, nazwisko, nrTelefonu, email, adres;

};

struct Uzytkownik
{
    int idUzytkownika;
    string nazwa, haslo;
};

bool sprawdzNumerIDuzytkownika (int idZalogowanegoUzytkownika, int sprawdzanyNumerUzytkownika) {

if (idZalogowanegoUzytkownika==sprawdzanyNumerUzytkownika)
    return true;

    else
        return false;

}


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

void wczytajWszystkieOsobyZpliku (vector<kontakt> &pelnaListaKontaktow, int iloscKontaktow) {

    //vector<kontakt> pelnaListaKontaktow;
    fstream PelnaKsiazkaAdresowa;

    PelnaKsiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(PelnaKsiazkaAdresowa.good()==true) {

        int i=0;
        int j=0;
        string linia="";
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";
      //  int odczytaneIDuzytkownika=0;

        while(getline(PelnaKsiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%7==1) {

                        danaInformacja="";

                    }

                    //if(sprawdzNumerIDuzytkownika(idZalogowanegoUzytkownika, atoi(danaInformacja.c_str()) )==true){

                    if(licznikZnakuPrzerwy%7==2) {

                        //odczytaneIDuzytkownika = atoi(danaInformacja.c_str());
                        //if (odczytaneIDuzytkownika==idZalogowanegoUzytkownika){

                            pelnaListaKontaktow[j].idUzytkownika=atoi(danaInformacja.c_str());

                        danaInformacja="";
                      //  }
                      //  else
                         //   danaInformacja="";


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


/*
                    if(kontakty[j].idUzytkownika != idZalogowanegoUzytkownika) {

                           // vector<kontakt>  = kontakty;

                        kontakty.erase(kontakty.begin()+j);
                       // cout<<kontakty.size();
                        //Sleep(2000);

                    }
*/

                       // else
                        j++;

                    }

                    i++;
                }

                danaInformacja+=linia[i];

            }

        }

    }



    PelnaKsiazkaAdresowa.close();
   // pelnaListaKontaktow=kontakty;

//    iloscKontaktow=kontakty.size();
/*
    for (int i=0; i<iloscKontaktow; i++) {
            cout<<pelnaListaKontaktow[i].idUzytkownika<<endl;
        cout<<pelnaListaKontaktow[i].imie<<endl;
        cout<<pelnaListaKontaktow[i].nazwisko<<endl;
        cout<<pelnaListaKontaktow[i].nrTelefonu<<endl;
        cout<<pelnaListaKontaktow[i].email<<endl;
        cout<<pelnaListaKontaktow[i].adres<<endl;
        cout<<pelnaListaKontaktow[i].idKontaktu<<endl;
        cout<<endl;

    }
    Sleep(5000);
*/

}



int wczytajOsobyZpliku (vector<kontakt> &kontakty, int idZalogowanegoUzytkownika, int iloscKontaktow) {

    //vector<kontakt> pelnaListaKontaktow;
    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci.txt", ios::in);

    if(ksiazkaAdresowa.good()==false) {
        cout<<"Brak zapisanych kontaktow"<<endl;
        Sleep(1000);
    }

    else {

        int i=0;
        int j=0;
        string linia;
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";
        int odczytaneIDuzytkownika=0;

        while(getline(ksiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%7==1) {

                        danaInformacja="";

                    }

                    //if(sprawdzNumerIDuzytkownika(idZalogowanegoUzytkownika, atoi(danaInformacja.c_str()) )==true){

                    if(licznikZnakuPrzerwy%7==2) {

                        odczytaneIDuzytkownika = atoi(danaInformacja.c_str());
                        //if (odczytaneIDuzytkownika==idZalogowanegoUzytkownika){

                            kontakty[j].idUzytkownika=atoi(danaInformacja.c_str());

                        danaInformacja="";
                      //  }
                      //  else
                         //   danaInformacja="";


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

                           // vector<kontakt>  = kontakty;

                        kontakty.erase(kontakty.begin()+j);
                       // cout<<kontakty.size();
                        //Sleep(2000);

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
   // pelnaListaKontaktow=kontakty;

    iloscKontaktow=kontakty.size();
/*
    for (int i=0; i<iloscKontaktow; i++) {
            cout<<pelnaListaKontaktow[i].idUzytkownika<<endl;
        cout<<pelnaListaKontaktow[i].imie<<endl;
        cout<<pelnaListaKontaktow[i].nazwisko<<endl;
        cout<<pelnaListaKontaktow[i].nrTelefonu<<endl;
        cout<<pelnaListaKontaktow[i].email<<endl;
        cout<<pelnaListaKontaktow[i].adres<<endl;
        cout<<pelnaListaKontaktow[i].idKontaktu<<endl;
        cout<<endl;

    }
    Sleep(5000);
    */

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

        int i=0;
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

    pelnaListaKontaktow.push_back(zapisanyKontakt);

    zapisanyKontakt.imie=imie;
    zapisanyKontakt.nazwisko=nazwisko;
    zapisanyKontakt.nrTelefonu=nrTelefonu;
    zapisanyKontakt.email=email;
    zapisanyKontakt.adres=adres;
    zapisanyKontakt.idKontaktu=sprawdzNajwiekszaLiczbeID(kontakty)+1;
    zapisanyKontakt.idUzytkownika=idUzytkownika;

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

int usunKontakty (vector<kontakt> &kontakty, int iloscKontaktow) {

    int nrIdKontaktuDoUsuniecia;

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


        }
        else {

            cout<<"Znaleziono kontakt(y)"<<endl;
            break;

        }

    }

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

                ksiazkaAdresowa.open("Adresaci.txt", ios::out);


                for (auto &informacjeOkontakcie: kontakty) {

                    ksiazkaAdresowa<<informacjeOkontakcie.idKontaktu<<"|"<<informacjeOkontakcie.imie<<"|"<<informacjeOkontakcie.nazwisko<<"|"<<informacjeOkontakcie.nrTelefonu<<"|"<<informacjeOkontakcie.email<<"|"<<informacjeOkontakcie.adres<<"|";
                    ksiazkaAdresowa<<endl;

                }
                ksiazkaAdresowa.close();

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

void zapiszNoweInformacjeWPliku (vector<kontakt> &kontakty) {

    ofstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci.txt", ios::out);

    for (auto &informacjeOkontakcie: kontakty) {

        ksiazkaAdresowa<<informacjeOkontakcie.idKontaktu<<"|"<<informacjeOkontakcie.imie<<"|"<<informacjeOkontakcie.nazwisko<<"|"<<informacjeOkontakcie.nrTelefonu<<"|"<<informacjeOkontakcie.email<<"|"<<informacjeOkontakcie.adres<<"|";
        ksiazkaAdresowa<<endl;

    }
    ksiazkaAdresowa.close();

}

void edytujKontakt(vector<kontakt> &kontakty, int iloscKontaktow) {

    int nrIdKontaktuDoEdycji;

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

    cout<<"Podaj numer id kontaktu do edycji: ";
    cin>>nrIdKontaktuDoEdycji;

    for (int i=0; i<iloscKontaktow; i++) {

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

                zapiszNoweInformacjeWPliku(kontakty);

                cout<<"Imie kontaktu zostalo zmienione"<<endl;
                Sleep(1000);

            }

            else if(wybor=='2') {

                string noweNazwisko = "";
                cout<<"Wprowadz nowe nazwisko:"<<endl;
                cin>>noweNazwisko;
                kontakty[i].nazwisko=noweNazwisko;

                zapiszNoweInformacjeWPliku(kontakty);

                cout<<"Nazwisko kontaktu zostalo zmienione"<<endl;
                Sleep(1000);
            }

            else if(wybor=='3') {

                string nowyNumerTelefonu = "";
                cout<<"Wprowadz nowy numer telefonu:"<<endl;
                cin>>nowyNumerTelefonu;
                kontakty[i].nrTelefonu=nowyNumerTelefonu;

                zapiszNoweInformacjeWPliku(kontakty);

                cout<<"Numer telefonu kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='4') {

                string nowyEmail = "";
                cout<<"Wprowadz nowy email:"<<endl;
                cin>>nowyEmail;
                kontakty[i].email=nowyEmail;

                zapiszNoweInformacjeWPliku(kontakty);

                cout<<"Email kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='5') {

                string nowyAdres = "";
                cout<<"Wprowadz nowy adres:"<<endl;
                cin>>nowyAdres;
                kontakty[i].adres=nowyAdres;

                zapiszNoweInformacjeWPliku(kontakty);

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

    listaUzytkownikow.open("Uzytkownicy.txt", ios::in);

    if(listaUzytkownikow.good()==false) {
        cout<<"Nie ma jeszcze zapisanych uzytkownikow"<<endl;
        Sleep(1000);
    }

    else {

        int i=0;
        int j=0;

        string linia;
        int licznikZnakuPrzerwy=0;
        string danaInformacja="";

        while(getline(listaUzytkownikow,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if (linia[i]=='|') {

                    licznikZnakuPrzerwy++;

                    if(licznikZnakuPrzerwy%3==1) {

                        Uzytkownik zapisanyUzytkownik;

                        danaInformacja=linia;
                        string numerIDuzytkownika = danaInformacja.erase(i, danaInformacja.length()-i);

                       // cout<<danaInformacja;
                        //Sleep(1000);

                        zapisanyUzytkownik.idUzytkownika=atoi(numerIDuzytkownika.c_str());
                        //cout<<zapisanyUzytkownik.idUzytkownika;
                        //Sleep(1000);
                        uzytkownicy.push_back(zapisanyUzytkownik);
                        iloscUzytkownikow++;

                        danaInformacja="";


                    }

                    if(licznikZnakuPrzerwy%3==2) {

                        uzytkownicy[j].nazwa=danaInformacja;
                        danaInformacja="";
                    }

                     if(licznikZnakuPrzerwy%3==0) {

                        uzytkownicy[j].haslo=danaInformacja;
                        danaInformacja="";
                        j++;
                    }

                    i++;
                }

                danaInformacja+=linia[i];
                //cout<<danaInformacja;
                //Sleep(1000);
            }

        }

    }

    listaUzytkownikow.close();
    return iloscUzytkownikow;


}

int rejestracja (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow )
{
    string nazwa, haslo;
    fstream wszyscyUzytkownicy;
    Uzytkownik nowyUzytkownik;

    cout<<"Podaj nazwe uzytkownika: ";
    cin.sync();
    getline(cin, nazwa);

    int i = 0;

    while (i<iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
        {
            cout<<"Taki uzytkownik istnieje. Wpisz inna nazwe uzytkownika: ";
            cin>>nazwa;
            i=0;
        }

        else i++;

    }
    cout<<"Podaj haslo: ";
    cin>>haslo;
    nowyUzytkownik.nazwa = nazwa;
    nowyUzytkownik.haslo = haslo;
    nowyUzytkownik.idUzytkownika = iloscUzytkownikow+1;

    wszyscyUzytkownicy.open("Uzytkownicy.txt", ios::out | ios::app);


    wszyscyUzytkownicy<<iloscUzytkownikow+1<<"|"<<nazwa<<"|"<<haslo<<"|";
    wszyscyUzytkownicy<<endl;

    wszyscyUzytkownicy.close();

    cout<<"Konto zalozone"<<endl;
    Sleep(1000);

    wczytajUzytkownikowZpliku (uzytkownicy);
    return iloscUzytkownikow+1;


}

int logowanie(vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow)
{
    string nazwa, haslo;
    cout<<"Podaj login: ";
    cin.sync();
    getline(cin, nazwa);
    int i = 0;


    while (i<iloscUzytkownikow)
    {
        if (uzytkownicy[i].nazwa == nazwa)
        {

            for (int proby=0; proby<3; proby++)
            {

                cout<<"Podaj haslo. Pozostalo prob "<<3-proby<<": ";
                cin>>haslo;

                if (uzytkownicy[i].haslo == haslo)
                {
                    cout<<"Zalogowales sie."<<endl;
                    Sleep(1000);
                    return uzytkownicy[i].idUzytkownika;
                }


            }
            cout<<"Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba"<<endl;
            Sleep(3000);
            return 0;
        }

        i++;
    }

    cout<<"Nie ma uzytkownika z takim loginem"<<endl;
    Sleep(1000);
    return 0;
}

int logowanieUzytkownika (vector<Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{
   // vector<Uzytkownik> uzytkownicy;
    //int idZalogowanegoUzytkownika = 0;
    int iloscUzytkownikow = wczytajUzytkownikowZpliku (uzytkownicy);
    /*
    for (int i=0; i<iloscUzytkownikow; i++) {
        cout<<uzytkownicy[i].idUzytkownika<<endl;
        cout<<uzytkownicy[i].nazwa<<endl;
        cout<<uzytkownicy[i].haslo<<endl;
        cout<<endl;

    }
    Sleep(3000);
*/
    char wybor;

    while (1)
    {
        if (idZalogowanegoUzytkownika ==0)
        {
            system("cls");
            cout<<"1. Rejestracja"<<endl;
            cout<<"2. Logowanie"<<endl;
            cout<<"3. Zakoncz program"<<endl;
            cin>>wybor;

            if (wybor == '1')
            {
                iloscUzytkownikow = rejestracja (uzytkownicy, iloscUzytkownikow);


            }

            else if (wybor=='2')
            {

                idZalogowanegoUzytkownika=logowanie(uzytkownicy, iloscUzytkownikow);
                return idZalogowanegoUzytkownika;

            }

            else if (wybor=='3')
            {
                exit(0);
            }
        }

    }

}

void zapiszNoweInformacjeOuzytkowniku (vector<Uzytkownik> &uzytkownicy) {

    ofstream wszyscyUzytkownicy;

    wszyscyUzytkownicy.open("Uzytkownicy.txt", ios::out);

    for (auto &informacjeOuzytkowniku: uzytkownicy) {

        wszyscyUzytkownicy<<informacjeOuzytkowniku.idUzytkownika<<"|"<<informacjeOuzytkowniku.nazwa<<"|"<<informacjeOuzytkowniku.haslo<<"|";
        wszyscyUzytkownicy<<endl;

    }
    wszyscyUzytkownicy.close();

}


void zmianaHasla(vector <Uzytkownik> &uzytkownicy, int idZalogowanegoUzytkownika)
{

    string haslo;

    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].idUzytkownika==idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo=haslo;
            zapiszNoweInformacjeOuzytkowniku(uzytkownicy);

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
   // cout<<idZalogowanegoUzytkownika<<endl;


    }
//cout<<idZalogowanegoUzytkownika<<endl;
  //          Sleep(2000);

    int idKontaktu = 0;
    int iloscKontaktow = sprawdzIloscKontaktow(kontakty);

    int PelnaIloscKontaktow = sprawdzIloscKontaktow(pelnaListaKontaktow);
    wczytajWszystkieOsobyZpliku (pelnaListaKontaktow, iloscKontaktow);

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
                iloscKontaktow = usunKontakty(kontakty, iloscKontaktow);

            }

            else if (wybor=='6') {
                edytujKontakt(kontakty, iloscKontaktow);
            }

            else if (wybor == '7')
            {
                zmianaHasla(uzytkownicy, idZalogowanegoUzytkownika);


            }

            else if (wybor=='8')
            {
                idZalogowanegoUzytkownika=0;
              while (idZalogowanegoUzytkownika==0) {

    idZalogowanegoUzytkownika = logowanieUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
   // cout<<idZalogowanegoUzytkownika<<endl;


   kontakty.erase(kontakty.begin(), kontakty.end());

    }
    iloscKontaktow = sprawdzIloscKontaktow (kontakty);
    //cout<<iloscKontaktow<<endl;
   // Sleep(2000);
iloscKontaktow = wczytajOsobyZpliku(kontakty, idZalogowanegoUzytkownika, iloscKontaktow);
//cout<<iloscKontaktow<<endl;
  //  Sleep(2000);
            }


            else if (wybor=='9') {
                exit(0);
            }
        }

    }

    return 0;
}
