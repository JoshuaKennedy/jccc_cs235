#include "project1.h"

#include <iostream>

using namespace std;

int schedule::dateFlag;

schedule::schedule()
{
	this->count = 0;
	this->title = "no title";
}

schedule::schedule(const char* p)
{
	this->count = 0;
	this->title = (char*)p;
}

schedule::schedule(const schedule& p)
{
	this->count = p.count;
	this->title = p.title;
}

bool schedule::addtoSchedule(const appointment& app)
{
	if (this->isFull()) return false;
	else
	{
		this->appointmentArray[this->count] = app;
		this->count++;

		return true;
	}
}

bool schedule::isFull() const
{
	return (this->count == SCH_ENTRIES);
}

void schedule::print(ostream& w) const
{
	for (int i = 0; i < count; i++)
	{
		w << "Appointment created by: " << this->appointmentArray[i].getSource() << endl;
		this->appointmentArray[i].print(w, schedule::dateFlag);
		w << endl;
	}

	w << "Total Number of Appoinments: " << this->count << '\n';

	w.flush();
}

void schedule::printForSource(long s, ostream& w) const
{
	this->search(s).print(w, 1);
}

appointment schedule::search(long s) const
{
	for (int i = 0; i < this->count; i++)
	{
		if (this->appointmentArray[i].getSource() == s)
			return this->appointmentArray[i];
	}

	return appointment(-1, "not found", 1, 1, 2000);
}

void schedule::setDateFlag(int date)
{
	schedule::dateFlag = date;
}

int main()
{
	schedule wow;

	int numAppointments = 0;

	cout << "enter number of appointments: ";
	cin >> numAppointments;

	for (int i = 0; i < numAppointments; i++)
	{
		appointment myApp = appointment();
		myApp.keyBoardInput();

		wow.addtoSchedule(myApp);
	}

	wow.print(cout);

	cout << "enter source id for search: ";
	long sourceId = 0L;

	cin >> sourceId;
	appointment search = wow.search(sourceId);

	if (strcmp(search.getDescription(), "not found") == 0)
		cout << "The source id couldn't be found!" << endl;
	else
		search.print(cout, 2);

	cout << "The schedule is " << (wow.isFull() ? "full" : "not full") << endl;

	return 0;
}
