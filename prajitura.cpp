#include <iostream>

using namespace std;

class Prajitura {
public:
    string nume;
    int gramaj;
    float pret;
    bool dePost;
    string ingredientDominant;
    
    
    Prajitura() {
        this->nume="Amandină";
        this->gramaj=300;
        this->pret=6.5;
        this->dePost=0;
        this->ingredientDominant="Vanilie";
    }
    
    Prajitura(string nume, int gramaj, float pret, bool dePost, string ingredientDominant){
        this->nume=nume;
        this->gramaj=gramaj;
        this->pret=pret;
        this->dePost=dePost;
        this->ingredientDominant=ingredientDominant;
    }
    
    void afisare(){ 
        cout<<"Nume prăjitură: "<<this->nume<<endl;
        cout<<"Gramaj: "<<this->gramaj<<endl;
        cout<<"Preț: "<<this->pret<<endl;
        cout<<"Este de post: ";
        if (dePost)
            cout<<"Da";
        else
            cout<<"Nu";
        cout<<endl<<"Ingredient dominant: "<<this->ingredientDominant;
        cout<<endl;
    }
    
    float pretPerKilogram() {
        cout<<"Prețul per kilogram de "<<this->nume<<" este "<<(this->pret/this->gramaj)*1000<<" lei."<<endl;
        return 0;
    }
    
    void confirmareComanda(){
        cout<<"Ați comandat prăjitura numită "<<this->nume;
        cout<<", la prețul de "<<this->pret<<" lei";
        cout<<" pentru "<<this->gramaj<<" grame. ";
        if (this->dePost)
            cout<<"Prăjitura este de post.";
        else
            cout<<"Prăjitura nu este de post.";
        cout<<endl;
    }
    
    void citirePrajitura(Prajitura &p){
        cout<<"Nume prăjitură: ";
        cin>>p.nume;
        cout<<"Gramaj: ";
        cin>>p.gramaj;
        cout<<"Preț: ";
        cin>>p.pret;
        cout<<"Este de post? (0=NU; 1=DA) ";
        cin>>p.dePost;
        cout<<"Ingredient dominant: ";
        cin>>p.ingredientDominant;
        cout<<endl;
    }
};


int main() {
    Prajitura p1;
    p1.confirmareComanda();
    p1.afisare();
    
    Prajitura p2("Negresă", 200, 5, 0,"Rom");
    p2.pretPerKilogram();
    
    
    Prajitura p3;
    p3.citirePrajitura(p3);
    p3.afisare();
    p3.pretPerKilogram();
    p3.confirmareComanda();
}
