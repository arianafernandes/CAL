/*
 * Estrada.cpp
 *
 *  Created on: 08/05/2017
 *      Author: Asus
 */

#include "Estrada.h"

Estrada::Estrada() {

}

Estrada::Estrada(int id, string name, bool d) {
	this->id = id;
	this->NomeEstrada = name;
	this->direction = d;
}
void Estrada::setId(int id) {
	this->id = id;
}

void Estrada::setNomeEstrada(string n) {
	this->NomeEstrada = n;
}

void Estrada::setDirection(bool d) {
	this->direction = d;
}

int Estrada::getId() {
	return this->id;
}

string Estrada::getNomeEstrada() {
	return this->NomeEstrada;
}

bool Estrada::getDirection() {
	return this->direction;
}


