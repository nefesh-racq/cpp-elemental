#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <class T>
T mensaje(T msn) {
  return msn;
}


int main() {
  int a = 10;
  char b = 'x';
  float c = 3.2;
  string d = "nombre";

  cout << mensaje(a) << endl;
  cout << mensaje(b) << endl;
  cout << mensaje(c) << endl;
  cout << mensaje(d) << endl;

  return 0;
}
