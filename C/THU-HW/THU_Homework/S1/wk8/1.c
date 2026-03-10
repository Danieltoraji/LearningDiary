#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
int main() {
	double sabc(double,double,double);
	double a, b, c;
	printf("Enter three numbers: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("Size:%lf\n", sabc(a, b, c));
}
static double sabc(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}