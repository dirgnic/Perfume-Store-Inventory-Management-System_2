+#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Parfum;
class Angajat;
class Vanzare;
class InventarMagazin;

class Parfum
{
private:
    static int PARFCONT; // nr total tipuri de parfum
    const int idParfum;
    char *numeParfum;
    char *brand;
    char rating;
    char *tipAroma;
    bool inStoc;
    double pret;

public:
    // constructor fara parametrii

    Parfum() : idParfum(PARFCONT++)
    {
        numeParfum = new char[strlen("anonim") + 1];
        strcpy(numeParfum, "anonim");
        brand = new char[strlen("anonim") + 1];
        strcpy(brand, "anonim");
        rating = 'x';
        tipAroma = new char[strlen("anonim") + 1];
        strcpy(tipAroma, "anonim");
        inStoc = false;
        pret = 0;
    }

    // constructor cu toti parametrii

    Parfum(char *numeParfum, char *brand, char rating, char *tipAroma,
           bool inStoc, double pret)
        : idParfum(PARFCONT++), rating(rating), inStoc(inStoc), pret(pret)
    {
        this->numeParfum = new char[strlen(numeParfum) + 1];
        strcpy(this->numeParfum, numeParfum);
        this->brand = new char[strlen(brand) + 1];
        strcpy(this->brand, brand);
        this->tipAroma = new char[strlen(tipAroma) + 1];
        strcpy(this->tipAroma, tipAroma);
    }

    // constructori cu unii parametrii

    Parfum(char *numeParfum, bool inStoc, double pret)
        : idParfum(PARFCONT++), inStoc(inStoc), pret(pret)
    {
        this->numeParfum = new char[strlen(numeParfum) + 1];
        strcpy(this->numeParfum, numeParfum);
        this->brand = new char[strlen("anonim") + 1];
        strcpy(this->brand, "anonim");
        this->rating = 'x';
        this->tipAroma = new char[strlen("anonim") + 1];
        strcpy(this->tipAroma, "anonim");
    }

    Parfum(char *numeParfum, char *tipAroma, double pret)
        : idParfum(++PARFCONT), pret(pret)
    {
        this->numeParfum = new char[strlen(numeParfum) + 1];
        strcpy(this->numeParfum, numeParfum);
        this->brand = new char[strlen("anonim") + 1];
        strcpy(this->brand, "anonim");
        this->rating = 'x';
        this->inStoc = false;
        this->tipAroma = new char[strlen(tipAroma) + 1];
        strcpy(this->tipAroma, tipAroma);
    }
    // constructor de copiere
    Parfum(const Parfum &p)
        : idParfum(p.idParfum), rating(p.rating), inStoc(p.inStoc), pret(p.pret)
    {
        this->numeParfum = new char[strlen(p.numeParfum) + 1];
        strcpy(this->numeParfum, p.numeParfum);
        this->brand = new char[strlen(p.brand) + 1];
        strcpy(this->brand, p.brand);
        this->tipAroma = new char[strlen(p.tipAroma) + 1];
        strcpy(this->tipAroma, p.tipAroma);
    }

    // destructor
    ~Parfum()
    {
        if (this->numeParfum != NULL)
            delete[] this->numeParfum;
        if (this->brand != NULL)
            delete[] this->brand;
        if (this->tipAroma != NULL)
            delete[] this->tipAroma;
    }

    // setteri

    void setNumeParfum(char *numeSala)
    {
        if (this->numeParfum != NULL)
            delete[] this->numeParfum;
        this->numeParfum = new char[strlen(numeParfum) + 1];
        strcpy(this->numeParfum, numeParfum);
    }

    void setBrand(char *numeBrand)
    {
        if (this->brand != NULL)
            delete[] this->brand;
        this->brand = new char[strlen(numeBrand) + 1];
        strcpy(this->brand, numeBrand);
    }

    void setRating(char rating) { this->rating = rating; }

    void setTipAroma(char *nume_tipAroma)
    {
        if (this->tipAroma != NULL)
            delete[] this->tipAroma;
        this->tipAroma = new char[strlen(nume_tipAroma) + 1];
        strcpy(this->tipAroma, nume_tipAroma);
    }

    void setInStoc(bool inStoc) { this->inStoc = inStoc; }

    void setPret(double pret) { this->pret = pret; }

    // getteri

    int getIdParfum() { return idParfum; }

    char *getNumeParfum() { return numeParfum; }

    char *getBrand() { return brand; }

    char getRating() { return rating; }

    char *getTipAroma() { return tipAroma; }

    bool isInStoc() { return inStoc; }

    double getPret() { return pret; }

    // functionalitate

    void perioadaDeVarf() // print perioada cand parfumul ar trebui sa se vanda
                          // cel mai bine
    {

        switch (((int)rating - 'a') % 4)
        {
        case 0:
            cout << "primavara";
            break;
        case 1:
            cout << "vara";
            break;
        case 2:
            cout << "toamna";
            break;
        case 3:
            cout << "iarna";
            break;
        }
    }

    // supraincarcare operator = pentru Parfum
    Parfum &operator=(const Parfum &obj)
    {
        if (this != &obj)
        {

            if (this->numeParfum != NULL)
                delete[] this->numeParfum;
            if (this->brand != NULL)
                delete[] this->brand;
            if (this->tipAroma != NULL)
                delete[] this->tipAroma;

            this->numeParfum = new char[strlen(obj.numeParfum) + 1];
            strcpy(this->numeParfum, obj.numeParfum);

            this->brand = new char[strlen(obj.brand) + 1];
            strcpy(this->brand, obj.brand);

            this->rating = obj.rating;

            this->tipAroma = new char[strlen(obj.tipAroma) + 1];
            strcpy(this->tipAroma, obj.tipAroma);

            this->inStoc = obj.inStoc;
            this->pret = obj.pret;
        }
        return *this;
    }

