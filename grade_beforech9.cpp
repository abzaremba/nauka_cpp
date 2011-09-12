#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
//#include <string>
//#include <ostream>
#include <numeric>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;
using std::string;
using std::ostream;
using std::endl;

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade (double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

//compute a students overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because medias does so for us.

double grade (double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}


double grade (const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}


// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}


double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), 
				    const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did)
				<< ", median(didn't) = " << analysis(didnt) << endl;
}

double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info s)
{
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}

// median of nonzero elements of s.homework, or 0 if no such element exist
double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if(nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}