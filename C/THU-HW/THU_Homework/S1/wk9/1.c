#include<stdio.h>
#pragma warning(disable:4996)
int main(void) {
	int foo[10] = { 0 };
	int findmax(int[], int);
	int i;
	for (i = 0;i <= 9; i++) scanf("%d", &foo[i]);
	for (i = 9;i >= 0; i--) printf("%d ", foo[i]);
	printf("\nMax label:%d", findmax(foo, 10));
}
int findmax(int foo[], int n) {
	int result = 0;
	int i;
	for (i = 0;i < n; i++) {
		if (foo[i] > foo[result]) result = i;
	}
	return result;
}