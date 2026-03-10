#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	int up, down, final, process, temp;
	double an, sn;
	an = 1;sn = 0;up = 1;down = 1;process = 1;
	scanf("%d", &final);
	for(;process <= final; process++) {
		sn = sn + an;
		temp = up;
		up = up + down;
		down = temp;
		an = up * 1.0 / down;
	}
	printf("%lf\n", sn);
}