    friend ostream &operator<<(
        ostream &,
        const Parfum
            &); // const rezolva eroarea de identificare membrii private pt parfum
                // - pt ca nu vrem ca friend sa modifice membrii private
    friend istream &operator>>(istream &, Parfum &);

    // Operatorul de indexare[]
    int operator[](int index)
    {
        switch (index)
        {
        case 0:
            return idParfum;
        case 1:
            return strlen(this->numeParfum);
        case 2:
            return strlen(this->brand);
        case 3:
            return (int)rating;
        case 4:
            return strlen(this->tipAroma);
        case 5:
            return (inStoc == false) ? 0 : 1;
        default:
            throw runtime_error("Index invalid");
        }
    }

    // supraincarcarea operatorilor ++ la stanga si dreapta pentru Parfum

    Parfum &operator++() /// pre-incrementare
    {
        this->pret++;

        return *this;
    }

    Parfum operator++(int) /// post-incrementare
    {
        Parfum copie = *this;
        copie.pret++;
        return copie;
    }

    /// OPERATORUL +, * cu un char* in dreapta
    Parfum operator+(char *s)
    {
        Parfum copie = *this;
        strcat(copie.numeParfum, " ");
        strcat(copie.numeParfum, s);
        return copie;
    }

    Parfum operator*(char *s)
    {
        Parfum copie = *this;
        strcat(copie.tipAroma, " ");
        strcat(copie.tipAroma, s);
        return copie;
    }

    /// OPERATORUL +, * cu un char* in stanga
    friend Parfum operator+(char *s, Parfum obj);
    friend Parfum operator*(char *s, Parfum obj);

    /// CAST char* pentru Parfum
    operator char *() // implicit
    {
        return this->numeParfum;
    }

    // supraincarcarea operatorului >= si == pentru doua obiecte din Parfum

    bool operator>=(const Parfum &obj)
    {
        return idParfum >= obj.idParfum || this->pret >= obj.pret;
    }

    bool operator==(const Parfum &obj)
    {
        return idParfum == obj.idParfum && this->pret == obj.pret;
    }
};

// supraincarcarea la stanga a operatorilor +, * pentru Parfum

Parfum operator*(char *s, Parfum obj)
{
    strcat(obj.tipAroma, " ");
    strcat(obj.tipAroma, s);
    return obj;
}

Parfum operator+(char *s, Parfum obj)
{
    strcat(obj.numeParfum, " ");
    strcat(obj.numeParfum, s);
    return obj;
}

// supraincarcarea operatorului << pentru Parfum

ostream &operator<<(ostream &out, const Parfum &obj)
{
    out << "ID Parfum: " << obj.idParfum << endl;
    out << "Nume Parfum: " << obj.numeParfum << endl;
    out << "Brand: " << obj.brand << endl;
    out << "Rating: " << obj.rating << endl;
    out << "Tip Aroma: " << obj.tipAroma << endl;
    out << "In Stoc: " << std::boolalpha << obj.inStoc << endl;
    out << "Pret: " << obj.pret << endl;
    out << endl;
    return out;
}

// supraincarcarea operatorului >> pentru Parfum

istream &operator>>(istream &in, Parfum &obj)
{
    // id ul apare la crearea obiectului
    char nume[100];
    cout << "Nume Parfum: ";
    in.get();
    in.getline(nume, 100);
    if (obj.numeParfum != NULL)
        delete[] obj.numeParfum;
    obj.numeParfum = new char[strlen(nume) + 1];
    strcpy(obj.numeParfum, nume);

    char brand[100];
    cout << "Brand: ";
    in.getline(brand, 100);
    if (obj.brand != NULL)
        delete[] obj.brand;
    obj.brand = new char[strlen(brand) + 1];
    strcpy(obj.brand, brand);

    cout << "Rating: ";
    in >> obj.rating;

    char tip[100];
    cout << "Tip Aroma: ";
    in.get();
    in.getline(tip, 100);
    if (obj.tipAroma != NULL)
        delete[] obj.tipAroma;
    obj.tipAroma = new char[strlen(tip) + 1];
    strcpy(obj.tipAroma, tip);

    cout << "In Stoc: ";
    char boolVal[2];
    in >> boolVal;
    obj.inStoc = strcmp(boolVal, "da") == 0;

    cout << "Pret: ";
    in >> obj.pret;

    return in;
};

// initializarea variabilei statice 

int Parfum::PARFCONT = 0;

class Angajat
{
protected:
    static int ANGCONT;
    const int idAngajat;
    string nume;
    string post;
    bool inActivitate;
    float salariuLunar;

public:
    // constructor fara parametrii
    Angajat() : idAngajat(ANGCONT++)
    {
        nume =  "anonim";
        post = "anonim";
        inActivitate = false;
        salariuLunar = 0;
    }

    // constructor cu toti parametrii

    Angajat(string nume, string post, bool inActivitate, float salariuLunar)
        : idAngajat(ANGCONT++), inActivitate(inActivitate),
          salariuLunar(salariuLunar), nume(nume), post(post)
    {
    }

    // constructori cu cativa parametrii
    Angajat(string nume, bool inActivitate, float salariuLunar)
        : idAngajat(ANGCONT++), inActivitate(inActivitate),
          salariuLunar(salariuLunar), nume(nume)
    {
        post =  "anonim";
    }

    Angajat(char *nume, bool inActivitate)
        : idAngajat(ANGCONT++), inActivitate(inActivitate), nume(nume)
    {
        post =  "anonim";
        salariuLunar = 0;
    }

    Angajat(string nume, string post) : idAngajat(ANGCONT++), nume(nume), post(post)
    {
        salariuLunar = 0;
    }

