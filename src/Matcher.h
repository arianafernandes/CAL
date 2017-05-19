#ifndef SRC_MATCHER_H_
#define SRC_MATCHER_H_

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

/**
 * @brief Search algorithm.
 * @param pattern Pattern to search.
 * @param prefix Prefix.
 */
void pre_kmp(string pattern, vector<int> & prefix);

/**
 * @brief Search algorithm.
 *
 * @param text Text.
 * @param pattern Pattern to search.
 *
 * @return int.
 */
int kmp(string text, string pattern);


/**
 * @brief Number of string matching algorithm.
 *
 * @param filename Filename.
 * @param toSearch String to search.
 *
 * @return int.
 *
 */
int numStringMatching(string filename, string toSearch);

/**
 * @brief Edit distance.
 *
 * @param pattern Pattern to search.
 * @param text Text.
 *
 * @return int.
 *
 */
int editDistance(string pattern, string text);

/**
 * @brief Number approximate string matching.
 *
 * @param filename Filename.
 * @param toSearch String to search.
 *
 * @return float.
 *
 */
float numApproximateStringMatching(string filename, string toSearch);

#endif /* SRC_MATCHER_H_ */
