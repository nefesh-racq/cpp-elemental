#compilacion del programa con clase abstracta
BINARY = main

main: Empleado.o EmpleadoAsalariado.o EmpleadoPorHoras.o EmpleadoPorComision.o EmpleadoBaseMasComision.o main.o
	g++ -Iheaders Empleado.o EmpleadoAsalariado.o EmpleadoPorHoras.o EmpleadoPorComision.o EmpleadoBaseMasComision.o main.o -o $(BINARY)

Empleado.o: Empleado.cpp
	g++ -Iheaders -c Empleado.cpp

EmpleadoAsalariado.o:
	g++ -Iheaders -c EmpleadoAsalariado.cpp

EmpleadoPorHoras.o:
	g++ -Iheaders -c EmpleadoPorHoras.cpp

EmpleadoPorComision.o:
	g++ -Iheaders -c EmpleadoPorComision.cpp

EmpleadoBaseMasComision.o:
	g++ -Iheaders -c EmpleadoBaseMasComision.cpp

main.o:
	g++ -Iheaders -c main.cpp

clean:
	rm -f Empleado.o EmpleadoAsalariado.o EmpleadoPorHoras.o EmpleadoPorComision.o EmpleadoBaseMasComision.o main