    // constructor de copiere
    Angajat(const Angajat &a)
        : idAngajat(a.idAngajat), inActivitate(a.inActivitate),
          salariuLunar(a.salariuLunar)
    {
        this->nume =  a.nume;
        this->post = a.post;
    }

    // destructor

    ~Angajat()
    {
   
    }

    // setteri
    void setNume(const string &name)
    {
        nume = name;
    }

    void setPost(const string &job)
    {
        post = job;
    }

    void setInActivitate(bool activ) { inActivitate = activ; }

    void setSalariuLunar(float salary) { salariuLunar = salary; }

    // getteri
    int getIdAngajat() { return idAngajat; }

    string getNume() { return nume; }

    string getPost() { return post; }

    bool getInActivitate() { return inActivitate; }

    float getSalariuLunar() { return salariuLunar; }

    // functionalitate - estimarea salariului pentru angajatii activi peste un nr de luni,
    // stiind cu cat creste salariul lunar

    float salariuEstimat(int nrLuni, float crestereLunara)
    {
        if (this->inActivitate == true)
        {
            float salEstim = 0.0;
            float salCresc = this->salariuLunar;

            for (int i = 0; i < nrLuni; i++)
            {
                salCresc *= crestereLunara;
                salEstim += salCresc;
            }

            return salEstim;
        }

        return 0;
    }

    // supraincarcare operator = pentru Angajat

    Angajat &operator=(const Angajat &obj)
    {
        if (this != &obj)
        {

        

            this->nume = obj.nume;

            this->post =  obj.post;

            this->inActivitate = obj.inActivitate;
            this->salariuLunar = obj.salariuLunar;
        }
        return *this;
    }

    friend ostream &operator<<(
        ostream &,
        const Angajat
            &); // const rezolva eroarea de identificare membrii private pt parfum
                // - pt ca nu vrem ca friend sa modifice membrii private
    friend istream &operator>>(istream &, Angajat &);

    // supraincarcarea operatorului [] pentru angajat

    int operator[](int index)
    {
        switch (index)
        {
        case 0:
            return idAngajat;
        case 1:
            return this->nume.length();
        case 2:
            return this->post.length();
        case 3:
            return inActivitate;
        case 4:
            return salariuLunar;
        default:
            throw runtime_error("Index invalid");
        }
    }

  
};


// initializare variabila statica

int Angajat::ANGCONT = 0;

// supraincarcarea operatorului << pentru angajat

ostream &operator<<(ostream &out, const Angajat &obj)
{
    out << "ID Angajat: " << obj.idAngajat << endl;
    out << "Nume: " << obj.nume << endl;
    out << "In Activitate: " << std::boolalpha << obj.inActivitate << endl;
    out << "Salariu: " << obj.salariuLunar << endl;
    out << endl;
    return out;
}

// supraincarcarea operatorului >> pentru Angajat

istream &operator>>(istream &in, Angajat &obj)
{
    // id ul apare la crearea obiectului

    cout << "Nume: ";
    in >> obj.nume;

    cout << "Post: ";
    in >> obj.post;

    cout << "In Activitate: ";

    char boolVal[2];
    in >> boolVal;
    obj.inActivitate = strcmp(boolVal, "da") == 0;

    cout << "Salariu Lunar: ";
    in >> obj.salariuLunar;

    return in;
}

class Vanzare
{
protected: //pt mostenire
    static int VANZCONT;
    const int idVanzare;
    int idAngajat;
    string numeClient;
    double sumaTotala;
    int numarAchizitii;
    int *listaIdCumparaturi;

public:
    // constructor fara parametrii
    Vanzare() : idVanzare(VANZCONT++)
    {
        idAngajat = 0;
        numeClient = "anonim";
        sumaTotala = 0;
        numarAchizitii = 0;
        listaIdCumparaturi = new int[numarAchizitii];
    }

    // constructor cu toti parametrii

    Vanzare(int idAngajat, string numeClient, double sumaTotala,
            int numarAchizitii, int *listaIdCumparaturi)
        : idVanzare(VANZCONT++), idAngajat(idAngajat), sumaTotala(sumaTotala),
          numarAchizitii(numarAchizitii), numeClient(numeClient)
    {
        this->listaIdCumparaturi = new int[numarAchizitii];
        for (int i = 0; i < numarAchizitii; i++)
            this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
    }

    // constructori cu unii parametrii

       Vanzare(string numeClient, double sumaTotala,
            int numarAchizitii, int *listaIdCumparaturi)
        : idVanzare(VANZCONT++), numeClient(numeClient), sumaTotala(sumaTotala),
          numarAchizitii(numarAchizitii)
    {
        idAngajat = 0;
        this->listaIdCumparaturi = new int[numarAchizitii];
        for (int i = 0; i < numarAchizitii; i++)
            this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
    }

    Vanzare(string numeClient, int idAngajat, double sumaTotala, int numarAchizitii,
            int *listaIdCumparaturi)
        : idVanzare(VANZCONT++), idAngajat(idAngajat), numeClient(numeClient),sumaTotala(sumaTotala),
          numarAchizitii(numarAchizitii)
    {

        this->listaIdCumparaturi = new int[numarAchizitii];
        for (int i = 0; i < numarAchizitii; i++)
            this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
    }

    Vanzare(int idAngajat, string numeClient, int numarAchizitii,
            int *listaIdCumparaturi)
        : idVanzare(VANZCONT++), idAngajat(idAngajat),
          numarAchizitii(numarAchizitii), numeClient(numeClient)
    {
        this->sumaTotala = 0;
        this->listaIdCumparaturi = new int[numarAchizitii];
        for (int i = 0; i < numarAchizitii; i++)
            this->listaIdCumparaturi[i] = listaIdCumparaturi[i];
    }

    // constructor de copiere

