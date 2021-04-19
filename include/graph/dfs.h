#ifndef _DEPTH_FIRST_SEARCH_H
#define _DEPTH_FIRST_SEARCH_H

#include "graph.h"
#include <vector>

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

  std::vector<int> topologicalOrder(){
    if(!g.directed()){
      throw std::runtime_error("Graph must be directed");
    }
    std::vector<int> t;
    for(int i = post.size() - 1; i >= 0; i--){
      t.push_back(post[i]);
    }

    return t;
  }
  std::vector<int> postorder() { return post; }
  std::vector<int> preorder() { return pre; }
  
  ~DepthFirstSearch(){
    delete [] attr;
  }
private:
  Graph& g;
  VertexAttr* attr;
  std::vector<int> pre, post;

  void dfs(int u){
    static int time = 0;

    attr[u].color = VColor::Grey;
    attr[u].stime = ++time;
    pre.push_back(u);
    for(int v : g.adjList(u)){
      if(attr[v].color == VColor::White){
        dfs(v);
      }
    }

    attr[u].color = VColor::Black;
    attr[u].ftime = ++time;
    post.push_back(u);
  }
};

}
#endif