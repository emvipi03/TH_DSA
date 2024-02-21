#include <iostream>
using namespace std;

int sqr(int x) {
    return x*x;
}
 
int pow(int a, int b) {
    if (b == 0) return 1;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2));
        else
            return a * (sqr(pow(a, b/2)));
}

int main() {
    int x,n;
    cin >> x >> n;
    cout << "x^n = " << pow(x,n) << endl;
}