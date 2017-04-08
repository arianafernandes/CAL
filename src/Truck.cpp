/*
 * Truck.cpp
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#include "Truck.h"

Truck::Truck() {
	this->weight = 0;
	this->capacity = 500;
	this->maxdist = 1.93622e+006;
	this->isFull = false;
	this->travelledDist=0;
}

int Truck::getWeight() const {
	return this->weight;
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
	return this->capacity;
}

void Truck::setCapacity(int capacity) {
	this->capacity = capacity;
}

double Truck::getMaxdist() const {
	return this->maxdist;
}

void Truck::setMaxdist(double maxdist) {
	this->maxdist = maxdist;
}

bool Truck::getIsFull() const {
	return this->isFull;
}

void Truck::setIsFull() {
	if (this->weight == this->capacity) {
		this->isFull = true;
	}
	this->isFull = false;
}

string Truck::getDate() const {
	return this->date;
}

void Truck::setDate(string d) {
	this->date = d;
}

const vector<Order>& Truck::getOrders() const {
	return this->orders;
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

void Truck::setId(int id){
	this->id = id;
}
int Truck::getId() const{
	return this->id;
}


void Truck::setTravelledDist(double dist){
	this->travelledDist = dist;
}
double Truck::getTravelledDist() const{
	return this->travelledDist;
}

void Truck::incDist(double d){
	this->travelledDist += d;
}


ostream & operator<<(ostream &os, const Truck& truck){
	for(unsigned int i= 0; i < truck.getOrders().size(); i++){
		os << truck.getOrders()[i];
	}
	return os;
}
