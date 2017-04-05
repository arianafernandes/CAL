/*
 u * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <iostream>
#include "Info.h"

#define M_PI 3.14159265359

using namespace std;

template<class T> class Vertex;
template<class T> class Edge;
template<class T> class Graph;

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITED = 2;
const int INT_INFINITY = INT_MAX;

template<class T>
class Vertex {
	T info;
	bool visited;
	bool processing;
	int indegree;
	double dist;
	vector<Edge<T> > adj;

public:

	/**
	 * Vertex constructor.
	 * @param in Class to represent the vertex info.
	 */
	Vertex(T in);

	friend class Graph<T> ;
	void addEdge(Vertex<T> *dest, double w, int id);
	bool removeEdgeTo(Vertex<T> *d);

	/**
	 *
	 * @return The object of the class representing the vertex info.
	 */
	T getInfo() const;

	/**
	 *
	 * @param info Object of the class that represents the vertex info.
	 */
	void setInfo(T info);

	/**
	 *
	 * @return The distance of the vertex.
	 */
	int getDist() const;

	/**
	 *
	 * @param d Set d as distance of the Vertex.
	 */
	void setDist(int d);

	/**
	 *
	 * @return The indegree of the vertex.
	 */
	int getIndegree() const;

	/**
	 *
	 * @return The vector with the adjacent edges.
	 */
	vector<Edge<T> >& getAdj();

	bool operator<(const Vertex<T> vertex);

	Vertex* path;
};

template<class T>
class Edge {
	Vertex<T> * dest;
	double weight;
	int ID;
	int idRua;
	static int count;
public:

	/**
	 *
	 * Edge default constructor.
	 *
	 */
	Edge();

	/**
	 * Edge constructor.
	 * @param d Destination node.
	 * @param w Edge weight.
	 * @param id Edge id.
	 */
	Edge(Vertex<T> *d, double w, int id);

	/**
	 *
	 * @return The destination node.
	 */
	Vertex<T>* getDest() const;

	/**
	 *
	 * @return The edge id.
	 */
	int getID() const;

	/**
	 *
	 * @return The id of the Street of the edge.
	 */
	int getIdRua() const;

	/**
	 *
	 * @param id Edge ID.
	 */
	void setID(int id);

	/**
	 *
	 * @param id Street ID.
	 */
	void setIdRua(int id);
	friend class Graph<T> ;
	friend class Vertex<T> ;
};

template<class T>
class Graph {
	vector<Vertex<T> *> vertexSet;
	void dfs(Vertex<T> *v, vector<T> &res) const;
	int numCycles;
	void dfsVisit(Vertex<T> *v);
	void dfsVisit();
	void getPathTo(Vertex<T> *origin, list<T> &res);
	int ** W;   //weight
	int ** P;   //path
public:
	static double minLat, minLong, maxLat, maxLong;

	/**
	 * Adds a vertex to the graph.
	 * @param in Object of the class representing the vertex info.
	 *
	 * @return True if the vertex was successfully added or false otherwise.
	 */
	bool addVertex(const T &in);

	/**
	 * Adds an edge to the graph.
	 * @param sourc Source vertex.
	 * @param dest Destination vertex.
	 * @param w Weight of the edge.
	 * @param id Id of the edge.
	 * @return True of the edge was successfully added or false otherwise.
	 */
	bool addEdge(const T &sourc, const T &dest, double w, int id);

	/**
	 *
	 * @param sourc Source vertex.
	 * @param dest Destination vertex.
	 * @return Returns the edge connecting the to vertexes passed as arguments.
	 */

	/**
	 *
	 * @param sourc Source vertex.
	 * @param dest Destination vertex.
	 * @return Returns the edge connecting the to vertexes passed as arguments.
	 */

	Edge<T> getEdge(const T &source, const T &dest);

	/**
	 * Removes a vertex from the graph.
	 * @param in Info of the vertex.
	 * @return True if the vertex was successfully removed or false otherwise.
	 */
	bool removeVertex(const T &in);

	/**
	 * Removes an edge from the graph.
	 * @param sourc Source vertex.
	 * @param dest Destination source.
	 * @return True if the edge was successfully removed or false otherwise.
	 */
	bool removeEdge(const T &sourc, const T &dest);

	/**
	 *
	 * @return A vector with the information of the vertexes in the same order as they were visited using a dfs algorithm.
	 */
	vector<T> dfs() const;

	vector<T> bfs(Vertex<T> *v) const;

	int maxNewChildren(Vertex<T> *v, T &inf) const;

	/**
	 *
	 * @return The vector of the exisiting vertexes of the graph.
	 */
	vector<Vertex<T> *> getVertexSet() const;

	/**
	 *
	 * @return The number of exisiting vertexes.
	 */
	int getNumVertex() const;

	/**
	 * @param id Id of the vertex.
	 *
	 * @return The class Info of the vertex with that id.
	 */
	T findInfo(double id);

	/**
	 * @param T class Info.
	 *
	 * @return The Vertex with that Info .
	 */
	Vertex<T>* getVertex(const T &v) const;

	/**
	 * Reset indegrees of the edge.
	 *
	 */
	void resetIndegrees();

	/**
	 *
	 *@return The vector of vertexs that are de sources of the edge.
	 */
	vector<Vertex<T>*> getSources() const;

	/**
	 * @param origin Origin of the edge
	 * @param dest Destination of the edge
	 * @return The vector with Info's of the path from the edge.
	 */
	vector<T> getPath(const T &origin, const T &dest);

	/**
	 * Dijkstra Shortest Path algorithm
	 * @param T Info class
	 *
	 */
	void dijkstraShortestPath(const T &s);

	/**
	 *
	 * @param vOrigIndex Source vertex.
	 * @param vDestIndex Destination vertex.
	 * @return The weight of the edge connecting the two vertexes passed as arguments.
	 */
	int edgeCost(int vOrigIndex, int vDestIndex);

	/**
	 *
	 * @param id Id do Vertex.
	 *
	 * @return Return the Info class of the Vertex with that Id.
	 */
	T getInfoVertexId(int id) const;

	/**
	 *
	 * @param id Id do Vertex.
	 *
	 * @return Return the Vertex with that Id.
	 */
	Vertex<T>* getVertexId(int id) const;

	/**
	 *
	 * @param source Vertex source.
	 * @param dest Vertex destination.
	 *
	 * @return Returns the edge connecting the to vertexes passed as arguments.
	 */
	Edge<T> getEdgeFromVertex(Vertex<T>* source, Vertex<T>* dest);
};

#endif /* GRAPH_H_ */
