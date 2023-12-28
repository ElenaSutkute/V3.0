#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <type_traits>


using namespace std;

class Zmogus {
public:
    virtual ~Zmogus() = default;

    virtual string getVardas() const = 0;
    virtual string getPavarde() const = 0;


};

template <typename Container>
class Duomenys : public Zmogus {
public:
    Duomenys() : egz(0), vid(0.0) {}

    Duomenys(const string &vardas, const string &pavarde, const Container &nd, int egz)
        : vardas(vardas), pavarde(pavarde), nd(nd), egz(egz), vid(0.0) {}

    Duomenys(const Duomenys &other)
        : vardas(other.vardas), pavarde(other.pavarde), nd(other.nd), egz(other.egz), vid(other.vid), med(other.med) {}

    Duomenys& operator=(const Duomenys &other)
    {
        if (this != &other)
        {
            vardas = other.vardas;
            pavarde = other.pavarde;
            nd = other.nd;
            egz = other.egz;
            vid = other.vid;
            med = other.med;
        }
        return *this;
    }

    ~Duomenys(){}

    string getVardas() const override {
        return vardas;
    }

    string getPavarde() const override {
        return pavarde;
    }

    const Container& getNd() const {
        return nd;
    }

    int getEgz() const {
        return egz;
    }

    double getVid() const {
        return vid;
    }

    void setVardas(const string &newVardas) {
        vardas = newVardas;
    }

    void setPavarde(const string &newPavarde) {
        pavarde = newPavarde;
    }

    void setEgz(int newEgz) {
        egz = newEgz;
    }

    void setVid(double newVid) {
        vid = newVid;
    }

    void addScore(int score) {
        nd.push_back(score);
    }


    friend std::istream& operator>>(std::istream& is, Duomenys& duomenys)
    {
        is >> duomenys.vardas >> duomenys.pavarde;

        int pazymys;
        while (is >> pazymys && pazymys != -1)
        {
            duomenys.addScore(pazymys);
        }

        is >> duomenys.egz;

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Duomenys& duomenys)
    {
        os << std::setw(15) << std::left << duomenys.vardas
           << std::setw(15) << std::left << duomenys.pavarde;

        for (const auto& score : duomenys.nd)
        {
            os << std::setw(4) << std::right << score;
        }

        os << std::setw(4) << std::right << duomenys.egz;

        return os;
    }

private:
    string vardas;
    string pavarde;
    Container nd;
    int egz;
    double vid, med;
};


template <typename Container>
vector<Duomenys<Container>> skaitytiDuomenisIsFailo();

template <typename Container>
void spausdintiDuomenis(const vector<Duomenys<Container>> &studentai);

template <typename Container>
vector<Duomenys<Container>> ivestiDuomenisRanka();

template <typename Container>
void StudentuSkirstymas(const string &sortingCriteria, const string &StorageType);

template <typename Container>
void GeneruotiFailus();

template <typename Container>
double vidurkis(const Container &vektorius);

template <typename Container>
bool rusiavimas(const Duomenys<Container> &a, const Duomenys<Container> &b);

template <typename Container>
void SortStudentsByGalutinis(vector<Duomenys<Container>> &students);

template <typename Container>
void SortStudentsByGalutinisList(list<Duomenys<Container>> &students);


