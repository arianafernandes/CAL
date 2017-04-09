#include "Info.h"

Info::Info(){

	id = 0;
	dlat = 0;
	dlon = 0;
	rlat = 0;
	rlon= 0;
}

double Info::getDlat() const {
	return dlat;
}

void Info::setDlat(double dlat) {
	this->dlat = dlat;
}

double Info::getDlon() const {
	return dlon;
}

void Info::setDlon(double dlon) {
	this->dlon = dlon;
}

int Info::getId() const {
	return id;
}

void Info::setId(int id) {
	this->id = id;
}

double Info::getRlat() const {
	return rlat;
}

void Info::setRlat(double rlat) {
	this->rlat = rlat;
}

double Info::getRlon() const {
	return rlon;
}

void Info::setRlon(double rlon) {
	this->rlon = rlon;
}

bool Info::operator ==(const Info &i2) const {
	return (id == i2.id);
}

bool Info::operator !=(const Info &i2) const{
return !(id == i2.id);
}


