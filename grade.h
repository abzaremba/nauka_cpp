#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include <ostream>
#include <string>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
//double grade(const Student_info&);
bool   fgrade(const Student_info& s);
double grade_aux(const Student_info& s);


#endif