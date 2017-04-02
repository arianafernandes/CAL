
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"

int main() {

	Company comp = Company();
	comp.readMaps();
	comp.createGraphViewer();
	//readUsers(super);
	getchar();
	return 0;
}
