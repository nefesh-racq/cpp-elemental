#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
	A() : _x(0), _y(0), _z(new int(0)) { cout << "constructor defecto\n"; }
	A(int x, int y, int z) : _x(x), _y(y), _z(new int(z)) { cout << "constructor sobrecargado\n"; }
	A(const A& origen)
	{
		cout << "constructor de copia..\n";
		_x = origen._x;
		_y = origen._y;
		_z = new int(*origen._z);
	}
	~A()
	{
		cout << "destructor...\n";
/*
		// esto puede dar error ya que en la linea #62 los punteros de ambos objetos
		// apuntan a la misma memoria asi que al tratar de liberar memoria mostrara un error
		// por que no puede liberar memoria del mismo puntero dos veces
		if (_z != NULL)
		{
			cout << "_z no es null " << *_z << "\n";
			delete _z;
		}*/
	}

	void print() const 
	{ 
		cout << "(x, y, z) = (" << _x << ", " << _y << ", " << *_z << ")\n"; 
	}
	void setZ(int z)
	{
		//_z = new int(z);
		*_z = z;
	}

	// llamada en cascada es posible al retornar la referencia al mismo objeto
	// this es un puntero a su clase se define:
	// const Clase * this;
	A &setX(int x)
	{
		_x = x;

		return *this;
	}

private:
	int _x;
	int _y;
	int* _z;
};

int main()
{
	A a(10, 12, 14);
	A b;
	// si no se define un constructor de copia explicito
	// esto cambia el valor de todos por que usa memoria dinamica,
	// el constructor de copia por defecto copia todos los datos pero no
	// reserva memoria para cada puntero de cada objeto
	A c = a;	// equivale a A c(a); solo en la declaracion si fuera solo asignacion no llama al constructor de copia

	cout << "a"; a.print();

	// b = a; en este caso da error por que usamos punteros y la asignacion directa
	// copia los miembros uno por uno y no reserva memoria, asi que _z apuntan a la misma memoria
	// si se trabaja con punteros/memoria dinamia es necesario sobrecargar el operador =
	b = a;
	cout << "b"; b.print();

	cout << "c"; c.print();

	// puede causar errores porque usamos punteros(memoria dinamica), esto hace que los dos objetos
	// a y b tengan el puntero _z apuntando al mismo segmento de memoria, ya que 
	// = copia los miembros a nivel de bit y no reserva memoria para nuestro puntero
	b.setZ(11);	// en este caso b comarte la memoria con a en sus punteros
	//c.setZ(11);	// en este caso c tiene su propia memoria del puntero _z por que en su declaracion usa el constructor de copia
	
	cout << endl;
	cout << "a"; a.print();
	cout << "b"; b.print();
	cout << "c"; c.print();

	// reserva de memoria dinamica
	A* d = new A();

	cout << "d"; d->print();

	*d = a;
	cout << "d"; d->print();

	d->setZ(111);
	cout << endl;
	cout << "a"; a.print();
	cout << "b"; b.print();
	cout << "c"; c.print();
	cout << "d"; d->print();

	A e(a);
	cout << "e"; e.print();

	delete d;	// liberamos la memoria asignada

	// llamada en cascada es posible al retornar la referencia al mismo objeto
	a.setX(99).setX(55).print();

	return 0;
}
