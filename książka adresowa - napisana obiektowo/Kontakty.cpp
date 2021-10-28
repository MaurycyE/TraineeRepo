#include "Kontakty.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

Kontakty::Kontakty() {
    //ctor
}

Kontakty::Kontakty (int idUzytkownika, string imie, string nazwisko, string nrTelefonu, string email, string adres): idUzytkownika(idUzytkownika), imie(imie), nazwisko(nazwisko), nrTelefonu(nrTelefonu), email(email), adres(adres) {

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

void Kontakty::wyswietlListeKontaktow() {//vector<Kontakty> &kontakty){

    cout<<kontakty.size()<<endl;
    system("pause");

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
   system("pause");
    //getchar();
    //getchar();

}

void Kontakty::sprawdzCzyPodaneImieJestWbazieDanych (string imie) {

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
        //else


    }
    cout<<"Nie ma kontaktow o takim imieniu"<<endl;
}

void Kontakty::sprawdzCzyPodaneNazwiskoJestWbazieDanych (string nazwisko) {

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
        //else


    }
    cout<<"Nie ma kontaktow o takim nazwisku"<<endl;
}

void Kontakty::usunPozycjeZwektora (int nrIdKontaktuDoUsuniecia, vector<Kontakty> &danyWektor ) {


                       // for(auto i=0; i<kontakty.size(); i++){
                    //Kontakty danyKontakt;
                    //if(i->idKontaktu == nrIdKontaktuDoUsuniecia) {

                    for (auto i = danyWektor.begin(); i!=danyWektor.end(); i++) {
                            if(i->idKontaktu == nrIdKontaktuDoUsuniecia) {

                   // if(kontakty[i].getterIdKontaktu() == nrIdKontaktuDoUsuniecia) {


                    //usunPozycjeZwektora (i);
                        danyWektor.erase(i);
                        break;
                    }

                }


}

void Kontakty::usunKontaktZplikuTekstowego (int nrIdKontaktuDoUsuniecia) {

  ofstream ksiazkaAdresowa;

                ksiazkaAdresowa.open("Adresaci_tymczasowy.txt", ios::out|ios::app);

                /*
                for (auto &informacjeOkontakcie: pelnaListaKontaktow) {

                    if (informacjeOkontakcie.idKontaktu==nrIdKontaktuDoUsuniecia) {

                        ksiazkaAdresowa<<"";

                    }
                    */

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

void Kontakty:: zapiszZmianyOkontakcieWplikuTekstowym(int nrIdKontaktuDoEdycji) {


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




}

void Kontakty::edytujKontakty(int nrIdKontaktuDoEdycji) {

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

                //zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );
                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji);

                cout<<"Imie kontaktu zostalo zmienione"<<endl;
                Sleep(1000);

            }

            else if(wybor=='2') {

                string noweNazwisko = "";
                cout<<"Wprowadz nowe nazwisko:"<<endl;
                cin>>noweNazwisko;
                kontakty[i].nazwisko=noweNazwisko;

                //zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji);

                cout<<"Nazwisko kontaktu zostalo zmienione"<<endl;
                Sleep(1000);
            }

            else if(wybor=='3') {

                string nowyNumerTelefonu = "";
                cout<<"Wprowadz nowy numer telefonu:"<<endl;
                cin>>nowyNumerTelefonu;
                kontakty[i].nrTelefonu=nowyNumerTelefonu;

                //zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji);

                cout<<"Numer telefonu kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='4') {

                string nowyEmail = "";
                cout<<"Wprowadz nowy email:"<<endl;
                cin>>nowyEmail;
                kontakty[i].email=nowyEmail;

                //zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji);

                cout<<"Email kontaktu zostal zmieniony"<<endl;
                Sleep(1000);
            }

            else if(wybor=='5') {

                string nowyAdres = "";
                cout<<"Wprowadz nowy adres:"<<endl;
                cin.sync();
                getline(cin, nowyAdres);
                kontakty[i].adres=nowyAdres;

                //zapiszNoweInformacjeWPliku(kontakty, pelnaListaKontaktow, nrIdKontaktuDoEdycji );

                zapiszZmianyOkontakcieWplikuTekstowym( nrIdKontaktuDoEdycji);

                cout<<"Adres kontaktu zostal zmieniony"<<endl;
                Sleep(1000);

            }

            else if(wybor=='6') {

                break;

            }

        }
    }




}
