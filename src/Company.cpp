#include "Company.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#define RTerra 60000000
using namespace std;

#define M_PI 3.14159265359

Company::Company(int id) {
	this->super.setIdSuper(id);
	this->colorDelivery = "green";
	this->idSupers[0] = 96895428;
	this->idSupers[1] = 1154801453;
}
string Company::getColorDelivery() const {
	return this->colorDelivery;
}
void Company::setColorDelivery(string color) {
	this->colorDelivery = color;
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

double Company::calcDist(Info f1, Info f2) {
	double deltalat = f1.getRlat() - f2.getRlat();
	double deltalon = f1.getRlon() - f2.getRlon();
	double a = pow(sin(deltalat / 2), 2)
			+ pow(sin(deltalon / 2), 2) * cos(f1.getRlat()) * cos(f2.getRlat());
	double c = 2 * asin(sqrt(a));
	return RTerra * c * 100;

}

bool Company::Bidirection(vector<Road> roads, int id) {
	for (unsigned int i = 0; i < roads.size(); i++) {
		if (roads.at(i).getId() == id) {
			if (roads.at(i).getDirection() == true)
				return true;
		}
	}
	return false;
}

void Company::readMaps() {

	ifstream maps;

	maps.open("vertex.txt");

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

	maps.open("roads.txt");
	if (!maps) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	int i = 1;
	while (getline(maps, line)) {

		string id;
		string name, direction;

		stringstream linestream(line);
		string data;

		//cout << i << endl;
		getline(linestream, id, ';');
		//cout << "id: " << id << endl;
		getline(linestream, name, ';');
		//cout << "name: " << name << endl;
		getline(linestream, direction, ';');
		//cout << "direction: " << direction << endl << endl;

		Road r = Road();

		int idE = stoi(id);
		r.setId(idE);
		r.setName(name);
		if (direction == "False") {
			r.setDirection(false);
		} else {
			r.setDirection(true);
		}
		super.addRoad(r);
		i++;
	}

	maps.close();

	maps.open("edges.txt");

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


		graph.addEdge(source, dest, w, idAresta, idRua);

		//cout << "idRua" << g << endl;

		//gv->setEdgeLabel(idRua, super.getRoadNameByID(idRua));

		if (Bidirection(super.getRoads(), idRua) == true) {
			idAresta++;
			graph.addEdge(dest, source, w, idAresta, idRua);
		}
		idAresta++;

	}

	maps.close();
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

	int id;

	vector<Vertex<Info> *>::const_iterator itv = vertexSet.begin();
	for (; itv != vertexSet.end(); itv++) {

		id = (*itv)->getInfo().getId();
		double longt = (*itv)->getInfo().getRlon() - 2 * M_PI;
		double latt = (*itv)->getInfo().getRlat() - 2 * M_PI;
		int y = -((longt / M_PI) * r - (ymax + ymin) / 2);
		int x = (log((1 + sin(latt)) / (1 - sin(latt))) / (4 * M_PI)) * r
				- (xmin + xmax) / 2;

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
			int idRua = ite->getIdRua();
			gv->addEdge(id, idOrigem, idDestino, EdgeType::DIRECTED);
			//stringstream ss;
			//ss << idRua;



			gv->setEdgeLabel(id, super.getRoadNameByID(idRua));

			//cout << "id" << super.getRoadNameByID(id) << endl;
			//gv->setEdgeLabel(id, );
		}
	}

	gv->rearrange();

}

void Company::readDeliveries() {
	ifstream maps;

	maps.open("delivery.txt");

	if (!maps) {
		cerr << "Unable to open file users.txt";
		return;
	}

	string line;

	while (getline(maps, line)) {
		string name;
		int orderId;
		int capacity;
		string date;

		stringstream linestream(line);
		string data;
		linestream >> orderId;
		getline(linestream, data, ';');
		linestream >> capacity;
		getline(linestream, data, ';');
		linestream >> date;
		Order tempOrder = Order(orderId, capacity, date);
		super.addOrderToTruck(tempOrder);

	}

	maps.close();

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

		stringstream linestream(line);
		string data, lastname;

		getline(linestream, name, ';');
		linestream >> nif;
		getline(linestream, data, ';');
		linestream >> orderId;
		getline(linestream, data, ';');

		User tempUser = User(name, nif, orderId);
		super.addUser(tempUser);

	}
}

void Company::paintRoad(Vertex<Info>* source, Vertex<Info>* dest) {
	vector<Info> temp = graph.getPath(source->getInfo(), dest->getInfo());
	for (unsigned int i = 0; i < temp.size() - 1; i++) {
		gv->setVertexColor(temp[i].getId(), "red");
		Vertex<Info>* no1 = graph.getVertexFromId(temp[i].getId());
		int tempi = i;
		tempi++;
		gv->setVertexColor(temp[tempi].getId(), "red");
		Vertex<Info>* no2 = graph.getVertexFromId(temp[tempi].getId());
		Edge<Info> edge = graph.getEdgeFromVertex(no1, no2);
		gv->setEdgeColor(edge.getID(), "red");
	}
}

