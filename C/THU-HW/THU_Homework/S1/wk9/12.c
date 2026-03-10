#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main(void) {
	int isrunnian(int);
	int calcdays(int, int, int);
	int yy, mm, dd;
	int days = 0;
	int t;
	scanf("%d%d%d", &yy, &mm, &dd);
	days = calcdays(yy, mm, dd);
	printf("This is Day %d", days);
	t = days % 5;
	if ((t==4)||(t==0))printf("shaiwang");
	else printf("dayu");
}
int isrunnian(int x) {
	if ((x % 4 == 0) && (x % 100 != 0)) return 1;
	else if (x % 400 == 0) return 1;
	else return 0;
}
int calcdays(int yy, int mm, int dd) {
	int days = 0;
	int now_year = 2000, now_month = 0;
	int m_d[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (;now_year < yy;now_year++) {
		if (isrunnian(now_year) == 1) days += 366;
		else days += 365;
	}
	for (;now_month < (mm - 1);now_month++) {
		days += m_d[now_month];
	}
	if ((isrunnian(yy) == 1) && (mm > 2)) days += 1;
	days += dd;
	return days;
}