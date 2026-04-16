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
class Circle : virtual public Point {
private:
	double R;
public:
	Circle(double x, double y, double r) :Point(x, y) { this->R = r; }
	Circle(const Circle& c) :Point(c) { R = c.R; }
	virtual ~Circle() { cout << "Circle" << R << "destructed" << endl; };
	virtual double GetArea() { return 3.14 * R * R; }
protected:
	double getR(){ return R; }
};
class Square : virtual public Point {
private:
	double L;
public:
	Square(double x, double y, double a) :Point(x, y),L(a) {};
	Square(const Square& s) :Point(s),L(s.L) {};
	virtual ~Square() { cout << "Square"<< L << "destructed" << endl; }
	virtual double GetArea() { return L*L; }
protected:
	double getL() { return L; }
};
class Margin : public Circle, public Square {
public:
	Margin(double x, double y, double r, double a) :Point(x, y), Circle(x, y, r), Square(x, y, a) {};
	Margin(const Margin& m) :Point(m), Circle(m), Square(m) {};
	virtual ~Margin() { cout << "Margin" << "destructed" << endl; };
	virtual double GetArea(){
		if (getL() > 2 * getR()) { return Square::GetArea() - Circle::GetArea(); }
		else if (getL() < 1.414 * getR()) { return Circle::GetArea() - Square::GetArea(); }
		else return 0;
	}
};

int main(void) {
	Margin m1(1, 2, 3, 4);
	Margin m2(5, 6, 7, 8);
	cout << m1.GetArea()<<endl;
	cout << m2.GetArea()<<endl;
}