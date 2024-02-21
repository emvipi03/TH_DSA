#include <iostream>
#include <math.h>
#include<vector>
using namespace std;

struct soHuuTi{
	int tuSo;
	int mauSo;
};
typedef soHuuTi SHT;

void docSHT(SHT *n) {
	cout << "Nhap tu so: ";
	cin >> n->tuSo;
	cout << "Nhap mau so: ";
	cin >> n->mauSo;
}

int UCLN(int a, int b) {
	if (a == b) return a;
	else if (a > b) return UCLN(a-b, b);
	else return UCLN(a, b-a);
}

void toiGianSHT(SHT *n) {
	int a = UCLN(n->tuSo, n->mauSo);
	n->tuSo /= a;
	n->mauSo /= a;
}

void inSHT(SHT *n) {
	toiGianSHT(n);
	if(n->mauSo == 0) {
		cout << "Loi phan so" << endl;
	} else {
		cout << n->tuSo << "/" << n->mauSo << endl;
	}
}

SHT *congSHT(SHT *a, SHT *b) {
	SHT *c = new SHT();
	c->mauSo = a->mauSo * b->mauSo;
	c->tuSo = a->tuSo * b->mauSo + a->mauSo * b->tuSo;
	return c;
}

int soSanhSHT(SHT *a, SHT *b) {
	if (a->tuSo*b->mauSo >= a->mauSo*b->tuSo) {
		return 1;
	} else return 0;
}

int main() {
	vector<SHT> daySHT;
	int n;
	cin >> n;
	SHT x;
	for (int i = 0; i < n; i++) {
		docSHT(&x);
		daySHT.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		inSHT(&daySHT[i]);
	}
	
	return 0;
}
