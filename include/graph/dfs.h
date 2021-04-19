#ifndef _DEPTH_FIRST_SEARCH_H
#define _DEPTH_FIRST_SEARCH_H

#include "graph.h"

namespace cs2420 {
enum class VColor { White, Grey, Black };
struct VertexAttr {
  VColor color = VColor::White;
  int stime = 0; // Start (Discover) time
  int ftime = 0;  // Finish time
};

class DepthFirstSearch {
public:
  DepthFirstSearch(Graph& g): g(g), attr(new VertexAttr[g.V()]){
    for(int v = 0; v < g.V(); v++){
      if(attr[v].color == VColor::White){
        dfs(v);
      }
    }
  }

  ~DepthFirstSearch(){
    delete [] attr;
  }
private:
  Graph& g;
  VertexAttr* attr;

  void dfs(int u){
    static int time = 0;

    attr[u].color = VColor::Grey;
    attr[u].stime = ++time;

    for(int v : g.adjList(u)){
      if(attr[v].color == VColor::White){
        dfs(v);
      }
    }

    attr[u].color = VColor::Black;
    attr[u].ftime = ++time;
  }
};

}
#endif