/*
 * Order.cpp
 *
 */

#include "Order.h"

Order::Order(int id, int weight, string date) {
	this->id = id;
	this->weight = weight;
	this->date = date;
	this->delivery = false;
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

void Order::setDelivery(bool d) {
	this->delivery = d;
}
bool Order::getDelivery() const {
	return this->delivery;
}
ostream & operator<<(ostream &os, const Order& order) {
	return (os << "Order id " << order.getId() << endl << "Peso da entrega "
			<< order.getWeight() << endl << "Data da entrega "
			<< order.getDate() << endl << endl);
}
