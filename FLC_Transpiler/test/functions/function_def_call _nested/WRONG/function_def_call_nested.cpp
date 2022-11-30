// Function definition and call wrong
#include <iostream>
#include <fstream>
using namespace std;



int Funzione1() {
    cout << "Funzione 1 sbagliata, chiama Funzione2 prima della dichiarazione";
    Funzione2();
    return 0;
}

int Funzione2(int x){
    cout << "Funzione 2 corretta"<<x;
    return x;
}

int main () {

int z = Funzione2(1);
Funzione1();


return 0;
}
