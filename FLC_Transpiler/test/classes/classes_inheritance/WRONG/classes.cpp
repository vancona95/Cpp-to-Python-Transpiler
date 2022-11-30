// Classes definition and objects
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



int main () {


//Class10 obj10;      // blocking error: class Class10 is not declared
Class1 obj1;
Class2 obj2;
obj1.x = 1.1;     
obj1.yyy = 1;        //error
obj1.k = 1 ;         //error
obj1.a = false ;     //error
obj1.Funzione2();     //error



obj2.a = false;
obj2.v = 3.5;



return 0;
}
