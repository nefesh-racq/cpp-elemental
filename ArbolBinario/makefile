BINARY	= a.out
OBJ		= Nodo.o ArbolBinario.o MyApp.o main.o

a.out: $(OBJ)
	g++ -Iheaders $(OBJ) -o $(BINARY)

Nodo.o: Nodo.cpp
	g++ -Iheaders -c Nodo.cpp

ArbolBinario.o: ArbolBinario.cpp
	g++ -Iheaders -c ArbolBinario.cpp

MyApp.o: MyApp.cpp
	g++ -Iheaders -c MyApp.cpp

main.o: main.cpp
	g++ -Iheaders -c main.cpp

clean:
	rm -f $(OBJ)
