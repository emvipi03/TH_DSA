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
	//string str là chu?i xâu ngo?c s? nh?p vào
	for(int i=0;i<str.size();i++)//duy?t l?n lu?t h?t chu?i
	{
		if(str[i]=='('||str[i]=='['||str[i]=='{')//n?u g?p d?u m? ngo?c
		{
			a.push(str[i]);//push h?t vào stack 
		}
		else //n?u g?p d?u dóng ngo?c
		{
			if(!a.empty())//n?u stack khác r?ng 
			{
				if(str[i]==']')//ki?m tra xem ph?n t? ngo?c d?nh stack có h?p v?i str[i] hay không
				{
					if(a.top()!='[')//không h?p
					{
						return false;//sai
					}
				}
				if(str[i]==')')//ki?m tra xem ph?n t? ngo?c d?nh stack có h?p v?i str[i] hay không
				{
					if(a.top()!='(')//không h?p
					{
						return false;//sai
					}
				}
				if(str[i]=='}')//ki?m tra xem ph?n t? ngo?c d?nh stack có h?p v?i str[i] hay không
				{
					if(a.top()!='{')//không h?p
					{
						return false;//sai
					}
				}
				a.pop();//ki?m tra xong xóa nó di
			}
			else //n?u nhu stack r?ng, không h?p l?, có d?u m? mà không có dóng
			{
				return false;
			}
		}
	}
	return a.empty()==true;
	//n?u nhu cu?i cùng stack v?n r?ng các ph?n t? dã l?y ra ki?m tra phù h?p h?t
}

int main(){
	string test;
	cin >> test;
	if (check(test) == 1) {
		cout << "Hople";
	} else cout << "khong hop le";
	return 0;
}
