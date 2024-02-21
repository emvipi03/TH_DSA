#include <iostream>
#include <math.h>
using namespace std;

struct dathuc {
    int bac;
    int heSo[100];
};
typedef dathuc DT;
void nhapDT(DT *n) {
	cout << "Nhap bac da thuc: ";
    cin >> n->bac;
    cout << "Nhap he so da thuc: ";
    for (int i = 0; i <= n->bac; i++) {
        cin >> n->heSo[i];
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
	for (int i = 0; i <= c->bac; i++) {
		if (a->bac > b->bac) {
			if (i <= b->bac) {
				c->heSo[i] = a->heSo[i] + b->heSo[i];
			} else c->heSo[i] = a->heSo[i];
		} else {
			if (i <= a->bac) {
				c->heSo[i] = a->heSo[i] + b->heSo[i];
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
	for (int i = 0; i <= c->bac; i++) {
		if (a->bac > b->bac) {
			if (i <= b->bac) {
				c->heSo[i] = a->heSo[i] - b->heSo[i];
			} else c->heSo[i] = a->heSo[i];
		} else {
			if (i <= a->bac) {
				c->heSo[i] = a->heSo[i] - b->heSo[i];
			} else c->heSo[i] = - b->heSo[i];
		}
	}
	return c;
}

DT *tichDT(const DT *a, const DT *b) {
	DT *c = new DT();
	c->bac = a->bac + b->bac;
	for ( int i = 0; i <= c->bac; i++) {
		c->heSo[i] = 0;
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
	DT *c = hieuDT(&d1,&d2);
	int n = c->bac;
	cout << "Hieu hai da thuc: ";
	xuatDT(c,n);
	double x;
	cout << "nhap gia tri x de tinh gia tri da thuc: ";
	cin >> x;
	cout << "gia tri da thuc tong la " << giatriDT(c,x); 
	return 0;
}