void Company::paintDeliveries(vector<Order> orders) {
	for (unsigned int j = 0; j < orders.size(); j++) {
		Vertex<Info>* no = graph.getVertexFromId(orders[j].getId());
		gv->setVertexIcon(no->getInfo().getId(), "home.png");
		gv->setVertexColor(no->getInfo().getId(), "green");
	}
}

int Company::getNextDelivery(vector<Order> &orders, int currentPosition) {
	Vertex<Info>* currentNo = graph.getVertexFromId(currentPosition);
	graph.dijkstraShortestPath(currentNo->getInfo());
	int distance = INT_INFINITY;
	int id = -1;
	int min = -1;
	for (unsigned int j = 0; j < orders.size(); j++) {
		if (!orders[j].getDelivery()) {
			Vertex<Info> *no = graph.getVertexFromId(orders[j].getId());
			if (no->getDist() < distance) {
				distance = no->getDist();
				id = orders[j].getId();
				min = j;
			}
		}
	}
	if (min >= 0)
		orders[min].setDelivery(true);
	return id;
}

vector<Order> Company::eliminateFromOrders(vector<Order> orders,
		int currentPosition) {
	vector<Order> temp;
	if (currentPosition != this->getSupermarket().getIdSuper()) {
		for (unsigned int i = 0; i < orders.size(); i++) {
			if (orders[i].getId() != currentPosition)
				temp.push_back(orders[i]);
		}
	} else {
		return orders;
	}
	return temp;
}

boolean Company::checkDistToSupermarket(Vertex<Info>* source, Truck truck) {
	double dist = source->getDist();
	int id = source->getInfo().getId();
	Vertex<Info> *superm = graph.getVertexFromId(
			this->getSupermarket().getIdSuper());
	graph.dijkstraShortestPath(superm->getInfo());
	Vertex<Info>* dest = graph.getVertexFromId(id);
	if (truck.getTravelledDist() + dist + dest->getDist() > truck.getMaxdist())
		return false;

	return true;
}

void Company::printOrders(vector<Order> orders) {
	Vertex<Info> *superm = graph.getVertexFromId(
			this->getSupermarket().getIdSuper());
	graph.dijkstraShortestPath(superm->getInfo());
	for (unsigned int i = 0; i < orders.size(); i++) {
		cout << "id " << orders[i].getId() << endl;
		cout << "data " << orders[i].getDate() << endl;
		Vertex<Info> *no = graph.getVertexFromId(orders[i].getId());
		cout << "dist " << no->getDist() << endl;
	}
}

void Company::returnToSupermarket(int currentPosition, int idSupermarket) {
	Vertex<Info>* source = graph.getVertexFromId(currentPosition);
	Vertex<Info>* dest = graph.getVertexFromId(idSupermarket);
	graph.dijkstraShortestPath(source->getInfo());

	vector<Info> temp = graph.getPath(source->getInfo(), dest->getInfo());
	for (unsigned int i = 0; i < temp.size() - 1; i++) {
		Vertex<Info>* no1 = graph.getVertexFromId(temp[i].getId());
		int tempi = i;
		tempi++;
		Vertex<Info>* no2 = graph.getVertexFromId(temp[tempi].getId());
		Edge<Info> edge = graph.getEdgeFromVertex(no1, no2);
		gv->setEdgeColor(edge.getID(), "cyan");
	}
}

void Company::distribution(int id) {
	int nextPosition;
	Vertex<Info>* source;
	Vertex<Info>* dest;
	int currentPosition;
	int supermarket = this->getSupermarket().getIdSuper();
	currentPosition = supermarket;
	Truck truck = super.getTrucks()[id];
	vector<Order> orders = truck.getOrders();
	while (true) {
		source = graph.getVertexFromId(currentPosition);
		nextPosition = getNextDelivery(orders, currentPosition);
		if (nextPosition == -1) {
			break;
		}
		dest = graph.getVertexFromId(nextPosition);
//calcula a distancia total do caminho e se é possivel voltar para o supermercado
		if (checkDistToSupermarket(dest, truck) == false)
			break;
		truck.incDist(dest->getDist());
		paintRoad(source, dest);
		currentPosition = nextPosition;
	}
	returnToSupermarket(currentPosition, supermarket);
	paintDeliveries(super.getTrucks()[id].getOrders());

	gv->setVertexIcon(supermarket, "super2.png");

}

Supermarket& Company::getSupermarket() {
	return this->super;
}

bool Company::checkIfNodeExist(int id) {
	for (unsigned int i = 0; i < this->graph.getVertexSet().size(); i++) {
		if (this->graph.getVertexSet()[i]->getInfo().getId() == id)
			return true;
	}
	return false;
}

Graph<Info> Company::getGraph() {
	return this->graph;
}

vector<Road> Company::getRoads() {
	return this->roads;
}

void Company::setRoad(Road r) {
	roads.push_back(r);
}
