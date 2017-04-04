/*
 * Files.cpp
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#include "Company.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#define RTerra 60000000
using namespace std;

#define M_PI 3.14159265359

Company::Company(int id){
	this->supermarket =id;
}

double Company::calcX(double lat, double lon) {
	double X;
	X = RTerra * cos(lat) * cos(lon);
	return X;
}

double Company::calcY(double lat, double lon) {
	double Y;
	Y = RTerra * cos(lat) * sin(lon);
	return Y;
}

bool Company::checkIfRejected(vector<int> NoRejected, int no) {
	for (unsigned int i = 0; i < NoRejected.size(); i++) {
		if (NoRejected[i] == no)
			return true;
	}
	return false;
}

double Company::calcDist(Info f1, Info f2) {
	double deltalat = f1.getRlat() - f2.getRlat();
	double deltalon = f1.getRlon() - f2.getRlon();
	double a = pow(sin(deltalat / 2), 2)
											+ pow(sin(deltalon / 2), 2) * cos(f1.getRlat()) * cos(f2.getRlat());
	double c = 2 * asin(sqrt(a));
	return RTerra * c * 100;

}

bool Company::Bidirection(vector<Estrada> estradas, int id) {

	for (unsigned int i = 0; i < estradas.size(); i++) {
		if (estradas.at(i).id == id) {
			if (estradas.at(i).direction == true)
				return true;
		}
	}
	return false;
}

void Company::readMaps() {

	ifstream maps;

	maps.open("nos1.txt");

	if (!maps) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	string line;

	int idNo = 0;
	float X = 0;
	float Y = 0;
	float Z = 0;
	float W = 0;

	graph = Graph<Info>();

	while (getline(maps, line)) {
		stringstream linestream(line);
		string data;

		linestream >> idNo;

		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> X; //lat g
		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> Y; //lon g
		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> Z; // lon r
		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> W; // lat r

		Info tempInfo = Info();

		tempInfo.setId(idNo);
		tempInfo.setDlat(X);
		tempInfo.setDlon(Y);
		tempInfo.setRlon(Z);
		tempInfo.setRlat(W);

		graph.addVertex(tempInfo);

		if (tempInfo.getRlat() > Graph<Info>::maxLat) {
			Graph<Info>::maxLat = tempInfo.getRlat();
		}
		if (tempInfo.getRlat() < Graph<Info>::minLat) {
			Graph<Info>::minLat = tempInfo.getRlat();
		}
		if (tempInfo.getRlon() > Graph<Info>::maxLong) {
			Graph<Info>::maxLong = tempInfo.getRlon();
		}
		if (tempInfo.getRlon() < Graph<Info>::minLong) {
			Graph<Info>::minLong = tempInfo.getRlon();
		}
	}
	maps.close();

	maps.open("estradas.txt");
	if (!maps) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	int idEstrada = 0;
	string NomeEstrada = "";
	string direction = "";

	vector<Estrada> estradas;

	while (getline(maps, line)) {
		stringstream linestream(line);
		string data;

		linestream >> idEstrada;

		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> NomeEstrada;
		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> direction;

		Estrada e;
		e.id = idEstrada;
		e.NomeEstrada = NomeEstrada;
		if (direction == "False") {
			e.direction = false;
		} else {
			e.direction = true;
		}
		estradas.push_back(e);
	}
	maps.close();

	maps.open("arestas1.txt");

	if (!maps) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	int idRua = 0;
	int idNoOrigem = 0;
	int idNoDestino = 0;
	int idAresta = 0;

	while (getline(maps, line)) {
		stringstream linestream(line);
		string data;

		linestream >> idRua;

		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> idNoOrigem;
		getline(linestream, data, ';'); // read up-to the first ; (discard ;).
		linestream >> idNoDestino;

		Info source = graph.findInfo(idNoOrigem);
		Info dest = graph.findInfo(idNoDestino);
		double w = calcDist(source, dest);

		graph.addEdge(source, dest, w,idAresta);
		//gv->addEdge(idAresta, idNoOrigem, idNoDestino, EdgeType::DIRECTED);

		if (Bidirection(estradas, idRua) == true) {
			idAresta++;
			graph.addEdge(dest, source, w,idAresta);
		}

		/*cout << "source: " << source.getId() << "| " << source.getDlat()
		 << "| " << source.getDlon() << "| " << source.getRlon()
		 << "| " << source.getRlat() << endl;
		 cout << "dest: " << dest.getId() << "| " << dest.getDlat() << "| "
		 << dest.getDlon() << "| " << dest.getRlon() << "| "
		 << dest.getRlat() << endl;
		 cout << "weight: " << w << endl;*/

		idAresta++;
	}

	maps.close();

	//supermarket.floydWarshallShortestPath();
	//gv->rearrange();
}

