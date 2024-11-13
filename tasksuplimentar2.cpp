#include <iostream>

using namespace std;

class Telefon{
public:
    string* contacte;
    float pret;
    int sanatateBaterie;
    int nrContacte;
    static int numarTelefoane;
    const int id;
    
    Telefon():id(++numarTelefoane){
        this->nrContacte=NULL;
        this->contacte=NULL;
        this->pret=4000;
        this->sanatateBaterie=95;
    }
    
    Telefon(int _nrContacte, float pret, int sanatateBaterie):id(++numarTelefoane){
        this->nrContacte=_nrContacte;
        this->contacte=new string[_nrContacte];
        for(int i=0; i<_nrContacte;i++){
            this->contacte[i]="Vladimir Mitroi";
        }
        this->pret=pret;
        this->sanatateBaterie=sanatateBaterie;
    }
    
    Telefon(const Telefon& t):id(++numarTelefoane){
        this->nrContacte=t.nrContacte;
        this->contacte=new string[this->nrContacte];
        for(int i=0; i<nrContacte;i++){
            this->contacte[i]=t.contacte[i];
        }
        this->pret=t.pret;
        this->sanatateBaterie=t.sanatateBaterie;
    }
    
    void afisareTelefon(){
        cout<<"Numar telefon: "<<this->id<<endl;
        if(contacte!=NULL){
            cout<<"Contacte:"<<endl;
            for (int i=0; i<nrContacte; i++){
                cout<<this->contacte[i]<<endl;
            }
        }
        else {
            cout<<"Nu exista contacte"<<endl;
        }
        cout<<"Pret: "<<this->pret<<" lei"<<endl;
        cout<<"Sanatate baterie:"<<this->sanatateBaterie<<"%"<<endl<<endl;
    }
    
    ~Telefon(){
        if (this->contacte!=NULL){
            delete[]this->contacte;
        }
    }
    
    Telefon operator=(const Telefon &t){
        if (&t!=this){
            this->nrContacte=t.nrContacte;
            for(int i=0;i<t.nrContacte;i++)
            {
                this->contacte[i]=t.contacte[i];
            }
            this->sanatateBaterie=t.sanatateBaterie;
            this->pret=t.pret;
        }
        return *this;
    }
    
    static void getNumarTelefoane(){
        cout<<"Numar total telefoane: "<<numarTelefoane<<endl<<endl;
    };
    
};

class Laptop{
private:
    string* programe;
    int numarPrograme;
    float pret;
    string producator;
    static int numarLaptop;
    const int id;
public:
    Laptop():id(++numarLaptop){
        this->numarPrograme=NULL;
        this->programe=NULL;
        this->pret=2000;
        this->producator="Lenovo";
    }
    
    Laptop(int _numarPrograme, float pret, string producator):id(++numarLaptop){
        this->numarPrograme=_numarPrograme;
        this->programe=new string[_numarPrograme];
        for (int i=0;i<_numarPrograme;i++){
            this->programe[i]="Slack";
        }
        this->pret=pret;
        this->producator="Asus";
    }
    
    Laptop(const Laptop &l):id(++numarLaptop){
        this->numarPrograme=l.numarPrograme;
        this->programe=new string[numarPrograme];
        for(int i=0;i<numarPrograme;i++){
            this->programe[i]=l.programe[i];
        }
        this->pret=l.pret;
        this->producator=l.producator;
    }
    
    Laptop operator=(const Laptop &l){
        this->numarPrograme=l.numarPrograme;
        for(int i=0;i<numarPrograme;i++){
            this->programe[i]=l.programe[i];
        }
        this->pret=l.pret;
        this->producator=l.producator;
        return *this;
    }
    
    void afisareLaptop(){
        cout<<"Numar laptop: "<<this->numarLaptop<<endl;
        cout<<"Producator: "<<this->producator<<endl;
        cout<<"Pret: "<<this->pret<<endl;
        if(numarPrograme!=0){
            cout<<"Programe: "<<endl;
            for(int i=0;i<numarPrograme;i++){
                cout<<this->programe[i]<<endl;
            }
            cout<<endl;
        }
        else {
            cout<<"Nu exista programe."<<endl<<endl;
        }
    }
    
