#include<stdio.h>
#pragma warning(disable:4996)
int main() {
	int foo[4][6];
	int i, j;
	int ri=0, rj=0;
	for (i = 0;i < 4; i++) {
		for (j = 0;j < 6; j++) {
			scanf("%d", &foo[i][j]);
		}
	}
	for (i = 0;i < 4; i++) {
		for (j = 0;j < 6; j++) {
			if (foo[i][j] < foo[ri][rj]) {
				ri = i;
				rj = j;
			}
			printf("%d\t", foo[i][j]);
		}
		printf("\n");
	}
	printf("%d,%d", ri, rj);

}