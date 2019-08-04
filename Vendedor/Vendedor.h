// definicion de la clase vendedor
// funciones miembro definias en vendedor.cpp
#ifndef VENDEDOR_H
#define VENDEDOR_H

class Vendedor
{
public:
	Vendedor();		// constructor
	void obtenerVentasDelUsuario();		// recibe las ventas del teclado
	void establecerVentas(int, double);	// establece las ventas para un mes especifico
	void imprimirVentasAnuales();		// resume e imprime las ventas

private:
	double ventas[12];		// 12 meses para las ventas

	double totalVentasAnuales();	// prototipo para la funcion utilitaria
};

#endif	// VENDEDOR_H

