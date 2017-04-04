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

/*
 * ================================================================================================
 * Class Vertex
 * ================================================================================================
 */
template<class T>
class Vertex {
	T info;
	bool visited;
	bool processing;
	int indegree;
	double dist;
	vector<Edge<T> > adj;

public:
	Vertex(T in);
	friend class Graph<T>;

	void addEdge(Vertex<T> *dest, double w,int id);
	bool removeEdgeTo(Vertex<T> *d);
	T getInfo() const;
	void setInfo(T info);

	int getDist() const;
	int getIndegree() const;
	vector<Edge<T> >& getAdj();
	Vertex<T>& operator=(Vertex<T> v2);

	bool operator<(const Vertex<T> vertex);


	Vertex* path;
};

/* ================================================================================================
 * Class Edge
 * ================================================================================================
 */
template<class T>
class Edge {
	Vertex<T> * dest;
	double weight;
	int ID;
	int idRua;
	static int count;
public:
	Edge();
	Edge(Vertex<T> *d, double w,int id);
	Vertex<T>* getDest() const;
	int getID() const;
	int getIdRua() const;
	void setID(int id);
	void setIdRua(int id);
	friend class Graph<T>;
	friend class Vertex<T>;
};

/* ================================================================================================
 * Class Graph
 * ================================================================================================
 */
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
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w,int id);
	bool removeVertex(const T &in);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(Vertex<T> *v) const;
	int maxNewChildren(Vertex<T> *v, T &inf) const;
	vector<Vertex<T> *> getVertexSet() const;
	int getNumVertex() const;
	T findInfo(double id);
	Vertex<T>* getVertex(const T &v) const;
	void resetIndegrees();
	vector<Vertex<T>*> getSources() const;
	int getNumCycles();
	vector<T> topologicalOrder();
	vector<T> getPath(const T &origin, const T &dest);
	void unweightedShortestPath(const T &v);
	bool isDAG();
	void bellmanFordShortestPath(const T &s);
	void dijkstraShortestPath(const T &s);
	void floydWarshallShortestPath();
	int edgeCost(int vOrigIndex, int vDestIndex);
	vector<T> getfloydWarshallPath(const T &origin, const T &dest);
	void getfloydWarshallPathAux(int index1, int index2, vector<T> & res);
	T getInfoVertexId(int id) const;
	Vertex<T>* getVertexId(int id) const;
	Edge<T> getEdge(const T &source, const T &dest);
};

#endif /* GRAPH_H_ */
