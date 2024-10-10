#include <iostream>

using namespace std;

struct CoordonateGPS {
    int latitudine;
    int longitudine;
    float altitudine;
    string locatie;
};

void afisareCoordonateGPS(CoordonateGPS l) {
    cout<< "Latitudine: " << l.latitudine << endl;
    cout<< "Longitudine: " << l.longitudine << endl;
    cout<< "Altitudine: " << l.altitudine << endl;
    cout<< "Locatie: " << l.locatie << endl;
}

void modificaAltitudine(CoordonateGPS *l, float nouaAltitudine){
    l->altitudine=nouaAltitudine; //-> = dereferentiere+accesare
}

void modificaAltitudineRef(CoordonateGPS& l, float nouaAltitudine){
    l.altitudine=nouaAltitudine;
}

CoordonateGPS initializareCoordonate(int latitudine, int longitudine, float altitudine, string locatie){
    CoordonateGPS l;
    l.latitudine=latitudine;
    l.longitudine=longitudine;
    l.altitudine=altitudine;
    l.locatie=locatie;
    return l;
}

int main(){
    CoordonateGPS l;
    l.latitudine=46;
    l.longitudine=22;
    l.altitudine=1010;
    l.locatie="Predeal";
    
    afisareCoordonateGPS(l);
    
    CoordonateGPS l2;
    cout << "Introduceti latitudinea: ";
    cin >> l2.latitudine;
    cout << "Introduceti longitudinea: ";
    cin >> l2.longitudine;
    cout << "Introduceti altitudinea: ";
    cin >> l2.altitudine;
    cout << "Introduceti locatia: ";
    cin >> l2.locatie;
    
    afisareCoordonateGPS(l2);
        
    modificaAltitudine(&l2, 2000);
    
    afisareCoordonateGPS(l2);
    
    modificaAltitudineRef(l2, 3000);
    
    afisareCoordonateGPS(l2);
    
   // int a=20;
   // int* pa=&a; //pointer
   // int* p=new int(50); //aloca spatiu pentru 50 si ii da adresa lui p
    
    return 0;
}


//Funcția are (în ordine): tip returnat nume [parametri] { corp }
