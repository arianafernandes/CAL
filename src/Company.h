/*
 * Files.h
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#ifndef SRC_COMPANY_H_
#define SRC_COMPANY_H_

using namespace std;
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cmath>
#include "Graph.h"
#include "GraphViewer.h"
#include "Supermarket.h"

class Company {
private:
	Graph<Info> graph;
	GraphViewer *gv;
public:
	double calcX(double lat, double lon);
	double calcY(double lat, double lon);
	bool checkIfRejected(vector<int> NoRejected, int no);
	double calcDist(Info f1, Info f2);
	bool Bidirection(vector<Estrada> estradas, int id);
	void readMaps();
	void readUsers(Supermarket super);
	void createGraphViewer();
};






#endif /* SRC_COMPANY_H_ */
