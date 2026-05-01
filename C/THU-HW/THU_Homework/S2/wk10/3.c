#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;
int main() {
	ifstream infile("input.txt");
	if (!infile) {
		cerr << "Error opening file!" << endl;
		return 1;
	}
	std::multiset<std::string> lines;   // 自动按字典序排序

	std::string line;
	while (std::getline(infile, line)) {
		if (line.length() > 80) {
			std::cerr << "警告：字符串长度超过80，已截断：" << line << std::endl;
			line = line.substr(0, 80);
		}
		lines.insert(line);
	}
	infile.close();

	ofstream outfile("output.txt");
	if (!outfile) {
		cerr << "Error opening output file!" << endl;
		return 1;
	}
	
	for (const auto& str : lines) {
		outfile << str << std::endl;
	}
	outfile.close();

	return 0;
}