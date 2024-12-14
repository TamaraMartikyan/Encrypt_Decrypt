
#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    int a, b, gcd;
    cout << "Enter 2 integers" << endl;
    cin >> a >> b;

    a = abs(a);
    b = abs(b);

    int min = (a > b) ? b : a;

    for (int i = min; i >= 1; i--) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
            break; 
        }
    }

    cout << "GCD is " << gcd << endl;
    return 0;
}