int main()
{
    //Zmogus zmogus;


    Duomenys<vector<int>> duomenys1("Mhm", "Jonaityte", {9, 8, 7}, 9);

    Duomenys<vector<int>> duomenys2 = duomenys1;
    cout << "kopijavimo konstruktorius kopijuojant duomenys1, isvedama duomenys2 rezultatas:" << endl;
    cout << duomenys2 << endl;
    cout << "----------------------------------------" << endl;

    Duomenys<vector<int>> duomenys3;
    duomenys3 = duomenys1;
    cout << "kopijavimo priskyrimo operatorius, isvedama duomenys3 rezultatas:" << endl;
    cout << duomenys3 << endl;
    cout << "----------------------------------------" << endl;

        Duomenys<vector<int>> duomenys;

    cout << "Iveskite duomenis formatu vardas, pavarde, pazymys1 pazymys2(norint nutraukti ivedima veskite -1), egz):" << endl;
    cin >> duomenys;
    cout << "----------------------------------------" << endl;

    cout << "Rezultatas:" << endl;
    cout << duomenys << endl;
    cout << "----------------------------------------" << endl;



    string ats;
    string containerType;
    cout << "Ar naudoti vector ar list? (v/l)" << endl;

    try
    {
        cin >> containerType;
        if (containerType != "v" && containerType != "l")
        {
            throw runtime_error("Error. Pasirinkite 'v' arba 'l'");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (containerType == "v")
    {
        cout << "Ar generuoti failus?" << endl;
        cin >> ats;
        if (ats == "taip")
        {
            GeneruotiFailus<vector<int>>();
        }
    }
    else if (containerType == "l")
    {
        cout << "Ar generuoti failus?" << endl;
        cin >> ats;
        if (ats == "taip")
        {
            GeneruotiFailus<list<int>>();
        }
    }

    string kriterijus;
    cout << "Ar rusiuoti studentus pagal vidurki ar pagal pavardes?(v/p)" << endl;
    cin >> kriterijus;
    for (int i = 0; i < 3; i++)
    {
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << endl;
        if (containerType == "v")
        {
            StudentuSkirstymas<vector<int>>(kriterijus, containerType);
        }
        else if (containerType == "l")
        {
            StudentuSkirstymas<list<int>>(kriterijus, containerType);
        }
        for (int i = 0; i < 48; i++)
        {
            cout << "--";
        }
        cout << endl;
    }

    cout << "Ar skaityti duomenis is failo? taip/ne" << endl;
    string tekstinis;
    try
    {
        cin >> tekstinis;
        if (tekstinis != "taip" && tekstinis != "ne")
        {
            throw runtime_error("Error. Veskite tik 'taip' arba 'ne'");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }

    if (tekstinis == "taip")
    {
        if (containerType == "v")
        {
            vector<Duomenys<vector<int>>> studentai = skaitytiDuomenisIsFailo<vector<int>>();
            spausdintiDuomenis<vector<int>>(studentai);
        }
        else if (containerType == "l")
        {
            vector<Duomenys<list<int>>> studentai = skaitytiDuomenisIsFailo<list<int>>();
            spausdintiDuomenis<list<int>>(studentai);
        }
    }
    else
    {
        if (containerType == "v")
        {
            vector<Duomenys<vector<int>>> studentai = ivestiDuomenisRanka<vector<int>>();
            spausdintiDuomenis<vector<int>>(studentai);
        }
        else if (containerType == "l")
        {
            vector<Duomenys<list<int>>> studentai = ivestiDuomenisRanka<list<int>>();
            spausdintiDuomenis<list<int>>(studentai);
        }
    }
    cout << "Press Enter to exit...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}


template <typename Container>
vector<Duomenys<Container>> skaitytiDuomenisIsFailo()
{
    vector<Duomenys<Container>> studentai;

    ifstream infile("studentai.txt");
    if (!infile.is_open())
        {
            cerr << "Error: Failo atidaryti nepavyko." << endl;
            terminate();
        }

    string eile;
    getline(infile, eile);
    int lineNum = 0;
    while (getline(infile, eile))
    {
        lineNum++;
        Duomenys<Container> studentas;
        istringstream iss(eile);
        string vardas, pavarde;
        iss >> vardas >> pavarde;
        studentas.setVardas(vardas);
        studentas.setPavarde(pavarde);

        for (int i = 0; i < 7; i++)
        {
            int pazimys;
            iss >> pazimys;

            if (iss.fail())
            {
                cerr << "Error skaitant " << lineNum << " studento pazymius." << endl;
                break;
            }
            if (pazimys == -1)
            {
                break;
            }
            studentas.addScore(pazimys);
        }

        if (!iss.fail())
        {
            int egz;
            iss >> egz;
            studentas.setEgz(egz);
            studentai.push_back(studentas);
        }
    }
    infile.close();
    sort(studentai.begin(), studentai.end(), rusiavimas<Container>);

    return studentai;
}

template <typename Container>
vector<Duomenys<Container>> ivestiDuomenisRanka()
{
    int zmones;
    string atsakymas;
    cout << "Iveskite zmoniu skaiciu: ";
    try
    {
        cin >> zmones;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw runtime_error("Error. Veskite tik skaicius");
        }
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        exit(EXIT_FAILURE);
    }
    vector<Duomenys<Container>> studentai;
    for (int studentIndex = 0; studentIndex < zmones; studentIndex++)
    {
        Duomenys<Container> studentas;

        string vardas, pavarde;

        cout << "Iveskite varda: ";
        cin >> vardas;
        studentas.setVardas(vardas);
        cout << "Iveskite pavarde: ";
        cin >> pavarde;
        studentas.setPavarde(pavarde);

        cout << "Ar norite ivesti savo pazymius? Atsakymas: taip arba ne" << endl;
        try
        {
            cin >> atsakymas;
            if (atsakymas != "taip" && atsakymas != "ne")
            {
                throw runtime_error("Neteisinga ivestis. Veskite 'taip' arba 'ne'.");
            }
        }
        catch (const runtime_error &e)
        {
            cerr << e.what() << endl;
        }

        if (atsakymas == "taip")
        {
            cout << "Iveskite nd pazymius noredami uzbaigti ivedima, iveskite -1" << endl;
            int pazimys;
            while (cin >> pazimys)
            {
                if (pazimys == -1)
                {
                    break;
                }

                try
                {
                    if (pazimys <= 0 || pazimys > 10)
                    {
                        throw runtime_error("Error. Pazimys turi buti skaicius (0,10] ribose.");
                    }
                }
                catch (const runtime_error &e)
                {
                    cerr << e.what() << endl;
                }
                studentas.addScore(pazimys);
            }
            cout << "Iveskite egzamino rezultata: ";
            try
            {
                int egz;
                cin >> egz;
                studentas.setEgz(egz);
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Error. Veskite tik skaicius");
                }
            }
            catch (const runtime_error &e)
            {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            int n;
            cout << "Kiek namu darbu atlikote? ";
            try
            {
                cin >> n;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Error. Veskite tik skaicius");
                }
            }
            catch (const runtime_error &e)
            {
                cerr << e.what() << endl;
                exit(EXIT_FAILURE);
            }

            random_device rd;
            mt19937 generator(rd() + studentIndex);
            int min = 1;
            int max = 10;
            for (int j = 0; j < n; j++)
            {
                uniform_int_distribution<int> distribution(min, max);
                int random_skaicius = distribution(generator);
                studentas.addScore(random_skaicius);
                cout << random_skaicius << endl;
            }
            uniform_int_distribution<int> distribution(min, max);
            int egz = distribution(generator);
            studentas.setEgz(egz);
            cout << "Egzamino pazimys: " << studentas.getEgz() << endl;
        }

        studentai.push_back(studentas);
    }
    sort(studentai.begin(), studentai.end(), rusiavimas<Container>);
    return studentai;
}

template <typename Container>
void spausdintiDuomenis(const vector<Duomenys<Container>> &studentai)
{
    cout << setw(15) << left << "Pavarde" << setw(15) << left << "Vardas"
         << setw(20) << left << "Galutinis(Vid.)" << endl;
    for (int i = 0; i < 32; i++)
    {
        cout << "--";
    }
    cout << endl;

    for (const Duomenys<Container> &studentas : studentai)
    {

        cout << setw(15) << left << studentas.getPavarde() << setw(15) << left << studentas.getVardas();
        cout << setw(20) << left << round((0.4 * vidurkis(studentas.getNd()) + 0.6 * studentas.getEgz()) * 100.0) / 100.0 << endl;
    }
}

template <typename Container>
void GeneruotiFailus()
{
    const int studentCounts[] = {1000, 10000, 100000, 1000000, 10000000};

    for (int studentCount : studentCounts)
    {
        string filename = to_string(studentCount) + " studentu.txt";
        auto start = chrono::high_resolution_clock::now();
        ofstream Failas(filename);

        if (!Failas.is_open())
        {
            cerr << "Failed to open " << filename << endl;
            return;
        }

        Failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde";
        for (int i = 1; i <= 7; i++)
        {
            Failas << setw(5) << left << "ND" + to_string(i);
        }
        Failas << setw(5) << "Egz." << endl;

        random_device rd;
        mt19937 generator(rd() + studentCount);
        uniform_int_distribution<int> distribution(1, 10);

        for (int i = 1; i <= studentCount; i++)
        {
            Failas << setw(15) << left << "Vardas" + to_string(i) << setw(15) << left
                  << "Pavarde" + to_string(i);
            int min = 1;
            int max = 10;
            for (int j = 0; j < 7; j++)
            {
                uniform_int_distribution<int> distribution(min, max);
                int random_skaicius = distribution(generator);
                Failas << setw(5) << random_skaicius;
            }
            uniform_int_distribution<int> distribution(min, max);
            Failas << setw(5) << distribution(generator) << endl;
        }

        Failas.close();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        cout << studentCount << " studentu failas sukurtas per " << duration.count() << " sekundziu" << endl;
    }
}


template <typename Container>
void StudentuSkirstymas(const string &sortingCriteria, const string &StorageType)
{
    if (StorageType == "v")
    {
        vector<Duomenys<Container>> studentai;

        ifstream infile("10000 studentu.txt");

        cout << "Skaitymas vyksta is failo su 10,000 studentu" << endl;
        cout << endl;
        if (!infile)
        {
            cerr << "Error: Failo atidaryti nepavyko." << endl;
            terminate();
        }

        string eile;
        getline(infile, eile);
        int lineNum = 0;
        auto startRead = chrono::high_resolution_clock::now();
        while (getline(infile, eile))
        {
            lineNum++;
            Duomenys<Container> studentas;
            istringstream iss(eile);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            studentas.setVardas(vardas);
            studentas.setPavarde(pavarde);

            for (int i = 0; i < 7; i++)
            {
                int pazimys;
                iss >> pazimys;

                if (iss.fail())
                {
                    cerr << "Error skaitant " << lineNum << " studento pazymius." << endl;
                    break;
                }
                if (pazimys == -1)
                {
                    break;
                }

                studentas.addScore(pazimys);
            }

            if (!iss.fail())
            {
                int egz;
                iss >> egz;
                studentas.setEgz(egz);
                studentai.push_back(studentas);
            }
        }
        infile.close();

        auto endRead = chrono::high_resolution_clock::now();
        chrono::duration<double> durationRead = endRead - startRead;
        cout << "duomenu skaitymas is failo truko " << durationRead.count() << " sekundziu" << endl;

        for (Duomenys<Container> &studentas : studentai)
        {
            double vid = round((0.4 * vidurkis(studentas.getNd()) + 0.6 * studentas.getEgz()) * 100.0) / 100.0;
            studentas.setVid(vid);
        }
        if (sortingCriteria == "p")
        {

            auto startSort = chrono::high_resolution_clock::now();
            sort(studentai.begin(), studentai.end(), rusiavimas<Container>);
            auto endSort = chrono::high_resolution_clock::now();
            chrono::duration<double> durationSort = endSort - startSort;
            cout << "duomenu rusiavimas pagal pavardes ir vardus funkcija sort truko " << durationSort.count() << " sekundziu" << endl;
        }
        else if (sortingCriteria == "v")
        {

            auto startSort = chrono::high_resolution_clock::now();
            SortStudentsByGalutinis<Container>(studentai);
            auto endSort = chrono::high_resolution_clock::now();
            chrono::duration<double> durationSort = endSort - startSort;
            cout << "duomenu skirstymas pagal vidurki truko " << durationSort.count() << " sekundziu" << endl;
        }
        else
        {
            cerr << "Neteisingai Ivestas rusiavimo kriterijus, veskite tik v/p" << endl;
            return;
        }

        vector<Duomenys<Container>> protingi;

        auto startFilter = chrono::high_resolution_clock::now();

        auto partitionIt = partition(studentai.begin(), studentai.end(),
                                      [](const Duomenys<Container> &studentas) {
                                          return studentas.getVid() < 5;
                                      });

        protingi.insert(protingi.end(), make_move_iterator(partitionIt), make_move_iterator(studentai.end()));
        studentai.erase(partitionIt, studentai.end());
        SortStudentsByGalutinis<Container>(protingi);

        auto endFilter = chrono::high_resolution_clock::now();
        chrono::duration<double> durationFilter = endFilter - startFilter;

        cout << "duomenu rusiavimas i failus paval vidurki truko " << durationFilter.count() << " sekundziu" << endl;

        auto startWriteVargsiukai = chrono::high_resolution_clock::now();

        ofstream Vargsiukai("Vargsiukai.txt");
        Vargsiukai << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
                   << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;

        for (const Duomenys<Container> &studentas : studentai)
        {
            Vargsiukai << setw(15) << left << studentas.getVardas() << setw(15) << left << studentas.getPavarde()
                       << setw(20) << left << studentas.getVid() << setw(20) << endl;
        }

        Vargsiukai.close();

        auto endWriteVargsiukai = chrono::high_resolution_clock::now();
        chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
        cout << "duomenu isvedimas i Vargsiuku studentu faila truko " << durationWriteVargsiukai.count() << " sekundziu" << endl;

        auto startWriteMoksliukai = chrono::high_resolution_clock::now();

        ofstream Moksliukai("Moksliukai.txt");
        Moksliukai << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
                   << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;

        for (const Duomenys<Container> &studentas : protingi)
        {
            Moksliukai << setw(15) << left << studentas.getVardas() << setw(15) << left << studentas.getPavarde()
                       << setw(20) << left << studentas.getVid() << setw(20) << endl;
        }

        Moksliukai.close();

        auto endWriteMoksliukai = chrono::high_resolution_clock::now();
        chrono::duration<double> durationWriteMoksliukai = endWriteMoksliukai - startWriteMoksliukai;
        cout << "duomenu isvedimas i Moksliuku studentu faila truko " << durationWriteMoksliukai.count() << " sekundziu" << endl;
    }
    else
    {
        list<Duomenys<Container>> studentai;

        ifstream infile("10000 studentu.txt");

        cout << "Skaitymas vyksta is failo su 10,000 studentu" << endl;
        cout << endl;
        if (!infile)
        {
            cerr << "Error: Failo atidaryti nepavyko." << endl;
            terminate();
        }

        string eile;
        getline(infile, eile);
        int lineNum = 0;
        auto startRead = chrono::high_resolution_clock::now();
        while (getline(infile, eile))
        {
            lineNum++;
            Duomenys<Container> studentas;
            istringstream iss(eile);
            string vardas, pavarde;
            iss >> vardas >> pavarde;
            studentas.setVardas(vardas);
            studentas.setPavarde(pavarde);

            for (int i = 0; i < 7; i++)
            {
                int pazimys;
                iss >> pazimys;

                if (iss.fail())
                {
                    cerr << "Error skaitant " << lineNum << " studento pazymius." << endl;
                    break;
                }
                if (pazimys == -1)
                {
                    break;
                }
                studentas.addScore(pazimys);
            }

            if (!iss.fail())
            {
                int egz;
                iss >> egz;
                studentas.setEgz(egz);
                studentai.push_back(studentas);
            }
        }
        infile.close();

        auto endRead = chrono::high_resolution_clock::now();
        chrono::duration<double> durationRead = endRead - startRead;
        cout << "duomenu skaitymas is failo truko " << durationRead.count() << " sekundziu" << endl;

        for (Duomenys<Container> &studentas : studentai)
        {
            double vid = round((0.4 * vidurkis(studentas.getNd()) + 0.6 * studentas.getEgz()) * 100.0) / 100.0;
            studentas.setVid(vid);
        }

        if (sortingCriteria == "p")
        {
            auto startSort = chrono::high_resolution_clock::now();
            studentai.sort(rusiavimas<Container>);
            auto endSort = chrono::high_resolution_clock::now();
            chrono::duration<double> durationSort = endSort - startSort;
            cout << "duomenu rusiavimas pagal pavardes ir vardus funkcija sort truko " << durationSort.count() << " sekundziu" << endl;
        }
        else if (sortingCriteria == "v")
        {
            auto startSort = chrono::high_resolution_clock::now();
            SortStudentsByGalutinisList<Container>(studentai);
            auto endSort = chrono::high_resolution_clock::now();
            chrono::duration<double> durationSort = endSort - startSort;
            cout << "duomenu skirstymas pagal vidurki truko " << durationSort.count() << " sekundziu" << endl;
        }
        else
        {
            cerr << "Neteisingai Ivestas rusiavimo kriterijus, veskite tik v/p" << endl;
            return;
        }

        list<Duomenys<Container>> protingi;
        list<Duomenys<Container>> kiti;

        auto startFilter = chrono::high_resolution_clock::now();

        auto partitionIt = partition(studentai.begin(), studentai.end(),
                                      [](const Duomenys<Container> &studentas) {
                                          return studentas.getVid() >= 5;
                                      });

        protingi.insert(protingi.end(), make_move_iterator(partitionIt), make_move_iterator(studentai.end()));
        studentai.erase(partitionIt, studentai.end());
        SortStudentsByGalutinisList<Container>(protingi);

        auto endFilter = chrono::high_resolution_clock::now();
        chrono::duration<double> durationFilter = endFilter - startFilter;
        cout << "duomenu rusiavimas i failus pagal vidurki truko " << durationFilter.count() << " sekundziu" << endl;

        auto startWriteVargsiukai = chrono::high_resolution_clock::now();

        ofstream Vargsiukai("Vargsiukai.txt");
        Vargsiukai << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
                   << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;

        for (const Duomenys<Container> &studentas : protingi)
        {
            Vargsiukai << setw(15) << left << studentas.getVardas() << setw(15) << left << studentas.getPavarde()
                       << setw(20) << left << studentas.getVid() << setw(20) << endl;
        }

        Vargsiukai.close();
            auto endWriteVargsiukai = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
    cout << "duomenu isvedimas i Vargsiuku studentu faila truko " << durationWriteVargsiukai.count() << " sekundziu" << endl;

    auto startWriteMoksliukai = chrono::high_resolution_clock::now();

    ofstream Moksliukai("Moksliukai.txt");
    Moksliukai << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
               << setw(20) << left << "Galutinis(Vid.)" << setw(20) << endl;

    for (const Duomenys<Container> &studentas : studentai)
    {
        Moksliukai << setw(15) << left << studentas.getVardas() << setw(15) << left << studentas.getPavarde()
                   << setw(20) << left << studentas.getVid() << setw(20) << endl;
    }

    Moksliukai.close();

    auto endWriteMoksliukai = chrono::high_resolution_clock::now();
    chrono::duration<double> durationWriteMoksliukai = endWriteMoksliukai - startWriteMoksliukai;
    cout << "duomenu isvedimas i Moksliuku studentu faila truko " << durationWriteMoksliukai.count() << " sekundziu" << endl;


    }

}

template <typename Container>
double vidurkis(const Container &vektorius)
{
    double suma = 0.0;
    int kiekis = 0;

    for (const auto &element : vektorius)
    {
        suma += element;
        kiekis++;
    }

    if (kiekis == 0)
    {
        return 0.0;
    }

    return suma / kiekis;
}



template <typename Container>
bool rusiavimas(const Duomenys<Container> &a, const Duomenys<Container> &b)
{
    string vardas1 = a.getVardas();
    string vardas2 = b.getVardas();
    string pavarde1 = a.getPavarde();
    string pavarde2 = b.getPavarde();

    if (vardas1 == vardas2)
    {
        return pavarde1 < pavarde2;
    }
    return vardas1 < vardas2;
}


template <typename Container>
void SortStudentsByGalutinis(vector<Duomenys<Container>> &students)
{
    sort(students.begin(), students.end(), [](const Duomenys<Container> &a, const Duomenys<Container> &b) {
        return (vidurkis(a.getNd()) * 0.4 + a.getEgz() * 0.6) > (vidurkis(b.getNd()) * 0.4 + b.getEgz() * 0.6);
    });
}

template <typename Container>
void SortStudentsByGalutinisList(list<Duomenys<Container>> &students)
{
    students.sort([](const Duomenys<Container> &a, const Duomenys<Container> &b) {
        return (vidurkis(a.getNd()) * 0.4 + a.getEgz() * 0.6) > (vidurkis(b.getNd()) * 0.4 + b.getEgz() * 0.6);
    });
}
