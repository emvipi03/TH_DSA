#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int Item;

// goi thanh vien cua class giong nhu cua struct, su dung toan tu .
// xem vi du voi push, pop, top trong 3 ham test
class NganXep {
public:
    NganXep(int c) {
        capacity = c;
        NX = new Item[capacity];
        t = -1;
    }
    ~NganXep();
    NganXep & operator= (const NganXep & nx);
    bool empty();
    int length();
    void push(const Item & value);
    void pop();
    Item & top() const;
    void print() const;
private:
    int capacity;
    Item * NX;
    int t;
};

void testPush(NganXep &nx, const Item &value) {
    cout << "Danh sach ngan xep truoc khi push " << value << endl;
    nx.print();
    nx.push(value);
    cout << "Danh sach ngan xep sau khi push " << value << endl;
    nx.print();
}

void testPop(NganXep &nx) {
    cout << "Danh sach ngan xep truoc khi pop\n";
    nx.print();
    nx.pop();
    cout << "Danh sach ngan xep sau khi pop\n";
    nx.print();
}

void testTop(NganXep &nx) {
    cout << "Danh sach ngan xep truoc khi top\n";
    nx.print();
    cout << "Dau hang doi la " << nx.top() << endl;
    cout << "Danh sach ngan xep sau khi top\n";
    nx.print();
}

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo Hang Doi su dung DSLK don cai dat." << endl;
    cout << "Tac gia: [Your name please]\n--------------------" << endl;

    // Khoi tao ngan xep 100
    NganXep nx(100);
    nx.operator=(0);
    
    for (int i = 0; i < 5; i++) {
    	nx.push(i);
	}

    cout << "\nXong!" << endl;
    testPush(nx,10);
    cout << "Len: " << nx.length()<<endl;
    testPop(nx);
    cout << "Len: " << nx.length()<<endl;
    testTop(nx);
    cout << "Len: " << nx.length()<<endl;
    // xong khi cai dat xong cac ham, khong loi, chay thu doan chuong trinh sau

    return 0;
}

// 1. Ham huy
NganXep::~NganXep() {
   delete NX; 
}

// 2. Toan tu gan
NganXep & NganXep::operator = (const NganXep &nx) {
	this->capacity = nx.capacity;
	this->NX = nx.NX;
	this->t = nx.t;
}

// 3. Kiem tra ngan xeps co rong hay khong
bool NganXep::empty() {
    if (capacity == 0)
    return true;
    else return false;
}

// 4. Xac dinh do dai cua hang doi
int NganXep::length() {
    
    return capacity;
}

// 5. Them phan tu moi vao dau ngan xep
void NganXep::push(const Item & value) {
    NX[capacity] = value;
    capacity++;
}

// 6. Xoa phan tu o dau ngan xep
void NganXep::pop() {
    capacity--;
}

// 7. Tra ve du lieu cua phan tu o dau ngan xep
Item & NganXep::top() const {
    return *(NX + capacity-1);
}

// 8. In danh sach ngan xep
void NganXep::print() const {
    for (int i = 0; i < capacity; i++) {
    	cout << " " << NX[i];
	}
	cout << endl;
}
