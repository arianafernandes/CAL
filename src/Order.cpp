/*
 * Order.cpp
 *
 */

#include "Order.h"

Order::Order() {
	id = 0;
	weight = 0;
	date = "";
}

int Order::getWeight() const {
	return weight;
}

void Order::setWeight(int w) {
	weight = w;
}

int Order::getId() const {
	return id;
}

void Order::setId(int id) {
	this->id = id;
}

string Order::getDate() const {
	return date;
}

void Order::setDate(string d) {
	date = d;
}
