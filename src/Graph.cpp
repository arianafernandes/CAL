#include "Graph.h"

using namespace std;

template<class T>
struct vertex_greater_than {
	bool operator()(Vertex<T> * a, Vertex<T> * b) const {
		return a->getDist() > b->getDist();
	}
};

template<class T>
vector<Edge<T> >& Vertex<T>::getAdj() { return adj; }

template<class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	d->indegree--;
	typename vector<Edge<T> >::iterator it = adj.begin();
	typename vector<Edge<T> >::iterator ite = adj.end();
	while (it != ite) {
		if (it->dest == d) {
			adj.erase(it);
			return true;
		} else
			it++;
	}
	return false;
}

template<class T>
Vertex<T>::Vertex(T in) :
info(in), visited(false), processing(false), indegree(0), dist(0){
	path = NULL;
}

template<class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w,int id) {
	Edge<T> edgeD(dest, w,id);
	adj.push_back(edgeD);
}

//--
template<class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template<class T>
int Vertex<T>::getDist() const {
	return this->dist;
}

template<class T>
void Vertex<T>::setInfo(T info) {
	this->info = info;
}

template<class T>
int Vertex<T>::getIndegree() const {
	return this->indegree;
}

template<class T>
Edge<T>::Edge(Vertex<T> *d, double w,int id) :
dest(d), weight(w), ID(id) {}

template<class T>
Edge<T>::Edge(){

}

template<class T>
Vertex<T>* Edge<T>::getDest() const { return dest; }

template<class T>
int Edge<T>::getID() const { return ID; }

template<class T>
int Edge<T>::getIdRua() const{
	return this->idRua;
}
template<class T>
void Edge<T>::setID(int id){
	this->ID = id;
}

template<class T>
void Edge<T>::setIdRua(int id){
	this->idRua = id;
}

template<class T>
double Graph<T>::minLat = M_PI / 2;

template<class T>
double Graph<T>::minLong = M_PI;

template<class T>
double Graph<T>::maxLat = - M_PI / 2;

template<class T>
double Graph<T>::maxLong = -M_PI;


template<class T>
T Graph<T>::findInfo(double id) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info.getId() == id) {
			return (*it)->info;
		}
	Info f = Info();
	return f;

}

template<class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}
template<class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

template<class T>
bool Graph<T>::addVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++)
		if ((*it)->info == in)
			return false;
	Vertex<T> *v1 = new Vertex<T>(in);
	vertexSet.push_back(v1);
	return true;
}

template<class T>
bool Graph<T>::removeVertex(const T &in) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	for (; it != ite; it++) {
		if ((*it)->info == in) {
			Vertex<T> * v = *it;
			vertexSet.erase(it);
			typename vector<Vertex<T>*>::iterator it1 = vertexSet.begin();
			typename vector<Vertex<T>*>::iterator it1e = vertexSet.end();
			for (; it1 != it1e; it1++) {
				(*it1)->removeEdgeTo(v);
			}

			typename vector<Edge<T> >::iterator itAdj = v->adj.begin();
			typename vector<Edge<T> >::iterator itAdje = v->adj.end();
			for (; itAdj != itAdje; itAdj++) {
				itAdj->dest->indegree--;
			}
			delete v;
			return true;
		}
	}
	return false;
}

template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w,int id) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();

	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;
	vD->indegree++;
	vS->addEdge(vD, w,id);

	return true;
}

template<class T>
Edge<T> Graph<T>::getEdge(const T &source, const T &dest){
	vector<Edge<T>> adjs;
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	while (found != 1 && it != ite) {
		if ((*it)->info.getId() == source.getId()) {
			adjs = (*it)->getAdj();
			found = 1;
		}
	}
	typename vector<Edge<T>>::iterator itadj = adjs.begin();
	typename vector<Edge<T>>::iterator iteadj = adjs.end();
	Edge<T> temp;
	while (itadj != iteadj) {
		if((*itadj).dest->info.getId() == dest.getId()){
			return (*itadj);
		}
	}
	return temp;

}

template<class T>
Edge<T> Graph<T>::getEdgeFromVertex(Vertex<T>* source, Vertex<T>* dest){
	Edge<T> temp;
	for(unsigned int i = 0; i < source->getAdj().size(); i++){
		if(source->getAdj()[i].getDest()->getInfo().getId() == dest->getInfo().getId())
			return source->getAdj()[i];
	}
	return temp;
}



template<class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	typename vector<Vertex<T>*>::iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::iterator ite = vertexSet.end();
	int found = 0;
	Vertex<T> *vS, *vD;
	while (found != 2 && it != ite) {
		if ((*it)->info == sourc) {
			vS = *it;
			found++;
		}
		if ((*it)->info == dest) {
			vD = *it;
			found++;
		}
		it++;
	}
	if (found != 2)
		return false;

	vD->indegree--;

	return vS->removeEdgeTo(vD);
}

template<class T>
vector<T> Graph<T>::dfs() const {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	vector<T> res;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfs(*it, res);
	return res;
}

template<class T>
void Graph<T>::dfs(Vertex<T> *v, vector<T> &res) const {
	v->visited = true;
	res.push_back(v->info);
	typename vector<Edge<T> >::iterator it = (v->adj).begin();
	typename vector<Edge<T> >::iterator ite = (v->adj).end();
	for (; it != ite; it++)
		if (it->dest->visited == false) {
			//cout << "ok ";
			dfs(it->dest, res);
		}
}

