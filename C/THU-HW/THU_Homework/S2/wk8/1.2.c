#include<iostream>
using namespace std;
class Point {
private:
	double x, y;
public:
	Point(double x, double y) { this->x = x; this->y = y; }
	Point(const Point& p) { x = p.x; y = p.y; };
	virtual ~Point() { cout << "Point" << x << "," << y << "destructed" << endl; };
	virtual double GetArea() { return 0.0; };
};
class Circle : public Point {
private:
	double R;
public:
	Circle(double x, double y, double r) :Point(x, y) { this->R = r; }
	Circle(const Circle& c) :Point(c) { R = c.R; }
	~Circle() { cout << "Circle" << R << "destructed" << endl; };
	virtual double GetArea() { return 3.14 * R * R; }
};
class Rectangle :public Point {
private:
	double Height, Width;
public:
	Rectangle(double x, double y, double h, double w) :Point(x, y) { this->Height = h; this->Width = w; }
	Rectangle(const Rectangle& r) :Point(r) { Height = r.Height; Width = r.Width; }
	~Rectangle() { cout << "Rectangle" << Height << "," << Width << "destructed" << endl; };
	virtual double GetArea() { return Height * Width; }
};
class Square :public Rectangle {
public:
	Square(double x, double y, double a) :Rectangle(x, y, a, a) {};
	Square(const Square& s) :Rectangle(s) {};
	~Square() { cout << "Square" << "destructed" << endl; }
	virtual double GetArea() { return Rectangle::GetArea(); }
};
double f(Point& a) {
	return a.GetArea();
}
int main(void) {
	Point p1(2.0, 3.0);
	cout << p1.GetArea() << endl;
	Circle c1(2.0, 4.0, 3.0);
	cout << c1.GetArea() << endl;
	Rectangle r1(2.0, 3.0, 4.0, 5.0);
	cout << r1.GetArea()<<endl;
	Square s1(2.0, 3.0, 4.0);
	cout << s1.GetArea()<<endl;
	Point* ptrs[4];
	ptrs[0] = new Point(p1);
	ptrs[1] = new Circle(c1);
	ptrs[2] = new Rectangle(r1);
	ptrs[3] = new Square(s1);
	for (int i = 0; i < 4; i++) {
		cout<< "ptrs[" << i << "] -> "<<f(*ptrs[i])<<endl;
	}
	for (int i = 0; i < 4; i++) {
		delete ptrs[i];
	}
	cout << "--------------------------" << endl;
}