#include <iostream>
using namespace std;

int check(int n, int a[][2]) {
    for (int i = 0; i < n-1; i++) {
        int y = a[i][1];  
        int count = 0;     
        for (int j = 0; j < n-1; j++) {
            if (a[j][0] == y) count ++;
        }
        if (count > 2 || count == 1) return 0;
    }
    return 1;
}

int main() {
    int n; 
    cin >> n;
    int a[1000][2];
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    if (check(n, a)) {
        cout << "yes";
    } else cout << "no";

    
}