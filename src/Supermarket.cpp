#include "Supermarket.h"

#define RTerra 6371

Supermarket::Supermarket() {
	this->name = "Super Preços Baixos";
}

vector<User>& Supermarket::getUsers() {
	return users;
}

vector<Truck> Supermarket::getTrucks() const {
	return trucks;
}

vector<Road> Supermarket::getRoads() const {
	return roads;
}

void Supermarket::addUser(User u1) {
	users.push_back(u1);
}

void Supermarket::addTruck(Truck t) {
	trucks.push_back(t);
}

void Supermarket::addRoad(Road r) {
	roads.push_back(r);
}

bool Supermarket::addOrderToTruck(Order o) {
	if (trucks.size() == 0) {
		Truck t;
		t.setDate(o.getDate());
		t.addOrder(o);
		Supermarket::addTruck(t);
		return true;
	}
	for (unsigned int i = 0; i < trucks.size(); i++) {
		if (trucks.at(i).getDate() == o.getDate()) {
			if (trucks.at(i).addOrder(o) == true) {
				return true;
			}
		}
	}
	Truck t = Truck();
	t.setDate(o.getDate());
	t.addOrder(o);
	Supermarket::addTruck(t);
	return true;

}

User Supermarket::findUserFromNif(int nif) {
	for (unsigned int i = 0; i < this->users.size(); i++) {
		if (nif == this->users[i].getNif())
			return users[i];
	}
	User user = User(" ", 0, 0);
	return user;
}

bool Supermarket::userExists(int nif) {
	for (unsigned int i = 0; i < this->users.size(); i++) {
		if (nif == this->users[i].getNif())
			return true;
	}
	return false;
}

void Supermarket::setName(string name) {
	this->name = name;
}
string Supermarket::getName() const {
	return this->name;
}

void Supermarket::setIdSuper(vector<int> id) {
	this->idSuper = id;
}

int Supermarket::getIdSuper() const {
	return this->idSuper.at(0);
}

vector<int> Supermarket::getSuperIDs() const{
	return this->idSuper;
}

void Supermarket::printAllTrucks() const {
	for (unsigned int i = 0; i < trucks.size(); i++) {
		cout << "id Truck " << i << endl;
		cout << " truck date: " << trucks.at(i).getDate() << endl
				<< " truck capacity max: " << trucks.at(i).getCapacity() << endl
				<< " truck max distance: " << trucks.at(i).getMaxdist() << endl
				<< endl;
	}
}

bool Supermarket::setCapacityToTruck(int capacity, int id) {
	if ((unsigned int) id >= this->trucks.size()) {
		cout << "O camiao não existe" << endl;
		return false;
	}
	this->trucks[id].setCapacity(capacity);
	return true;
}
bool Supermarket::setDistanceToTruck(int dist, int id) {
	if ((unsigned int) id >= this->trucks.size()) {
		cout << "O camiao não existe" << endl;
		return false;
	}
	this->trucks[id].setMaxdist(dist);
	return true;
}

void Supermarket::displayOrdersFromTruck(int id) const {
	cout << this->trucks[id];
}

string Supermarket::getRoadNameByID(int id) {
	string name;
	for (int i = 0; i < roads.size(); i++) {
		if (roads.at(i).getId() == id) {
			name = roads.at(i).getName();
		}
	}
	return name;
}
