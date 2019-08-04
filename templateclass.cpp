// plantilla de clase
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class A
{
public:
	A();
	void imprimir(T* v, int n);
	void imprimir();

private:
	int v[10];
};

template <class T>
A<T>::A()
{
	for (int i = 0; i < 10; i++)
		v[i] = 2 * i + 1;
}

template <class T>
void A<T>::imprimir(T* v, int n)
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << endl;
}

template <class T>
void A<T>::imprimir()
{
	for (int i = 0; i < 10; i++)
		cout << v[i] << " ";

	cout << endl;
}

int main()
{
	int v[] = {1, 2, 5, 3, 4, 5};
	A<int> a;

	a.imprimir(v, 6);

	cout << "\n\notro ejemplo\n";
	a.imprimir();

	return 0;
}