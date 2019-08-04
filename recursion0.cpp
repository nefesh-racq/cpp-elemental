#include <iostream>

using std::cout;
using std::endl;

#include <iomanip>

using std::setw;

unsigned long factorial(unsigned long);
unsigned long fibonacci(unsigned long);

int main() {
  for (int i = 0; i <= 10; i++) {
    cout << setw(2) << i << "! = " << factorial(i) << endl;
  }

  
  for (int i = 0; i <= 10; i++) {
    cout << "fibonacci( " << i << " ) = " << fibonacci(i) << endl;
  }

  cout << "fibonacci(20) = " << fibonacci(20) << endl;
  cout << "fibonacci(30) = " << fibonacci(30) << endl;
  cout << "fibonacci(35) = " << fibonacci(35) << endl;
  cout << "fibonacci(40) = " << fibonacci(40) << endl;

  return 0;
}

unsigned long factorial(unsigned long num) {
  if (num <= 1)
    return 1;
  else
    return num * factorial(num -1);
}

unsigned long fibonacci(unsigned long num) {
  if ((num == 0) || (num == 1))
    return num;
  else
    return fibonacci(num -1) + fibonacci(num - 2);
}
