#include <iostream>

using namespace std;

class Masina {
private:
    int nrRoti;
    string* producatori;
    string marca;
    float pret;
    static int TVA; //la fel pentru toate obiectele, apartine clasei
    const int anFabricatie;
public:
    
    Masina():anFabricatie(2024),nrRoti(4){
        this->marca="Dacia";
        this->pret=5000;
        this->producatori=NULL;
    }
    Masina(int _nrRoti, string marca, float pret, int an):anFabricatie(an){
        this->nrRoti=_nrRoti;
        this->marca=marca;
        this->pret=pret;
        this->producatori=new string[this->nrRoti];
        for (int i=0;i<this->nrRoti; i++){
            this->producatori[i]="Michelin";
        }
    };
    
    
    Masina(const Masina& m):anFabricatie(m.anFabricatie){
        this->nrRoti=m.nrRoti;
        this->marca=m.marca;
        this->pret=m.pret;
        this->producatori=new string[m.nrRoti];
        for(int i=0; i<m.nrRoti; i++){
            this->producatori[i]=m.producatori[i];
        }
    }
    
    Masina operator=(const Masina& m){
        if(&m!=this){
            this->nrRoti=m.nrRoti;
            this->marca=m.marca;
            this->pret=m.pret;
            if (this->producatori!=NULL){
                delete[]this->producatori;
            }
            this->producatori=new string[m.nrRoti];
            for(int i=0; i<m.nrRoti; i++){
                this->producatori[i]=m.producatori[i];
            }
        }
        return *this;
    }
    
    Masina operator+(const Masina& m)const{
        Masina temp=*this;
        temp.pret=this->pret+m.pret;
        return temp;
    }
    
    Masina operator+=(const Masina&m){
        this->pret=this->pret+m.pret;
        return *this;
    }
    
    Masina operator+(float val)const{
        Masina temp=*this;
        temp.pret=this->pret+val;
        return temp;
    }
    
    explicit operator float(){
        return calculeazaPretTotal();
    }
    
    explicit operator int(){
        return this->nrRoti;
    }
    
    string& operator[](int index){
        if (index>=0 && index<this->nrRoti){
            return this->producatori[index];
        }
        else {
            throw "Indexul este in afara limitelor";
        }
    }
    
    
    
    friend Masina operator+(float valoare, const Masina& m);
    
    ~Masina() {
        if(this->producatori!=NULL){
            delete[]this->producatori;
        }
    }
    
    string getMarca(){
        return this->marca;
    }
    
    void setMarca(string marca){
        if (marca.length()>2){
            this->marca=marca;
        }
    }

    float getPret(){
        return this->pret;
    }
    
    void setPret(float pret){
        if (pret>0){
            this->pret=pret;
        }
    }
    
    string* getProducatori(){
        return this->producatori;
    }
    
    string getProducator(int index){
        if(index >=0 && index<this->nrRoti){
            return this->producatori[index];
        }
        else{
            return "Nu a fost gasit.";
        }
    }
    
    void setNrRoti(int nrRoti, string* producatori){
        if (nrRoti>0){
            this->nrRoti=nrRoti;
            if (this->producatori!=NULL)
                delete[] this->producatori;
        }
        this->producatori=new string[this->nrRoti];
        for(int i=0; i<nrRoti; i++)
            this->producatori[i]=producatori[i];
    }
    
    void afisare(){
        cout<<"Marca: "<<this->marca<<endl;
        cout<<"Numar roti: "<<this->nrRoti<<": ";
        if (this->producatori  !=NULL){
            for(int i=0; i<this->nrRoti; i++){
                cout<<this->producatori[i]<<", ";
            }
        }
        cout<<endl;
        cout<<"Pret: "<<this->pret<<endl;
        cout<<"TVA: "<<this->TVA<<endl;
        cout<<"An fabricatie: "<<this->anFabricatie<<endl;
    }
    
    float calculeazaPretTotal(){
        return this->pret+(this->pret*TVA/100.0f);
    }
    
    static void modificaTVA(int noulTVA){
        if (noulTVA>0){
            Masina::TVA=noulTVA;
        }
    }
    
    static float calculeazaPretTotalVector(int nrMasini, Masina*vector) {
        float pretTotal=0;
        for(int i=0; i<nrMasini; i++){
            pretTotal+=vector[i].calculeazaPretTotal();
        }
        return pretTotal;
    }
    
    friend istream& operator>>(istream& istream, Masina& masina);
    friend ostream& operator<< (ostream& ostream, const Masina& masina);
};

