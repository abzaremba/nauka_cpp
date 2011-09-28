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

//Student_info::Student_info(): midterm(0), final(0) {}
//Student_info::Student_info(istream& is) { read(is); }
//istream& Student_info::read(istream& in)
//{
//	in >> n >> midterm >> final;
//	read_hw(in, homework);
//	return in;
//}
//double Student_info::grade() const
//{
//	return ::grade(midterm, final,homework);
//}
//
//
//
//bool compare(const Student_info& x, const Student_info& y)
//{
//	return x.name() < y.name();
//}
//
////istream& read (istream& is, Student_info& s)
////{
////	//read and store student's name and midterm and final exam grades
////	is >> s.name >> s.midterm >> s.final;
////	read_hw (is, s.homework); // read and store all the student's homework grades
////	return is;
////}
//
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
//
//
//bool pgrade(const Student_info& s)
//{
//	return !fgrade(s);
//}
//
////// version 5 with vectors and faster way of dealing with them
////vector<Student_info> extract_fails(vector<Student_info>& students)
////{
////	vector<Student_info> fail;
////	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
////	students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
////
////	return fail;
////}
//
//
//// version 6 using stable_partition
//vector<Student_info> extract_fails(vector<Student_info>& students)
//{
//	vector<Student_info>::iterator iter = stable_partition(students.begin(),students.end(), pgrade);
//	vector<Student_info> fail(iter, students.end());
//	students.erase(iter,students.end());
//
//	return fail;
//}
//
//
////bool did_all_hw(const Student_info& s)
////{
////	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
////}
//
//
////// version 4: use list instead of vector
////list<Student_info> extract_fails(list<Student_info>& students)
////{
////	list<Student_info> fail;
////	list<Student_info>::iterator iter = students.begin();
////
////	while (iter != students.end())
////	{
////		if (fgrade(*iter)){
////			fail.push_back(*iter);
////			iter = students.erase(iter);
////		}else
////			++iter;
////	}
////	return fail;
////}
