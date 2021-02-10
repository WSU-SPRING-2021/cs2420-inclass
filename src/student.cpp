#include "student.h"

Student::Student(std::string name):id(-1), name(name), fulltime(true){}
Student::Student(std::string name, bool ft):id(-1), name(name), fulltime(ft){}

void Student::show() const {
  std::cout << *this;
}

Student::~Student(){}

std::ostream& operator<<(std::ostream& out, const Student &std){
  out << "ID: " << std.id << std::endl
      << "NAME: " << std.name << std::endl
      << "FULLTIME: " << std.fulltime << std::endl;

  return out;
}
