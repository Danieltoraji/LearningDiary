#include <iostream>
using namespace std;
class Rectangle {
	double ld[2];
	double ru[2];
public:
	Rectangle(double, double, double, double);
	Rectangle(const Rectangle & a);
	~Rectangle();
	void Print() const;
	void Set(double, double, double, double);
	void Area() const;
};

Rectangle::Rectangle(double ld1 =1 , double ld2=2, double ru1=0, double ru2=1) {
	ld[0] = ld1; ld[1] = ld2; ru[0] = ru1; ru[1] = ru2;
	cout << "构造函数调用" << endl;
}
Rectangle::Rectangle(const Rectangle& a) {
	ld[0] = a.ld[0]; ld[1] = a.ld[1]; ru[0] = a.ru[0]; ru[1] = a.ru[1];
	cout << "构造函数调用" << endl;
}
Rectangle::~Rectangle() {
	cout << "析构函数调用" << endl;
}
void Rectangle::Print() const {
	cout << ld[0] << "----" << ld[1] << "----" << ru[0] << "----" << ru[1] << endl;
}
void Rectangle::Set(double ld1, double ld2, double ru1, double ru2) {
	ld[0] = ld1; ld[1] = ld2; ru[0] = ru1; ru[1] = ru2;
}
void Rectangle::Area() const {
	double size = (ld[1] - ld[0]) * (ru[1] - ru[0]);
	size = size > 0 ? size : -size;
	cout << size << endl;;
}
int main() {
	Rectangle rc1(1.0, 2.0, 3.0, 4.0);
	Rectangle rc2(rc1);
	rc1.Print(); 
	rc1.Area();
	rc1.Set(5, 1, 9, 0);
	rc1.Print();
	rc1.Area();
	rc2.Print();
	rc2.Area();
	rc2.Set(5, 1, 0, 9);
	rc2.Print();
	rc2.Area();
}