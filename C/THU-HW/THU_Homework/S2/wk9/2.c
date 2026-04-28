#include<iostream>
using namespace std;
template <typename T>
class Queue {
private:
	T* Front, *Tail;
	int max;
public:
	Queue(int m) {
		max = m;
		Front = Tail = new T[m];
	}
	Queue(const Queue& q) {
		max = q.max;
		Front = new T[max];
		Tail = Front + (q.Tail - q.Front);
		for (int i = 0; i < max; i++) {
			Front[i] = q.Front[i];
		}
	}
	~Queue() {
		cout << "Destructed!" << endl;
		delete[]Front;
	}
	bool In(T inEle) {
		if (Tail - Front == max) {
			return false;
		}
		*Tail++ = inEle;
		return true;
	}
	bool Out(T& outEle) {
		if (Tail == Front) {
			return false;
		}
		outEle = *Front;
		Tail--;
		for (int i = 0; i < max - 1; i++) {
			Front[i] = Front[i + 1];
		}
	}
	bool Empty() {
		return Tail == Front;
	}
};
int main() {
	Queue<int> q(5);
	q.In(1);
	q.In(2);
	q.In(3);
	int outEle;
	while (!q.Empty()) {
		q.Out(outEle);
		cout << outEle << " ";
	}
	cout << endl;

	Queue<double> q2(3);
	q2.In(1.1);
	q2.In(2.2);
	q2.In(3.3);
	double outEle2;
	while (!q2.Empty()) {
		q2.Out(outEle2);
		cout << outEle2 << " ";
	}
	cout << endl;
}