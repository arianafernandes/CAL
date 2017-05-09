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
	Road();
	Road(int id, string name, bool d);
	void setId(int id);
	void setName(string n);
	void setDirection(bool d);
	int getId();
	string getName();
	bool getDirection();
};



#endif /* SRC_ROAD_H_ */
