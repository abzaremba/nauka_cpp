//// source file for Student_infoted functions
#include "Student_info.h"
#include "grade.h"
//#include <list>
#include <algorithm>
//#include <iterator>
#include <istream>
#include <vector>

//
using std::istream;
using std::vector;
using std::min;
//using std::list;


istream& Core::read_common(istream& in)
{
	// read the student's name and grade
	in >> n >> midterm >> final;
	return in;
}
istream& Core::read(istream& in)
{
	read_common(in);
	read_hw(in, homework);
	return in;
}


double Core::grade() const
{
	return ::grade(midterm, final, homework);
}

istream& Grad::read(istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad:: grade() const
{
	return min(Core::grade(), thesis);
}

bool compare (const Core& c1, const Core& c2)
{
	return c1.name() < c2.name();
}

istream& Student_info::read(istream& is)
{
	delete spointer; // delete previous object, if any

	char ch;
	is >> ch;  // get record type

	if (ch == 'U') {
		spointer = new Core(is);
	} else {
		spointer = new Grad(is);
	}

	return is;
}

Student_info::Student_info(const Student_info& s) : spointer(0)
{
	if (s.spointer) spointer = s.spointer->clone();
}

Student_info& Student_info::operator= (const Student_info& s)
{
	if (&s != this) {
		delete spointer;
		if (s.spointer)
			spointer = s.spointer->clone();
		else
			spointer = 0;
	}
	return *this;
}


istream& read_hw (istream& in, vector<double>& hw)
{
	//read homework grades from an input stream into a vector<double>
	if (in) {
		// get rid of previous contents
		hw.clear();

		//read homework grades
		double x;
		while (in >> x)
			hw.push_back(x);

		//clear the stream so that input will work for the next student
			in.clear();
	}
	return in;
}
