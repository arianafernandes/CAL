/*
 * Auxi.cpp
 *
 *  Created on: 08/04/2017
 *      Author: Cristiana Ribeiro
 */


#include "Auxi.h"


bool isNumber(string name)
{
	bool digit=false;
	for (unsigned int i = 0; i<name.size(); i++)
			{
				if (isdigit(name[i]))
					digit=true;
			}
	return digit;
}

bool isNOTNumber(string nif)
{
	bool digit=true;
	for (unsigned int i = 0; i<nif.size(); i++)
			{
				if (isdigit(nif[i]))
					digit=false;
			}
	return digit;
}
