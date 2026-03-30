#include<iostream>
#pragma warning(disable:4996)
using namespace std;
class Matrix {
	int row, col;
	int** data;
public:
	Matrix(int row, int col) {
		this->row = row;
		this->col = col;
		data = new int* [row];
		for (int i = 0; i < row; i++) {
			data[i] = new int[col];
		}
	}
	~Matrix() {
		for (int i = 0; i < row; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
	void setMatrix() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> data[i][j];
			}
		}
	}
	void printMatrix() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
	friend Matrix operator+(const Matrix&, const Matrix&);
	friend Matrix operator-(const Matrix&, const Matrix&);
};
Matrix operator+(const Matrix& m1, const Matrix& m2) {
	if (!(m1.row == m2.row && m1.col == m2.col)) {
		cout << "同型矩阵方可加减！" << endl;
		exit(1);
	}
	Matrix result(m1.row, m1.col);
	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m1.col; j++) {
			result.data[i][j] = m1.data[i][j] + m2.data[i][j];
		}
	}
	return result;
}
Matrix operator-(const Matrix& m1, const Matrix& m2) {
	if (!(m1.row == m2.row && m1.col == m2.col)) {
		cout << "同型矩阵方可加减！" << endl;
		exit(1);
	}
	Matrix result(m1.row, m1.col);
	for (int i = 0; i < m1.row; i++) {
		for (int j = 0; j < m1.col; j++) {
			result.data[i][j] = m1.data[i][j] - m2.data[i][j];
		}
	}
	return result;
}

int main() {
	int row, col;
	cout << "请输入矩阵的行数和列数：";
	cin >> row >> col;
	Matrix m1(row, col), m2(row, col);
	cout << "请输入第一个矩阵的元素：" << endl;
	m1.setMatrix();
	cout << "请输入第二个矩阵的元素：" << endl;
	m2.setMatrix();
	Matrix sum = m1 + m2;
	Matrix diff = m1 - m2;
	cout << "两个矩阵的和为：" << endl;
	sum.printMatrix();
	cout << "两个矩阵的差为：" << endl;
	diff.printMatrix();
	return 0;

}