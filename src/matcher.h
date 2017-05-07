/*
 * matcher.h
 *
 *  Created on: 07/05/2017
 *      Author: Marta
 */

#ifndef SRC_MATCHER_H_
#define SRC_MATCHER_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;



void pre_kmp(string pattern, vector<int> & prefix);

int kmp(string text, string pattern);

int numStringMatching(string filename,string toSearch);

int editDistance(string pattern, string text);

float numApproximateStringMatching(string filename,string toSearch);






#endif /* SRC_MATCHER_H_ */
