#include "Road.h"

Road::Road() {
	this->id = 0;
	this->name = "";
	this->direction = true;
}

Road::Road(int id, string name, bool d) {
	this->id = id;
	this->name = name;
	this->direction = d;
}
void Road::setId(int id) {
	this->id = id;
}

void Road::setName(string n) {
	this->name = n;
}

void Road::setDirection(bool d) {
	this->direction = d;
}

int Road::getId() {
	return this->id;
}

string Road::getName() {
	return this->name;
}

bool Road::getDirection() {
	return this->direction;
}

