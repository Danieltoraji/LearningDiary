#include<iostream>
using namespace std;
class Point {
private:
	double x, y;
public:
	Point(double a, double b) { cout << "构造了点"; x = a; y = b; cout << x << y << endl; }
	Point(const Point& p) { cout << "构造了点"; x = p.x; y = p.y; cout << x << y << endl; }
	~Point() { cout << x << "," << y << "已被析构" << endl; }
	void Set(double a, double b) { x = a; y = b; }
	void Print() { cout << x << "," << y; }
};
class Line :public Point {
private:
	double s;
public:
	Line(double ix, double iy, double is) :Point(ix, iy) { cout << "构造了线"; s = is; cout << s<< endl; }
	Line(const Line& il) :Point(il) { cout << "构造了线"; s = il.s; cout << s<< endl; }
	~Line() { Point::Print(); cout << "," << s << "已被析构" << endl; }
	void Set(double ia, double ib, double is) { Point::Set(ia, ib); s = is; }
	void Print() { Point::Print(); cout <<"," << s << endl; }
};
int main(void) {
	Line line1(11, 45, 14);
	Line line2(line1);
	line1.Print();
	line2.Print();
	line2.Set(19, 19, 810);
	line2.Print();
}