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
	int supermarket;
	Supermarket super;
	string colorDelivery;
public:
	Company(int id);
	double calcX(double lat, double lon);
	double calcY(double lat, double lon);
	bool checkIfRejected(vector<int> NoRejected, int no);
	double calcDist(Info f1, Info f2);
	bool Bidirection(vector<Estrada> estradas, int id);
	void readMaps();
	void readUsers();
	void createGraphViewer();
	void distribution();
	void paintRoad(Vertex<Info>* source, Vertex<Info>* dest);
	void paintDeliveries(vector<Order> orders);
	int getNextDelivery(vector<Order> orders,int currentPosition);
	vector<Order> eliminateFromOrders(vector<Order> orders, int currentPosition);
	void returnToSupermarket(int currentPosition,int idSupermarket);
	string getColorDelivery() const;
	void setColorDelivery(string color);
	void printOrders(vector<Order>orders);
};






#endif /* SRC_COMPANY_H_ */
