// source file for Student_infoted functions
#include "Student_info.h"
#include "grade.h"
#include <list>
#include <algorithm>
#include <iterator>

using std::istream;
using std::vector;
using std::list;


bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read (istream& is, Student_info& s)
{
	//read and store student's name and midterm and final exam grades
	is >> s.name >> s.midterm >> s.final;
	read_hw (is, s.homework); // read and store all the student's homework grades
	return is;
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


bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}

// version 5 with vectors and faster way of dealing with them
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
	students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

	return fail;
}

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}


//// version 4: use list instead of vector
//list<Student_info> extract_fails(list<Student_info>& students)
//{
//	list<Student_info> fail;
//	list<Student_info>::iterator iter = students.begin();
//
//	while (iter != students.end())
//	{
//		if (fgrade(*iter)){
//			fail.push_back(*iter);
//			iter = students.erase(iter);
//		}else
//			++iter;
//	}
//	return fail;
//}
