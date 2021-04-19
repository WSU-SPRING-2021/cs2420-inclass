#include <iostream>
#include <fstream>
#include "graph/digraph.h"
#include "graph/dfs.h"

using namespace std;

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
  return 0;
}
