/* 
IF nested 
WRONG
*/
#include <iostream>
#include <fstream>
using namespace std;

int main () {

int x = 1;
int y = 2;
int z = 3;
bool b = true;
float q = 1.1;
float w = 2.2;

if (x < y){
    cout<<" if first line "<< x;
    else (y < z){
        cout<<" ***Else is wrong here***, second line "<< z;}
    else if (z < 4){
        cout<<" else if second line "<< z;}
    if (b == true){
        if (q < w){cout<<" if third line "<< x;}
        else {cout<<" else third line "<< x;}
        }
    }
else {
cout<<" else first line";}

  return 0;
}
