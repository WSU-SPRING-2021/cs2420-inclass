#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

int main(){
  cs2420::Stack<int> s;

  s.push(10);

  s.push(30);

  cout << s.pop() << endl;

  string msg = "Good morning";

  cs2420::Stack<char> r;

  for(char c : msg){
    r.push(c);
  }

  while(!r.empty()){
    cout << r.pop();
  }

  cout << endl;


  return 0;
}