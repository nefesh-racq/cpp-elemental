#include <iostream>
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class Enteros
{
	friend ostream &operator<<(ostream &, const Enteros &);
	friend istream &operator>>(istream &, Enteros &);

public:
	Enteros();
	Enteros(int, int, int);
	Enteros(const Enteros &);
	~Enteros();

	Enteros &operator+(const Enteros &);
	Enteros &operator-(const Enteros &);
	Enteros &operator=(const Enteros &);
	Enteros &operator+=(const Enteros &);
	Enteros &operator+=(int);
	Enteros &operator++();
	Enteros operator++(int);

private:
	int n1;
	int n2;
	int n3;
};


Enteros::Enteros()
{
	n1 = n2 = n3 = 0;
}

Enteros::Enteros(int nro1, int nro2, int nro3)
{
	n1 = nro1;
	n2 = nro2;
	n3 = nro3;
}

Enteros::Enteros(const Enteros &obj)
{

}

Enteros::~Enteros()
{}

Enteros	&Enteros::operator+(const Enteros &der)
{
	n1 += der.n1;
	n2 += der.n2;
	n3 += der.n3;

	return *this;
}

Enteros &Enteros::operator-(const Enteros &der)
{
	n1 -= der.n1;
	n2 -= der.n2;
	n3 -= der.n3;

	return *this;
}

Enteros &Enteros::operator=(const Enteros &der)
{
	n1 = der.n1;
	n2 = der.n2;
	n3 = der.n3;

	return *this;
}

Enteros &Enteros::operator+=(const Enteros &der)
{
	n1 += der.n1;
	n2 += der.n2;
	n3 += der.n3;

	return *this;
}


Enteros &Enteros::operator+=(int der)
{
	n1 += der;
	n2 += der;
	n3 += der;

	return *this;
}

Enteros &Enteros::operator++()
{
	n1++;
	n2++;
	n3++;

	return *this;
}

Enteros Enteros::operator++(int)
{
	Enteros tmp(n1, n2, n3);

	n1++;
	n2++;
	n3++;

	return tmp;
}

// funciones friend
ostream &operator<<(ostream &output, const Enteros &obj)
{
	output << obj.n1 << '-' << obj.n2 << '-' << obj.n3;

	return output;
}

istream &operator>>(istream &input, Enteros &obj)
{
	input >> obj.n1 >> obj.n2 >> obj.n3;
}

/************************************************************/
int main()
{
	Enteros a(1, 2, 3);
	Enteros b(4, 5, 6);
	Enteros c;

	cout << a << '\n' << b << '\n';

	c = a;
	cout << c << '\n';

	c = a + b;
	cout << c << '\n';

	//c++;
	cout << c++ << '\n';

	//++c;
	cout << ++c << '\n';

	c += 5;
	cout << c << '\n';

	return 0;
}
