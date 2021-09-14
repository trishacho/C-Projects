#include<iostream>
#include <math.h>

using namespace std;

class Cube
{
	private:
		double Side;
    public:
		Cube();				    //default constructor set at   “ – 2 “
		Cube(double);
		void setSide(double s);
		double getSide();		// used in Properties
		double Diagonal();		// used in Properties
        double Area();			// used in Properties
		double Volume();		// used in Properties
		void Properties();		// Calls all functions and displays them
		void Challenge(Cube);
		void operator+(Cube);
		void operator-();
};

Cube::Cube()
{
    Side = -2;
}

Cube::Cube(double mySide)
{
    Side = mySide;
}

void Cube::operator+(Cube temp)
{
    cout << "Operator: " << Side+temp.getSide() << endl;
}

void Cube::Challenge(Cube temp)
{
    int value = Side+temp.getSide();
    cout << value;
}

void Cube::setSide(double mySide)
{
    Side = mySide;
}

double Cube::getSide()
{
    return Side;
}

double Cube::Diagonal()
{
    double d = (Side*sqrt(2));
    return d;
}

double Cube::Area()
{
    double a = 6*Side*Side;
    return a;
}

double Cube::Volume()
{
    double v = Side*Side*Side;
    return v;
}

void Cube::operator-()
{
    int value = Volume()-Area();
    cout << value << endl;
}

void Cube::Properties()
{
    cout << "Side Length: " << getSide() << endl;
    cout << "Diagonal: " << Diagonal() << endl;
    cout << "Area: " <<  Area() << endl;
    cout << "Volume: " << Volume() << endl;
}

int main()
{
	Cube c;
	double myside;
	cout << "Enter side length: ";
	cin >> myside;
	c.setSide(myside);
	c.Properties();
	Cube p(3);
	Cube add(p.getSide()+c.getSide());
	int value = p.getSide()+c.getSide();
	cout << endl;
	add.Properties();
	cout << endl;
	cout << value << endl;
	c.Challenge(p);
	cout << endl;
	c+p;
	cout << endl;
	-c;
	return 0;
}
