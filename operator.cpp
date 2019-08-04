// ejemplo sobrecarga de operadores
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;

class Complejo
{
	friend ostream &operator<<(ostream &, const Complejo &);
	friend istream &operator>>(istream &, Complejo &);

public:
	Complejo();
	Complejo(double, double);
	Complejo(const Complejo &);

	Complejo &operator+(const Complejo &);
	Complejo &operator-(const Complejo &);
	Complejo &operator=(const Complejo &);

private:
	double entero;
	double decimal;
};

Complejo::Complejo()
{
	entero = 0;
	decimal = 0;
}

Complejo::Complejo(double _entero, double _decimal)
{
	entero = _entero;
	decimal = _decimal;
}

Complejo::Complejo(const Complejo &obj)
{
	entero = obj.entero;
	decimal = obj.decimal;
}

Complejo &Complejo::operator+(const Complejo &derecho)
{
	entero = entero + derecho.entero;
	decimal = decimal + derecho.decimal;

	return *this;
}

Complejo &Complejo::operator-(const Complejo &derecho)
{
	entero = entero - derecho.entero;
	decimal = decimal - derecho.decimal;

	return *this;
}

Complejo &Complejo::operator=(const Complejo &derecho)
{
	entero = derecho.entero;
	decimal = derecho.decimal;

	return *this;
}


// friend
ostream &operator<<(ostream &output, const Complejo &obj)
{
	output << obj.entero << "." << obj.decimal;

	return output;
}


// friend
istream &operator>>(istream &input, Complejo &obj)
{
	cout << "Introdusca los numeros separados por enter:\n";
	input >> obj.entero;
	//input.ignore();
	input >> obj.decimal;

	return input;
}


/***************************************************************/
int main()
{
	Complejo n1(6, 67);
	Complejo n2(10, 43);
	Complejo n3;

	cout << "numero1: " << n1;
	cout << "\numero2: " << n2;
	n3 = n1 + n2;

	cout << "\nsuma n3 = " << n3;
	cout << '\n';

	cin >> n3;
	cout << "\nn3: " << n3;
	cout << '\n';


	return 0;
}
