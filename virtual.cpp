#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual void imprimir() const;
	virtual int proceso() const;
};

void Base::imprimir() const
{
	cout << "clase Base" << endl;
}

int Base::proceso() const
{
	return 3 * 3;
}


/**************************************************************/
class Derivada : public Base
{
public:
	virtual void imprimir() const;
	virtual int proceso() const;
};

void Derivada::imprimir() const
{
	cout << "clase Derivada." << endl;
}

int Derivada::proceso() const
{
	return 9 * 9;
}

/**************************************************************/
int main()
{
	Derivada obj;

	obj.imprimir();
	cout << obj.proceso();
	cout << endl << endl;

	Base *basePtr = &obj;
	Base base;

	basePtr->imprimir();
	cout << basePtr->proceso() << endl;

	basePtr = &base;
	basePtr->imprimir();
	cout << basePtr->proceso() << endl;
	

	return 0;
}
