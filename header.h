#include "libraries.h"

// Abstract base class Human
class Zmogas {
    protected:
        string vardas;
        string pavarde;

    public:
        Zmogas(const string& vardas, const string& pavarde)
            : vardas(vardas), pavarde(pavarde) {}

        // Getteriai
        string getVardas() const { return vardas; }
        string getPavarde() const { return pavarde; }

        // Virtuali Funkcija
        virtual void rasoInfo(ofstream& raso) const = 0;

        // Destruktorius
        virtual ~Zmogas() {}
};

// Derived class Student from Human
class Studentas : public Zmogas {
    private:
        vector<int> nd_rezultatai;
        int egzamino_rezultatas;
        double galutinis_vid, galutinis_med;

    public:
        // R05 -----
        Studentas(const string& vardas, const string& pavarde, const vector<int>& nd_rezultatai,
                int egzamino_rezultatas, double galutinis_vid, double galutinis_med)
            : Zmogas(vardas, pavarde), nd_rezultatai(nd_rezultatai), egzamino_rezultatas(egzamino_rezultatas),
            galutinis_vid(galutinis_vid), galutinis_med(galutinis_med) {}
        Studentas(const Studentas& other)
            : Zmogas(other), nd_rezultatai(other.nd_rezultatai), egzamino_rezultatas(other.egzamino_rezultatas),
            galutinis_vid(other.galutinis_vid), galutinis_med(other.galutinis_med) {}
        Studentas(Studentas&& other) noexcept
            : Zmogas(move(other)), nd_rezultatai(move(other.nd_rezultatai)),
            egzamino_rezultatas(other.egzamino_rezultatas), galutinis_vid(other.galutinis_vid),
            galutinis_med(other.galutinis_med) {}
        
        Studentas& operator=(const Studentas& other) {
            if(this != &other) {
                Zmogas::operator=(other);
                nd_rezultatai = other.nd_rezultatai;
                egzamino_rezultatas = other.egzamino_rezultatas;
                galutinis_vid = other.galutinis_vid;
                galutinis_med = other.galutinis_med;
            }
            return *this;
        } Studentas& operator=(Studentas&& other) noexcept {
            if(this != &other) {
                Zmogas::operator=(move(other));
                nd_rezultatai = move(other.nd_rezultatai);
                egzamino_rezultatas = other.egzamino_rezultatas;
                galutinis_vid = other.galutinis_vid;
                galutinis_med = other.galutinis_med;
            }
            return *this;
        }

        // Setteriai
        void setNdRezultatai(const vector<int>& nd_rezultatai) { this->nd_rezultatai = nd_rezultatai; }
        void setEgzaminoRezultatas(int egzamino_rezultatas) { this->egzamino_rezultatas = egzamino_rezultatas; }
        void setGalutinisVid(double galutinis_vid) { this->galutinis_vid = galutinis_vid; }
        void setGalutinisMed(double galutinis_med) { this->galutinis_med = galutinis_med; }

        // Getteriai
        vector<int> getNdRezultatai() const { return nd_rezultatai; }
        int getEgzaminoRezultatas() const { return egzamino_rezultatas; }
        double getGalutinisVid() const { return galutinis_vid; }
        double getGalutinisMed() const { return galutinis_med; }

        // Perrašyta printInfo funkcija iš bazinės klasės
        void rasoInfo(ofstream& raso) const override {
            raso << "Vardas: " << vardas << endl;
            raso << "Pavarde: " << pavarde << endl;
            raso << "ND rezultatai: ";
            for (int rezultatas : nd_rezultatai)
                raso << rezultatas << " ";
            raso << endl << "Egzamino rezultatas: " << egzamino_rezultatas << endl;
            raso << "Galutinis (Vid.): " << galutinis_vid << endl;
            raso << "Galutinis (Med.): " << galutinis_med << endl;
            raso << "--------" << endl;
        }

        // Destruktorius
        ~Studentas() {}
};

void generatorius(string failas, int kiek_studentu, int kiek_nd);
void failo_skaitymas(vector<Studentas>& studentai);
void atsitiktiniai_rez(string vardas, string pavarde, int kiek_nd, vector<Studentas>& studentai);
void rasomi_rez(string vardas, string pavarde, bool is_naujo2, vector<Studentas>& studentai);
void galutinis(vector<Studentas>& studentai);
void isvesti(vector<Studentas>& studentai);
