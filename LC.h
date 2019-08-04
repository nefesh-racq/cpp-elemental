#include <iostream>
#include <string>

using std::string;

class LC
{
private:
   string nombre;

public:
   LC(string nom);
   void setNombre(string nom);
   void getNombre() const;
};
