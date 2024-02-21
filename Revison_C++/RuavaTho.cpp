#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
using namespace std;

#define start  0
#define finish  70
#define align  5

int *rua = new int(0);
int *tho = new int(0);

int ruaCD();
    // so buoc cua rua
int thoCD();
    // so buoc cua tho
void display() ;
    //hien thi duong dua
void chay(int*, const int&);
    // cap nhat vi tri cua rua va tho
void gameLoop();
    // chay game

int main() {
    gameLoop();
    return 0;
}

int ruaCD() {
   // srand(time(NULL));
    int buoc = 0;
    int x = rand()%10;
//    switch (x) {
//        case 0:
//        case 1:
//        case 2:
//        case 3:
//        case 4: buoc = 3; break;
//        case 5:
//        case 6:
//        case 7: buoc = 1; break;
//        case 8:
//        case 9: buoc = -6; break;
//        default: buoc = 0;
//    }
    if(x == 0 || x == 1 || x == 2|| x == 3|| x == 4) buoc = 3;
    else if (x == 5 || x == 6 || x == 7) buoc = 1;
    else if(x == 8 || x == 9) buoc = -6;
    else buoc = 0;
    return buoc;
}

int thoCD() {
    //srand(time(NULL));
    int buoc = 0;
    int x = rand() % 10;
    if(x == 0 || x == 1) buoc = 0;
    else if (x == 2 || x == 3) buoc = 9;
    else if(x == 4) buoc = -12;
    else if (x == 5 || x == 6 || x == 7) buoc = 1;
    else if (x == 8 || x == 9) buoc = -2;
    else buoc = 0;
//switch (y) {
//        case 0:
//        case 1: buoc = 0; break;
//        case 2:
//        case 3: buoc = 9; break;
//        case 4: buoc = -12; break;
//        case 5:
//        case 6:
//        case 7: buoc = 1; break;
//        case 8:
//        case 9: buoc = -2; break;
//        default: buoc = 0;
//    }
   return buoc;
}

void chay(int *viTri, const int &buoc) {
    *viTri += buoc;
    if (*viTri > finish) *viTri = finish;
    if(*viTri < start) *viTri = start;
}

void display(const int * rua, const int *tho) {
    system("CLS");
    cout << setw(align) << " " << setw(start) << "S" << setw(finish) << "F" << endl;
    cout << setw(align) << " " << setw(start) << "T" << setw(finish) << "I" << endl;
    cout << setw(align) << " " << setw(start) << "A" << setw(finish) << "N" << endl;
    cout << setw(align) << " " << setw(start) << "R" << setw(finish) << "I" << endl;
    cout << setw(align) << " " << setw(start) << "T" << setw(finish) << "S" << endl;
    cout << setw(align) << " " << setw(start) << "|" << setw(finish) << "H" << endl;
    cout << setw(align) << " " << setw(start) << "|" << setw(finish) << "|" << endl;
    cout << setw(align) << " " << setw(start) << "|" << setw(finish) << "|" << endl;

    if(*rua == start) {
        cout << setw(align) << " " << setw(start) << "R" << setw(finish) << "|" << endl;
    } else if (*rua == finish) {
        cout << setw(align) << " " << setw(start) << " " << setw(finish) << "R" << endl;
    } else {
        cout << setw(align) << " " << setw(start) << "|" << setw(*rua) << "R" << setw(finish-*rua) << "|" << endl;
    }

    if(*tho == start) {
        cout << setw(align) << " " << setw(start) << "T" << setw(finish) << "|" << endl;
    } else if (*tho == finish) {
        cout << setw(align) << " " << setw(start) << " " << setw(finish) << "T" << endl;
    } else {
        cout << setw(align) << " " << setw(start) << "|" << setw(*tho) << "T" << setw(finish-*tho) << "|" << endl;
    }

    cout << setw(align) << "" << setw(start) << "|" << setw(finish) << "|" << endl;

}

void gameLoop() {
	srand(time(NULL));
    int ruathang = 0;
    int thothang = 0;
    char chon;
    do {
        *rua = 0;
        *tho = 0;
        display(rua,tho);
        system("pause");

        while(*rua < finish && *tho < finish) {
            int buocrua = ruaCD();
            int buoctho = thoCD();

            chay(rua,buocrua);
            chay(tho,buoctho);

            display(rua,tho);
            Sleep(10);
        }

        if (*tho < *rua) {
            cout << "Rua thang cmnr" << endl;
            ruathang++;
        } else if (*tho > *rua) {
            cout << "Tho thang cmnr" << endl;
            thothang++;
        }else cout << "O vl tho va rua hoa nhau" << endl;
        cout << "Bang ti so: " << endl;
        cout << "Rua: " << ruathang << endl;
        cout << "Tho: " << thothang << endl;

        cout << "Choi tiep khong ku? C/K" << endl;
        cin >> chon;
    } while (chon == 'c' || chon == 'C');

}

