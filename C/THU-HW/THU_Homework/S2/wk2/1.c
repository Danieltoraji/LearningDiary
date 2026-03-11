#include<iostream>
#define PI 3.14
using namespace std;
class Circle {
	double position[3];
	double radius;
public:
	Circle(double,double,double,double);
	Circle(const Circle& a);
	~Circle();
	void Print() const;
	void Area() const;
};
void Circle::Print()const  {
	cout << position[0] << "----"<<position[1] <<"----"<<position[2] <<"----"<<radius<< endl;
}
void Circle::Area()const {
	double size = PI * radius * radius;
	cout << size << endl;
}
Circle::~Circle() {
	cout << "析构函数" << endl;
}
Circle::Circle(double p1,double p2,double p3, double r) {
	position[0] = p1;
	position[1] = p2;
	position[2] = p3;
	radius = r;
	cout << "构造函数：通过指派" << endl;
}
Circle::Circle(const Circle& a) {
	position[0] = a.position[0];
	position[1] = a.position[1];
	position[2] = a.position[2];
	radius = a.radius;
	cout << "构造函数：通过复制" << endl;
}
int main() {
	Circle cir1(1,2,3,4);
	Circle cir2(cir1);
	cir1.Print();
	cir1.Area();
	cir2.Print();
	cir2.Area();
}