    Vanzare(const Vanzare &a)
        : idVanzare(a.idVanzare), idAngajat(a.idAngajat),
          sumaTotala(a.sumaTotala), numarAchizitii(a.numarAchizitii), numeClient(a.numeClient)
    {
        this->listaIdCumparaturi = new int[numarAchizitii];
        for (int i = 0; i < numarAchizitii; i++)
            this->listaIdCumparaturi[i] = a.listaIdCumparaturi[i];
    }

    // destructor

    ~Vanzare()
    {

        if (this->listaIdCumparaturi != NULL)
            delete[] this->listaIdCumparaturi;
    }
    // setteri

    void setidAngajat(int id) { idAngajat = id; }

    void setNumeClient(const string &nume)
    {
       numeClient = nume;
    }

    void setSumaTotala(double total) { sumaTotala = total; }

    void setNumarAchizitii(int num) { numarAchizitii = num; }

    void setListaIdCumparaturi(int *list, int dim)
    {
        delete[] listaIdCumparaturi;

        listaIdCumparaturi = new int[dim];
        for (int i = 0; i < dim; ++i)
        {
            listaIdCumparaturi[i] = list[i];
        }
    }

    // getteri

    int getIdVanzare() { return idVanzare; }

    int getIdAngajat() { return idAngajat; }

    double getSumaTotala() { return sumaTotala; }

    int *getListaIdCumparaturi() { return listaIdCumparaturi; }

    // functionalitate

    bool
    parfumCumparat(vector<Parfum> parfumes) // verifica daca parfumurile dintr o
                                            // lista au fost comparate
    {
        bool peLista = false;
        for (auto parfume : parfumes)
        {
            peLista = false;
            for (int i = 0; i < numarAchizitii; i++)
                if (parfume.getIdParfum() == listaIdCumparaturi[i])
                    peLista = true;
            if (!peLista)
                return false;
        }
        return peLista;
    }

    // virtualizare
     virtual void asteptareComanda() const {
        cout << "Nume Client: " << numeClient << endl;
        cout << "Suma Totala: " << sumaTotala << endl;
        cout << "Numar Achizitii: " << numarAchizitii << endl;
        cout << "Lista ID Cumparaturi: ";
        for (int i = 0; i < numarAchizitii; ++i) {
            cout << listaIdCumparaturi[i] << " ";
        }

        cout << "Durata de astpetare: ";
        cout << endl;
    }

    // supraincarcare operator = pentru Vanzare

    Vanzare &operator=(const Vanzare &obj)
    {
        if (this != &obj)
        {

            this->idAngajat = obj.idAngajat;
            this->sumaTotala = obj.sumaTotala;
            this->numarAchizitii = obj.numarAchizitii;


            this->numeClient = obj.numeClient;

            if (this->listaIdCumparaturi != NULL)
                delete[] this->listaIdCumparaturi;

            this->listaIdCumparaturi = new int[numarAchizitii];
            for (int i = 0; i < numarAchizitii; i++)
                this->listaIdCumparaturi[i] = obj.listaIdCumparaturi[i];
        }

        return *this;
    }

    friend ostream &operator<<(
        ostream &,
        const Vanzare
            &); // const rezolva eroarea de identificare membrii private pt parfum
                // - pt ca nu vrem ca friend sa modifice membrii private
    friend istream &operator>>(istream &, Vanzare &);

    // supraincarcarea operatorului [] pentru Vanzare

    int operator[](int index)
    {
        if (index >= 0 && index < numarAchizitii)
            return this->listaIdCumparaturi[index];
        else
            throw runtime_error("Index invalid");
    }

    // supraincarcarea operatorilor -- la stanga si dreapta pentru Vanzare

    Vanzare &operator--() /// pre-incrementare
    {
        this->sumaTotala -= 100;
        this->numarAchizitii--;

        int *listID = new int[this->numarAchizitii];

        for (int i = 0; i < this->numarAchizitii; i++)
            listID[i] = listaIdCumparaturi[i];
        delete[] listaIdCumparaturi;

        listaIdCumparaturi = new int[this->numarAchizitii];
        for (int i = 0; i < this->numarAchizitii; i++)
            listaIdCumparaturi[i] = listID[i];

        delete[] listID;

        return *this;
    }

    Vanzare operator--(
        int) /// post-incrementare, mics de pret/nr prod, int anunta post inc
    {
        Vanzare copie = *this; // this e pointer, * sa fie obiect
        copie.numarAchizitii--;
        copie.sumaTotala -= 100;

        delete[] copie.listaIdCumparaturi;

        copie.listaIdCumparaturi = new int[copie.numarAchizitii];

        for (int i = 0; i < copie.numarAchizitii; i++)
            copie.listaIdCumparaturi[i] = this->listaIdCumparaturi[i];

        return copie;
    }

    /// OPERATORUL +, * cu un int in dreapta


};

// supraincarcarea la stanga a operatorului + pentru un obiect din Vanzare si un obiect din Angajat

// supraincarcarea operatorului << pentru Vanzare

ostream &operator<<(ostream &out, const Vanzare &obj)
{
    out << "ID Vanzare: " << obj.idVanzare << endl;
    out << "ID Client: " << obj.idAngajat << endl;
    out << "Nume: " << obj.numeClient << endl;
    out << "Suma Totala: " << obj.sumaTotala << endl;
    out << "Numar Achizitii: " << obj.numarAchizitii << endl;
    out << "ID Achizitii: " << endl;

    for (int i = 0; i < obj.numarAchizitii; i++)
        out << obj.listaIdCumparaturi[i] << " ";
    out << endl;
    return out;
}

// supraincarcarea operatorului >> pentru Vanzare

