#include<iostream>
using namespace std;
template <typename T>
T Max(T a, T b, T c) {
	T temp = a > b ? a : b;
	return temp > c ? temp : c;
}
int main() {
    // 1. char
    char c1 = 'a', c2 = 'z', c3 = 'm';
    cout << "Max char: " << Max(c1, c2, c3) << endl;

    // 2. short
    short s1 = 10, s2 = 30, s3 = 20;
    cout << "Max short: " << Max(s1, s2, s3) << endl;

    // 3. int
    int i1 = 100, i2 = 500, i3 = 300;
    cout << "Max int: " << Max(i1, i2, i3) << endl;

    // 4. long
    long l1 = 1000L, l2 = 3000L, l3 = 2000L;
    cout << "Max long: " << Max(l1, l2, l3) << endl;

    // 5. float
    float f1 = 1.5f, f2 = 3.2f, f3 = 2.8f;
    cout << "Max float: " << Max(f1, f2, f3) << endl;

    // 6. double
    double d1 = 2.7, d2 = 5.9, d3 = 4.2;
    cout << "Max double: " << Max(d1, d2, d3) << endl;

    cout << Max<double>(1, 2.5, 3) << endl;
    cout << Max<float>(2, 2.4f, 6.12) << endl;
    cout << Max<int>(4, 5, 1.2) << endl;
}