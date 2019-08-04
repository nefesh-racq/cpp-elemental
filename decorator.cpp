/* ejemplo del patron decorador */
#include <iostream>
using std::cout;
using std::endl;

// clase abstracta "interfaz"
class FireArm
{
public:
	FireArm() { cout << "FireArm\n"; }
	virtual float noise() const = 0;
	virtual int bullets() const = 0;
};

class Rifle : public FireArm
{
public:
	Rifle() { cout << "Rifle\n"; }
	// funciones heredadas virtuales puras
	virtual float noise() const { return 150.0; }
	virtual int bullets() const { return 5; }
};

/* decorador */
class FireArmDecorator : public FireArm
{
public:
	FireArmDecorator(FireArm *gun) : _gun(gun) { cout << "FireArmDecorator\n"; }
	// virtuales puros heredadas
	virtual float noise() const { return _gun->noise(); }
	virtual int bullets() const { return _gun->bullets(); }

protected:
	FireArm *_gun;
};

class Silencer : public FireArmDecorator
{
public:
	Silencer(FireArm *gun) : FireArmDecorator(gun) { cout << "Silencer\n"; }
	// virtuales puras heredadas
	virtual float noise() const { return _gun->noise() + 55; }
	virtual int bullets() const { return _gun->bullets(); }
};

class Magazine : public FireArmDecorator
{
public:
	Magazine(FireArm *gun) : FireArmDecorator(gun) { cout << "Magazine\n"; }
	// virtuales puras heredadas
	virtual float noise() const { return _gun->noise(); }
	virtual int bullets() const { return _gun->bullets() + 5; }
};

/*  usando el decorador  */
int main()
{
	// instanciando un objeto Rifle
	FireArm *gun = new Rifle();
	cout << "Arma normal:\n"
		<< "Noise: " << gun->noise()
		<< "\nBullets: " << gun->bullets()
		<< "\n\n";

	/* poniendo un silenciador */
	gun = new Silencer(gun);

	cout << "Arma con silenciador:\n"
		<< "Noise: " << gun->noise()
		<< "\nBullets: " << gun->bullets()
		<< "\n\n";

	/* poniendo un magazine */
	gun = new Magazine(gun);

	cout << "Arma con magazine:\n"
		<< "Noise: " << gun->noise()
		<< "\nBullets: " << gun->bullets()
		<< "\n\n";

	return 0;
}
