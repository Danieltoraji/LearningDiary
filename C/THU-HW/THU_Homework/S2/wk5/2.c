#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;
class String {
	char* dataStr;
public:
	String(const char* inputStr) { dataStr = new char[strlen(inputStr) + 1]; strcpy(this->dataStr, inputStr); cout << "构造了" << dataStr << endl; }
	String(const String& inputStr) { dataStr = new char[strlen(inputStr.dataStr) + 1]; strcpy(this->dataStr, inputStr.dataStr); cout << "构造了" << dataStr << endl;}
	~String() { cout << dataStr << "的析构函数被调用啦！" << endl; delete[] dataStr; }
	void Set(const char* newStr) { char* newData = new char[strlen(newStr) + 1]; strcpy(newData, newStr);  delete[] dataStr; dataStr = newData; }
	void Print() const { cout << dataStr << endl; }
	friend bool operator == (const String, const String);
	friend bool operator > (const String, const String);
	friend bool operator < (const String, const String);
	friend bool operator != (const String, const String);
	friend bool operator >= (const String, const String);
	friend bool operator <= (const String, const String);
};
bool operator ==(const String a,const String b) {
	if (strcmp(a.dataStr, b.dataStr) == 0)return 1;
	else return 0;
}
bool operator > (const String a,const String b) {
	if (strcmp(a.dataStr, b.dataStr) > 0) return 1;
	else return 0;
}
bool operator < (const String a,const String b) {
	if (strcmp(a.dataStr, b.dataStr) < 0) return 1;
	else return 0;
}
bool operator != (const String a,const String b) {
	if (strcmp(a.dataStr, b.dataStr) == 0) return 0;
	else return 1;
}
bool operator >= (const String a,const String b) {
	if (strcmp(a.dataStr, b.dataStr) >= 0) return 1;
	else return 0;
}
bool operator <= (const String a,const String b) {
	if (strcmp(a.dataStr, b.dataStr) <= 0) return 1;
	else return 0;
}

int main(void) {
	String s1("abcd"), s2("abce");
	if (s1 > s2)  cout << "s1 > s2!\n";
	else if (s1 < s2)  cout << "s1 < s2!\n";
	else if (s1 == s2)  cout << "s1 == s2!\n";
	if (s1 >= s2)  cout << "s1 >= s2!\n";
	if (s1 <= s2)  cout << "s1 <= s2!\n";
	if (s1 != s2)  cout << "s1 != s2!\n";
}
