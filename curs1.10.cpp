#include<iostream>

using namespace std;

struct Pereche {
    int x;
    int y;
};

int suma(Pereche p) {
    return p.x+p.y;
}

int inmultire(Pereche p) {
    return p.x*p.y;
}

int diferenta(Pereche p) {
    return p.x-p.y;
}

int main() {
    Pereche p1;
    cin >> p1.x;
    cin >> p1.y;
    cout << suma(p1);
    
    Pereche p2;
    cin >> p2.x;
    cin >> p2.y;
    cout << suma(p2);
    
    return 10;
}
