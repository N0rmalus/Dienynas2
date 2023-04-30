#include "libraries.h"

class Studentas {
    private:
        string vardas;
        string pavarde;
        vector<int> nd_rezultatai;
        int egzamino_rezultatas;
        double galutinis_vid, galutinis_med;

    public:
        Studentas() : egzamino_rezultatas(0), galutinis_vid(0), galutinis_med(0) {}

        Studentas(string v, string p) : vardas(v), pavarde(p), egzamino_rezultatas(0), galutinis_vid(0), galutinis_med(0) {}

        Studentas(const Studentas& other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            nd_rezultatai = other.nd_rezultatai;
            egzamino_rezultatas = other.egzamino_rezultatas;
            galutinis_vid = other.galutinis_vid;
            galutinis_med = other.galutinis_med;
        }

        // Setteriai
        void set_vardas(string v) { vardas = v; }
        void set_pavarde(string p) { pavarde = p; }
        void set_egzamino_rezultatas(int e) { egzamino_rezultatas = e; }
        void set_nd_rezultatai(const vector<int>& nd) { nd_rezultatai = nd; }

        void set_galutinis_vid(double gv) { galutinis_vid = gv; }
        void set_galutinis_med(double gm) { galutinis_med = gm; }

        // Getteriai
        inline string get_vardas() const { return vardas; }
        inline string get_pavarde() const { return pavarde; }
        inline int get_egzamino_rezultatas() const { return egzamino_rezultatas; }
        inline vector<int> get_nd_rezultatai() const { return nd_rezultatai; }
        inline double get_galutinis_vid() const { return galutinis_vid; }
        inline double get_galutinis_med() const { return galutinis_med; }

        ~Studentas() {}
};

void generatorius(string failas, int kiek_studentu, int kiek_nd);
void galutinis(vector<Studentas>& studentai);
void atsitiktiniai_rez(int kiek_nd, Studentas& naujas_studentas);
void rasomi_rez(bool is_naujo2, int nd_rezultatas, int egz_rez, Studentas& naujas_studentas);
void isvesti(vector<Studentas>& studentai);