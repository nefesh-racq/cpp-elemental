#include <iostream>
using std::cout;
using std::endl;

class Objeto
{
public:
	Objeto()
	{
		cout << "Constructor clase objeto." << endl;
	}

	~Objeto()
	{
		cout << "Destructor clase objeto." << endl;
	}
};

class SuperBase
{
public:
	SuperBase()
	{
		cout << "Constructor clase super base." << endl;
	}

	~SuperBase()
	{
		cout << "Destructor clase super base." << endl;
	}

	Objeto obj;
};


class Base : public SuperBase
{
public:
	Base();
	~Base();

//	Objeto obj;
};

Base::Base() : SuperBase()
{
	cout << "Constructor clase base." << endl;
}

Base::~Base()
{
	cout << "Destructor clase base." << endl;
}

/****************************************************/
class Derivada : public Base
{
public:
	Derivada();
	~Derivada();

//	Objeto obj;
};

Derivada::Derivada() : Base()
{
	cout << "Constructor clase derivada." << endl;
}

Derivada::~Derivada()
{
	cout << "Destructor clase derivada." << endl;
}

/****************************************************/

int main()
{
	cout << "Orden de llamada de los constructores y destructores." << endl;

	Derivada obj;

	return 0;
}

