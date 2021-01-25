#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <string>

class Student {
private:
  int id;
  std::string name;
  bool fulltime;

public:
  Student(std::string name):id(-1), name(name), fulltime(true){}
  Student(std::string name, bool ft):id(-1), name(name), fulltime(ft){}

  void show() {
    std::cout << "ID: " << id << std::endl
              << "NAME: " << name << std::endl
              << "FULLTIME: " << fulltime << std::endl;
  }

  ~Student(){}
};

#endif