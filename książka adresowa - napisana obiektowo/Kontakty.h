#ifndef KONTAKTY_H
#define KONTAKTY_H
#include <iostream>
#include <vector>

using namespace std;

class Kontakty
{
    public:
        /** Default constructor */
        Kontakty();
        Kontakty (int idUzytkownika, string imie, string nazwisko, string nrTelefonu, string email, string adres);
        /** Default destructor */
        virtual ~Kontakty();

        int getterIdKontaktu();
        int getterIdUzytkownika();
        void setterIdKontaktu(int idKontaktu);
        void wyswietlListeKontaktow(); //vector<Kontakty> &kontakty);
        void sprawdzCzyPodaneImieJestWbazieDanych (string imie);
        void sprawdzCzyPodaneNazwiskoJestWbazieDanych (string nazwisko);
        void usunPozycjeZwektora (int nrIdKontaktuDoUsuniecia, vector<Kontakty> &danyWektor);
        void usunKontaktZplikuTekstowego (int nrIdKontaktuDoUsuniecia);
        void zapiszZmianyOkontakcieWplikuTekstowym(int nrIdKontaktuDoEdycji);
        void edytujKontakty(int nrIdKontaktuDoEdycji);

    //protected:

    private:
        int idKontaktu;
        int idUzytkownika;
        string imie;
        string nazwisko;
        string nrTelefonu;
        string email;
        string adres;
        vector<Kontakty> kontakty;
    vector<Kontakty> pelnaListaKontaktow;


};

#endif // KONTAKTY_H