int Masina::TVA=19;

    
istream& operator>>(istream& istream, Masina& masina){
    cout<<"Marca: ";
    istream>>masina.marca;
    cout<<endl<<"Numar roti: ";
    istream>>masina.nrRoti;
//    if(masina.nrRoti!=0){
//        delete producatori[];
//    }
    if (masina.nrRoti !=0){
        for (int i=0; i<masina.nrRoti; i++){
            cout<<"Producatorul "<<i+1<<": ";
            istream>>masina.producatori[i];
        }
    }
    else{
        masina.producatori=NULL;
    }
    cout<<endl<<"Pret: ";
    istream>>masina.pret;
    cout<<endl<<"TVA: ";
    istream>>masina.TVA;
    cout<<endl<<"An fabricatie: ";
    //istream>>masina.anFabricatie;
    return istream;
}
    
ostream& operator<< (ostream& ostream, const Masina& masina){
        ostream<<"Marca: "<<masina.marca<<endl;
        ostream<<"Numar roti: "<<masina.nrRoti<<": ";
        if (masina.producatori  !=NULL){
            for(int i=0; i<masina.nrRoti; i++){
                cout<<masina.producatori[i]<<", ";
            }
        }
        ostream<<endl;
        ostream<<"Pret: "<<masina.pret<<endl;
        ostream<<"TVA: "<<masina.TVA<<endl;
        ostream<<"An fabricatie: "<<masina.anFabricatie<<endl;
        return ostream;
}

Masina operator+(float valoare, const Masina& m){
    Masina masina=m;
    masina.pret=valoare+m.pret;
    return masina;
}

int main(){
    
    Masina m1;
    cout<<m1.getMarca()<<endl;
    m1.setMarca("Audi");
    cout<<m1.getMarca()<<endl;
    m1.afisare();
    
    Masina m2(4, "BMW", 45000, 2021);
    m2.afisare();
    cout<<endl<<endl;
    cout<<m2.getProducatori()[1]<<endl;
    
    cout<<m2.getProducator(1)<<endl;
    
    m2.setNrRoti(6, new string[6]{"Michelin","Continental","Pirelli","Bridgestone","Hankook","POO"});
    cout<<m2.getProducator(3)<<endl;
    
    Masina m3(m2);
    Masina m4=m2;
    
    cout<<m4.getProducator(2)<<endl;
    
    m4=m2;
//    m4.operator=(m2);
    
    m4= m2+m3;
//    m4.operator=(m2.operator+(m3));
    
//    m4.afisare();
    
    m4+=m2;
    
//    m4.operator=(m4.operator+(m2));
    
    m4=m2+5000.0f;
    
//    m4.operator+(5000.0f);
    
    m4=5000.0f+m2;
    
//    operator+(5000.f,m2)
    
    float pretMasina=(float)m2;
    cout<<pretMasina<<endl;
    
    int nrRoti=(int)m2;
    cout<<nrRoti<<endl;
    
    cout<<(float)m2<<endl;
    
    try{
        cout<<m2[1]<<endl;
        m2[1]="Hankook";
        cout<<m2[1]<<endl;
//        cout<<m2[-4]<<endl;
    }catch(int ex){
        
    }catch(float ex){
        
    }
    catch(const char* exceptie){
        cout<<exceptie<<endl;
    }
    catch(...){
        
    }
    
    cout << m2<<endl;
    cin>>m2;
    cout<<m2;
    
    
//tipReturnat nume(lista_parametri)
    
//    Masina m1;
//    m1.afisare();
//    
//    Masina m2(4,"Audi",7000,2020);
//    m2.afisare();
//    
//    Masina::modificaTVA(21);
//    Masina* pointer=new Masina(6,"Volvo",20000,2022);
//    pointer->afisare();
//    
//    cout<<"Pret total: "<<pointer->calculeazaPretTotal()<<endl;
//    
//    int nrMasini=3;
//    Masina* vector;
//    vector=new Masina[nrMasini];
//    
//    for(int i=0; i<nrMasini; i++){
//        //(*(vector+i)).afisare();
//        //(vector+i)->afisare();
//        vector[i].afisare();
//    }
//    
//    cout<<"Pret total flotă: "<<Masina::calculeazaPretTotalVector(nrMasini, vector)<<endl;
//    //-> - dereferentiere + accesare
//    //[] - deplasare + dereferentiere
//    
//    return 1000;
}
