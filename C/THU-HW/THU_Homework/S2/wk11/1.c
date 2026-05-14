#include <iostream>
using namespace std;
template <typename Q>
Q* safeMalloc(size_t size) {
	Q* ptr = new(std::nothrow) Q[size];
	if (ptr == nullptr) {
		throw 1000;
	}
	return ptr;
}
template <typename R>
void safeFree(R* ptr) {
	if (ptr == nullptr) {
		throw 1001;
	}
	delete[] ptr;
}
template <typename T>
class SafeArray {
private:
	T* arr;
	size_t size;
public:
	T operator[](int index) {
		if (index < 0) {
			throw 2001;
		}
		else if (index >= size) {
			throw 2002;
		}
		return arr[index];
	}
	SafeArray(size_t s, T* arrPtr) {
		size = s;
		try {
			arr = safeMalloc<T>(size);
			for (size_t i = 0; i < size; i++) {
				arr[i] = arrPtr[i];
			}
		}
		catch (int e) {
			if (e == 1000) {
				throw 2000;
			}
		}
	}
	~SafeArray() {
		safeFree(arr);
	}
};
void handleError(int e) {
	switch (e) {
	case 1000: cout << "内存分配失败." << endl; break;
	case 1001: cout << "试图释放空指针." << endl; break;
	case 2000: cout << "数组创建失败（内存不足）" << endl; break;
	case 2001: cout << "索引不能为负数." << endl; break;
	case 2002: cout << "索引超出范围." << endl; break;
	default:   cout << "未知错误码" << endl;
	}
}
int main() {
	int size = 5;
	int* arrPtr = new int[size] {1, 2, 3, 4, 5};
	size_t largeSize = 100000000000;
	cout << "测试1000" << endl;
	try {
		int* ptr = safeMalloc<int>(largeSize);
	}
	catch (int e) {
		handleError(e);
	}
	cout << "测试1001" << endl;
	int* nptr = nullptr;
	try {
		safeFree(nptr);
	}
	catch (int e) {
		handleError(e);
	}
	cout << "测试2000" << endl;
	try {
		SafeArray<int> safeArr(largeSize, arrPtr);
	}
	catch (int e) {
		handleError(e);
	}
	cout << "测试2001" << endl;
	try {
		SafeArray<int> safeArr(size, arrPtr);
		for (int i = 0; i < size; i++)  cout << safeArr[i] << " ";
		cout << endl;//正常访问
		cout << safeArr[-1] << endl;//访问负数索引
	}
	catch (int e) {
		handleError(e);
	}
	cout << "测试2002" << endl;
	try {
		SafeArray<int> safeArr(size, arrPtr);
		for (int i = 0; i < size; i++)  cout << safeArr[i] << " ";
		cout << endl;//正常访问
		cout << safeArr[5] << endl;//访问超出范围的索引
	}
	catch (int e) {
		handleError(e);
	}

	safeFree(arrPtr);
	return 0;
}
