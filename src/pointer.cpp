#include <iostream>
#include "student.h"
using namespace std;

int main() {
  Student *sam = new Student("Sam Smith");
  Student *jane = new Student("Jane Doe", false);

  sam->show();
  jane->show();

  delete sam;
  delete jane;
  sam = nullptr;
  jane = nullptr;


  int num = 100;
  int another_number = 1000;
  int &ref = another_number;

  int *iptr = &num;

  cout << num << endl;
  cout << iptr << endl;
  cout << *iptr << endl;


  iptr = &another_number;
  cout << *iptr << endl;

  cout << ref << endl;
  another_number = 999;
  cout << ref << endl;

  return 0;
}