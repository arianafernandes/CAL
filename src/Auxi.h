/*
 * Auxi.h
 *
 *  Created on: 08/04/2017
 *      Author: Cristiana Ribeiro
 */

#ifndef SRC_AUXI_H_
#define SRC_AUXI_H_

#include <string>

using namespace std;

/**
 * @param name User name.
 *
 * @return True if success, otherwise return false.
 */
bool isNumber(string name);

/**
 * @param nif User nif.
 *
 * @return True if success, otherwise return false.
 */
bool isNOTNumber(string nif);

#endif /* SRC_AUXI_H_ */
