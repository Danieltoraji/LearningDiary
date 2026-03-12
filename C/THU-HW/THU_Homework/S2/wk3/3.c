#include<iostream>
using namespace std;
class Car;
class Boat {
	double weight;
public:
	Boat(int);
	void Print()const;
	void Set(int);
	friend void TotalWeight(Boat B, Car C);
};
Boat::Boat(int w=500) {
	weight = w;
}
void Boat::Print()const {
	cout << weight << endl;
}
void Boat::Set(int w) {
	weight = w;
}
class Car {
	double weight;
public:
	Car(int);
	void Print()const;
	void Set(int);
	friend void TotalWeight(Boat B, Car C);
};
Car::Car(int w=200) {
	weight = w;
}
void Car::Print()const {
	cout << weight << endl;
}
void Car::Set(int w) {
	weight = w;
}
void TotalWeight(Boat B, Car C) {
	double tw = B.weight + C.weight;
	cout << tw << endl;
}
int main() {
	Car c(2000);
	Boat b(30000);
	TotalWeight(b, c);
}