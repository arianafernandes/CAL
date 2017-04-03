
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Company.h"

int main() {
	Company comp = Company(137309415);
	comp.readMaps();
	comp.createGraphViewer();
	comp.readUsers();
	comp.distribution();
	getchar();
	return 0;
}
