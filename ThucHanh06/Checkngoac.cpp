#include<iostream>
#include<stack>
using namespace std;

int check(string d){
	stack<char> s;
	char x;
	for (int i = 0; i < d.size(); i++) {
		x = d[i];		
		if (x == '(' || x == '{' || x == '[') {
			s.push(x);
		} else {
			if (!s.empty()) {
				if (x == ')') {
					if (s.top() != '(') return 0;
				} else
				if (x == ']') {
					if (s.top() != '[') return 0;
				} else
				if (x == '}') {
					if (s.top() != '{') return 0;
				} 
				s.pop();
			} else return 0;
		}
		
//		if (s.empty()) {
//			if (x == ')' || x == '}' || x == ']') return 0;
//		} else if (x == '(' || x == '{' || x == '[') {
//			s.push(x);
//		} else {
//			if (s.top() == '(' && x == ')' || s.top() == '[' && x == ']' || s.top() == '{' && x == '}')  {
//				s.pop();
//			}
//		}
	}
	if (s.empty()) return 1;
	else return 0;
	

}


bool check2(string str)
{
	stack<char> a;
	//string str l� chu?i x�u ngo?c s? nh?p v�o
	for(int i=0;i<str.size();i++)//duy?t l?n lu?t h?t chu?i
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//n?u g?p d?u m? ngo?c
		{
			a.push(str[i]);//push h?t v�o stack 
		}
		else //n?u g?p d?u d�ng ngo?c
		{
			if(!a.empty())//n?u stack kh�c r?ng 
			{
				if(str[i]==']')//ki?m tra xem ph?n t? ngo?c d?nh stack c� h?p v?i str[i] hay kh�ng
				{
					if(a.top()!='[')//kh�ng h?p
					{
						return false;//sai
					}
				}
				if(str[i]==')')//ki?m tra xem ph?n t? ngo?c d?nh stack c� h?p v?i str[i] hay kh�ng
				{
					if(a.top()!='(')//kh�ng h?p
					{
						return false;//sai
					}
				}
				if(str[i]=='}')//ki?m tra xem ph?n t? ngo?c d?nh stack c� h?p v?i str[i] hay kh�ng
				{
					if(a.top()!='{')//kh�ng h?p
					{
						return false;//sai
					}
				}
				a.pop();//ki?m tra xong x�a n� di
			}
			else //n?u nhu stack r?ng, kh�ng h?p l?, c� d?u m? m� kh�ng c� d�ng
			{
				return false;
			}
		}
	}
	return a.empty()==true;
	//n?u nhu cu?i c�ng stack v?n r?ng c�c ph?n t? d� l?y ra ki?m tra ph� h?p h?t
}

int main(){
	string test;
	cin >> test;
	if (check(test) == 1) {
		cout << "Hople";
	} else cout << "khong hop le";
	return 0;
}
