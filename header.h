#include "libraries.h"

class Studentas {
private:
    string vardas;
    string pavarde;
    vector<int> nd_rezultatai;
    int egzamino_rezultatas;
    double galutinis_vid, galutinis_med;

public:
    // Konstruktorius
    Studentas(string vardas, string pavarde, vector<int> nd_rezultatai, int egzamino_rezultatas, double galutinis_vid, double galutinis_med)
        : vardas(vardas), pavarde(pavarde), nd_rezultatai(nd_rezultatai), egzamino_rezultatas(egzamino_rezultatas), galutinis_vid(galutinis_vid), galutinis_med(galutinis_med) {}

    // RO5 -----
    Studentas(const Studentas& other) // Copy constructor
        : vardas(other.vardas), pavarde(other.pavarde), nd_rezultatai(other.nd_rezultatai),
          egzamino_rezultatas(other.egzamino_rezultatas), galutinis_vid(other.galutinis_vid),
          galutinis_med(other.galutinis_med) {}
    Studentas(Studentas&& other) noexcept // Move constructor
        : vardas(std::move(other.vardas)), pavarde(std::move(other.pavarde)),
          nd_rezultatai(std::move(other.nd_rezultatai)), egzamino_rezultatas(other.egzamino_rezultatas),
          galutinis_vid(other.galutinis_vid), galutinis_med(other.galutinis_med) {}
    Studentas& operator=(const Studentas& other) { // Copy assignment operator
        if(this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            nd_rezultatai = other.nd_rezultatai;
            egzamino_rezultatas = other.egzamino_rezultatas;
            galutinis_vid = other.galutinis_vid;
            galutinis_med = other.galutinis_med;
        }
        return *this;
    }
    Studentas& operator=(Studentas&& other) noexcept { // Move assignment operator
        if(this != &other) {
            vardas = std::move(other.vardas);
            pavarde = std::move(other.pavarde);
            nd_rezultatai = std::move(other.nd_rezultatai);
            egzamino_rezultatas = other.egzamino_rezultatas;
            galutinis_vid = other.galutinis_vid;
            galutinis_med = other.galutinis_med;
        }
        return *this;
    }

    // Destruktorius
    ~Studentas() {}

    // Setteriai
    void setVardas(const string& vardas) { this->vardas = vardas; }
    void setPavarde(const string& pavarde) { this->pavarde = pavarde; }
    void setNdRezultatai(const vector<int>& nd_rezultatai) { this->nd_rezultatai = nd_rezultatai; }
    void setEgzaminoRezultatas(int egzamino_rezultatas) { this->egzamino_rezultatas = egzamino_rezultatas; }
    void setGalutinisVid(double galutinis_vid) { this->galutinis_vid = galutinis_vid; }
    void setGalutinisMed(double galutinis_med) { this->galutinis_med = galutinis_med; }

    // Getteriai
    string getVardas() const { return vardas; }
    string getPavarde() const { return pavarde; }
    vector<int> getNdRezultatai() const { return nd_rezultatai; }
    int getEgzaminoRezultatas() const { return egzamino_rezultatas; }
    double getGalutinisVid() const { return galutinis_vid; }
    double getGalutinisMed() const { return galutinis_med; }

    // Cout operatorius
    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
        os << "Vardas: " << studentas.vardas << endl;
        os << "Pavarde: " << studentas.pavarde << endl;
        os << "ND rezultatai: ";
        for (int rezultatas : studentas.nd_rezultatai)
            os << rezultatas << " ";
        os << endl;
        os << "Egzamino rezultatas: " << studentas.egzamino_rezultatas << endl;
        os << "Galutinis (Vid.): " << studentas.galutinis_vid << endl;
        os << "Galutinis (Med.): " << studentas.galutinis_med << endl;
        return os;
    }
};

void generatorius(string failas, int kiek_studentu, int kiek_nd);
void failo_skaitymas(vector<Studentas>& studentai);
void atsitiktiniai_rez(string vardas, string pavarde, int kiek_nd, vector<Studentas>& studentai);
void rasomi_rez(string vardas, string pavarde, bool is_naujo2, vector<Studentas>& studentai);
void galutinis(vector<Studentas>& studentai);
void isvesti(vector<Studentas>& studentai);
