// Expressions wrong
#include <iostream>
#include <fstream>
using namespace std;

int main () {

    int a;
    float b;

    a = 5 + 3.3;

    a = 5 - "3";

    a = 5 * false;

    a = 5 / 0;

    cout<<a;

  return 0;
}
