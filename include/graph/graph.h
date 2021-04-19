#ifndef _UNDIRECTED_GRAPH_H_
#define _UNDIRECTED_GRAPH_H_
#include <iostream>
#include <list>
#include <sstream>
#include <string>

namespace cs2420 {

class Graph {
protected:
  const int _V; // Number of vertices (nodes)
  int _E = 0;   // Number of edges
  std::list<int> *adj;

public:
  Graph(int V): _V(V), adj(new std::list<int>[V]{}){}

  int V() { return _V; }
  int E() { return _E; }

  std::list<int>& adjList(int v){
    return adj[v];
  }

  virtual void addEdge(int v, int w){
    if(v < 0 || v >= _V) return;
    if(w < 0 || w >= _V) return;

    adj[v].push_back(w);
     _E++;
  }

  virtual void removeEdge(int v, int w){
    if(v < 0 || v >= _V) return;
    if(w < 0 || w >= _V) return;

    adj[v].remove(w);
    _E--;
  }

  virtual int degree(int v){
    if(v < 0 || v >= _V) return -1; // invalid degree
    return adj[v].size();
  }

  friend std::istream& operator>>(std::istream& in, Graph &g){
    std::string line;
    while(std::getline(in, line)){
      if(!line.empty()){
        std::stringstream ss(line);
        int u; ss >> u;
        char ignore; ss >> ignore;
        int v;
        while(ss>>v){
          g.addEdge(u, v);
        }
      }
    }

    return in;
  }

  friend std::ostream& operator<<(std::ostream &out, const Graph &g){
    out << g._V << std::endl;
    out << g._E << std::endl;
    for(int v = 0; v < g._V; v++){
      out << v << ": ";
      for(int w : g.adj[v]){
        out << w << " ";
      }
      out << std::endl;
    }

    return out;
  }

  virtual ~Graph(){
    delete [] adj;
  }

};





}



#endif