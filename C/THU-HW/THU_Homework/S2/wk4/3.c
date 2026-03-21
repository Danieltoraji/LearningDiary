#include<iostream>
using namespace std;
class List;
class ListNode {
	int data;
	ListNode* next;
public:
	ListNode(int value) {
		data = value;
		next = nullptr;
	}
	friend class List;
};
class List {
	ListNode* head, * current;
public:
	List() { head = nullptr; current = nullptr; }
	void appendNode(int data) {
		ListNode* newNode = new ListNode{ data };
		if (!head) {
			head = newNode;
			current = head;
		}
		else {
			current->next = newNode;
			current = current->next;
		}
	}
	void display() const {
		ListNode* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void release() {
		ListNode* temp;
		while (head) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};
int main() {
	int buffer[500] = { 0 };
	int i, j, num=0;
	cout << "请输入不超过500个正整数，以-1结束" << endl;
	for(i=0;i<500;i++) {
		cin >> buffer[i];
		if (buffer[i] == -1) {
			break;
		}
	}
	num = i;
	for (i = 0; i < num - 1;i++) {
		for(j=0;j<num-1-i;j++) {
			if(buffer[j]>buffer[j+1]) {
				int temp = buffer[j];
				buffer[j] = buffer[j+1];
				buffer[j+1] = temp;
			}
		}
	}
	List sortedList;
	for (i = 0; i < num; i++) {
		sortedList.appendNode(buffer[i]);
	}
	sortedList.display();
	sortedList.release();
}