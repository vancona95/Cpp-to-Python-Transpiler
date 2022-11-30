// for loop nested wrong
#include <iostream>
#include <fstream>
using namespace std;

int main () {


for (int x = 0 x < 10; x = x + 1){
    cout<<"for loop 1 wrong semicolon, this is a blocking error";
    fo (int y = 10; y > 0; y = y - 1){
        cout<<"for loop 2 wrong token for";
        for (int z = 10; ; z = z -1){
            cout<<"for loop 3 wrong missing condition";
        }
    }
}

return 0;
}
