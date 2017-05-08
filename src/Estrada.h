#ifndef SRC_ESTRADA_H_
#define SRC_ESTRADA_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>
using namespace std;

class Estrada {
private:
	int id;
	string NomeEstrada;
	bool direction;
public:
	Estrada();
	Estrada(int id, string name, bool d);
	void setId(int id);
	void setNomeEstrada(string n);
	void setDirection(bool d);
	int getId();
	string getNomeEstrada();
	bool getDirection();
};



#endif /* SRC_ESTRADA_H_ */
