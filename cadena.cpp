#include <iostream>
using namespace std;

int main() {
  char cad[] = "esto es una cadena";

  for (int i = 0; cad[i] != '\0'; i++)
    cout << cad[i];

  return 0;
}
