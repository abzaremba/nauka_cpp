#ifndef GUARD_grade_h
#define GUARD_grade_h

// grade.h
#include <vector>
#include <ostream>
#include <string>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool   fgrade(const Student_info& s);
double grade_aux(const Student_info& s);
double median_analysis(const std::vector<Student_info>& students);
void write_analysis(std::ostream& out, const std::string& name, double analysis(const std::vector<Student_info>&), 
				    const std::vector<Student_info>& did, const std::vector<Student_info>& didnt);
double average(const std::vector<double>& v);
double average_grade(const Student_info s);
double average_analysis(const std::vector<Student_info>& students);
double optimistic_median(const Student_info& s);
double optimistic_median_analysis(const std::vector<Student_info>& students);


#endif