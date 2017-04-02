#include "Supermarket.h"

#define RTerra 6371

Supermarket::Supermarket() {
}

vector<User> Supermarket::getUsers() {
	return users;
}

vector<Truck> Supermarket::getTrucks() {
	return trucks;
}
vector<Order> Supermarket::getOrders() {
	return orders;
}

void Supermarket::addUser(User u1) {
	users.push_back(u1);
}

void Supermarket::addOrder(Order o) {
	orders.push_back(o);
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

