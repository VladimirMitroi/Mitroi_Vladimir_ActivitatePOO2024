#include <iostream>

using namespace std;

struct Bloc {
    string strada;
    int nrScari;
    int nrEtaje;
    int nrApartamente;
    bool areLift;
};

void afisareBloc(Bloc &b){
    cout<<" de pe strada "<<b.strada;
    cout<<" are "<<b.nrScari<<" scari, ";
    cout<<b.nrEtaje<<" etaje în fiecare scară";
    cout<<", un număr total de "<<b.nrApartamente<<" de apartamente";
    if (b.areLift) {
        cout<<" și are lift.";
    } else {
        cout<<" și nu are lift.";
    }
    cout<<endl<<endl;
}


void citireBloc(Bloc &b){
    cout<<"Strada: ";
    cin>>b.strada;
    cout<<"Numar scari: ";
    cin>>b.nrScari;
    cout<<"Număr etaje în fiecare scară: ";
    cin>>b.nrEtaje;
    cout<<"Numar apartamente: ";
    cin>>b.nrApartamente;
    cout<<"Are lift? 0=NU, 1=DA: ";
    cin>>b.areLift;
    cout<<endl;
}

int main(){
    int nrBlocuri=10;
    Bloc vector[nrBlocuri];
    
    for (int i=1; i<=nrBlocuri; i++){
        cout<<"Blocul "<<i<<endl;
        citireBloc(vector[i]);
        cout<<"Blocul "<<i;
        afisareBloc(vector[i]);
    }
}
