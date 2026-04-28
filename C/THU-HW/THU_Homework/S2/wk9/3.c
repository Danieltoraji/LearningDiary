#include<iostream>
using namespace std;
template <typename T>
class Node {
public:
	T data;
	Node* next;
	Node(T d) :data(d), next(nullptr) {};
};
template <typename T>
class LinkedList {
private:
	Node<T>* head;

public:
	LinkedList(T init) {
		head = new Node<T>(init);
	}
	~LinkedList() {
		Node<T>* temp = head;
		while (head != nullptr) {
			head = head->next;
			delete temp;
			temp = head;
		}
		cout << "Destructed!" << endl;
	}
	void Display() {
		Node<T>* temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	bool AddNode(int index, T newdata) {
		if (index < 0) return false;
		if (!head) {
			head = new Node<T>(newdata);
			return true;
		}
		if (index == 0) {
			Node<T>* node1 = new Node<T>(newdata);
			node1->next = head;
			head = node1;
			return true;
		}
		else {
			Node<T>* temp = head;
			while (index > 1) {
				if (temp->next == nullptr) return false;
				temp = temp->next;
				index--;
			}
			Node<T>* node1 = new Node<T>(newdata);
			node1->next = temp->next;
			temp->next = node1;
			return true;
		}
	}
	bool DeleteNode(int index) {
		if (!head) return false;
		Node<T>* temp = head;
		if (index == 0) {
			head = head->next;
			delete temp;
			return true;
		}
		while (index > 1) {
			if (temp->next == nullptr) return false;
			temp = temp->next;
			index--;
		}
		Node<T>* delnode = temp->next;
		if (delnode == nullptr) return false;
		temp->next = delnode->next;
		delete delnode;
		return true;
	}
};
int main() {
	LinkedList<int> list(10);
	list.Display();
	list.AddNode(0, 5);
	list.Display();
	list.AddNode(2, 20);
	list.Display();
	list.AddNode(1, 15);
	list.Display();
	list.DeleteNode(2);
	list.Display();
	list.DeleteNode(0);
	list.Display();
	list.DeleteNode(1);
	list.Display();
	return 0;
}