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
#include <cfloat>

class Truck {
private:
	vector<Order> orders;
	int weight;
	int capacity;
	double maxdist;
	double travelledDist;
	bool isFull;
	string date;
	int id;
public:

	/**
	 * @brief Default constructor.
	 */
	Truck();

	/**
	 *
	 * @return Truck weight.
	 */
	int getWeight() const;

	/**
	 *
	 * @param w Truck weight.
	 */
	void setWeight(int w);

	/**
	 *
	 * @return Truck total weight.
	 */
	int getTotalWeightOrders();

	/**
	 *
	 * @return Truck capacity.
	 */
	int getCapacity() const;

	/**
	 *
	 * @param capacity Truck capacity.
	 */
	void setCapacity(int capacity);

	/**
	 *
	 * @return Truck current capacity.
	 */
	int getCurrentCapacity();

	/**
	 *
	 * @return Truck maximum distance.
	 */
	double getMaxdist() const;

	/**
	 *
	 * @param maxdist Truck maximum distance.
	 */
	void setMaxdist(double maxdist);

	/**
	 *
	 * @return true if truck is full, otherwise return false.
	 */
	bool getIsFull() const;

	/**
	 *
	 * @brief Set a truck full.
	 */
	void setIsFull();

	/**
	 *
	 * @return Truck date.
	 */
	string getDate() const;

	/**
	 *
	 * @param d Truck date.
	 */
	void setDate(string d);

	/**
	 *
	 * @return Truck orders.
	 */
	const vector<Order>& getOrders() const;

	/**
	 * @brief Make a truck empty and then add orders to the truck.
	 *
	 * @param orders Truck orders.
	 */
	void setOrders(const vector<Order>& orders);

	/**
	 * @brief Add a order to the truck.
	 *
	 * @param o Order.
	 *
	 * @return true if possible to add the order, otherwise return false.
	 */
	bool addOrder(Order o);

	void setId(int id);
	int getId() const;

	void setTravelledDist(double dist);
	double getTravelledDist() const;

	void incDist(double d);

	friend ostream & operator<<(ostream &os, const Truck& truck);
};

#endif /* SRC_TRUCK_H_ */
