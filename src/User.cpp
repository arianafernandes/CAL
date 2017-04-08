/*
 * User.cpp
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#include "User.h"
using namespace std;

User::User(string name,int nif,int addressId) {
	this->name = name;
	this->nif = nif;
	this->addressId = addressId;
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

int User::getAddressId() const {
	return this->addressId;
}

void User::setAddressId(int addressId) {
	this->addressId = addressId;
}

void User::viewProfile(){
	cout << "Name: " << this->name << endl;
	cout << "Nif: " << this->nif << endl;
	cout << "Address id: " << this->addressId << endl << endl;
}