istream &operator>>(istream &in, Vanzare &obj)
{
    // id ul apare la crearea obiectului
    cout << "Id Angajat: ";
    in >> obj.idAngajat;

    char nume[100];
    cout << "Nume Client: ";
    in >> obj.numeClient;

    cout << "Suma: ";
    in >> obj.sumaTotala;
    cout << "Nr Achizitii: ";
    in >> obj.numarAchizitii;

    cout << "ID Achizitii: " << endl;
    obj.listaIdCumparaturi = new int[obj.numarAchizitii];
    for (int i = 0; i < obj.numarAchizitii; i++)
        in >> obj.listaIdCumparaturi[i];

    return in;
}

// initalizare variabila statica

int Vanzare::VANZCONT = 0;

//////////////////////////

// Derived class VanzareOnline
class VanzareOnline : public Vanzare {
private:
    string adresaLivrare;
    string modalitPlata;
    string dataComanda;

public:
    
    VanzareOnline():Vanzare() /// Daca nu chem constructorul din parinte, e chemat automat cel FARA PARAMETRI
    {
        this->adresaLivrare="Oras/Strada/Numar";
        this->modalitPlata="card";
        this->dataComanda="dd/mm/yyyy";
    }
    VanzareOnline(string numeClient, double sumaTotala,
            int numarAchizitii, int* listaIdCumparaturi, string adresaLivrare, string modalitPlata, string dataComanda):Vanzare(numeClient, sumaTotala,
            numarAchizitii, listaIdCumparaturi)
    {
        this->adresaLivrare=adresaLivrare;
        this->modalitPlata=modalitPlata;
        this->dataComanda=dataComanda;
    }

    VanzareOnline(const VanzareOnline &obj):Vanzare(obj)  ///Daca nu pun nimic, ia constructorul default, in cazul meu face up-cast
    {
        this->adresaLivrare=adresaLivrare;
        this->modalitPlata=modalitPlata;
        this->dataComanda=dataComanda;
    }

    VanzareOnline& operator = (const VanzareOnline &obj)
    {
        if(this!=&obj)
        {
            Vanzare::operator=(obj);
            this->adresaLivrare=adresaLivrare;
            this->modalitPlata=modalitPlata;
            this->dataComanda=dataComanda;
        }
        return *this;
    }

    friend istream& operator >> (istream &in, VanzareOnline &obj)
    {
        cout<<"Vanzare: ";
        in>>(Vanzare&)obj;

        cout << "Adresa Livrare: ";
        in >> obj.adresaLivrare;

        cout << "Modalitate Plata: ";
        in >> obj.modalitPlata;

        cout<< "Data Comanda: ";
        in>>obj.dataComanda;

        return in;
    }
    friend ostream& operator << (ostream &out,const VanzareOnline &obj)
    {
        out<<(Vanzare&)obj;
        
        out << "Adresa Livrare: " << obj.adresaLivrare;

        out << "Modalitate Plata: " << obj.modalitPlata;

        out<< "Data Comanda: " << obj.dataComanda;
        return out;
    }

      void asteptareComanda() const override {
       
        Vanzare::asteptareComanda();
        cout << "Timp de asteptare estimat pentru livrare la adresa: '" << adresaLivrare << "': ";
        if (modalitPlata == "card") {
            cout << "1-2 zile lucratoare." << endl;
        } else {
            cout << "3-5 zile lucratoare." << endl;
        }
    }

     ~VanzareOnline() 
     { //string sterge singur memorie 
     }

};

class InventarMagazin
{
protected:
    int numarTipParfumuri;
    int *listaIdParfumuri;
    int *bucatiInStoc;
private:
    bool perioadaPromotie;
    float profitTotal;

public:
    // constructor fara parametrii
    InventarMagazin()
    {
        numarTipParfumuri = 0;
        listaIdParfumuri = new int[numarTipParfumuri];
        bucatiInStoc = new int[numarTipParfumuri];
        perioadaPromotie = false;
        profitTotal = 0.0;
    }

    // constructor cu toti parametrii
    InventarMagazin(int numarParfumuri, int *listaIdParfumuri, int *bucatiInStoc,
                    bool perioadaPromotie, float profit)
        : numarTipParfumuri(numarParfumuri), perioadaPromotie(perioadaPromotie),
          profitTotal(profit)
    {

        this->listaIdParfumuri = new int[numarParfumuri];
        for (int i = 0; i < numarParfumuri; ++i)
            this->listaIdParfumuri[i] = listaIdParfumuri[i];

        this->bucatiInStoc = new int[numarTipParfumuri];
        for (int i = 0; i < numarTipParfumuri; ++i)
            this->bucatiInStoc[i] = bucatiInStoc[i];
    }

    // constructori cu cativa parametrii

    InventarMagazin(int numarParfumuri, int *listaIdParfumuri, int *bucatiInStoc,
                    float profit)
        : numarTipParfumuri(numarParfumuri), profitTotal(profit)
    {

        this->perioadaPromotie = false;

        this->listaIdParfumuri = new int[numarParfumuri];
        for (int i = 0; i < numarParfumuri; ++i)
            this->listaIdParfumuri[i] = listaIdParfumuri[i];

        this->bucatiInStoc = new int[numarTipParfumuri];
        for (int i = 0; i < numarTipParfumuri; ++i)
            this->bucatiInStoc[i] = bucatiInStoc[i];
    }

    InventarMagazin(int numarParfumuri, int *listaIdParfumuri, int *bucatiInStoc)
        : numarTipParfumuri(numarParfumuri)
    {

        this->perioadaPromotie = false;
        this->profitTotal = 0.0;

        this->listaIdParfumuri = new int[numarParfumuri];
        for (int i = 0; i < numarParfumuri; ++i)
            this->listaIdParfumuri[i] = listaIdParfumuri[i];

        this->bucatiInStoc = new int[numarTipParfumuri];
        for (int i = 0; i < numarTipParfumuri; ++i)
            this->bucatiInStoc[i] = bucatiInStoc[i];
    }

