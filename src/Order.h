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

	/**
	 * @brief Default constructor.
	 */
	Order();

	/**
	 *
	 * @return Order ID.
	 */
	int getId() const;

	/**
	 *
	 * @param id Order ID.
	 */
	void setId(int id);

	/**
	 *
	 * @return Order weight.
	 */
	int getWeight() const;

	/**
	 *
	 * @param w Order weight.
	 */
	void setWeight(int w);

	/**
	 *
	 * @return Order date.
	 */
	string getDate() const;

	/**
	 *
	 * @param d Order date.
	 */
	void setDate(string d);

};

#endif /* SRC_ORDER_H_ */
