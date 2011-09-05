// source file for Student_infoted functions
#include "Student_info.h"
#include "grade.h"
#include <list>

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
	double midterm, final;
	is >> s.name >> midterm >> final;
	vector<double> homework;
	read_hw (is, homework); // read and store all the student's homework grades
	//s.subject_grade = grade (midterm, final, homework);
	if (is) s.subject_grade = grade (midterm, final, homework);
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

// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
	return s.subject_grade < 60;
}

// version 3 with vectors
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter=students.begin();

	while(iter != students.end()){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else
			++iter;
	}
	return fail;
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
