#include <iostream>
using namespace std;

int power(int x, int n) {
    int sum = 1;
    for (int i = 0; i < n; i++) {
        sum *= x;
    }
    return sum;
}

int main() {
    int x,n;
    cin >> x >> n;
    cout << "x^n = " << power(x,n) << endl;
}