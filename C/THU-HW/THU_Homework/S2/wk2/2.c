#include<iostream>
using namespace std;
int main() {
	int (*a) = new int[100];
	int (*b)[25] = new int[20][25];
	int (*c)[8][5] = new int[9][8][5];
	int i,j,k;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (i = 0; i < 100; i++) { a[i] = i; sum1 += a[i]; }
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 25; j++) {
			b[i][j] = i * 25 + j;
			sum2 += b[i][j];
		}
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 5; k++) {
				c[i][j][k] = i * 100 + j * 10 + k;
				sum3 += c[i][j][k];
			}
		}
	}
	int m, n;
	cout << "Enter m n"<<endl ;
	cin >> m >> n;
	int** d = new int* [m];
	for (i = 0; i < m; i++) {
		d[i] = new int[n];
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			d[i][j] = i * n + j;
			sum4 += d[i][j];
		}
	}
	cout << sum1 << "," << sum2 << "," << sum3 << "," << sum4 << "," << endl;
	delete[]a;
	delete[]b;
	delete[]c;
	for (i = 0; i < m; i++) delete[]d[i];
	delete[]d;
}