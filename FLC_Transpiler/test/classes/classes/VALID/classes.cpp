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

Class1 obj1;
obj1.x = 1;
obj1.y = "1";
obj1.Funzione1();

Class2 obj2;
obj2.a = false;

obj1.Funzione1();
obj2.Funzione3(10);


return 0;
}
