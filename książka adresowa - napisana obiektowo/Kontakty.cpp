#include "Kontakty.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

Kontakty::Kontakty() {
    //ctor
}

Kontakty::Kontakty (int idKontaktu, int idUzytkownika, string imie, string nazwisko, string nrTelefonu, string email, string adres): idKontaktu(idKontaktu), idUzytkownika(idUzytkownika), imie(imie), nazwisko(nazwisko), nrTelefonu(nrTelefonu), email(email), adres(adres) {

}

Kontakty::~Kontakty() {
    //dtor
}

void Kontakty::setterIdKontaktu(int idKontaktu) {

    this->idKontaktu=idKontaktu;


}

int Kontakty::getterIdKontaktu() {

    return idKontaktu;

}

int Kontakty::getterIdUzytkownika() {

    return idUzytkownika;

}

string Kontakty::getterImie(){

return imie;

}

string Kontakty::getterNazwisko(){

return nazwisko;

}


void Kontakty::wyswietlListeKontaktow(vector<Kontakty> &kontakty) {

    for (auto i=0; i<kontakty.size(); i++) {
        cout<<"Numer ID Uzytkownika: "<<kontakty[i].idUzytkownika<<endl;
        cout<<"Imie: "<<kontakty[i].imie<<endl;
        cout<<"Nazwisko: "<<kontakty[i].nazwisko<<endl;
        cout<<"Numer telefonu: "<<kontakty[i].nrTelefonu<<endl;
        cout<<"Email: "<<kontakty[i].email<<endl;
        cout<<"Adres: "<<kontakty[i].adres<<endl;
        cout<<"Numer ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
        cout<<endl;

    }
    cout<<endl<<"Nacisnij enter zeby powrocic do poprzedniego menu";
    getchar();
    getchar();

}

void Kontakty::sprawdzCzyPodaneImieJestWbazieDanych (string imie, vector<Kontakty> &kontakty) {

    for (auto i=0; i<kontakty.size(); i++) {


        if (kontakty[i].imie==imie) {
            cout<<"Numer ID Uzytkownika: "<<kontakty[i].idUzytkownika<<endl;
            cout<<"Imie: "<<kontakty[i].imie<<endl;
            cout<<"Nazwisko: "<<kontakty[i].nazwisko<<endl;
            cout<<"Numer telefonu: "<<kontakty[i].nrTelefonu<<endl;
            cout<<"Email: "<<kontakty[i].email<<endl;
            cout<<"Adres: "<<kontakty[i].adres<<endl;
            cout<<"Numer ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
            cout<<endl;
            return;
        }

    }
    cout<<"Nie ma kontaktow o takim imieniu"<<endl;
}

void Kontakty::sprawdzCzyPodaneNazwiskoJestWbazieDanych (string nazwisko, vector<Kontakty> &kontakty) {

    for (auto i=0; i<kontakty.size(); i++) {


        if (kontakty[i].nazwisko==nazwisko) {
            cout<<"Numer ID Uzytkownika: "<<kontakty[i].idUzytkownika<<endl;
            cout<<"Imie: "<<kontakty[i].imie<<endl;
            cout<<"Nazwisko: "<<kontakty[i].nazwisko<<endl;
            cout<<"Numer telefonu: "<<kontakty[i].nrTelefonu<<endl;
            cout<<"Email: "<<kontakty[i].email<<endl;
            cout<<"Adres: "<<kontakty[i].adres<<endl;
            cout<<"Numer ID kontaktu: "<<kontakty[i].idKontaktu<<endl;
            cout<<endl;
            return;
        }

    }
    cout<<"Nie ma kontaktow o takim nazwisku"<<endl;
}

void Kontakty::usunPozycjeZwektora (int nrIdKontaktuDoUsuniecia, vector<Kontakty> &danyWektor ) {

    for (auto i = danyWektor.begin(); i!=danyWektor.end(); i++) {
        if(i->idKontaktu == nrIdKontaktuDoUsuniecia) {

            danyWektor.erase(i);
            break;
        }

    }

}

void Kontakty::usunKontaktZplikuTekstowego (int nrIdKontaktuDoUsuniecia, vector<Kontakty> &pelnaListaKontaktow) {

    ofstream ksiazkaAdresowa;

    ksiazkaAdresowa.open("Adresaci_tymczasowy.txt", ios::out|ios::app);

    for (Kontakty informacjeOkontakcie: pelnaListaKontaktow) {

        if (informacjeOkontakcie.idKontaktu==nrIdKontaktuDoUsuniecia) {

            ksiazkaAdresowa<<"";

        }

        else {

            ksiazkaAdresowa<<informacjeOkontakcie.idKontaktu<<"|"<<informacjeOkontakcie.idUzytkownika<<"|"<<informacjeOkontakcie.imie<<"|"<<informacjeOkontakcie.nazwisko<<"|"<<informacjeOkontakcie.nrTelefonu<<"|"<<informacjeOkontakcie.email<<"|"<<informacjeOkontakcie.adres<<"|";
            ksiazkaAdresowa<<endl;
        }

    }
    ksiazkaAdresowa.close();

    remove("Adresaci.txt");

    rename("Adresaci_tymczasowy.txt", "Adresaci.txt");

}

void Kontakty:: zapiszZmianyOkontakcieWplikuTekstowym(int nrIdKontaktuDoEdycji, vector<Kontakty> &pelnaListaKontaktow, vector<Kontakty> &kontakty) {

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

void Kontakty::edytujKontakty(int nrIdKontaktuDoEdycji, vector<Kontakty> &kontakty, vector<Kontakty> &pelnaListaKontaktow) {

    for (int i=0; i<kontakty.size(); i++) {

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

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji, pelnaListaKontaktow, kontakty);

                cout<<"Imie kontaktu zostalo zmienione"<<endl;
                Sleep(1000);

            }

            else if(wybor=='2') {

                string noweNazwisko = "";
                cout<<"Wprowadz nowe nazwisko:"<<endl;
                cin>>noweNazwisko;
                kontakty[i].nazwisko=noweNazwisko;

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji, pelnaListaKontaktow, kontakty);

                cout<<"Nazwisko kontaktu zostalo zmienione"<<endl;
                Sleep(1000);
            }

            else if(wybor=='3') {

                string nowyNumerTelefonu = "";
                cout<<"Wprowadz nowy numer telefonu:"<<endl;
                cin>>nowyNumerTelefonu;
                kontakty[i].nrTelefonu=nowyNumerTelefonu;

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji, pelnaListaKontaktow, kontakty);

                cout<<"Numer telefonu kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='4') {

                string nowyEmail = "";
                cout<<"Wprowadz nowy email:"<<endl;
                cin>>nowyEmail;
                kontakty[i].email=nowyEmail;

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji, pelnaListaKontaktow, kontakty);

                cout<<"Email kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='5') {

                string nowyAdres = "";
                cout<<"Wprowadz nowy adres:"<<endl;
                cin.sync();
                getline(cin, nowyAdres);
                kontakty[i].adres=nowyAdres;

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji, pelnaListaKontaktow, kontakty);

                cout<<"Adres kontaktu zostal zmieniony"<<endl;
                Sleep(1000);

            }

            else if(wybor=='6') {

                break;

            }

        }
    }

}
