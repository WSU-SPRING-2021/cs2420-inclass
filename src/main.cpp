#include <iostream>
#include <iomanip>
#include "student.h"
#include "counter.h"
#include "bag.h"

using namespace std;

// Structures

enum class FormattingChar {
  Equal, Underscore, Astrisk
};

struct MTable {
  int size;
  FormattingChar ch;
};

// function prototypes
void print_formatted_line(int, const MTable & t); 
void print_formatted_num(int, int);

void print_table(const MTable &t) {
  for(int i = 1; i <= t.size; i++){
    for(int j = 1; j <= t.size; j++) {
      print_formatted_num(i, j);
    }
    cout << endl;
    print_formatted_line(i, t);
  }
}

void print_formatted_line(int i, const MTable & t){
  if(i == 1) {
    for(int k = 0; k < 6 * t.size; k++){
      switch (t.ch){
        case FormattingChar::Equal: 
          cout << '='; 
          break;
        case FormattingChar::Underscore: 
          cout << '_'; 
          break;
        case FormattingChar::Astrisk: 
          cout << '*'; 
          break;
      }
    }

    cout << endl;
  }
}

void print_formatted_num(int i, int j) {
  if(j == 1){
    cout << setw(3) << i * j << setw(3) << '|';
  } else {
    cout << setw(6) << i *j;
  }
}

int main() {
  Bag<int> bi;
  cout << bi.get_capacity() << ", " << bi.get_size() << endl;
  bi.insert_last(16).insert_last(8).insert_last(4).insert_last(2).insert_last(1);
  cout << bi << endl;
  cout << bi.get_capacity() << ", " << bi.get_size() << endl;


  Bag<double> bd {1.3, 3.5, 2.5, 6., 8., 2.5, 9.4};
  cout << bd << endl;
  cout << bd.get_capacity() << ", " << bd.get_size() << endl;

  for(double d : bd){
    cout << d << endl;
  }

  bd.remove_last();
cout << bd << endl;

  /*
  Counter c(1, 3);

  cout << c.next() << ',' << c.next() << ',' << c.next() << endl;

  cout << ++c << ',' << --c << endl;

  (c * 5) * 4;
  cout << c.next() << endl;
  c+ 100;

  cout << c << endl;*/

  /*
  Student sam ("Sam Smith");
  Student jane {"Jane Doe", false};

  cout << sam;
  cout << jane;


  MTable big = {12, FormattingChar::Equal};
  MTable small = {6, FormattingChar::Astrisk};

  print_table(big);
  print_table(small);
  */
  return 0;
}