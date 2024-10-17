#include <iostream>

using namespace std;
//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru
//citirea unui vector

struct Tara {
    char* denumire;
    int nrLocuitori;
    string capitala;
    bool areIesireLaMare;
};

void afisareTara(Tara tara){
    
}

void afisarePointerLaTara(Tara* pt){
    cout<<"Nume: "<<pt->denumire<<endl;
    cout<<"Numar locuitori: "<<pt->nrLocuitori<<endl;
    cout<<"Capitala: "<<pt->capitala<<endl;
    cout<<"Are iesire la mare: "<<(pt->areIesireLaMare?"DA":"NU")<<endl;
//  if (pt->areIesireLaMare) {
//     cout << "DA" << endl;
//    }
//  else {
//        cout << "NU" << endl;
//    }
    //op ternar
}

Tara* citirePointerLaTara() {
    Tara* p = new Tara();
    cout << "Capitala: ";
    cin >> p->capitala;
    
    cout << "Denumire: ";
    char  buffer[100];
    cin >> buffer;
    p->denumire=new char[strlen(buffer)+1];
    strcpy(p->denumire,buffer);
    
    cout<<"Numar locuitori: ";
    cin>>p->nrLocuitori;
    
    cout<<"Are iesire la mare? (0=NU ; 1=DA)";
    cin>>p->areIesireLaMare;
    
    return p;
}

int main() {
    Tara tara;
    tara.areIesireLaMare=false;
    
    Tara* pTara;
    pTara=new Tara();
    pTara->areIesireLaMare=true;
    pTara->capitala="Bucuresti";
    pTara->denumire=new char[strlen("Romania")+1];
    strcpy(pTara->denumire, "Romania");
    pTara->nrLocuitori=200;
    //shallow copy = atribuim adresele si nu informatiile
    
    afisarePointerLaTara(pTara);
    
    delete []pTara->denumire;
    delete pTara;
//    Tara* p2Tara=citirePointerLaTara();
//    afisarePointerLaTara(p2Tara);
    
    Tara *vector;
    vector=new Tara[2];
    
    delete []vector;
    
    //vector de pointeri (in jos)
    
    int nrPointeri=2;
    Tara **pointeri;
    pointeri=new Tara*[nrPointeri];
    for (int i=0; i<nrPointeri; i++) {
        pointeri[i]=citirePointerLaTara();
    }
    //procesare
    for(int i=0; i<nrPointeri; i++) {
        afisarePointerLaTara(pointeri[i]);
    }
    //procesare
    
    for(int i=0; i<nrPointeri; i++) {
        delete []pointeri[i]->denumire;
        delete pointeri[i];
    }
    delete []pointeri;
    //memory leak= zona de memorie alocata care nu a fost dezalocata si nu mai avem referinta catre ea
}
