#include<stdio.h>
#include<math.h>
#pragma warning(disable: 4996)
main() {
    double x, an, sn;
    int k;
    sn = 0;
    an = 1;
	scanf("%lf", &x);
    for (k = 0;fabs(an) >= 1.0e-6;k++) {
        sn += an;
		an = an * (0.5 - k) / (k + 1) * x;
    }
	printf("sn=%lf\n", sn);
}