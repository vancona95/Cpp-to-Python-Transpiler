// WRONG if single line
#include <iostream>
#include <fstream>
using namespace std;

int main () {

int x = 1;
string y = "2";
bool z = true;

if (x < y){
    cout<<" if condition is wrong"<< x;
}

else if (z == true){
cout<<" else if condition is correct";
}

  return 0;
}
