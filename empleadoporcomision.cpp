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

private:
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

/***************************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

int main()
{
	EmpleadoPorComision empleado("sue", "jones", "222-22-2222", 10000, .06);

	cout << fixed << setprecision(2);

	cout << "Informacion del empleado obtenida por las funciones get: \n"
		<< "\nEl primer nombre es " << empleado.getPrimerNombre()
		<< "\nEl apellido paterno es " << empleado.getApellidoPaterno()
		<< "\nEl nro de seguro social es " << empleado.getNroSeguroSocial()
		<< "\nLas ventas brutas son " << empleado.getVentasBrutas()
		<< "\nLa tarifa por comision es " << empleado.getTarifaComision()
		<< endl;

	empleado.setVentasBrutas(8000);
	empleado.setTarifaComision(.1);

	cout << "\nInformacion actualizada del empleado. mostrada por la funcion imprimir"
		<< endl;

	empleado.imprimir();

	cout << "\n\nIngresos del empleado: $" << empleado.ingresos() << endl;

	return 0;
}
