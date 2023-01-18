#include <iostream>
#include "power.h"

using namespace std;

int main() {
    int base, exponent, result;
    cout<<"Please enter two integers: ";
    cin>>base>>exponent;
    power(base, exponent, result);
    cout<<base<<" to the power of "<<exponent<<" is "<<result<<"!"<<endl;
}