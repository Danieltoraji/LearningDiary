#include<iostream>
using namespace std;
class Point {
public:
	double x;
	double y;
	Point(double a = 1.0, double b = 1.0) { x = a; y = b; }
	~Point() { cout << "Poi-xigouhanshu" << endl; }
	void Set(double a, double b) { x = a; y = b; };
	void Print() { cout << "x is " << x << ", y is " << y << endl; }
};
class Rectangle {
	Point a;
	Point b;
public:
	Rectangle(Point m, Point n) { a = m; b = n; }
	Rectangle(double x1 = 1, double y1 = 2, double x2 = 3, double y2 = 4) :a(x1, y1), b(x2, y2) {}
	~Rectangle() { cout << "Rec-xigouhanshu" << endl; }
	void Set(double x1, double y1, double x2, double y2) { a.Set(x1, y1); b.Set(x2, y2); }
	void Print() { a.Print(); b.Print(); }
	double Area() {
		double s = (a.x - b.x) * (a.y - b.y);
		return s > 0 ? s : -s;
	}
};
int main(void) {
	Rectangle rc1(2, 3, 4, 5);
	rc1.Set(1, 2, 3, 4);
	rc1.Print();
	cout << rc1.Area() << endl;
}