#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
main() {
	double a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10,
		a11, a12, a13, a14, a15, a16, a17, a18, a19,
		a20, a21, a22, a23, a24, a25, a26, a27, a28, a29;
	double count_positive = 0;
	double count_negative = 0;
	double sum_positive = 0;
	double sum_negative = 0;
	double fabs_sum = 0;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",
		&a0, &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9,
		&a10, &a11, &a12, &a13, &a14, &a15, &a16, &a17, &a18, &a19,
		&a20, &a21, &a22, &a23, &a24, &a25, &a26, &a27, &a28, &a29);
	
	if (a0 > 0) { count_positive++; sum_positive += a0; }
	else if (a0 < 0) { count_negative++; sum_negative += a0; }
	fabs_sum += fabs(a0);
	if (a1 > 0) { count_positive++; sum_positive += a1; }
	else if (a1 < 0) { count_negative++; sum_negative += a1; }
	fabs_sum += fabs(a1);
	if (a2 > 0) { count_positive++; sum_positive += a2; }
	else if (a2 < 0) { count_negative++; sum_negative += a2; }
	fabs_sum += fabs(a2);
	if (a3 > 0) { count_positive++; sum_positive += a3; }
	else if (a3 < 0) { count_negative++; sum_negative += a3; }
	fabs_sum += fabs(a3);
	if (a4 > 0) { count_positive++; sum_positive += a4; }
	else if (a4 < 0) { count_negative++; sum_negative += a4; }
	fabs_sum += fabs(a4);
	if (a5 > 0) { count_positive++; sum_positive += a5; }
	else if (a5 < 0) { count_negative++; sum_negative += a5; }
	fabs_sum += fabs(a5);
	//此后的重复省略......
	printf("count_positive=%d\n", count_positive);
	printf("count_negative=%d\n", count_negative);
	printf("sum_positive=%d\n", sum_positive);
	printf("sum_negative=%d\n", sum_negative);
	printf("fabs_sum=%d\n", fabs_sum);
}