    // constructor de copiere

    InventarMagazin(const InventarMagazin &obj)
        : numarTipParfumuri(obj.numarTipParfumuri),
          perioadaPromotie(obj.perioadaPromotie), profitTotal(obj.profitTotal)
    {

        this->listaIdParfumuri = new int[obj.numarTipParfumuri];
        for (int i = 0; i < obj.numarTipParfumuri; ++i)
            this->listaIdParfumuri[i] = obj.listaIdParfumuri[i];

        this->bucatiInStoc = new int[numarTipParfumuri];
        for (int i = 0; i < numarTipParfumuri; ++i)
            this->bucatiInStoc[i] = obj.bucatiInStoc[i];
    }
    // destructor
    ~InventarMagazin()
    {
        if (this->listaIdParfumuri != NULL)
            delete[] this->listaIdParfumuri;
        if (this->bucatiInStoc != NULL)
            delete[] this->bucatiInStoc;
    }

    // setteri
    void setNumarTipParfumuri(int numarParfumuri)
    {
        numarTipParfumuri = numarParfumuri;
    }

    void setListaIdParfumuri(int *lista, int dim)
    {
        delete[] listaIdParfumuri;

        listaIdParfumuri = new int[dim];
        for (int i = 0; i < dim; ++i)
        {
            listaIdParfumuri[i] = lista[i];
        }
    }

    void setBucatiInStoc(int *listBucInStoc, int dim)
    {
        delete[] bucatiInStoc;

        listaIdParfumuri = new int[dim];
        for (int i = 0; i < dim; ++i)
        {
            listaIdParfumuri[i] = listBucInStoc[i];
        }
    }

    void setPerioadaPromotie(bool perioadaPromotie)
    {
        this->perioadaPromotie = perioadaPromotie;
    }

    void setProfitTotal(float profitTotal) { this->profitTotal = profitTotal; }

    // getteri

    int getNumarTipParfumuri() { return numarTipParfumuri; }

    int *getListaIdParfumuric() { return listaIdParfumuri; }

    int *getBucatiInStoc() { return bucatiInStoc; }

    bool getPerioadaPromotie() { return perioadaPromotie; }

    float getProfitTotal() { return profitTotal; }

    // functionalitate
    // returneaza cate bucati dintr un anumit parfum sunt in inventar

    int bucatiInventar(Parfum p)
    {
        for (int i = 0; i < numarTipParfumuri; ++i)
        {
            if (p.getIdParfum() == listaIdParfumuri[i])
                return bucatiInStoc[i];
        }
        return 0;
    }

    // supraincarcarea operatorilor = pentru InventarMagazin

    InventarMagazin &operator=(const InventarMagazin &obj)
    {
        if (this != &obj)
        {

            this->numarTipParfumuri = obj.numarTipParfumuri;
            this->perioadaPromotie = obj.perioadaPromotie;
            this->profitTotal = obj.profitTotal;

            if (this->listaIdParfumuri != NULL)
                delete[] this->listaIdParfumuri;

            this->listaIdParfumuri = new int[obj.numarTipParfumuri];
            for (int i = 0; i < numarTipParfumuri; i++)
                this->listaIdParfumuri[i] = obj.listaIdParfumuri[i];

            if (this->bucatiInStoc != NULL)
                delete[] this->bucatiInStoc;

            this->bucatiInStoc = new int[obj.numarTipParfumuri];
            for (int i = 0; i < numarTipParfumuri; i++)
                this->bucatiInStoc[i] = obj.bucatiInStoc[i];
        }

        return *this;
    }

    friend ostream &
    operator<<(ostream &,
               const InventarMagazin
                   &); // const rezolva eroarea de identificare membrii private pt
                       // parfum
                       // - pt ca nu vrem ca friend sa modifice membrii private
    friend istream &operator>>(istream &, InventarMagazin &);

    // supraincarcarea operatorului [] pentru InventarMagazin

    int operator[](int index)
    {
        if (index >= 0 && index < numarTipParfumuri)
            return this->listaIdParfumuri[index];
        else
            throw runtime_error("Index invalid");
    }

    // supraincarcarea operatorilor -- la stanga si dreapta pentru InventarMagazin

    InventarMagazin &operator--() /// pre-incrementare
    {
        for (int i = 0; i < numarTipParfumuri; i++)
            if (bucatiInStoc[i] > 0)
                bucatiInStoc[i]--;

        return *this;
    }

    InventarMagazin operator--(int) /// post-incrementare, micsorare de pret/nr Vanzaree
    {
        InventarMagazin copie = *this; // this e pointer pentru ca * sa fie obiect
        for (int i = 0; i < numarTipParfumuri; i++)
            if (copie.bucatiInStoc[i] > 0)
                copie.bucatiInStoc[i]--;
        return copie;
    }

    /// OPERATORUL +, * doua obiecte de tip InventarMagazin
    friend InventarMagazin operator+(InventarMagazin, InventarMagazin);
    friend InventarMagazin operator*(InventarMagazin, InventarMagazin);

    /// CAST la float pentru InventarMagazin
    operator float() // implicit
    {
        return this->profitTotal;
    }

    // supraincarcarea operatorului < si == pentru doua obiecte din InventarMagazin
    bool operator<(const InventarMagazin &obj)
    {
        return profitTotal < obj.profitTotal;
    }

    bool operator==(const InventarMagazin &obj)
    {
        return profitTotal == obj.profitTotal;
    }
};

// supraincarcarea operatorului * pentru doua obiecte din InventarMagazin

InventarMagazin operator*(InventarMagazin obj1, InventarMagazin obj2)
{
    for (int i = 0; i < obj1.numarTipParfumuri; i++)
        obj1.bucatiInStoc[i] *= obj2.bucatiInStoc[i];

    return obj1;
}

