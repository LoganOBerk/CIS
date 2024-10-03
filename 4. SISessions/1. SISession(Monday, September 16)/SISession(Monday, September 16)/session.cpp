#include "session.h"

void Car::setColor(string color) {
	this->color = color;
}
string Car::getColor() {
	return color;
}
void Car::setMake(string make) {
	this->make = make;
}
string Car::getMake() {
	return make;
}
void Car::setModel(string model) {
	this->model = model;
}
string Car::getModel() {
	return model;
}
void Car::setYear(int year) {
	this->year = year;
}
int Car::getYear() {
	return year;
}
void Car::setDoors(int doors) {
	this->doors = doors;
}
int Car::getDoors() {
	return doors;
}



int main(){
	Car a, b, c;
	a.setColor("Pink");
	a.setMake("Lamborghini");
	a.setModel("Aventador");
	a.setDoors(2);
	a.setYear(2020);

	cout << a.getColor();
	cout << a.getMake();
	cout << a.getModel();
	cout << a.getDoors();
	cout << a.getYear();
	
	b.setColor("Pink");
	b.setMake("Lamborghini");
	b.setModel("aventador");
	b.setDoors(2);
	b.setYear(2020);

	cout << b.getColor();
	cout << b.getMake();
	cout << b.getModel();
	cout << b.getDoors();
	cout << b.getYear();



	return 0;
};