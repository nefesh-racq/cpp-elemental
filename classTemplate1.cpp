// ejemplo template de una clase
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

template <typename T>
class Test
{
public:
	Test() {};
	Test(T d) : dato(d) {}
	~Test();

	void mostrar() const;
	void setDato(T d);

private:
	T dato;
};

// definicion
template <typename T>
void Test<T>::mostrar() const
{
	cout << dato << endl;
}

// destructor
template <typename T>
Test<T>::~Test() {}

template <typename T>
void Test<T>::setDato(T d)
{
	dato = d;
}

// funcion plantilla para menjo de la plantailla
template <typename T>
void manejo(Test<T> clase, T dato, string nom)
{
	cout << nom << " ";
	clase.setDato(dato);
	clase.mostrar();
}

int main()
{
	Test<int> test;
	Test<double> testD;
	Test<string> testString;

	//test.mostrar();
	//testString.mostrar();

	manejo(test, 123, "enteros");
	manejo(testD, 123.321, "double");
	//manejo(testString, "cadena string", "string"); // error tipo de conversion de char a const char
	string dato = "esto es un dato";
	manejo(testString, dato, "string");

	return 0;
}