// supraincarcarea operatorului + pentru doua obiecte din InventarMagazin

InventarMagazin operator+(InventarMagazin obj1, InventarMagazin obj2)
{
    for (int i = 0; i < obj1.numarTipParfumuri; i++)
        obj1.bucatiInStoc[i] += obj2.bucatiInStoc[i];

    return obj1;
}

// supraincarcarea operatorului << pentru InventarMagazin

ostream &operator<<(ostream &out, const InventarMagazin &obj)
{
    out << "Numar Parfumuri: " << obj.numarTipParfumuri << endl;
    out << "Perioada Promotie: " << obj.perioadaPromotie << endl;
    out << "Total Profit: " << obj.profitTotal << endl;
    out << "Lista ID Parfumuri si bucati in stoc: " << endl;

    for (int i = 0; i < obj.numarTipParfumuri; i++)
        out << obj.listaIdParfumuri[i] << " " << obj.bucatiInStoc[i] << endl;

    out << endl;
    return out;
}

// supraincarcarea operatorului >> pentru InventarMagazin

istream &operator>>(istream &in, InventarMagazin &obj)
{
    cout << "Numar Parfumuri: ";
    in >> obj.numarTipParfumuri;
    cout << "Perioada Promotie: ";

    char boolVal[2];
    in >> boolVal;
    obj.perioadaPromotie = strcmp(boolVal, "da") == 0;
    cout << "Total Profit: ";
    in >> obj.profitTotal;

    if (obj.bucatiInStoc != NULL)
        delete[] obj.bucatiInStoc;
    if (obj.listaIdParfumuri != NULL)
        delete[] obj.listaIdParfumuri;

    cout << "Lista ID Parfumuri bucati in stoc: " << endl;
    obj.listaIdParfumuri = new int[obj.numarTipParfumuri];
    obj.bucatiInStoc = new int[obj.numarTipParfumuri];

    for (int i = 0; i < obj.numarTipParfumuri; i++)
        in >> obj.listaIdParfumuri[i] >> obj.bucatiInStoc[i];

    return in;
}




//////////////////////////
class VanzareInMagazin : public Vanzare, public InventarMagazin{
private:
    bool clientFidel;
    static int ORDCONT;
    const int numarOrdine;
    bool testereGratuite;

public:
    VanzareInMagazin()
        : Vanzare(), InventarMagazin(), clientFidel(false), testereGratuite(false), numarOrdine(++ORDCONT){}

    VanzareInMagazin(bool clientFidel, bool testereGratuite,
                      int idAngajat, 
                     string numeClient, double sumaTotala, int numarAchizitii, int* listaIdCumparaturi,  int numarTipParfumuri,
	    int *listaIdParfumuri,
	    int *bucatiInStoc)
        : Vanzare(idAngajat, numeClient, numarAchizitii, listaIdCumparaturi),
          clientFidel(clientFidel), numarOrdine(++ORDCONT), testereGratuite(false), InventarMagazin(numarTipParfumuri, listaIdParfumuri, bucatiInStoc){}


    VanzareInMagazin(const VanzareInMagazin &obj)
        : Vanzare(obj), InventarMagazin(obj),
          clientFidel(obj.clientFidel), numarOrdine(obj.numarOrdine) {}

    
    VanzareInMagazin& operator = (const VanzareInMagazin &obj)
    {
        if(this!=&obj)
        {
            Vanzare::operator=(obj);
            InventarMagazin::operator=(obj);
            this->clientFidel=obj.clientFidel;
            this->testereGratuite=obj.testereGratuite;
        }
        return *this;
    }

    friend istream& operator >> (istream &in, VanzareInMagazin &obj)
    {
        cout<<"Vanzare: ";
        in>>(Vanzare&)obj;

        cout<<"Inventar Magazin: ";
        in>>(InventarMagazin&)obj;

        cout << "Clinet Fidel: ";
        in >> obj.clientFidel;

        cout << "Testere Gratis: ";
        in >> obj.testereGratuite;

        return in;
    }
    friend ostream& operator << (ostream &out,const VanzareInMagazin &obj)
    {
        out<<(Vanzare&)obj;
        out << (InventarMagazin&)obj;
        
        out << "Clinet Fidel: " << obj.clientFidel;

        out << "Testere Gratis: " << obj.testereGratuite;
        return out;
    }
    
      void asteptareComanda() const override {
        // Assuming a simple estimation for queue time based on customer loyalty
        Vanzare::asteptareComanda();
        cout << "Timp de asteptare estimat la coada: ";
        if (clientFidel) {
            cout << numarOrdine*numarAchizitii << " minute." << endl;
        } else {
            cout << numarOrdine*numarAchizitii*2 << " minute." << endl;
        }
    }


    ~VanzareInMagazin() {
        // No dynamic memory to release in this class
    }

  
};

//TRANSF CHAR* IN STERING SI FAC CONSTR COMPLET BINE

int VanzareInMagazin::ORDCONT = 0;
//////////////////////////

