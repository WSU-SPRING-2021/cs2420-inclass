#include <iostream>
#include <fstream>
#include "graph/digraph.h"
#include "graph/dfs.h"

using namespace std;

void printVector(vector<int> v, string label){
  cout << label << ": ";
  for(int e : v){
    cout << "  " << e;
  }
  cout << endl;
}

int main(){
  ifstream fin("../src/resources/tinyUG.txt");
  int nodes; fin >> nodes;

  cs2420::Graph ug(nodes);
  fin >> ug;

  cout << ug;

  cs2420::DepthFirstSearch dfs(ug);

  fin.close();


  fin = ifstream("../src/resources/tinyDG.txt");
  fin >> nodes;

  cs2420::Digraph dg(nodes);
  fin >> dg;

  cout << dg;

  fin.close();

  // Testing topological sort
  fin = ifstream("../src/resources/topoDG.txt");
  fin >> nodes;

  cs2420::Digraph dg2(nodes);
  fin >> dg2;
  fin.close();

  cs2420::DepthFirstSearch dfs2(dg2);
  printVector(dfs2.preorder(), "Preorder");
  printVector(dfs2.postorder(), "Postorder");
  printVector(dfs2.topologicalOrder(), "Topological order");

  return 0;
}
