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
  Student(std::string name);
  Student(std::string name, bool ft);

  void show() const;

  friend std::ostream& operator<<(std::ostream& out, const Student &std);

  ~Student();
};

#endif