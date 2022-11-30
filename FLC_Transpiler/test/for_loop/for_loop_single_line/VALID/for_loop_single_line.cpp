// for loop single line correct
#include <iostream>
#include <fstream>
using namespace std;

int main () {

string str = "stringa";

for (int x = 0; x < 10; x = x + 1){
    cout<<"for loop 1 correct";}

for (int x = 10; x > 0; x = x - 1){
    cout<<"for loop 2 correct";} 

for (int x = 10; x > 0; x = x -1){
    cout<<"for loop 3 correct with X = X -1"<<str;} 

  return 0;
}
