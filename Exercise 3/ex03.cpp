// CIS 235 Exercise 3
// Josh Kennedy

#include <iostream>
#include <string>

using namespace::std;

class recording
{
   public:
      void setTitle(const string &);
      void setArtist(const string &);

      string getTitle(void) const;
      string getArtist(void) const;

   private:
      string title;
      string artist;
};

//  write the 4 member functions
void recording::setArtist(const string& artist)
{
	this->artist = artist;
}

void recording::setTitle(const string& title)
{
	this->title = title;
}

string recording::getArtist() const
{
	return this->artist;
}

string recording::getTitle() const
{
	return this->title;
}

void print(ostream& out, const recording& in)
{
	out << "Title: " << in.getTitle() << endl;
	out << "Artist: " << in.getArtist() << endl;
}

void main()
{
    recording one;
    //   set the title and artist to "Msirlou" and "Dick Dale"
	one.setTitle("Msirlou");
	one.setArtist("Dick Dale");

    // call the print function
	print(cout, one);

    recording * p1;
    //  allocate memory for a recording and store the address in p1
	p1 = new recording();

    //   set the title and artist to "Take a Chance on Me" and "ABBA";
	p1->setTitle("Take a Chance on Me");
	p1->setArtist("ABBA");



    //  call the print function for the recording pointed to by p1
	print(cout, *p1);




    //  Return all heap memory
	delete p1;
}


//  write the print function
