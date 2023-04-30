#include "header.h"

void galutinis(vector<Studentas>& studentai) {
    for (auto& studentas : studentai) {
        int nd_suma = accumulate(studentas.get_nd_rezultatai().begin(), studentas.get_nd_rezultatai().end(), 0);
        double nd_vidurkis = nd_suma / static_cast<double>(studentas.get_nd_rezultatai().size());
        double galutinis = 0.4 * nd_vidurkis + 0.6 * studentas.get_egzamino_rezultatas();
        studentas.set_galutinis_vid(galutinis);
        
        vector<int> nd_copy(studentas.get_nd_rezultatai().begin(), studentas.get_nd_rezultatai().end());
        sort(nd_copy.begin(), nd_copy.end());

        double mediana;
        if (studentas.get_nd_rezultatai().size() % 2 == 0) {
            mediana = (studentas.get_nd_rezultatai()[studentas.get_nd_rezultatai().size() / 2 - 1] + studentas.get_nd_rezultatai()[studentas.get_nd_rezultatai().size() / 2]) / 2.0;
        } else {
            mediana = studentas.get_nd_rezultatai()[studentas.get_nd_rezultatai().size() / 2];
        }
        double galutinis_mediana = 0.4 * mediana + 0.6 * studentas.get_egzamino_rezultatas();
        studentas.set_galutinis_med(galutinis_mediana);
    }
}

void atsitiktiniai_rez(int kiek_nd, Studentas& naujas_studentas) {
    cout << "-----------------------------------------------------------------------" << endl;
    do {
        try {
            cout << "Iveskite [" << naujas_studentas.get_vardas() << " " << naujas_studentas.get_pavarde() << "] namu darbu rezultatu kieki, kuris bus atsitiktinai sugeneruotas: ";
            cin >> kiek_nd; cout << endl;
            if(cin.fail()) {
                throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
            } else {
                break;
            }
        } catch(const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore();
        }
    } while(true);

    // Generuojami atsitiktiniai namų darbų bei egzamino rezultatai
    std::mt19937 mt(1729);
    std::uniform_int_distribution<int> dist(1, 10);
    vector<int> nd_rezultatai;
    for(int i = 0; i < kiek_nd; i++) {
        int nd_rezultatas = dist(mt);
        cout << "Atsitiktinis [" << naujas_studentas.get_vardas() << " " << naujas_studentas.get_pavarde() << "] namu darbu rezultatas: " << nd_rezultatas << endl;

        // Atsitiktiniai rezultatai pridedami į vektoriaus pabaigą
        nd_rezultatai.push_back(nd_rezultatas);
    }

    naujas_studentas.set_nd_rezultatai(nd_rezultatai);
    naujas_studentas.set_egzamino_rezultatas(dist(mt));
    
    cout << endl << "Atsitiktinis [" << naujas_studentas.get_vardas() << " " << naujas_studentas.get_pavarde() << "] egzamino rezultatas: " << naujas_studentas.get_egzamino_rezultatas() << endl;
}


void rasomi_rez(bool is_naujo2, int nd_rezultatas, int egz_rez, Studentas& naujas_studentas) {
    cout << "-----------------------------------------------------------------------" << endl;
    do {
        try {
            cout << "Iveskite [" << naujas_studentas.get_vardas() << " " << naujas_studentas.get_pavarde() << "] namu darbo rezultata intervale [1; 10] (arba 0, jei daugiau nenorite vesti): ";
            cin >> nd_rezultatas;
            if(cin.fail()) {
                throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
            } if(nd_rezultatas != 0 && nd_rezultatas > 0 && nd_rezultatas <= 10) {
                // Įvestas rezultatas pridedamas į vektoriaus pabaigą
                naujas_studentas.set_nd_rezultatai(vector<int>{nd_rezultatas});
            } else if(nd_rezultatas < 0 || nd_rezultatas > 10) {
                cout << "Klaida: pazymys turi buti intervale [1; 10]." << endl;

                continue;
            } else if(nd_rezultatas == 0) {break;}  
        } catch(const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore();

            is_naujo2 = true;
        }
    } while (nd_rezultatas != 0 || is_naujo2 != false);

    do {
        try {
            cout << endl << "Iveskite [" << naujas_studentas.get_vardas() << " " << naujas_studentas.get_pavarde() << "] egzamino rezultata intervale [1; 10]: ";
            cin >> egz_rez;
            
            if(cin.fail()) {
                throw invalid_argument("Klaida: ivestas neteisingas simbolis.");
            }
        } catch(const invalid_argument& e) {
            cout << e.what() << endl;
            cin.clear(); 
            cin.ignore();
        } if(egz_rez > 0 && egz_rez <= 10) {
            naujas_studentas.set_egzamino_rezultatas(egz_rez);

            break;
        } else if(egz_rez < 1 && egz_rez > 10) {
            cout << "Klaida: rezultatas turi buti intervale [1; 10]." << endl;

            continue;
        }
    } while(true);  
}

void isvesti(vector<Studentas>& studentai) {
    vector<Studentas> win;
    vector<Studentas> loss;

    int strategija;

    cout << "Kokia rusiavimo strategija norite naudoti? (1 / 2): ";
    cin >> strategija; cout << endl;

    // Mokinių duomenų išrašymas
    switch(strategija) {
        case 1: {
            auto sRusiavimas = std::chrono::system_clock::now();
            for (auto& s : studentai) {
                if(s.get_nd_rezultatai().empty() || s.get_galutinis_vid() <= 0 || s.get_galutinis_med() <= 0) {continue;}

                if(s.get_galutinis_vid() < 5.0 && s.get_galutinis_med() < 5.0) {
                    loss.push_back(s);
                } else {
                    win.push_back(s);
                }
            }
            studentai = win;

            auto eRusiavimas = std::chrono::system_clock::now();
            std::chrono::duration<double> dRusiavimas = eRusiavimas - sRusiavimas;

            cout << "Rusiavimas baigtas per " << dRusiavimas.count() << "s.";

            break;
        }
        case 2: {
            auto sRusiavimas = std::chrono::system_clock::now();

            auto it = remove_if(studentai.begin(), studentai.end(), [](const auto& s){
                return s.get_nd_rezultatai().empty() || s.get_galutinis_vid() <= 0 || s.get_galutinis_med() <= 0 ||
                    (s.get_galutinis_vid() < 5.0 && s.get_galutinis_med() < 5.0);
            });
            loss.insert(loss.end(), it, studentai.end());
            studentai.erase(it, studentai.end());

            auto eRusiavimas = std::chrono::system_clock::now();
            std::chrono::duration<double> dRusiavimas = eRusiavimas - sRusiavimas;

            cout << "Rusiavimas baigtas per " << dRusiavimas.count() << "s.";

            break;
        }
        default: {
            cout << "Tokio pasirinkimo [" << strategija << "] nera. Tesiama su pirma strategija" << endl;

            auto sRusiavimas = std::chrono::system_clock::now();
            for (auto& s : studentai) {
                if(s.get_nd_rezultatai().empty() || s.get_galutinis_vid() <= 0 || s.get_galutinis_med() <= 0) {continue;}

                if(s.get_galutinis_vid() < 5.0 && s.get_galutinis_med() < 5.0) {
                    loss.push_back(s);
                } else {
                    win.push_back(s);
                }
            }
            studentai = win;

            auto eRusiavimas = std::chrono::system_clock::now();
            std::chrono::duration<double> dRusiavimas = eRusiavimas - sRusiavimas;

            cout << "Rusiavimas baigtas per " << dRusiavimas.count() << "s.";

            break;
        }
    }
    
}

