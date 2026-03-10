#include<stdio.h>
#pragma warning(disable:4996)
int main(void) {
	struct date {
		int year;
		int month;
		int day;
	}dates;
	scanf("%d%d%d", &dates.year, &dates.month, &dates.day);
	printf("%4d-%02d-%02d", dates.year, dates.month, dates.day);
}