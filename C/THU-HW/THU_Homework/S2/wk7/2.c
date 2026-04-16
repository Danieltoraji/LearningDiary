#include<iostream>
using namespace std;
class Point {
protected:
	double x, y;
public:
	Point(double a, double b) :x(a), y(b) { cout << "构造了点" << x << "," << y << endl; }
	Point(const Point& p) :x(p.x), y(p.y) { cout << "构造了点" << x << "," << y << endl; }
	~Point() { cout << x << "," << y << "已被析构" << endl; }
	void Set(double a, double b) { x = a; y = b; }
	void Print() const { cout << x << "," << y; }
};
class Line :public Point {
private:
	double s;
public:
	Line(double ix, double iy, double is) :Point(ix, iy),s(is) { cout << "构造了线";  cout << s<< endl; }
	Line(const Line& il) :Point(il),s(il.s) { cout << "构造了线"; cout << s<< endl; }
	~Line() {cout << x << "," << y << "," << s << "已被析构" << endl; }
	void Set(double ia, double ib, double is) { x = ia; y = ib; s = is; }
	void Print() const { cout << x << "," << y << "," << s << endl; }
};
int main(void) {
	Line line1(11, 45, 14);
	Line line2(line1);
	line1.Print();
	line2.Print();
	line2.Set(19, 19, 810);
	line2.Print();
}