#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

int main()
{
	vector<int> vect;

	vect.push_back(14);
	vect.push_back(2);

	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";

	cout << endl;

	return 0;
}

