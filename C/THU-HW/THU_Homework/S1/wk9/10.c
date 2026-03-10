#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main(void) {
	char s[51];
	int num_letter = 0, num_number = 0;
	int i = 0;
	gets(s);
	for (;i < 50;i++) {
		if ((48 <= s[i]) && (s[i] <= 57)) num_number++;
		else if (((65 <= s[i]) && (s[i] <=90))||((97 <= s[i]) && (s[i] <= 122))) num_number++;
	}
	printf("%d %d", num_letter, num_number);
}