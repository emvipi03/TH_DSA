#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int Item;

// goi thanh vien cua class giong nhu cua struct, su dung toan tu .
// xem vi du voi enqueue, dequeue, front trong 3 ham test
class HangDoi {
public:
    HangDoi() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    HangDoi(const HangDoi & HD);
    ~HangDoi();
    HangDoi & operator= (const HangDoi & HD);
    bool empty();
    int length();
    void enqueue(const Item & value);
    void dequeue();
    Item & front() const;
    void print() const;
private:
    struct Node {
        Item data;
        Node * next;
        Node(const Item & value) {
            data = value;
            next = NULL;
        }
    };
    Node * head; // con tro dau hang doi
    Node * tail; // con tro cuoi hang doi
    int size;
};

void testEnqueue(HangDoi & hd, const Item & value) {
    cout << "Danh sach hang doi truoc khi enqueue " << value << endl;
    hd.print(); cout << endl;
    hd.enqueue(value);
    cout << "Danh sach hang doi sau khi enqueue " << value << endl;
    hd.print(); cout << endl;
}

void testDequeue(HangDoi & hd) {
    cout << "Danh sach hang doi truoc khi dequeue\n";
    hd.print(); cout << endl;
    hd.dequeue();
    cout << "Danh sach hang doi sau khi dequeue\n";
    hd.print(); cout << endl;
}

void testFront(HangDoi & hd) {
    cout << "Danh sach hang doi truoc khi front\n";
    hd.print(); cout << endl;
    cout << "Dau hang doi la " << hd.front() << endl;
    cout << "Danh sach hang doi sau khi front\n";
    hd.print(); cout << endl;
}

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo Hang Doi su dung DSLK don cai dat." << endl;
    cout << "Tac gia: [Your name please]\n--------------------" << endl;

    // Khoi tao hang doi rong
    HangDoi hd;

    cout << "\nXong!" << endl;
    hd.~HangDoi();
    // xong khi cai dat xong cac ham, khong loi, chay thu doan chuong trinh sau
    for (int i = 1; i <= 5; i++) {
    	hd.enqueue(i);
	}
	hd.print();
    return 0;
}

// 1. Ham kien tao sao chep (copy constructor)
HangDoi::HangDoi(const HangDoi &HD) {
    HangDoi *newNode = new HangDoi();
    newNode->head = HD.head;
    newNode->size = HD.size;
    newNode->tail = HD.tail;    
}

// 2. Ham huy
HangDoi::~HangDoi() {
    Node *p = head;
    while(p!=NULL) {
    	head = p->next;
    	delete(p);
    	p = head;
	}
	delete p;
    head = NULL;
    tail = NULL;
    size = 0;
}

// 3. Toan tu gan
HangDoi & HangDoi::operator= (const HangDoi &HD) {
    this->head = HD.head;
    this->size = HD.size;
    this->tail = HD.tail;
}

// 4. Kiem tra hang doi co rong hay khong
bool HangDoi::empty() {
    if(size == 0) return true;
    else return false;
}

// 5. Xac dinh do dai cua hang doi
int HangDoi::length() {
    return size;
}

// 6. Them phan tu moi vao cuoi hang doi
void HangDoi::enqueue(const Item & value) {
    Node *newNode = new Node(value);
    tail->next = newNode;
    tail = newNode;
    size++;
}

// 7. Xoa phan tu o dau hang doi
void HangDoi::dequeue() {
    Node *p = head;
    head = head->next;
    delete p;
    size--;
}

// 8. Tra ve du lieu cua phan tu o dau hang doi
Item & HangDoi::front() const {
    
    return head->data;
}

// 9. In danh sach hang doi
void HangDoi::print() const {
    Node * temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}
