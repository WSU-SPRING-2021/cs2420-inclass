#include <iostream>
#include "queue.h"

using namespace std;

int main(){
  cs2420::Queue<int> s;

  s.enqueue(10);

  s.enqueue(30);

  cout << s.dequeue() << endl;
  
  return 0;
}