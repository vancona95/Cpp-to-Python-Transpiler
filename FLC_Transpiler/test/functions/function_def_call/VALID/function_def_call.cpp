// Function definition and call correct
#include <iostream>
#include <fstream>
using namespace std;

int Funzione1(int x) {
    cout << "Funzione 1 corretta"<<x;
    return x;
}

int Funzione2() {
    cout << "Funzione 2 corretta";
    return 0;
}

int Funzione3(int x, string y, bool z) {    
    cout << "Funzione 1 corretta"<<x<<y<<z;
    return 0;
}


int main () {

Funzione1(1);
Funzione2();
Funzione3(1,"2",true);

return 0;
}
