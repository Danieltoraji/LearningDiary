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
	friend class Triangle;
};
class Triangle :public Point {
private:
	Point p1, p2;
public:
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3) :Point(x3, y3), p1(x1, y1), p2(x2, y2) { cout << "构造了三角"; Point::Print(); p1.Print(); p2.Print(); cout << endl; }
	Triangle(const Triangle& it) :Point(it), p1(it.p1), p2(it.p2) { cout << "构造了三角"; Point::Print(); p1.Print(); p2.Print(); cout << endl; }
	~Triangle() { Point::Print(); p1.Print(); p2.Print(); cout <<"Destructed!" << endl; }
	void Set(double x1, double y1, double x2, double y2, double x3, double y3) { Point::Set(x3, y3); p1.Set(x1, y1); p2.Set(x2, y2);}
	void Print() { Point::Print(); p1.Print(); p2.Print(); cout << endl; }
	double Area() {
		double temp = ((x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (y - p1.y)) / 2;
		return temp > 0 ? temp : -temp;
	}
};
int main(void) {
	Triangle Triangle1(0,5,3,0,0,-1);
	Triangle Triangle2(Triangle1);
	Triangle1.Print();
	Triangle2.Print();
	cout << endl << Triangle1.Area() << endl;
	Triangle2.Set(7,8,9,1,2,3);
	Triangle2.Print();
}