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
	double nif;
	double orderId;
	double capacity;
	string date;
public:

	/**
	 * @brief Default constructor.
	 */
	User();

	/**
	 *
	 * @return User order capacity
	 */
	int getCapacity() const;

	/**
	 *
	 * @param capacity User capacity
	 */
	void setCapacity(int capacity);

	/**
	 *
	 * @return User order date.
	 */
	const string& getDate() const;

	/**
	 *
	 * @param date User order date.
	 */
	void setDate(const string& date);

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
	 * @return User order id.
	 */
	int getOrderId() const;

	/**
	 *
	 * @param orderId User order Id.
	 */
	void setOrderId(int orderId);
};

#endif /* SRC_USER_H_ */
