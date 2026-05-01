#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
	ifstream infile("input.txt");
	if (!infile.is_open()) {
		cerr << "Error opening file!" << endl;
		return 1;
	}
	int num, count = 0;
	while(infile >> num) {
		cout << setw(8) << num;
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
	infile.close();
}