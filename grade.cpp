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


//double grade (const Student_info& s)
//{
//	return grade(s.midterm, s.final, s.homework);
//}


// predicate to determine whether a student failed
bool fgrade(const Student_info& s)
{
	return s.grade() < 60;
}

double grade_aux(const Student_info& s)
{
	return s.grade();
}

