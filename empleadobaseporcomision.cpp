#include <string>
using std::string;

class EmpleadoBaseMasComision
{
public:
	EmpleadoBaseMasComision(const string &, const string &, const string &,
							double = 0.0, double = 0.0, double = 0.0);

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

	void setSalarioBase(double);
	double getSalarioBase() const;

	double ingresos() const;
	void imprimir() const;

private:
	string primerNombre;
	string apellidoPaterno;
	string nroSeguroSocial;
	double ventasBrutas;
	double tarifaComision;
	double salarioBase;
};

/*****************************************************/
#include <iostream>
using std::cout;

EmpleadoBaseMasComision::EmpleadoBaseMasComision(const string &nombre, const string &apellido, const string &nss, 
		double ventas, double tarifa, double salario)
{
	// estas asignacines deben validarse
	primerNombre = nombre;
	apellidoPaterno = apellido;
	nroSeguroSocial = nss;

	setVentasBrutas(ventas);
	setTarifaComision(tarifa);
	setSalarioBase(salario);
}

void EmpleadoBaseMasComision::setPrimerNombre(const string &nombre)
{
	primerNombre = nombre;
}


string EmpleadoBaseMasComision::getPrimerNombre() const
{
	return primerNombre;
}

void EmpleadoBaseMasComision::setApellidoPaterno(const string &apellido)
{
	apellidoPaterno = apellido;
}

	
string EmpleadoBaseMasComision::getApellidoPaterno() const
{
	return apellidoPaterno;
}

void EmpleadoBaseMasComision::setNroSeguroSocial(const string &nss)
{
	nroSeguroSocial = nss;
}
	
string EmpleadoBaseMasComision::getNroSeguroSocial() const
{
	return nroSeguroSocial;
}


void EmpleadoBaseMasComision::setVentasBrutas(double ventas)
{
	ventasBrutas = (ventas < 0.0) ? 0.0 : ventas;
}
	

double EmpleadoBaseMasComision::getVentasBrutas() const
{
	return ventasBrutas;
}


void EmpleadoBaseMasComision::setTarifaComision(double tarifa)
{
	tarifaComision = (tarifa > 0.0 && tarifa < 1.0) ? tarifa : 0.0;
}
	
double EmpleadoBaseMasComision::getTarifaComision() const
{
	return tarifaComision;
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
	
void EmpleadoBaseMasComision::imprimir() const
{
	cout << "empleado por comision: " << primerNombre << " " << apellidoPaterno
		<< "\nnumero de seguro social: " << nroSeguroSocial
		<< "\nventas brutas: " << ventasBrutas
		<< "\ntarifa por comision: " << tarifaComision
		<< "\nsalario basico: " << salarioBase;
}

/**********************************************************************/
#include <iostream>
using std::endl;
using std::cout;
using std::fixed;

#include <iomanip>
using std::setprecision;

int main()
{
	EmpleadoBaseMasComision empleado("Bob", "tewis", "333-33-3333", 5000, -04, 300);

	// establece el formato de salida
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


	empleado.setSalarioBase( 1000 ); // establece el salario base

	cout << "\nInformacion actualizada del empleado, impresa por la funcion imprimir: \n"
		<< endl;
	empleado.imprimir(); // muestra la nueva informacion del empleado
	
	// muestra los ingresos del empleado
	cout << "\n\nIngresos del empleado: $" << empleado.ingresos() << endl;
	
	return 0;
}
