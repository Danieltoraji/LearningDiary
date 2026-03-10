#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
main() {
	char str1[101] = { 0 };
	char str2[101] = { 0 };
	short count1[128] = { 0 };
	short count2[128] = { 0 };
	char* check;
	int chklth;
	int i, j,flag;
	printf("str1\n");
	scanf("%s", str1);
	printf("str2\n");
	scanf("%s", str2);
	chklth = strlen(str1);
	if (chklth > strlen(str2)) {
		printf("False");
		return 0;
	}
	for (i = 0;i < strlen(str1);i++) {
		count1[(int)(str1[i])]++;
	}
	int a = 0;
	for (i = 0;i < (strlen(str2) - strlen(str1)+1);i++) {
		flag = 1;
		check = &(str2[i]);
		for (j = 0;j < 128;j++) count2[j] = 0;
		for (j = 0;j < chklth;j++) {
			count2[(int)check[j]]++;
		}
		for (j = 0;j < 128;j++) {
			if (count1[j] != count2[j]) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			for (j = 0;j < chklth;j++) {
				printf("%c",str2[i+j]);
			}
			printf("\n");
			a = 1;
		}
	}
	if (a == 0) {
		printf("False");
	}
	if (a == 1) {
		printf("True");
	}
}