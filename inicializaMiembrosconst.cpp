#ifndef INCREMENTO_H
#define INCREMENTO_H
class Incremento
{
public:
    Incremento(int c = 0, int i = 1);   // constructor

    // definicion de la funcion agregarincremento
    void agregarIncremento()
    {
        cuenta += incremento;
    }

    void imprimir() const;  // imprime la cuenta y el incremento

private:
    int cuenta;
    const int incremento;   // miembro dato constante
};

#endif //INCREMENTO_H

// definicion de la clase Incremento
#include <iostream>
using std::cout;
using std::endl;

// Incremento
Incremento::Incremento(int c, int i)
    : cuenta(c),        // inicializador para un miembro no constante
        incremento(i)   // inicializador requerido para un miembro constante
{ ; }

//
void Incremento::imprimir() const
{
    cout << "cuenta = " << cuenta << ", incremento = " << incremento << endl;
}

// funcion principal para el manejo de Incremento
int main()
{
    Incremento valor(10, 5);

    cout << "Antes de incrementar: ";
    valor.imprimir();

    for (int j = 1; j <= 3; j++)
    {
        valor.agregarIncremento();
        cout << "Despues de incrementar " << j << ": ";
        valor.imprimir();
    }

    return 0;
}
