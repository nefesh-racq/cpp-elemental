# compila el programa de sql
BINARY = a.out
OBJ = Campo.o Tabla.o MyDB.o main.o

program.o: $(OBJ)
	g++ $(OBJ) -o $(BINARY)

Campo.o: Campo.cpp
	g++ -Iheaders -c Campo.cpp

Tabla.o: Tabla.cpp
	g++ -Iheaders -c Tabla.cpp

MyDB.o: MyDB.cpp
	g++ -Iheaders -c MyDB.cpp

main.o: main.cpp
	g++ -Iheaders -c main.cpp

clean:
	rm -f $(OBJ) $(BINARY)
