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
	Supermarket super;
	string colorDelivery;
	int idSupers[];
	vector<Road> roads;
public:

	/**
	 * Default constructor.
	 * @param id Supermarket id.
	 */
	Company(int id);

	/**
	 * @brief Calculates x from latitude and longitude.
	 * @param lat Latitude
	 * @param lon Longitute
	 * @return X
	 */
	double calcX(double lat, double lon);

	/**
	 * @brief Calculates y from latitude and longitude.
	 * @param lat Latitude
	 * @param lon Longitute
	 * @return Y
	 */
	double calcY(double lat, double lon);

	/**
	 * @brief Calculates distance between two Info classes.
	 * @param f1 Info f1.
	 * @param f2 Info f2.
	 * @return distance.
	 */
	double calcDist(Info f1, Info f2);

	/**
	 * @param id Edge id.
	 * @param estradas Vector of estradas.
	 *
	 * @return true if the edge id is from a edge that is bidirectional, otherwise return false.
	 */
	bool Bidirection(vector<Road> roads, int id);

	/**
	 * @brief Read the maps files.
	 *
	 */
	void readMaps();

	/**
	 * @brief Read the delivery file.
	 *
	 */
	void readDeliveries();

	/**
	 * @brief Read the users file.
	 *
	 */
	void readUsers();

	/**
	 * @brief Creates the graph viewer.
	 *
	 */
	void createGraphViewer();

	/**
	 * @brief Distribution and shipping of the orders to the trucks and users.
	 *
	 */
	void distribution(int id);

	/**
	 * @brief Coloring the edge(road) from vertex source to vertex dest.
	 *
	 * @param source Vertex source.
	 * @param dest Vertex destination.
	 */
	void paintRoad(Vertex<Info>* source, Vertex<Info>* dest);

	/**
	 * @brief Coloring the vertex that represents a order.
	 *
	 * @param orders Vector of orders to color.
	 *
	 */
	void paintDeliveries(vector<Order> orders);

	/**
	 * @param orders Vector of orders.
	 * @param currentPosition Current position.
	 *
	 * @return Returns the next position of order.
	 *
	 */
	int getNextDelivery(vector<Order> &orders, int currentPosition);

	/**
	 * @param orders Vector of orders.
	 * @param currentPosition Current position.
	 *
	 * @return Eliminates the current position order from the vector of orders.
	 *
	 */
	vector<Order> eliminateFromOrders(vector<Order> orders,
			int currentPosition);

	/**
	 * @brief Gets the return from the current position to the supermarket.
	 * @param idSupermarket Id of the vertex of the supermarket.
	 * @param currentPosition Current position.
	 *
	 */
	void returnToSupermarket(int currentPosition, int idSupermarket);

	/**
	 *
	 * @return the color of the delivery.
	 *
	 */
	string getColorDelivery() const;

	/**
	 * @brief Changes the color of the delivery.
	 *
	 * @param color Color to dye the deliveries.
	 *
	 */
	void setColorDelivery(string color);

	/**
	 * @brief Prints all the orders of the supermarket.
	 *
	 * @param orders Vector of orders.
	 *
	 */
	void printOrders(vector<Order> orders);

	/**
	 * @brief Checks the distance from a truck to the supermarket.
	 *
	 * @param dest Vertex destination.
	 * @param truck Truck
	 *
	 * @return True if success, otherwise return false.
	 */
	boolean checkDistToSupermarket(Vertex<Info>* dest, Truck truck);

	/**
	 *
	 * @return Supermarket.
	 */
	Supermarket& getSupermarket();

	bool checkIfNodeExist(int id);

	Graph<Info> getGraph();

	vector<Road> getRoads();

	void setRoad(Road r);
};

#endif /* SRC_COMPANY_H_ */
