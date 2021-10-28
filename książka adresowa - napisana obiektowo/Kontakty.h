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
        Kontakty (int idKontaktu, int idUzytkownika, string imie, string nazwisko, string nrTelefonu, string email, string adres);
        /** Default destructor */
        virtual ~Kontakty();

        int getterIdKontaktu();
        int getterIdUzytkownika();
        void setterIdKontaktu(int idKontaktu);
        void wyswietlListeKontaktow(vector<Kontakty> &kontakty); //vector<Kontakty> &kontakty);
        void sprawdzCzyPodaneImieJestWbazieDanych (string imie, vector<Kontakty> &kontakty);
        void sprawdzCzyPodaneNazwiskoJestWbazieDanych (string nazwisko, vector<Kontakty> &kontakty);
        void usunPozycjeZwektora (int nrIdKontaktuDoUsuniecia, vector<Kontakty> &danyWektor);
        void usunKontaktZplikuTekstowego (int nrIdKontaktuDoUsuniecia, vector<Kontakty> &pelnaListaKontaktow);
        void zapiszZmianyOkontakcieWplikuTekstowym(int nrIdKontaktuDoEdycji, vector<Kontakty> &pelnaListaKontaktow);
        void edytujKontakty(int nrIdKontaktuDoEdycji, vector<Kontakty> &kontakty, vector<Kontakty> &pelnaListaKontaktow);

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
