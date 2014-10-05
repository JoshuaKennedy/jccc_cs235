//    CIS 235    Lab 1    -  defining classes , writing member functions
#include <iostream>
#include <cmath>

using namespace std;

class circle
{
public:
    void setX( double xV );
    void setY( double yV );
    void setR( double rV);
    void set(double value, char whichOne); // use 'x' for x, use 'y' for y and use 'r' for radius
    double getX(void) const;
    double getY(void) const;
    double getR(void) const;
    double get(char whichOne) const; // use 'x' for x, use 'y' for y and use 'r' for radius
    void print(ostream & w) const;
    double area(void) const;
    void input(void);
    
    circle move( double xC, double yC) const;
    // return a circle formed from
    // the invoking instance by:
    // keep the same radius, adjust the x and y
    //   of the center by the xC and yC amounts
    
    circle reSize(double rC) const;
    // return a circle formed from
    // the invoking instance by:
    // keep the same center
    //    adjust the radius by rC
    
    bool   isInside(const circle & inner) const;
    //  return true if the parameter
    //  circle inner is completely inside
    //  the invoking instance, return
    //  false otherwise
    
private:
    double x;
    double y;
    double radius;
};

void circle::setX(double xV)
{
    this->x = xV;
}

void circle::setY(double yV)
{
    this->y = yV;
}

void circle::setR(double rV)
{
    this->radius = rV;
}

void circle::set(double value, char whichOne)
{
    char letter = toupper(whichOne);
    switch (letter)
    {
        case 'X':
            this->setX(value);
            break;
        case 'Y':
            this->setY(value);
            break;
        case 'R':
            this->setR(value);
            break;
    }
}

double circle::getX() const
{
    return this->x;
}

double circle::getY() const
{
    return this->y;
}

double circle::getR() const
{
    return this->radius;
}

double circle::get(char whichOne) const
{
    char letter = toupper(whichOne);
    switch (letter)
    {
        case 'X':
            return this->x;
            break;
        case 'Y':
            return this->y;
            break;
        case 'R':
            return this->radius;
            break;
        default:
            return 0.0;
    }
}

void circle::print(ostream &w) const
{
    w << "X: " << this->x << endl << "Y: " << this->y << endl << "RADIUS: " << this->radius << endl;
    w.flush();
}

double circle::area() const
{
    return 3.14159265 * (this->radius * this->radius);
}

void circle::input()
{
    double x = 0, y = 0, r = 0;
    cout << "Input X, Y, and Radius: ";
    cin >> x >> y >> r;
    this->set(x, 'x');
    this->set(y, 'y');
    this->set(r, 'r');
}

circle circle::move(double xC, double yC) const
{
    circle temp;
    
    temp.setX(xC);
    temp.setY(yC);
    temp.setR(this->getR());
    
    return temp;
}

circle circle::reSize(double rC) const
{
    circle temp;
    
    temp.setX(this->x);
    temp.setY(this->y);
    temp.setR(rC);
    
    return temp;
}

bool circle::isInside(const circle& inner) const
{
    double distance;
	
	// calculate distance
	distance = sqrt(pow((this->getX() - inner.getX()), 2) + pow((this->getY() - inner.getY()), 2));
    
	// return true if invoking instance radius > (distance + parameter inner radius)
	return (this->getR() > (distance + inner.getR()));
}

// The following is NOT a member function
circle makeCircle(double xV, double yV, double rV)
{
    circle temp;
    
    temp.setX(xV);
    temp.setY(yV);
    temp.setR(rV);
    
    return temp;
}

int main()
{
	circle a;
    
	//   test input and print using a
    a.input();
    
	//   test the area function using a
    cout << "Area of circle a, is: " << a.area() << endl;
    
	//   add 2.4 to the x value of the circle a - use print to show the answer
    cout << "Adding 2.4 to x coordinate of circle a..." << endl;
    a.setX(a.getX() + 2.4);
    a.print(cout);
    
	//   test makeCircle, move and reSize  - use print to show the answers
    cout << "new circle, enter the X, Y, and R values: ";
    double x = 0, y = 0, r = 0;
    cin >> x >> y >> r;
    circle newCircle = makeCircle(x, y, r);
    newCircle.print(cout);
    
    cout << "we're going to move the circle: where do you wanna move it? X and Y: ";
    cin >> x >> y;
    newCircle = newCircle.move(x, y);
    newCircle.print(cout);
    
    cout << "now we're going to resize the circle: what size do you want it? Radius: ";
    cin >> r;
    newCircle = newCircle.reSize(r);
    newCircle.print(cout);
    
    cout << endl;
    
	//   using input create a circle named one
	//   using set   create a circle named two that is inside circle one
	//   using setX, setY, and setR create a circle named three that is not inside one
	//   test the isInside function
    circle one, two, three;
    one.input();
    two.set('X', one.getX());
    two.set('Y', one.getY());
    two.set('R', one.getR());
    three.setX(one.getX() + one.getR() * 2.5);
    three.setY(one.getY() + one.getR() * 2.5);
    
    cout << "circle two is " << (one.isInside(two) ? "" : "not") << " inside of circle one." << endl;
    cout << "circle three is " << (one.isInside(three) ? "" : "not") << " inside of circle one." << endl;
    
	// Use of function chaining
	//   starting with center of x = 2.3, y = 4.5 and radius = 8.2
	//     move the circle by adjusting x by 1.1 and y by 3.3
	//     then resize the circle by adding 5.5 to the radius
	//   print the resulting circle
	return 0;
}

//   PROGRAM OUTPUT