// demostracion del operador sizeof
#include <iostream>
using std::endl;
using std::cout;

int main()
{
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;
	long double ld;
	int arreglo[20];
	int *ptr = arreglo;

	cout << "sizeof c = " << sizeof c
		<< "\tsizeof(char) = " << sizeof(char)
		<< "\nsizeof s = " << sizeof s
		<< "\tsizeof(short) = " << sizeof(short)
		<< "\nsizeof i = " << sizeof i
		<< "\tsizeof(int) = " << sizeof(int)
		<< "\nsizeof l = " << sizeof l
		<< "\tsizeof(long) = " << sizeof(long)
		<< "\nsizeof f = " << sizeof f
		<< "\tsizeof(float) = " << sizeof(float)
		<< "\nsizeof d = " << sizeof d
		<< "\tsizeof(double) = " << sizeof(double)
		<< "\nsizeof ld = " << sizeof ld
		<< "\tsizeof(long double) = " << sizeof(long double)
		<< "\nsizeof arreglo = " << sizeof arreglo
		<< "\nsizeof *ptr = " << sizeof *ptr 
		<< "\nsizeof ptr = " << sizeof ptr << endl;

	return 0;
}

