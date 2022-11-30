// Function definition and call correct
#include <iostream>
#include <fstream>
using namespace std;

int Funzione2() {
cout << "Funzione 2 corretta";
return 11;
}

int Funzione1() {
    cout << "Funzione 1 corretta";
    Funzione2();
    return 0;
}

int Funzione3(int x){
    cout << "Funzione 3 corretta"<<x;
    return x;
}

int main () {

int z = Funzione2();
Funzione1();
Funzione3(z);

return 0;
}
