// Function definition and call correct
#include <iostream>
#include <fstream>
using namespace std;

int Funzione1(float x) {
    cout << "Funzione 1, sbagliato il return"<<x;
    return x;
}

int Funzione2() {
    cout << "Funzione 2 chiamata sbagliata, ha 1 parametro invece di 0";
    return 0;
}

int Funzione3(int x, string y, bool z) {    
    cout << "Funzione 3 chiamata sbagliata";
    return 0;
}

int Funzione4(int x) {    
    cout << "Funzione 4 tipo del parametro nella chiamata è sbagliato ";
    return 0;
}

float Funzione4(float x) {    
    cout << "Funzione 4 già dichiarata ";
    return x;
}


int main () {

Funzione1(1.1);
Funzione2("sbagliato");
Funzione3(1, "2", true, "4° parametro in più");
Funzione4(99.999);
Funzione5("non dichiarata");
return 0;
}
