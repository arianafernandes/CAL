#include "Supermarket.h"

#define RTerra 6371

Supermarket::Supermarket() {
}

vector<User> Supermarket::getUsers() const {
	return users;
}

vector<Truck> Supermarket::getTrucks() const {
	return trucks;
}


void Supermarket::addUser(User u1) {
	users.push_back(u1);
}


void Supermarket::addTruck(Truck t) {
	trucks.push_back(t);
}

bool Supermarket::addOrderToTruck(Order o) {
	if (trucks.size() == 0) {
		Truck t;
		t.setDate(o.getDate());
		t.addOrder(o);
		Supermarket::addTruck(t);
		return true;
	}
	//cout << "trucks size: " << trucks.size() << endl;
	for (unsigned int i = 0; i < trucks.size(); i++) {
		//cout << "Truck date: " << trucks.at(i).getDate() << endl;
		//cout << "Order date: " << o.getDate() << endl;
		if (trucks.at(i).getDate() == o.getDate()) {
			//cout << "cheguei aqui1" << endl;
			if (trucks.at(i).addOrder(o) == true) {
				//cout << "cheguei aqui2" << endl;
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

bool Supermarket::findUserFromNif(int nif){
	for(unsigned int i=0; i < this->users.size();i++){
		if(nif == this->users[i].getNif())
			return true;
	}
	return false;
}

