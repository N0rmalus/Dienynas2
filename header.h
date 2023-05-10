#include "libraries.h"

class Studentas {
    private:
        string vardas;
        string pavarde;
        vector<int> nd_rezultatai;
        int egzamino_rezultatas;
        double galutinis_vid, galutinis_med;

    public:
        Studentas(string vardas, string pavarde, vector<int> nd_rezultatai, int egzamino_rezultatas, double galutinis_vid, double galutinis_med)
            : vardas(vardas), pavarde(pavarde), nd_rezultatai(nd_rezultatai), egzamino_rezultatas(egzamino_rezultatas), galutinis_vid(galutinis_vid), galutinis_med(galutinis_med) {}

        // Setteriai
        void setVardas(string vardas) {this->vardas = vardas;}
        void setPavarde(string pavarde) {this->pavarde = pavarde;}
        void setNdRezultatai(vector<int> nd_rezultatai) {this->nd_rezultatai = nd_rezultatai;}
        void setEgzaminoRezultatas(int egzamino_rezultatas) {this->egzamino_rezultatas = egzamino_rezultatas;}
        void setGalutinisVid(double galutinis_vid) {this->galutinis_vid = galutinis_vid;}
        void setGalutinisMed(double galutinis_med) {this->galutinis_med = galutinis_med;}

        // Getteriai
        string getVardas() const {return vardas;}
        string getPavarde() const {return pavarde;}
        vector<int> getNdRezultatai() const {return nd_rezultatai;}
        int getEgzaminoRezultatas() const {return egzamino_rezultatas;}
        double getGalutinisVid() const {return galutinis_vid;}
        double getGalutinisMed() const {return galutinis_med;}
};

void generatorius(string failas, int kiek_studentu, int kiek_nd);
void failo_skaitymas(vector<Studentas>& studentai);
void atsitiktiniai_rez(string vardas, string pavarde, int kiek_nd, vector<Studentas>& studentai);
void rasomi_rez(string vardas, string pavarde, bool is_naujo2, vector<Studentas>& studentai);
void galutinis(vector<Studentas>& studentai);
void isvesti(vector<Studentas>& studentai);
