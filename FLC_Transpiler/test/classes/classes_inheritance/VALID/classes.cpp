// Classes inheritance definition and objects
#include <iostream>
#include <fstream>
using namespace std;

class Class1 {       
    public:             
        int x;        
        string y;
        int Funzione1(){int w = 1; cout<<"funzione in public"<<w; return w;}
    
    private:
        int k;
        float v;
        int Funzione2(){cout<<"funzione in private"<<k; return k;}    
};

class Class2 {       
    
    private:
        bool b = true; 
    
    public:             
        bool a;        
        int Funzione3(int z){z = 3; cout<<"altra funzione in public"<<z; return z;}  
};

class Class10 : public Class1 {
    public:

        int x10 = 10;
        string y10 = "10";
    
    private:
        int k10;
};


class Class100: public Class10 {
    public:

        int x100 = 100;
        string y100 = "100";
    
    private:
        int k100;
};


int main () {

Class1 obj1;
Class10 obj10;
Class100 obj100;



obj1.x = 1;
obj1.y = "1";

obj10.x10 = 11;
obj10.y10 = "11";

obj10.x = 11;
obj10.y = "11";
obj10.Funzione1();

obj100.x100 = 110;
obj100.y100 = "110";

obj100.x10 = 111;
obj100.y10 = "111";


obj100.x = 1110;
obj100.y = "1110";
obj100.Funzione1();





return 0;
}
