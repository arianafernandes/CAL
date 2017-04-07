/*
 * User.h
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#ifndef SRC_USER_H_
#define SRC_USER_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

using namespace std;

class User {
private:
	string name;
	int nif;
	int addressId;
public:

	/**
	 * @brief Default constructor.
	 */
	User(string name,int nif,int orderId);

	/**
	 *
	 * @return User name.
	 */
	const string& getName() const;

	/**
	 *
	 * @param name User name.
	 */
	void setName(const string& name);

	/**
	 *
	 * @return User nif.
	 */
	int getNif() const;

	/**
	 *
	 * @param nif User nif.
	 */
	void setNif(int nif);

	/**
	 *
	 * @return User address id.
	 */
	int getAddressId() const;

	/**
	 *
	 * @param orderId User order Id.
	 */
	void setAddressId(int addressId);

};

#endif /* SRC_USER_H_ */
