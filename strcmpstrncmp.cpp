// uso de strcmp y strncmp
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstring>
using std::strcmp;
using std::strncmp;

int main()
{
	const char *s1 = "felices fiestas";
	const char *s2 = "felices fiestas";
	const char *s3 = "felices dias de fiestas";

	cout << "s1 = " << s1 << "\ns2 = " << s2 << "\ns3 = " << s3
		<< "\n\nstrcmp(s1, s2) = " << setw(2) << strcmp(s1, s2)
		<< "\nstrcmp(s1, s3) = " << setw(2) << strcmp(s1, s3)
		<< "\nstrcmp(s3, s1) = " << setw(2) << strcmp(s3, s1);

	cout << "\n\nstrncmp(s1, s3, 8) = " << setw(2) << strncmp(s1, s3, 8)
		<< "\nstrncmp(s1, s3, 9) = " << setw(2) << strncmp(s1, s3, 9)
		<< "\nstrncmp(s3, s1, 9) = " << setw(2) << strncmp(s3, s1, 9) << endl;

	return 0;
}

