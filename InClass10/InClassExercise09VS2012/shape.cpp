#include "shape.h"
#include <ctime>

Shape::Shape(void) : timeCreated(time(0))
{


}

void Shape::print(ostream &out ) const
{
	out << "Time created is " << timeCreated << endl;
}