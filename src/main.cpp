
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"

int main() {
	Company comp = Company(1154804468);
	comp.readMaps();
	comp.createGraphViewer();
	comp.readUsers();
	comp.distribution();
	cout << " read distribution done" << endl;
	getchar();
	return 0;
}
