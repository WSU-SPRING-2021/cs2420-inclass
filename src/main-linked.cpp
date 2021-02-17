#include <iostream>
#include "doubly-linked-list.h"
using namespace std;

int main(){
  cs2420::List<int> lst = {1,3,5,7,9};

  cout << lst << endl;

  lst.add_back(11).add_back(13).add_back(15);
  cout << lst << endl;

  lst.remove(1);

  cout << lst << endl;

  if(lst.find(23)){
    cout << "found\n";
  } else {
    cout << "not found\n";
  }

  for(int n : lst){
    cout << n << ".\n";
  }
  return 0;
}