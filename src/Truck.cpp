/*
 * Truck.cpp
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#include "Truck.h"

Truck::Truck() {
	weight = 0;
	capacity = 500;
	maxdist = 1000;
	isFull = false;
}

int Truck::getWeight() const {
	return weight;
}

int Truck::getTotalWeightOrders() {
	int w;
	for (unsigned int i = 0; i < orders.size(); i++) {
		w += orders.at(i).getWeight();
	}
	return w;
}
void Truck::setWeight(int w) {
	weight = w;
}

int Truck::getCapacity() const {
	return capacity;
}

void Truck::setCapacity(int capacity) {
	this->capacity = capacity;
}

double Truck::getMaxdist() const {
	return maxdist;
}

void Truck::setMaxdist(double maxdist) {
	this->maxdist = maxdist;
}

bool Truck::getIsFull() const {
	return isFull;
}

void Truck::setIsFull() {
	if (weight == capacity) {
		isFull = true;
	}
	isFull = false;
}

string Truck::getDate() const {
	return date;
}

void Truck::setDate(string d) {
	date = d;
}

const vector<Order>& Truck::getOrders() const {
	return orders;
}

void Truck::setOrders(const vector<Order>& orders) {
	this->orders = orders;
}

int Truck::getCurrentCapacity() {
	int c;
	for (unsigned int i = 0; i < orders.size(); i++) {
		c += orders.at(i).getWeight();
	}
	return c;
}

bool Truck::addOrder(Order o) {
	int c = weight + o.getWeight();

	if (c <= capacity) {
		orders.push_back(o);
		weight += o.getWeight();
		if (weight == capacity) {
			isFull = true;
		}
		return true;
	}

	return false;
}
