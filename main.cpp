#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

struct kontakt {
    int idKontaktu;
    string imie, nazwisko, nrTelefonu, email, adres;

};

int sprawdzIloscKontaktow(vector<kontakt> &kontakty) {
    int iloscKontaktow=0;
    kontakt zapisanyKontakt;

    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::in);

    if(ksiazkaAdresowa.good()==false)
        cout<<"!"<<endl;

    else {

        string linia;
        int licznikZnakuPrzerwy = 0;

        while(getline(ksiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if(linia[i]=='|') {
                    licznikZnakuPrzerwy++;

                    if (licznikZnakuPrzerwy%6==1) {

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

    ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::in);

    if(ksiazkaAdresowa.good()==false)
        cout<<"!"<<endl;

    else {

        string linia;
        int licznikZnakuPrzerwy = 0;

        while(getline(ksiazkaAdresowa,linia)) {

            for (int i=0; i<linia.length(); i++) {

                if(linia[i]=='|') {
                    licznikZnakuPrzerwy++;

                    if (licznikZnakuPrzerwy%6==1) {
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


void wczytajOsobyZpliku (vector<kontakt> &kontakty) {
    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::in);

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

                    if(licznikZnakuPrzerwy%6==1) {

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%6==2) {

                        kontakty[j].imie=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%6==3) {

                        kontakty[j].nazwisko=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%6==4) {

                        kontakty[j].nrTelefonu=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%6==5) {

                        kontakty[j].email=danaInformacja;
                        danaInformacja="";
                    }

                    if(licznikZnakuPrzerwy%6==0) {

                        kontakty[j].adres=danaInformacja;
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

void wczytajIdKontaktuPoDodaniuNowejOsoby (vector<kontakt> &kontakty) {

    fstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::in);

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

                    if(licznikZnakuPrzerwy%6==1) {

                        string danaInformacja=linia;
                        string numerIDkontaktu = danaInformacja.erase(i, danaInformacja.length()-i);

                        kontakty[j].idKontaktu=atoi(numerIDkontaktu.c_str());

                        danaInformacja="";

                    }

                    if(licznikZnakuPrzerwy%6==0) {

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

int dodajKontakt (vector<kontakt> &kontakty, int iloscKontaktow) {

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

    kontakty.push_back(zapisanyKontakt);

    zapisanyKontakt.imie=imie;
    zapisanyKontakt.nazwisko=nazwisko;
    zapisanyKontakt.nrTelefonu=nrTelefonu;
    zapisanyKontakt.email=email;
    zapisanyKontakt.adres=adres;
    zapisanyKontakt.idKontaktu=sprawdzNajwiekszaLiczbeID(kontakty)+1;

    ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::out | ios::app);


    ksiazkaAdresowa<<sprawdzNajwiekszaLiczbeID(kontakty)+1<<"|"<<imie<<"|"<<nazwisko<<"|"<<nrTelefonu<<"|"<<email<<"|"<<adres<<"|";
    ksiazkaAdresowa<<endl;

    ksiazkaAdresowa.close();

    cout<<"Kontakt dodany";
    Sleep(1000);


    wczytajOsobyZpliku(kontakty);
    wczytajIdKontaktuPoDodaniuNowejOsoby(kontakty);
    return iloscKontaktow+1;

}

void wyswietlWszystkieKontakty (vector<kontakt> &kontakty, int iloscKontaktow) {

    for (int i=0; i<iloscKontaktow; i++) {
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

                ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::out);


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

    ksiazkaAdresowa.open("ksiazka adresowa.txt", ios::out);

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

int main() {
    vector<kontakt> kontakty;

    int idKontaktu = 0;
    int iloscKontaktow = sprawdzIloscKontaktow(kontakty);

    wczytajOsobyZpliku(kontakty);
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
            cout<<"9. Zakoncz program"<<endl;
            cout<<"Twoj wybor: ";
            cin>>wybor;
            cout<<endl;

            if (wybor == '1') {
                iloscKontaktow = dodajKontakt (kontakty, iloscKontaktow);

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

            else if (wybor=='9') {
                exit(0);
            }
        }

    }

    return 0;
}
