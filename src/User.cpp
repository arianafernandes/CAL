/*
 * User.cpp
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#include "User.h"
using namespace std;

User::User() {
	string name = "";
	int nif = 0;
	int orderId = 0;
	int capacity = 0;
	string date = "";
}

const string& User::getName() const {
	return name;
}

void User::setName(const string& name) {
	this->name = name;
}

int User::getNif() const {
	return nif;
}

void User::setNif(int nif) {
	this->nif = nif;
}

int User::getOrderId() const {
	return orderId;
}

void User::setOrderId(int orderId) {
	this->orderId = orderId;
}
