#include <iostream>

using std::cout;
using std::endl;

void s(int n, int a, int b, int c) {
  if (c < n) {  
    int tmp = c;
    
    c = a + b;
    a = b;
    b = c;
    
    cout << c << " ";

    s(n - 1, a, b, c);
  }
  
  return;
}

int main() {
  s(100, 0, 1, 0);
}
