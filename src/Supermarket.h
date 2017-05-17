#ifndef SRC_SUPERMARKET_H_
#define SRC_SUPERMARKET_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <cmath>

#include "Road.h"
#include "Truck.h"
#include "User.h"

using namespace std;

class Supermarket {
private:
	vector<User> users;
	vector<Truck> trucks;
	vector<Road> roads;
	string name;
	vector<int> idSuper;

public:
	/**
	 * @brief Default constructor.
	 */
	Supermarket();

	/**
	 *
	 * @return Users of the supermarket.
	 */
	vector<User>& getUsers();

	/**
	 *
	 * @return Trucks of the supermarket.
	 */
	vector<Truck> getTrucks() const;

	/**
	 *
	 * @return Roads of the supermarket.
	 */
	vector<Road> getRoads() const;

	/**
	 * @brief Add a user to the supermarket.
	 *
	 * @param u User.
	 */
	void addUser(User u);

	/**
	 * @brief Add a truck to the supermarket.
	 *
	 * @param t Truck.
	 */
	void addTruck(Truck t);

	/**
	 * @brief Add a road to the supermarket.
	 *
	 * @param r Road.
	 */
	void addRoad(Road r);

	/**
	 * @brief Add a order to the respective truck of the supermarket.
	 *
	 * @param o Order.
	 *
	 * @return true if it is possible to add the order, otherwise return false.
	 */
	bool addOrderToTruck(Order o);

	/**
	 * @brief Find user of the supermarket from nif number.
	 *
	 * @param nif User nif.
	 *
	 * @return User.
	 */
	User findUserFromNif(int nif);

	/**
	 *
	 * @param name Superarket name.
	 */
	void setName(string name);

	/**
	 *
	 * @return Supermarket name.
	 */
	string getName() const;

	/**
	 *
	 * @param id Superarket Id.
	 */
	void setIdSuper(vector<int> id);

	/**
	 *
	 * @return Supermarket id.
	 */
	int getIdSuper() const;

	/**
	 *
	 * @return Supermarket ids.
	 */
	vector<int> getSuperIDs() const;

	/**
	 * @brief Prints all trucks from the supermarket.
	 *
	 */
	void printAllTrucks() const;

	/**
	 * @brief Sets a capacity to truck.
	 *
	 * @param capacity New capacity.
	 * @param id Truck id.
	 *
	 * @return True if success, otherwise return false.
	 *
	 */
	bool setCapacityToTruck(int capacity, int id);

	/**
	 * @brief Sets a distance to truck.
	 *
	 * @param dist New distance.
	 * @param id Truck id.
	 *
	 * @return True if success, otherwise return false.
	 *
	 */
	bool setDistanceToTruck(int dist, int id);

	/**
	 * @brief Display orders from truck.
	 *
	 * @param id Truck id.
	 *
	 */
	void displayOrdersFromTruck(int id) const;

	/**
	 *
	 * @param nif User nif.
	 *
	 * @return True if success, otherwise return false.
	 *
	 */
	bool userExists(int nif);

	/**
	 * @brief Display roads name by id.
	 *
	 *
	 * @param id Road id.
	 *
	 * @return Road name.
	 *
	 */
	string getRoadNameByID(int id);

	/**
	 * @brief Display name by id.
	 *
	 *
	 * @param id ID.
	 *
	 * @return Name
	 *
	 */
	string getNameById(int id);

};

#endif /* SRC_SUPERMARKET_H_ */
