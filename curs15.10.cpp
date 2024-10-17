#include <iostream>

using namespace std;


void f0(int a) {
    a=90;
}

void f1(int& r) {
    r=80;
}

void f2(int* p) {
}

void main() {
    int a=10;
    f0(a);
    f1(a);
    f2(&a);
}

int main() {
    
    int numar=100;
    int numar2=numar;
    numar2++;
    cout << numar<<endl;
    
    int* p=&numar;
    p++;
    cout<<numar<<endl;
    
    int& ref=numar;
    ref++;
    cout<<ref<<endl;
    
}
