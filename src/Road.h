#ifndef SRC_ROAD_H_
#define SRC_ROAD_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>
using namespace std;

class Road {
private:
	int id;
	string name;
	bool direction;

public:

	/**
	 * @brief Road constructor.
	 *
	 */
	Road();

	/**
	 * @brief Road constructor.
	 * @param id Id.
	 * @param name Name.
	 * @param d Direction.
	 *
	 */
	Road(int id, string name, bool d);

	/**
	 *
	 * @param id Order ID.
	 */
	void setId(int id);

	/**
	 *
	 * @param n Road name.
	 */
	void setName(string n);

	/**
	 *
	 * @param d Road Direction.
	 */
	void setDirection(bool d);

	/**
	 *
	 * @return Road ID.
	 */
	int getId();

	/**
	 *
	 * @return Road name.
	 */
	string getName();

	/**
	 *
	 * @return Road direction.
	 */
	bool getDirection();

};

#endif /* SRC_ROAD_H_ */
