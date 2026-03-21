#include<iostream>
#include<stdlib.h>
using namespace std;
class Ball {
	double x, y, z, r;
public:
	Ball(double a = 1.0, double b = 1.0, double c = 1.0, double d = 1.0) { x = a; y = b; z = c; r = d; }
	Ball(const Ball& p) { this->x = p.x; this->y = p.y; this->z = p.z; this->r = p.r; }
	~Ball() { cout << "Ball-xigouhanshu" << endl; }
	void Set(double a, double b, double c, double d) { x = a; y = b; z = c; r = d; };
	double GetX() { return x; }double GetY() { return y; }double GetZ() { return z; }double GetR() { return r; }
	double Volume() { return 4.0 / 3.0 * 3.14 * r * r * r; }
	void Print() { double v = Volume(); cout << "x is " << x << ", y is " << y << ", z is " << z << ", r is " << r << ", volume is " << v << endl; }
};
int main() {
	Ball ballList01[10];
	Ball* ballList02 = new Ball[20];
	int i, j;
	double x, y, z, r;
	double sumx, sumy, sumz, sumr, sumv;
	srand(0);
	cout << "--------01--------" << endl;
	for (i = 0; i < 10; i++) {
		x = rand(); y = rand(); z = rand();
		r = abs(rand()) % 100;
		ballList01[i].Set(x, y, z, r);
		ballList01[i].Print();
	}
	cout << "--------02--------" << endl;
	for (i = 0; i < 20; i++) {
		x = rand(); y = rand(); z = rand();
		r = abs(rand()) % 100;
		ballList02[i].Set(x, y, z, r);
		ballList02[i].Print();
	}
	cout << "--------01sorted--------" << endl;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (ballList01[j].Volume() > ballList01[j + 1].Volume()) {
				Ball temp = ballList01[j];
				ballList01[j] = ballList01[j + 1];
				ballList01[j + 1] = temp;
			}
		}
	}
	sumx = 0; sumy = 0; sumz = 0; sumr = 0; sumv = 0;
	for (i = 0; i < 10; i++) {
		ballList01[i].Print();
		sumx += ballList01[i].GetX(); sumy += ballList01[i].GetY(); sumz += ballList01[i].GetZ(); sumr += ballList01[i].GetR(); sumv += ballList01[i].Volume();
	}
	cout << "average x is " << sumx / 10 << ", average y is " << sumy / 10 << ", average z is " << sumz / 10 << ", average r is " << sumr / 10 << ", average volume is " << sumv / 10 << endl;
	cout << "--------02sorted--------" << endl;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 19 - i; j++) {
			if (ballList02[j].Volume() > ballList02[j + 1].Volume()) {
				Ball temp = ballList02[j];
				ballList02[j] = ballList02[j + 1];
				ballList02[j + 1] = temp;
			}
		}
	}
	sumx = 0; sumy = 0; sumz = 0; sumr = 0; sumv = 0;
	for (j = 0; j < 20; j++) {
		ballList02[j].Print();
		sumx += ballList02[j].GetX(); sumy += ballList02[j].GetY(); sumz += ballList02[j].GetZ(); sumr += ballList02[j].GetR(); sumv += ballList02[j].Volume();
	}
	cout << "average x is " << sumx / 20 << ", average y is " << sumy / 20 << ", average z is " << sumz / 20 << ", average r is " << sumr / 20 << ", average volume is " << sumv / 20 << endl;

	delete[] ballList02;
}

