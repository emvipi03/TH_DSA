#include <iostream>
#include <math.h>
#include<vector>
using namespace std;

struct dathuc {
    int bac;
    vector<int> heSo;
};
typedef dathuc DT;
void nhapDT(DT *n) {
	cout << "Nhap bac da thuc: ";
    cin >> n->bac;
    cout << "Nhap he so da thuc: ";
    int x;
    for (int i = 0; i <= n->bac; i++) {
        cin >> x;
        n->heSo.push_back(x);
    }
}

void xuatDT(DT *d, int bac) {
	bac = d->bac;	
	for (int i = 0; i <= bac; i++) {
		if (i == 0) cout << d->heSo[i] << " + ";
		else if ( d->heSo[i] != 0 && i != bac) {
			cout << d->heSo[i] << "x^" << i<< " + ";
		} else if (i == bac) cout << d->heSo[i] << "x^" << i << endl;
	}
}

DT *congDT(const DT *a, const DT *b) {
	DT *c = new DT();
	if (a->bac > b->bac) {
		c->bac = a->bac;
	} else c->bac = b->bac;
	int x;
	for (int i = 0; i <= c->bac; i++) {
		if (a->bac > b->bac) {
			if (i <= b->bac) {
				x = a->heSo[i] + b->heSo[i];
				c->heSo.push_back(x);
			} else c->heSo[i] = a->heSo[i];
		} else {
			if (i <= a->bac) {
				x = a->heSo[i] + b->heSo[i];
				c->heSo.push_back(x);
			} else c->heSo[i] = b->heSo[i];
		}
	}
	return c;
}

double giatriDT(const DT *d, double x) {
	double res = 0;
	for (int i = 0; i <= d->bac; i++) {
		res += pow(x,i)*d->heSo[i];
	}
	return res;
}

DT *hieuDT(const DT *a, const DT *b) {
	DT *c = new DT();
	if (a->bac > b->bac) {
		c->bac = a->bac;
	} else c->bac = b->bac;
	int x;
	for (int i = 0; i <= c->bac; i++) {
		if (a->bac > b->bac) {
			if (i <= b->bac) {
				x = a->heSo[i] - b->heSo[i];
				c->heSo.push_back(x);
			} else c->heSo[i] = a->heSo[i];
		} else {
			if (i <= a->bac) {
				x = a->heSo[i] - b->heSo[i];
				c->heSo.push_back(x);
			} else c->heSo[i] = - b->heSo[i];
		}
	}
	return c;
}

DT *tichDT(const DT *a, const DT *b) {
	DT *c = new DT();
	c->bac = a->bac + b->bac;
	for ( int i = 0; i <= c->bac; i++) {
		c->heSo.push_back(0);
	}
	
	for (int i = 0; i <= a->bac; i++) {
		for (int j = 0; j <= b->bac; j++) {
			c->heSo[i+j] += a->heSo[i] * b->heSo[j];
		}
	}
	return c;
}

int main() {
	DT d1,d2;
	nhapDT(&d1);
	nhapDT(&d2);
	int selection = 1;
	
	
	do {
		cout <<"1. Tinh tong hai da thuc." << endl;
		cout <<"2. Tinh hieu hai da thuc." << endl;
		cout <<"3. Tinh tich hai da thuc." << endl;
		cout <<"4. Tinh gia tri hai da thuc." << endl;
		cout <<"0. Thoat." << endl;	
		cout << "Nhap lua chon: ";
		cin >> selection;
		switch(selection) {
			case 1: {
				DT *c = congDT(&d1,&d2);
				int n = c->bac;
				cout << "Tong hai da thuc: ";
				xuatDT(c,c->bac);
				break;
			}
			case 2: {
				DT *c = hieuDT(&d1,&d2);
				int n = c->bac;
				cout << "Hieu hai da thuc: ";
				xuatDT(c,c->bac);
				break;
			}
			case 3: {
				DT *c = tichDT(&d1,&d2);
				int n = c->bac;
				cout << "Tich hai da thuc: ";
				xuatDT(c,c->bac);
				break;
			}
			case 4: {
				double x;
				cout << "nhap gia tri x de tinh gia tri da thuc: ";
				cin >> x;
				cout << "gia tri da thuc d1 la " << giatriDT(&d1,x) << endl; 
				cout << "gia tri da thuc d2 la " << giatriDT(&d2,x) << endl;
				break;
			}
			
			default: {
				cout << "Nhap lai yeu cau!!! ";
				break;
			}
		}
	} while(selection != 0); 
	

	return 0;
}
