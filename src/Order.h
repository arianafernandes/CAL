/*
 * Order.h
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#ifndef SRC_ORDER_H_
#define SRC_ORDER_H_
#include <string>

using namespace std;

class Order {
private:
	int id;
	int weight;
	string date;

public:
	Order();
	int getId() const;
	void setId(int id);
	int getWeight() const;
	void setWeight(int w);
	string getDate() const;
	void setDate(string d);

};

#endif /* SRC_ORDER_H_ */
