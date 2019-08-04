// plantillas template
#include <iostream>

using std::cout;
using std::endl;

template <class T>
T maximo(T var1, T var2, T var3) {
  T valorMaximo = var1;

  if (var2  > valorMaximo)
    valorMaximo = var2;

  if (var3 > valorMaximo)
    valorMaximo = var3;

  return valorMaximo;
}

int main() {
  int a1 = 4, b1 = 2, c1 = 9;
  float a2 = 3.5, b2 = 3.3, c2 = 1.3;
  char a3 = 'f', b3 = 'c', c3 = 'a';
  
  cout << "maximo (" << a1 << ", " << b1 << ", " <<  c1 << ") = " << maximo(a1, b1, c1) << endl;
  cout << "maximo (" << a2 << ", " << b2 << ", " <<  c2 << ") = " << maximo(a2, b2, c2) << endl;
  cout << "maximo (" << a3 << ", " << b3 << ", " <<  c3 << ") = " << maximo(a3, b3, c3) << endl;

  return 0;  
}