void Company::createGraphViewer() {

	vector<Vertex<Info> *> vertexSet = graph.getVertexSet();

	gv = new GraphViewer(100000, 100000, false);

	gv->createWindow(1366, 768);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	double minLong = Graph<Info>::minLong - 2 * M_PI;
	double minLat = Graph<Info>::minLat - 2 * M_PI;
	double maxLat = Graph<Info>::maxLat - 2 * M_PI;
	double maxLong = Graph<Info>::maxLong - 2 * M_PI;

	int r = 60000000;
	int ymin = (minLong / M_PI) * r;
	int xmin = (log((1 + sin(minLat)) / (1 - sin(minLat))) / (4 * M_PI)) * r;
	int ymax = (maxLong / M_PI) * r;
	int xmax = (log((1 + sin(maxLat)) / (1 - sin(maxLat))) / (4 * M_PI)) * r;
	cout << "xmin: " << xmin << " xmax: " << xmax << " ymin: " << ymin
			<< " ymax: " << ymax << endl;

	int id;

	vector<Vertex<Info> *>::const_iterator itv = vertexSet.begin();
	for (; itv != vertexSet.end(); itv++) {

		id = (*itv)->getInfo().getId();
		double longt = (*itv)->getInfo().getRlon() - 2 * M_PI;
		double latt = (*itv)->getInfo().getRlat() - 2 * M_PI;
		int y = -((longt / M_PI) * r - (ymax + ymin) / 2);
		int x = (log((1 + sin(latt)) / (1 - sin(latt))) / (4 * M_PI)) * r - (xmin + xmax) / 2;

		gv->addNode(id, x, y);
	}

	int idOrigem, idDestino;
	itv = vertexSet.begin();

	for (; itv != vertexSet.end(); itv++) {
		vector<Edge<Info> > adj = (*itv)->getAdj();
		vector<Edge<Info> >::const_iterator ite = adj.begin();

		for (; ite != adj.end(); ite++) {
			idOrigem = (*itv)->getInfo().getId();
			idDestino = ite->getDest()->getInfo().getId();

			int id = ite->getID();
			gv->addEdge(id, idOrigem, idDestino, EdgeType::DIRECTED);
			stringstream ss;
			ss << id;
			gv->setEdgeLabel(id,ss.str());
		}
	}


	gv->rearrange();

}
void Company::readUsers() {
	ifstream maps;

	maps.open("users.txt");

	if (!maps) {
		cerr << "Unable to open file users.txt";
		return;
	}

	string line;

	while (getline(maps, line)) {
		string name;
		int nif;
		int orderId;
		int capacity;
		string date;

		stringstream linestream(line);
		string data;
		getline(linestream, name, ';');
		linestream >> nif;
		getline(linestream, data, ';');
		linestream >> orderId;
		getline(linestream, data, ';');
		linestream >> capacity;
		getline(linestream, data, ';');
		linestream >> date;

		User tempUser = User();
		tempUser.setName(name);
		tempUser.setNif(nif);
		tempUser.setOrderId(orderId);
		tempUser.setCapacity(capacity);
		tempUser.setDate(date);
		super.addUser(tempUser);

		Order tempOrder = Order();
		tempOrder.setId(orderId);
		tempOrder.setWeight(capacity);
		tempOrder.setDate(date);
		super.addOrder(tempOrder);
		super.addOrderToTruck(tempOrder);

	}

	/*
	for (unsigned int i = 0; i < super.getUsers().size(); i++) {
		cout << " User Name: " << super.getUsers().at(i).getName()
							 << " User Nif: " << super.getUsers().at(i).getNif()
							 << " User Order Id: " << super.getUsers().at(i).getOrderId()
							 << " User Capacity: " << super.getUsers().at(i).getCapacity()
							 << " User Date: " << super.getUsers().at(i).getDate() << endl;
	}
	for (unsigned int i = 0; i < super.getOrders().size(); i++) {

		cout << " Order ID: " << super.getOrders().at(i).getId()
							 << " Order Weight: " << super.getOrders().at(i).getWeight()
							 << endl;

	}
	for (unsigned int i = 0; i < super.getTrucks().size(); i++) {
		cout << "id Truck " << i << endl;
		for (unsigned int j = 0; j < super.getTrucks().at(i).getOrders().size(); j++) {
			cout << "truck order id: "
					<< super.getTrucks().at(i).getOrders().at(j).getId() << endl
					<< " truck order weight : "
					<< super.getTrucks().at(i).getOrders().at(j).getWeight()
					<< endl << " truck order date: "
					<< super.getTrucks().at(i).getOrders().at(j).getDate()
					<< endl << " truck date: "
					<< super.getTrucks().at(i).getDate() << endl
					<< " truck weight : " << super.getTrucks().at(i).getWeight()
					<< endl;
		}
	}*/

	maps.close();

}

void Company::distribution(){
	Info no = Info();
	no.setId(1154796515);
	graph.dijkstraShortestPath(graph.getVertexId(this->supermarket)->getInfo());
	gv->setVertexColor(this->supermarket,"red");
	gv->setVertexColor(no.getId(),"red");

	vector<Info> temp = graph.getPath(graph.getVertexId(this->supermarket)->getInfo(),no);
	for(unsigned int i=0; i < temp.size();i++){
		cout << "id " << i<< " " << temp[i].getId() << endl;
		gv->setVertexColor(temp[i].getId(),"red");
	}
	cout << "NEXT FOR" << endl;
	for(unsigned int i=0; i < temp.size()-1;i++){
		Info no1 = temp[i];
		Info no2 = temp[i+1];
		Edge<Info> edge = graph.getEdgeFromVertex(graph.getVertexId(no1.getId()),graph.getVertexId(no2.getId()));
		cout << "edge id " << edge.getID() << endl;
		gv->setEdgeColor(edge.getID(),"red");
	}
}