template<class T>
vector<T> Graph<T>::bfs(Vertex<T> *v) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	q.push(v);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		typename vector<Edge<T> >::iterator it = v1->adj.begin();
		typename vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
			}
		}
	}
	return res;
}

template<class T>
int Graph<T>::maxNewChildren(Vertex<T> *v, T &inf) const {
	vector<T> res;
	queue<Vertex<T> *> q;
	queue<int> level;
	int maxChildren = 0;
	inf = v->info;
	q.push(v);
	level.push(0);
	v->visited = true;
	while (!q.empty()) {
		Vertex<T> *v1 = q.front();
		q.pop();
		res.push_back(v1->info);
		int l = level.front();
		level.pop();
		l++;
		int nChildren = 0;
		typename vector<Edge<T> >::iterator it = v1->adj.begin();
		typename vector<Edge<T> >::iterator ite = v1->adj.end();
		for (; it != ite; it++) {
			Vertex<T> *d = it->dest;
			if (d->visited == false) {
				d->visited = true;
				q.push(d);
				level.push(l);
				nChildren++;
			}
		}
		if (nChildren > maxChildren) {
			maxChildren = nChildren;
			inf = v1->info;
		}
	}
	return maxChildren;
}

template<class T>
Vertex<T>* Graph<T>::getVertex(const T &v) const {
	for (unsigned int i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == v)
			return vertexSet[i];
	return NULL;
}

template<class T>
T Graph<T>::getInfoVertexId(int id) const{
	for (unsigned int i = 0; i < vertexSet.size(); i++){
		if(vertexSet[i]->info.getId() == id)
			return vertexSet[i]->info;
	}
	return Info();
}

template<class T>
Vertex<T> * Graph<T>::getVertexFromId(int id) const{
	for (unsigned int i = 0; i < vertexSet.size(); i++){
		if(vertexSet[i]->info.getId() == id)
			return vertexSet[i];
	}
	return NULL;
}

template<class T>
void Graph<T>::resetIndegrees() {

	for (unsigned int i = 0; i < vertexSet.size(); i++)
		vertexSet[i]->indegree = 0;

	for (unsigned int i = 0; i < vertexSet.size(); i++) {

		for (unsigned int j = 0; j < vertexSet[i]->adj.size(); j++) {
			vertexSet[i]->adj[j].dest->indegree++;
		}
	}
}

template<class T>
vector<Vertex<T>*> Graph<T>::getSources() const {
	vector<Vertex<T>*> buffer;
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->indegree == 0)
			buffer.push_back(vertexSet[i]);
	}
	return buffer;
}


template<class T>
void Graph<T>::dfsVisit() {
	typename vector<Vertex<T>*>::const_iterator it = vertexSet.begin();
	typename vector<Vertex<T>*>::const_iterator ite = vertexSet.end();
	for (; it != ite; it++)
		(*it)->visited = false;
	it = vertexSet.begin();
	for (; it != ite; it++)
		if ((*it)->visited == false)
			dfsVisit(*it);
}

template<class T>
void Graph<T>::dfsVisit(Vertex<T> *v) {
	v->processing = true;
	v->visited = true;
	typename vector<Edge<T> >::iterator it = (v->adj).begin();
	typename vector<Edge<T> >::iterator ite = (v->adj).end();
	for (; it != ite; it++) {
		if (it->dest->processing == true)
			numCycles++;
		if (it->dest->visited == false) {
			dfsVisit(it->dest);
		}
	}
	v->processing = false;
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) {

	list<T> buffer;
	Vertex<T>* v = getVertex(dest);

	buffer.push_front(v->info);
	while (v->path != NULL && v->path->info != origin) {
		v = v->path;
		buffer.push_front(v->info);
	}
	if (v->path != NULL)
		buffer.push_front(v->path->info);

	vector<T> res;
	while (!buffer.empty()) {
		res.push_back(buffer.front());
		buffer.pop_front();
	}
	return res;
}
template<class T>
void Graph<T>::dijkstraShortestPath(const T &s) {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
		vertexSet[i]->processing = false;
	}

	Vertex<T>* v = getVertex(s);
	v->dist = 0;

	vector<Vertex<T>*> pq;
	pq.push_back(v);

	make_heap(pq.begin(), pq.end());

	while (!pq.empty()) {

		v = pq.front();
		pop_heap(pq.begin(), pq.end());
		pq.pop_back();

		for (unsigned int i = 0; i < v->adj.size(); i++) {
			Vertex<T>* w = v->adj[i].dest;
			if (v->dist + v->adj[i].weight < w->dist) {

				w->dist = v->dist + v->adj[i].weight;
				w->path = v;

				if (!w->processing) {
					w->processing = true;
					pq.push_back(w);
				}

				make_heap(pq.begin(), pq.end(), vertex_greater_than<T>());
			}
		}
	}
}

template<class T>
int Graph<T>::edgeCost(int vOrigIndex, int vDestIndex) {
	if (vertexSet[vOrigIndex] == vertexSet[vDestIndex])
		return 0;

	for (unsigned int i = 0; i < vertexSet[vOrigIndex]->adj.size(); i++) {
		if (vertexSet[vOrigIndex]->adj[i].dest == vertexSet[vDestIndex])
			return vertexSet[vOrigIndex]->adj[i].weight;
	}

	return INT_INFINITY;
}

template<class T>
void Vertex<T>::setDist(int d){
	this->dist = d;
}
template<class T>
double Edge<T>::getWeight() const{
return this->weight;
}

template class Graph<Info>;
template class Vertex<Info>;
template class Edge<Info>;
