#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	int foo[5][5];
	int i, j;
	int small[5];
	for (i = 0;i < 5; i++) {
		for (j = 0;j < 5; j++) {
			scanf("%d", &foo[i][j]);
		}
	}
	for (i = 0;i < 5; i++) {
		small[i] = foo[i][0];
		for (j = 0;j < 5; j++) {
			if (foo[i][j] < small[i]) {
				small[i] = foo[i][j];
			}
			printf("%d\t", foo[i][j]);
		}
		printf("%d\n",small[i]);
	}
}