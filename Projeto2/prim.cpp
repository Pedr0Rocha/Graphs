#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>    
#include <map>
using namespace std;

#define INFITIY 9999

typedef vector<pair<int, int> > vpi;
vector<vpi> adjList;
vector<int> chaves;
vector<int> pais;
map<int,int> Q;
int numVertices, numEdges;

void mstPrim(int initialVertex) {
	for (int i = 0; i < numVertices; i++) {
		if (i == initialVertex)
			chaves[i] = 0;
		else
			chaves[i] = INFITIY;
		pais[i] = -1;
		Q.insert(pair<int,int>(chaves[i], i));
	}
	chaves[initialVertex] = 0;
	while(!Q.empty()) {
		int u = Q.at(0);
		for (uint i = 0; i < adjList[u].size(); i++) {
			pair<int,int> v = adjList[u][i];
			if (Q.at(v.first) && v.second < chaves[v.first]) {
				pais[v.first] = u;
				chaves[v.first] = v.second;
			}
		}
	}
}

int main() {	
	cin >> numVertices >> numEdges;
	adjList.assign(numVertices, vector<pair<int,int> >());

	chaves.assign(numVertices, int());
	pais.assign(numVertices, int());

	for (int i = 0; i < numEdges; i++) {
		int u, v, weight;
		cin >> u >> v >> weight;
		adjList[u].push_back(pair<int,int>(v, weight));
	}

	mstPrim(1);
	for (int i = 0; i < numVertices; i++) {
		for (uint j = 0; j < adjList[i].size(); j++) { 
			cout << "Vertex: " << i << " Connected To: " << adjList[i][j].first << " Weight: " << adjList[i][j].second << endl;
		}
	}
	
	return 0;
}


/*
	mst-prim(G, w, r)
	for cada u em G.V
	    u.chave = infinito
	    u.pai = null
	r.chave = 0
	Q = G.V
	while Q != 0
		u = extract-min(Q)
		for cada v em u.adj
			if (v em Q && w(u, v) < v.chave)
				v.pai = u
				v.chave = w(u, v)

*/