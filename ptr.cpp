#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int var = 10;
	int *ptr = &var;
	int *ptr2;

	ptr2 = &var;

	cout << "var: " << var << endl;
	cout << "*ptr: " << *ptr << endl;
	cout << "*ptr2:" << *ptr2 << endl;

	*ptr = 43;

	cout << "var: " << var << endl;
	cout << "*ptr: " << *ptr << endl;
	cout << "*ptr2:" << *ptr2 << endl;

	return 0;
}

