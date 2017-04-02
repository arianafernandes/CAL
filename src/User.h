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

class User{
private:
	string name;
	double nif;
	double orderId;
	double capacity;
	string date;
public:
	User();
	int getCapacity() const;
	void setCapacity(int capacity);
	const string& getDate() const;
	void setDate(const string& date);
	const string& getName() const;
	void setName(const string& name);
	int getNif() const;
	void setNif(int nif);
	int getOrderId() const;
	void setOrderId(int orderId);
};


#endif /* SRC_USER_H_ */
