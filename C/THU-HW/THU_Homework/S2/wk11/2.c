#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct Student{
	int sno;
	string name;
	int score;
};
bool cmp(const Student& a, const Student& b) {
	if (a.score != b.score) return a.score > b.score;
	if (a.name != b.name) return a.name < b.name;
	return a.sno < b.sno;
}
int main() {
	vector<Student> students = {
		{1001, "Alice", 85 },
		{1002, "Bob", 90},
		{1003, "Charlie", 85},
		{1006, "David", 92},
		{1005, "Eve", 90 },
		{1004, "David", 92}
	};
	sort(students.begin(), students.end(), cmp);
	cout << "学号\t姓名\t成绩\n";
	for (const auto& student : students) {
		cout << student.sno << "\t" << student.name << "\t" << student.score << endl;
	}
	return 0;
}