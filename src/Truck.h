/*
 * Truck.h
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#ifndef SRC_TRUCK_H_
#define SRC_TRUCK_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>
#include "Order.h"

class Truck {
private:
	vector<Order> orders;
	int weight;
	int capacity;
	double maxdist;
	bool isFull;
	string date;
public:
	Truck();
	int getWeight() const;
	void setWeight(int w);
	int getTotalWeightOrders();
	int getCapacity() const;
	void setCapacity(int capacity);
	int getCurrentCapacity();
	double getMaxdist() const;
	void setMaxdist(double maxdist);
	bool getIsFull() const;
	void setIsFull();
	string getDate() const;
	void setDate(string d);
	const vector<Order>& getOrders() const;
	void setOrders(const vector<Order>& orders);
	bool addOrder(Order o);
};

#endif /* SRC_TRUCK_H_ */
