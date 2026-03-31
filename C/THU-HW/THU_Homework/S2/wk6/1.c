#include <iostream>
using namespace std;
#include<cstring>
#pragma warning(disable:4996)
class String {
	char* str;
public:
	String(const char* input = "") {
		str = new char[strlen(input) + 1];
		strcpy(str, input);
	}
	String(const String& source) {
		str = new char[strlen(source.str) + 1];
		strcpy(this->str, source.str);
	}
	~String() {
		cout <<"----Console:"<< this->str << "is destructed!" << endl;
		delete[] str;
	}
	void Set(const String& source) {
		delete[] str;
		str = new char[strlen(source.str) + 1];
		strcpy(this->str, source.str);
	}
	void Print() {
		cout << this->str << endl;
	}
	friend String operator+(const String&, const String&);
	String operator=(const String& source) {
		delete[] this->str;
		this->str = new char[strlen(source.str)+1];
		strcpy(this->str, source.str);
		return String(source.str);
	}
};
String operator+(const String& first,const String& second) {
	char* temp = new char[strlen(first.str) + strlen(second.str)+1];
	strcpy(temp, first.str);
	strcat(temp, second.str);
	String result(temp);
	delete[] temp;
	return result;
}

int main(void) {
	String s1("abcd"), s2("efghij"), s3("lmnop"), s4, s5;
	s4 = s1 + s2 + s3;  s4.Print();  // 输出结果应该是 abcdefghijlmnop
	s5 = s5 + s3 + s4;  s5.Print();  // 输出结果应该是 lmnopabcdefghijlmnop
}