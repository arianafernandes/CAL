/*
 * Info.h
 *
 *  Created on: 01/04/2017
 *      Author: Asus
 */

#ifndef SRC_INFO_H_
#define SRC_INFO_H_

#include <iostream>
#include <iomanip>

using namespace std;

class Info {
private:
	int id;
	double dlat, dlon, rlat, rlon;
public:

	Info();
	double getDlat() const;
	void setDlat(double dlat);
	double getDlon() const;
	void setDlon(double dlon);
	int getId() const;
	void setId(int id);
	double getRlat() const;
	void setRlat(double rlat);
	double getRlon() const;
	void setRlon(double rlon);
	bool operator ==(const Info &i2) const;
	bool operator !=(const Info &i2) const;
};


#endif /* SRC_INFO_H_ */
