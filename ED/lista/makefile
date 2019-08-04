#
#
OBJ=Nodo.o Lista.o main.o
BINARY=main

$(BINARY): $(OBJ)
	g++ -Ihaders $(OBJ) -o $(BINARY)

Nodo.o: Nodo.cpp
	g++ -Iheaders -c Nodo.cpp

Lista.o: Lista.cpp
	g++ -Iheaders -c Lista.cpp

main.o: main.cpp
	g++ -Iheaders -c main.cpp

clear:
	rm -f $(OBJ)