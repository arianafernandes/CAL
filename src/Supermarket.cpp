#include "Supermarket.h"

#define RTerra 6371

Supermarket::Supermarket() {
	this->name = "Super Preços Baixos";
}

vector<User>& Supermarket::getUsers() {
	return users;
}

vector<Truck> Supermarket::getTrucks() const {
	return trucks;
}


void Supermarket::addUser(User u1) {
	users.push_back(u1);
}


void Supermarket::addTruck(Truck t) {
	trucks.push_back(t);
}

bool Supermarket::addOrderToTruck(Order o) {
	if (trucks.size() == 0) {
		Truck t;
		t.setDate(o.getDate());
		t.addOrder(o);
		Supermarket::addTruck(t);
		return true;
	}
	//cout << "trucks size: " << trucks.size() << endl;
	for (unsigned int i = 0; i < trucks.size(); i++) {
		//cout << "Truck date: " << trucks.at(i).getDate() << endl;
		//cout << "Order date: " << o.getDate() << endl;
		if (trucks.at(i).getDate() == o.getDate()) {
			//cout << "cheguei aqui1" << endl;
			if (trucks.at(i).addOrder(o) == true) {
				//cout << "cheguei aqui2" << endl;
				return true;
			}
		}
	}
	Truck t = Truck();
	t.setDate(o.getDate());
	t.addOrder(o);
	Supermarket::addTruck(t);
	return true;

}

User& Supermarket::findUserFromNif(int nif){
	User u = User(" ", 0, 0);
	for(unsigned int i=0; i < this->users.size();i++){
		if(nif == this->users[i].getNif())
			return this->users[i];
	}
	return u;
}

void Supermarket::setName(string name){
	this->name=name;
}
string Supermarket::getName() const{
	return this->name;
}

void Supermarket::setIdSuper(int id){
	this->idSuper=id;
}
int Supermarket::getIdSuper() const{
	return this->idSuper;
}

void Supermarket::printAllTrucks() const{
	for (unsigned int i = 0; i < trucks.size(); i++) {
		cout << "id Truck " << i << endl;
		cout << " truck date: " << trucks.at(i).getDate() << endl
				<< " truck capacity max: " << trucks.at(i).getCapacity()<< endl
				<< " truck max distance: " << trucks.at(i).getMaxdist()
				<< endl<<endl;
	}
}


bool Supermarket::setCapacityToTruck(int capacity,int id){
	if(id >= this->trucks.size()){
		cout << "O camiao não existe" << endl;
		return false;
	}
	this->trucks[id].setCapacity(capacity);
	return true;
}
bool Supermarket::setDistanceToTruck(int dist,int id){
	if(id >= this->trucks.size()){
		cout << "O camiao não existe" << endl;
		return false;
	}
	this->trucks[id].setMaxdist(dist);
	return true;
}
void Supermarket::displayOrdersFromTruck(int id) const{
		cout << this->trucks[id];
}
