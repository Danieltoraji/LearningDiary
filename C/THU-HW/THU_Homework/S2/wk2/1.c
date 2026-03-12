#include <iostream>
using namespace std;

int main() {
	int (*pt)[10] = new int[10][10];
	int i, j;
	pt[0][0] = 1;
	for (i = 1; i < 10; i++) {
		pt[i][0] = 1;
		pt[i][i] = 1;
		for (j = 1; j < i; j++) {
			pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j];
		}
	}

	for (i = 0; i < 10; i++) {
		// 输出 (9 - i) 个制表符以实现前置缩进
		for (int k = 0; k < 9 - i; k++) cout << '\t';

		for (j = 0; j <= i; j++) {
			cout << pt[i][j] << '\t' << '\t';
		}
		cout << endl;
	}

	delete[] pt;
	return 0;
}