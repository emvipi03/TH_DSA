#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string.h>
using namespace std;


int check(int num, const int root) {
	if (num == root) return 1;
	else return 0; 
}


void notification(int &y, const int x, int &count) {
	if(check(y,x)) {
		if (count == 1) {
			cout << "Doan dung ngay lan dau tien" << endl;
		} else cout << "Doan dung roi, doan " << count << " lan moi ra" << endl;
	} 
	else if(x-y > 100 ) cout << "Qua nho...";
	else if(y-x > 100) cout << "Qua lon...";
	else if (x-y > 50 && x-y <= 100) cout << "Hoi nho...";
	else if (y-x > 50 && y-x <= 100) cout << "Hoi lon...";
	else if (abs(x-y) > 10 && abs(x-y) <= 50) cout << "Gan roi do...";
	else if (abs(x-y) > 0 && abs(x-y) <= 10) cout << "Rat gan roi do...";
}
int generate() {
	srand(time(0));
	return rand() % 1000 + 1;
}

void gameLoop() {
	char controller = 'c';
	while (controller == 'c'){
		int number;
		const int root = generate();
		int count = 0;
		cout << root;
		while(!check(number, root)) {
			cout << endl <<"Hay nhap so do: ";
			cin >> number;
			count++;
			notification(number,root,count);
		}
		cout << "Muon choi tiep khong?";
		cin >> controller;	
	}
}
void gameController(char &controller) {
	controller = 'c';
}

int main() {
	gameLoop();
    return 0;
}
