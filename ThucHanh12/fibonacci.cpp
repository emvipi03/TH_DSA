#include <iostream>
using namespace std;

int fibo_loop(int n) {
    int pre2 = 0;
    int pre1 = 1;
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = pre1 + pre2;
        pre2 = pre1;
        pre1 = res;
    }
    return res;
}

int fibo_dequy(int n) {
    if (n == 0 || n == 1) return n;
    else return fibo_dequy(n-1) + fibo_dequy(n-2);
}

int fibo_quyhoachdong(int n) {
    int a[n+1];
    a[0] = 0; 
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i] = a[i-1] + a[i-2]; 
    }
    return a[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibo_loop(n) << endl;
    cout << fibo_dequy(n) << endl;
    cout << fibo_quyhoachdong(n) << endl;

}