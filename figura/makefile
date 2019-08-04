# ejecucion del programa
BINARY = main.out

main.out: Cuadrado.o Triangulo.o main.o
	g++ -Iheaders Cuadrado.o Triangulo.o main.o -o $(BINARY)

Cuadrado.o: Cuadrado.cpp
	g++ -Iheaders -c Cuadrado.cpp

Triangulo.o: Triangulo.cpp
	g++ -Iheaders -c Triangulo.cpp

main.o: main.cpp
	g++ -Iheaders -c main.cpp

clean:
	rm -f Cuadrado.o Triangulo.o main.o main.out