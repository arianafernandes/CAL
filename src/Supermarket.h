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

public:
	/**
	 * @brief Default constructor.
	 */
	Supermarket();

	/**
	 *
	 * @return Users of the supermarket.
	 */
	vector<User>& getUsers();

	/**
	 *
	 * @return Trucks of the supermarket.
	 */
	vector<Truck> getTrucks() const;

	/**
	 * @brief Add a user to the suepermarket.
	 *
	 * @param u User.
	 */
	void addUser(User u);

	/**
	 * @brief Add a truck to the suepermarket.
	 *
	 * @param t Truck.
	 */
	void addTruck(Truck t);

	/**
	 * @brief Add a order to the respective truck of the supermarket.
	 *
	 * @param o Order.
	 *
	 * @return true if it is possible to add the order, otherwise return false.
	 */
	bool addOrderToTruck(Order o);

	User& findUserFromNif(int nif);

};

#endif /* SRC_SUPERMARKET_H_ */
