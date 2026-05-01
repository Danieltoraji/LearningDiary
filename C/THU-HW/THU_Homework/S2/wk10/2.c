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
	while (infile >> num) count++;
	if (count == 0) {
		cout << "No numbers found in the file." << endl;
		return 0;
	}
	infile.clear();

	infile.seekg(0, ios::beg);
	int* buffer = new int[count];
	for (int i = 0; i < count; i++) {
		infile >> buffer[i];
	}
	infile.close();

	ofstream outfile("output.dat", ios::binary);
	if (!outfile.is_open()) {
		cerr << "Error opening output file!" << endl;
		delete[] buffer;
		return 1;
	}
	outfile.write((char*)(buffer), count * sizeof(int));
	outfile.close();
	delete[] buffer;

	ifstream readfile("output.dat", ios::binary);
	if (!readfile.is_open()) {
		cerr << "Error opening output file for reading!" << endl;
		return 1;
	}
	readfile.seekg(4 * sizeof(int), ios_base::beg);
	int buf[4]; int idx = 4, outputcount = 0;
	while (idx < count) {
		readfile.read((char*)buf, 4 * sizeof(int));
		idx += 4;
		cout <<setiosflags(ios::left)<< setw(8) << buf[0] << setw(8) << buf[1];
		outputcount += 2;
		if (outputcount % 10 == 0) cout << endl;
	}
	readfile.close();
}