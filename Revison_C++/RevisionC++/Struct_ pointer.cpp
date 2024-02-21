#include<bits/stdc++.h>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
	
	Date(int _day,int _month, int _year) {
		day = _day;
		month = _month;
		year = _year;
	}
	Date(){};
};

//void nhapDate(Date &d) {
//	cout << "Nhap ngay, thang, nam";
//	cin >> d.day >> d->month >> d.year;
//}

int main() {
	Date day1 =  Date(12,2,2003);
	cout << day1.day <<"/" << day1.month << endl;
    return 0;
}


