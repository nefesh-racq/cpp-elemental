// ejemplo template min
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

template <typename T>
T min(T a, T b)
{
	if (a <= b)
		return a;

	return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;

	return b;
}

template <typename T>
void intercambio(T& a, T& b)
{
	T tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
void ordenar(T* v, int n)
{
	for (int indice = 0; indice < n; indice++)
	{
		int posmin = indice;

		for (int i = indice + 1; i < n; i++)
			if (v[i] < v[posmin])
				posmin = i;

		intercambio(v[indice], v[posmin]);
	}
}

template <typename T>
void imprimir(const T* v, int n)
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << endl;
}

int main()
{
	int a = 10, b = 11;
	double c = 32, d = 15;

	cout << "enteros:\n"
		<< "min(" << a << ", " << b << "): " << min(a, b) << endl
		<< "max(" << a << ", " << b << "): " << max(a, b) << endl;

	cout << "\ndoubles:\n"
		<< "min(" << c << ", " << d << "): " << min(c, d) << endl
		<< "max(" << c << ", " << d << "): " << max(c, d) << endl;

	char v[11] = "hola_mundo";
	int w[10] = {5, 1, 10, 4, 23, 8, 7, 13, 9, 78};

	//cout << v << endl;
	imprimir(v, 10);
	ordenar(v, 9);
	imprimir(v, 10);

	cout << endl;
	imprimir(w, 10);
	ordenar(w, 10);
	imprimir(w, 10);

	return 0;
}
