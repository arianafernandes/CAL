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

	/**
	 * @brief Default constructor.
	 */
	Info();

	/**
	 *
	 * @return Info Latitude in degrees.
	 */
	double getDlat() const;

	/**
	 *
	 * @param dlat Latitude in degrees.
	 */
	void setDlat(double dlat);

	/**
	 *
	 * @return Info Longitude in degrees.
	 */
	double getDlon() const;

	/**
	 *
	 * @param dlon Longitude in degrees.
	 */
	void setDlon(double dlon);

	/**
	 *
	 * @return Info ID.
	 */
	int getId() const;

	/**
	 *
	 * @param id Info ID.
	 */
	void setId(int id);

	/**
	 *
	 * @return Info latitude in radians.
	 */
	double getRlat() const;

	/**
	 *
	 * @param rlat Latitude in radians.
	 */
	void setRlat(double rlat);

	/**
	 *
	 * @return Info longitude in radians.
	 */
	double getRlon() const;

	/**
	 *
	 * @param rlon Longitude in radians.
	 */
	void setRlon(double rlon);

	/**
	 *
	 * @param i2 Info object to compare if is equal.
	 *
	 * @return True if success, otherwise return false.
	 */
	bool operator ==(const Info &i2) const;

	/**
	 * @param i2 Info object to compare if is different.
	 *
	 * @return True if success, otherwise return false.
	 */
	bool operator !=(const Info &i2) const;
};

#endif /* SRC_INFO_H_ */
