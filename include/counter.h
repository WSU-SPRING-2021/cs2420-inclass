#ifndef _COUNTER_H_
#define _COUNTER_H_
#include <iostream>
class Counter {
private:
  int start = 1, step = 1;
  int current;

public:
  Counter(int start, int step): start(start), step(step), current(start) {}

  int operator++() {
    return next();
  }

  Counter& operator*(int times) {
    for (int i = 0; i < times; i++) {
      next();
    }
    return *this;
  }


  Counter& operator+(int jump){
    current += jump;
    return *this;
  }


  int next() { 
    current += step;
    return current;
  }

  int operator--() {
    return prev();
  }

  int prev() {
    if(current - step > start) {
      current -= step;
    }else {
      current = start;
    }

    return current;
  }

  friend std::ostream& operator<<(std::ostream& out, const Counter& c){
    return out << c.current;
  }
};

#endif