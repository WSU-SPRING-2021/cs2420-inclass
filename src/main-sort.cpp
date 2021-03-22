#include <iostream>
#include "bag.h"
using namespace std;

int main(){
  Bag<int> b = {3, 4, 6, 7, 9, 2, 3, 10};

  cout << "Before: " << b;
  b.sortByBubble(true);

  cout << "\nAfter: " << b;
  cout << endl;
  return 0;
}