int main()
{

    vector<Parfum> parfumuri;
    vector<Angajat> angajati;
    vector<Vanzare> vanzari;
    vector<InventarMagazin> inventare;

    bool inMeniu = true;
    // meniul interactiv pentru functionalitati de baza si functia specifica fiecarei clase
    while (inMeniu)
    {
        int comanda;
        cout << "Bine ati venit! Alegeti optiuni: \n 1: Creare - 2: Read - 3: Update - 4: Delete - 5: Apel functii \n 6: Inapoi la meniu - 7: Quit \n";
        cin >> comanda;

        // in functie de comanda putem inchide meniul sau sa ne intoarcem la comenzile de baza

        switch (comanda)
        {
        case 6:
            break;
        case 7:
            inMeniu = false;
            break;
        case 1:
        {   // utilizatorul alege ce doreste sa creeze (obiect)
            int alegere = 0;
            cout << "Alegeti optiuni: \n 1: Creare parfum, 2: Creare Angajat, 3: Creare Vanzare, 4: Creare Inventar \n 5: Inapoi la meniu - 6: Quit \n";
            cin >> alegere;
            switch (alegere)
            {
            case 1:
            {
                Parfum p;
                cin >> p;
                parfumuri.push_back(p);
                break;
            }
            case 2:
            {
                Angajat a;
                cin >> a;
                angajati.push_back(a);
                break;
            }
            case 3:
            {
                Vanzare v;
                cin >> v;
                vanzari.push_back(v);
                break;
            }
            case 4:
            {
                InventarMagazin i;
                cin >> i;
                inventare.push_back(i);
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                inMeniu = false;
                break;
            }
            default:
                break;
            }

            break;
        }
        case 2:
        {
             // utilizatorul alege ce doreste sa citeasca (obiect)
            int alegere = 0;
            cout << "Read optiuni: \n 1: Read Parfumuri, 2: Read Angajati, 3: Read Vanzari, 4: Read Inventare \n 5: Inapoi la meniu - 6: Quit \n";
            cin >> alegere;
            switch (alegere)
            {
            case 1:
            {
                for (auto parfum : parfumuri)
                    cout << parfum;
                break;
            }
            case 2:
            {
                for (auto angajat : angajati)
                    cout << angajat;
                break;
            }
            case 3:
            {
                for (auto vanzare : vanzari)
                    cout << vanzare;
                break;
            }
            case 4:
            {
                for (auto inventar : inventare)
                    cout << inventar;
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                inMeniu = false;
                break;
            }
            default:
                break;
            }

            break;
        }
        case 3:
        {    // utilizatorul alege ce doreste sa modifice (obiect)
            int alegere = 0, index;
            cout << "Update optiuni: \n 1: Update parfum, 2: Update Angajat, 3: Update Vanzare, 4: Update Inventar \n 5: Inapoi la meniu - 6: Quit \n";
            cin >> alegere;
            
            if (alegere < 5)
            {
                cout << "Introduceti index: \n";
                cin >> index;
            }
            switch (alegere)
            {
            case 1:
            {
                Parfum p;
                cin >> p;
                parfumuri[index] = p;
                break;
            }
            case 2:
            {
                Angajat a;
                cin >> a;
                angajati[index] = a;
                break;
            }
            case 3:
            {
                Vanzare v;
                cin >> v;
                vanzari[index] = v;
                break;
            }
            case 4:
            {
                InventarMagazin i;
                cin >> i;
                inventare[index] = i;
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                inMeniu = false;
                break;
            }
            default:
                break;
            }

            break;
        }
        case 4:
        {
             // utilizatorul alege ce doreste sa stearga (obiect)
            int alegere = 0, index;
            cout << "Delete optiuni: \n 1: Delete parfum, 2: Delete Angajat, 3: Delete Vanzare, 4: Delete Inventar \n 5: Inapoi la meniu - 6: Quit \n";
            cin >> alegere;
            if (alegere < 5)
            {
                cout << "Introduceti index: \n";
                cin >> index;
            }
            switch (alegere)
            {
            case 1:
            {
                parfumuri.erase(parfumuri.begin() + index);
                break;
            }
            case 2:
            {
                angajati.erase(angajati.begin() + index);
                break;
            }
            case 3:
            {
                vanzari.erase(vanzari.begin() + index);
                break;
            }
            case 4:
            {
                inventare.erase(inventare.begin() + index);
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                inMeniu = false;
                break;
            }
            default:
                break;
            }

            break;
        }
        case 5:
        {   // utilizatorul alege ce functie doreste sa apeleze
            int alegere = 0;
            cout << "Functii: \n 1: Cand avem parfumuri in stoc, 2: Estimare salarii, 3: Ce parfumuri contine fiecare vanzare, 4: Cate parfumuri am in fiecare inventar \n 5: Inapoi la meniu - 6: Quit \n";
            cin >> alegere;
            switch (alegere)
            {
            case 1:
            {
                for (auto p : parfumuri)
                {
                    cout << p.getNumeParfum() << " ";
                    p.perioadaDeVarf();
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                for (auto a : angajati)
                {
                    int nrLuni;
                    float crestere;
                    cout << "Introduceti numarul de luni si cresterea pe luna a salariului: \n";
                    cin >> nrLuni >> crestere;
                    cout << a.getNume() << " ";
                    cout << "Salariu estimat: " << a.salariuEstimat(nrLuni, crestere) << endl;
                }
                break;
            }
            case 3:
            {
                for (auto v : vanzari)
                {
                    int nrParfumuri, poz;
                    vector<Parfum> p2;
                    cout << "Vanzare: " << v.getIdVanzare() << endl;
                    cout << "Introduceti cate parfumuri se cauta si indexurile parfumurilr de cautat: \n";
                    cin >> nrParfumuri;
                    for (int i = 0; i < nrParfumuri; i++)
                    {
                        cin >> poz;
                        p2.push_back(parfumuri[poz]);
                    }

                    cout << "Vanzare " << v.getIdVanzare() << ": parufumurile ";
                    if (v.parfumCumparat(p2) == true)
                        cout << "sunt pe bon";
                    else
                        cout << " nu sunt pe bon";
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                for (auto i : inventare)
                    for (auto p : parfumuri)
                        cout << "Parfumul " << p.getNumeParfum() << " apare de " << i.bucatiInventar(p) << " ori in inventarul curent" << endl;
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                inMeniu = false;
                break;
            }
            default:
                break;
            }

            break;
        }
        }
    }

    return 0;
}

