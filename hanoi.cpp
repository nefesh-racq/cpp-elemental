#include <iostream>

using std::cout;
using std::endl;

void hanoi(int, int, int, int);

int main() {
  hanoi(4, 1, 2, 3);

  return 0;
}

void hanoi(int n, int a, int c, int b) {
  if (n == 1)
    cout << "mover el disco " << n << " desde la torre " << a << " hasta la torre " << c << endl;
  else {
    hanoi(n - 1, a, b, c);
    cout << "mover el disco " << n << " desde la torre " << a << " hasta la torre " << c << endl;
    hanoi(n - 1, b, c, a);
  }
}
