#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;

struct Uzytkownik
{
    int idUzytkownika;
    string nazwa, haslo;
};

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

                        zapisanyUzytkownik.idUzytkownika=atoi(danaInformacja.c_str());
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
            }

        }

    }

    listaUzytkownikow.close();
    return iloscUzytkownikow;


}



int rejestracja (vector <Uzytkownik> &uzytkownicy, int iloscUzytkownikow )
{
    string nazwa, haslo;
    fstream WszyscyUzytkownicy;
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
    uzytkownicy[iloscUzytkownikow].nazwa = nazwa;
    uzytkownicy[iloscUzytkownikow].haslo = haslo;
    uzytkownicy[iloscUzytkownikow].id = iloscUzytkownikow+1;
    cout<<"Konto zalozone"<<endl;
    Sleep(1000);
    return iloscUzytkownikow+1;


}

int logowanie(Uzytkownik uzytkownicy[], int iloscUzytkownikow)
{
    string nazwa, haslo;
    cout<<"Podaj login: ";
    cin>>nazwa;
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
                    return uzytkownicy[i].id;
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

void zmianaHasla(Uzytkownik uzytkownicy[], int iloscUzytkownikow, int idZalogowanegoUzytkownika)
{
    string haslo;

    cout<<"Podaj nowe haslo: ";
    cin>>haslo;
    for (int i=0; i<iloscUzytkownikow; i++)
    {
        if(uzytkownicy[i].id==idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].haslo=haslo;
            cout<<"Haslo zostalo zmienione"<<endl;
            Sleep(1500);
        }

    }


}

int main()
{
    vector<Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika = 0;
    int iloscUzytkownikow = 0;

    char wybor;

    while (1)
    {
        if (idZalogowanegoUzytkownika ==0)
        {
            system("cls");
            cout<<"1. Rejestracja"<<endl;
            cout<<"2. Logowanie"<<endl;
            cout<<"9. Zakoncz program"<<endl;
            cin>>wybor;

            if (wybor == '1')
            {
                iloscUzytkownikow = rejestracja (uzytkownicy, iloscUzytkownikow);


            }

            else if (wybor=='2')
            {

                idZalogowanegoUzytkownika=logowanie(uzytkownicy, iloscUzytkownikow);
            }

            else if (wybor=='9')
            {
                exit(0);
            }
        }

        else
        {
            system("cls");
            cout<<"1. Zmiana hasla"<<endl;
            cout<<"2. Wylogowanie"<<endl;

            cin>>wybor;

            if (wybor == '1')
            {
                zmianaHasla(uzytkownicy, iloscUzytkownikow, idZalogowanegoUzytkownika);


            }

            else if (wybor=='2')
            {
                idZalogowanegoUzytkownika=0;

            }
        }


    }


    return 0;
}
