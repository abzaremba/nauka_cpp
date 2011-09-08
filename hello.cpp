#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "text_care.h"
#include "grade.h"
#include "Student_info.h"
#include "string_care.h"
#include <algorithm>
#include <iomanip>


using std::cin; using std::cout; using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::max;
using std::domain_error;  


int main()
{
	// students who did and didn't do all their homework
	vector<Student_info> did, didnt;

	// read the students recods and partition them
	Student_info student;
	while (read(cin, student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	// verify that analyses will show us something
	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	// do the analyses
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);




	//string s;
	//// read and store in vector of strings string_vec
	//vector<string> string_vec;

	//while (getline(cin, s))
	//	string_vec.push_back(s);

	//vector<string> framed_string_vec = frame(string_vec);

	//// print the concatenated vector of strings
	//vector<string> concatenated_string_vec = hcat(string_vec, framed_string_vec);

	//	for (vector<string>::size_type i = 0; i != concatenated_string_vec.size(); ++i)
	//{
	//	cout << concatenated_string_vec[i] << endl;
	//}


	//vector<Student_info> students;
	//Student_info record;
	//string::size_type maxlen = 0;	// the length of the longest name

	//// read and store all the student's data
	//// invariant: students contains all the student records read so far
	////			  maxlen contains the length of the longest name in the students
	//while (read(cin, record)) {
	//	// find length of the longest name
	//	maxlen = max (maxlen, record.name.size());
	//	students.push_back(record);
	//}
	//
	//// delete records of those students who didn't pass
	////std::list<Student_info> extract_fails(std::list<Student_info>& students);
	//vector<Student_info> failed_students = extract_fails(students);


	//// alphabetise the student records
	//sort (students.begin(), students.end(), compare);

	//// write the names and grades
	//for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
	//	// write the name padded on the right to maxlen + 1 characters
	//	cout << students[i].name
	//		 << string (maxlen + 1 - students[i].name.size(), ' ');

	//	//// compute and write the grade
	//	try {
	//		double final_grade = grade (students[i]);
	//		streamsize prec = cout.precision();
	//		cout << setprecision(3) << final_grade << setprecision(prec);
	//	} catch (domain_error e) {
	//		cout << e.what();
	//	}
	//	cout << endl;
	//}

	return 0;

}