// for loop nested correct
#include <iostream>
#include <fstream>
using namespace std;

int main () {


for (int x = 0; x < 10; x = x + 1){
    cout<<"for loop 1 correct";
    for (int y = 10; y > 0; y = y - 1){
        cout<<"for loop 2 correct";
        for (int z = 10; z > 0; z = z -1){
            cout<<"for loop 3 correct";
        }
    }
}

return 0;
}
