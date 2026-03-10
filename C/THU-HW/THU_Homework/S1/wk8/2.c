#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
int main() {
	double m, n ;
	double a;
	double p(double x);
	printf("Enter m>=n>0");
	scanf("%lf%lf", &m, &n);
	a = p(m) / p(m - n);
	printf("%lf", a);

}
static double p(double x){
	double i;
	double s = 1.0;
	for (i = 1;i <= x;i++) {
		s = s * i;
	}
	return s;
}