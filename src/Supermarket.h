/*
 * supermarket.h
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#ifndef SRC_SUPERMARKET_H_
#define SRC_SUPERMARKET_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>
#include "Truck.h"
#include "User.h"

using namespace std;

struct Estrada {
	int id;
	string NomeEstrada;
	bool direction;
};

class Supermarket {
private:
	vector<User> users;
	vector<Truck> trucks;
	vector<Order> orders;

public:
	Supermarket();
	vector<User> getUsers();
	vector<Truck> getTrucks();
	vector<Order> getOrders();
	void addUser(User u);
	void addOrder(Order o);
	void addTruck(Truck t);
	bool addOrderToTruck(Order o);

};

#endif /* SRC_SUPERMARKET_H_ */
