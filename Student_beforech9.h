#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h - header file
#include <iostream>
#include <string>
#include <vector>
//#include <list>


struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool fgrade(const Student_info& s);
std::vector<Student_info> extract_fails(std::vector<Student_info>& students);
//std::list<Student_info> extract_fails(std::list<Student_info>& students);
bool did_all_hw(const Student_info& s);


#endif
