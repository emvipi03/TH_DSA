#include<iostream>
using namespace std;

void print(int m, int n) {
    for (int i = 0; i < m; i++) {
        cout <<" ";
    }
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void draw() {
    int d;
    cin >> d;
    for (int i = 0; i < d; i++) {
        print(d-1-i,1+2*i);
    }
}
int main() {
    draw();
    return 0;
}