    ~Laptop(){
        if(this->programe!=NULL){
            delete[] programe;
        }
    }
    
    static void getNumarLaptopuri(){
        cout<<"Numar laptopuri: "<<numarLaptop<<endl<<endl;
    }
    
};

class Smartwatch{
private:
    int numarCadrane;
    char* cadrane;
    string producator;
    float dimensiune;
    bool folosit;
    static int numarCeas;
    const int id;
public:
    Smartwatch():id(++numarCeas){
        this->cadrane=new char[strlen("Analog")+1];
        for(int i=0;i<numarCadrane;i++){
            strcpy(this->cadrane,"Analog");
        }
        this->producator="Samsung";
        this->dimensiune=41.8;
        this->folosit=0;
    }
    
    Smartwatch(int _numarCadrane, string producator, float dimenisune, bool folosit):id(++numarCeas){
        this->numarCadrane=_numarCadrane;
        this->cadrane=new char[strlen("Digital")+1];
        for(int i=0;i<numarCadrane;i++){
            strcpy(this->cadrane, "Digital");
        }
        this->producator=producator;
        this->dimensiune=dimenisune;
        this->folosit=folosit;
    }
    
    Smartwatch(const Smartwatch &s):id(++numarCeas){
        this->numarCadrane=s.numarCadrane;
        this->cadrane=new char[strlen(s.cadrane)+1];
        for(int i=0; i<numarCadrane;i++){
            strcpy(this->cadrane,s.cadrane);
        }
        this->producator=s.producator;
        this->dimensiune=s.dimensiune;
        this->folosit=s.folosit;
    }
    
    Smartwatch operator=(const Smartwatch &s){
        this->cadrane=s.cadrane;
        for (int i=0; i<numarCadrane; i++){
            strcpy(cadrane, s.cadrane);
        }
        this->producator=s.producator;
        this->dimensiune=s.dimensiune;
        this->folosit=s.folosit;
        return *this;
    }
    
    void afisareSmartwatch(){
        cout<<"Numar smartwatch: "<<numarCeas<<endl;
        cout<<"Producator: "<<producator<<endl;
        cout<<"Dimensiune: "<<dimensiune<<endl;
        if(cadrane!=NULL){
            cout<<"Cadrane: "<<endl;
            for(int i=0;i<numarCadrane;i++){
                cout<<this->cadrane<<endl;
            }
        }
        else{
            cout<<"Nu are cadrane salvate."<<endl;
        }
        cout<<"Folosit: ";
        if (folosit){
            cout<<"da"<<endl<<endl;
        }
        else{
            cout<<"nu"<<endl<<endl;
        }
    }
    
    ~Smartwatch(){
        if(this->cadrane!=NULL){
            delete[] cadrane;
        }
    }
    
    static void getNumarSmartwatchuri(){
        cout<<"Numar smartwatchuri: "<<numarCeas<<endl<<endl;
    }
    
};

int Smartwatch::numarCeas=0;

int Telefon::numarTelefoane=0;

int Laptop::numarLaptop=0;

int main(){
    
    Telefon::afisareNumarTelefoane();

    Telefon telefon1;
    telefon1.afisareTelefon();
    
    Telefon telefon2(4,8000,98);
    telefon2.afisareTelefon();

    Telefon telefon3(telefon2);
    telefon3.afisareTelefon();
    
    Telefon telefon4=telefon2;
    telefon4.afisareTelefon();
    
    Laptop l1;
    l1.afisareLaptop();
    
    Laptop l2(3,7999.99,"Asus");
    l2.afisareLaptop();
    
    Laptop::afisareNumarLaptopuri();
    
    Laptop l3(l2);
    l3.afisareLaptop();
    
    Laptop l4=l2;
    l4.afisareLaptop();
    
    Smartwatch::afisareNumarSmartwatchuri();
    
    Smartwatch s1;
    s1.afisareSmartwatch();
    
    Smartwatch s2(3, "Apple", 45.6, 1);
    s2.afisareSmartwatch();
    
    Smartwatch s3(s2);
    s3.afisareSmartwatch();
    
    Smartwatch s4=s2;
    s4.afisareSmartwatch();
}
