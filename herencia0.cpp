// ejemplo de miembros tipo protected
// son visibles por la clase derivada lo cual no es tan bueno
// ya que si modificamos los miembros datos de la clase base tendriamos que modificar
// la clase derivada y podriamos asignar datos invalidos a los miembros de la clase bae
// No debe depender de los datos miembros de la clase base, si no de los servicios que estos
// proporcionan a la clase derivada
#include <string>
using std::string;

class EmpleadoPorComision
{
public:
	EmpleadoPorComision(const string &, const string &, const string &,
					double = 0.0, double = 0.0);
	
	void setPrimerNombre(const string &);
	string getPrimerNombre() const;

	void setApellidoPaterno(const string &);
	string getApellidoPaterno() const;

	void setNroSeguroSocial(const string &);
	string getNroSeguroSocial() const;

	void setVentasBrutas(double);
	double getVentasBrutas() const;

	void setTarifaComision(double);
	double getTarifaComision() const;

	double ingresos() const;
	void imprimir() const;

protected:
	string primerNombre;
	string apellidoPaterno;
	string nroSeguroSocial;
	double ventasBrutas;
	double tarifaComision;
};

/************************************************************/
#include <iostream>
using std::cout;

EmpleadoPorComision::EmpleadoPorComision(const string &nombre, const string &apellido,
										const string &nss, double ventas, double tarifa)
{
	// deben validarse, aqui no se estan validando
	primerNombre = nombre;
	apellidoPaterno = apellido;
	nroSeguroSocial = nss;

	// se validan
	setVentasBrutas(ventas);
	setTarifaComision(tarifa);
}

// establece el primer nombre
void EmpleadoPorComision::setPrimerNombre(const string &nombre)
{
	primerNombre = nombre;
}

string EmpleadoPorComision::getPrimerNombre() const
{
	return primerNombre;
}

void EmpleadoPorComision::setApellidoPaterno(const string &apellido)
{
	apellidoPaterno = apellido;
}

string EmpleadoPorComision::getApellidoPaterno() const
{
	return apellidoPaterno;
}

void EmpleadoPorComision::setNroSeguroSocial(const string &nss)
{
	nroSeguroSocial = nss;
}

string EmpleadoPorComision::getNroSeguroSocial() const
{
	return nroSeguroSocial;
}

void EmpleadoPorComision::setVentasBrutas(double ventas)
{
	ventasBrutas = (ventas < 0.0) ? 0.0 : ventas;
}

double EmpleadoPorComision::getVentasBrutas() const
{
	return ventasBrutas;
}

void EmpleadoPorComision::setTarifaComision(double tarifa)
{
	tarifaComision = (tarifa > 0.0 && tarifa < 1.0) ? tarifa : 0.0;
}

double EmpleadoPorComision::getTarifaComision() const
{
	return tarifaComision;
}

double EmpleadoPorComision::ingresos() const
{
	return tarifaComision * ventasBrutas;
}

void EmpleadoPorComision::imprimir() const
{
	cout << "empleado por comision: " << primerNombre << " " << apellidoPaterno
		<< "\nnumero de seguro social: " << nroSeguroSocial
		<< "\nventas brutas: " << ventasBrutas
		<< "\ntarifa por comision: " << tarifaComision;
}

/*******************************************************************
*
********************************************************************/
#include <string>
using std::string;

class EmpleadoBaseMasComision : public EmpleadoPorComision
{
public:
	EmpleadoBaseMasComision(const string &, const string &, const string &,
			double = 0.0, double = 0.0, double = 0.0);

	void setSalarioBase(double);
	double getSalarioBase() const;

	double ingresos() const;
	void imprimir() const;

private:
	double salarioBase;
};

/***************************/
#include <iostream>
using std::cout;

EmpleadoBaseMasComision::EmpleadoBaseMasComision(const string &nombre, const string &apellido,
		const string &nss, double ventas, double tarifa, double salario)
	// llamada explicita al constructor de la clase base
	: EmpleadoPorComision(nombre, apellido, nss, ventas, tarifa)
{
	setSalarioBase(salario);
}

void EmpleadoBaseMasComision::setSalarioBase(double salario)
{
	salarioBase = (salario < 0.0) ? 0.0 : salario;
}

double EmpleadoBaseMasComision::getSalarioBase() const
{
	return salarioBase;
}

double EmpleadoBaseMasComision::ingresos() const
{
	return ventasBrutas * tarifaComision + salarioBase;
}

// imprime el objeto EmpleadoBaseMasComision
void EmpleadoBaseMasComision::imprimir() const
{
	// la clase derivada no puede acceder a los datos privados de la clase base
	cout << "empleado por comision con salario base: " << primerNombre << ' '
		<< apellidoPaterno << "\nnumero de seguro social: " << nroSeguroSocial
		<< "\nventas brutas: " << ventasBrutas
		<< "\ntarifa de comision: " << tarifaComision
		<< "\nsalario base: " << salarioBase;
}

/********************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

int main()
{
	EmpleadoBaseMasComision empleado("Bob", "Lewis", "333-33-3333", 5000, 0.04, 300);

	cout << fixed << setprecision(2);

	// obtiene los datos del empleado por comisión
	cout << "Informacion del empleado obtenida por las funciones get: \n"
		<< "\nEl primer nombre es " << empleado.getPrimerNombre()
		<< "\nEl apellido paterno es " << empleado.getApellidoPaterno()
		<< "\nEl numero de seguro social es "
		<< empleado.getNroSeguroSocial()
		<< "\nLas ventas brutas son " << empleado.getVentasBrutas()
		<< "\nLa tarifa de comision es " << empleado.getTarifaComision()
		<< "\nEl salario base es " << empleado.getSalarioBase() 
		<< endl;

	empleado.setSalarioBase(1000);

	cout << "\nInformacion actualizada del empleado, impresa por la funcion imprimir: \n"
		<< endl;

	empleado.imprimir();

	cout << "\n\nIngresos del empleado: $" << empleado.ingresos()
		<< endl;

	return 0;
}
