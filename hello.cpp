#include <string>
#include <iostream>
#include <vector>
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


int main()
{
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


	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;	// the length of the longest name

	// read and store all the student's data
	// invariant: students contains all the student records read so far
	//			  maxlen contains the length of the longest name in the students
	while (read(cin, record)) {
		// find length of the longest name
		maxlen = max (maxlen, record.name.size());
		students.push_back(record);
	}
	
	// delete records of those students who didn't pass
	//std::list<Student_info> extract_fails(std::list<Student_info>& students);
	vector<Student_info> failed_students = extract_fails(students);


	// alphabetise the student records
	sort (students.begin(), students.end(), compare);

	// write the names and grades
	for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
		// write the name padded on the right to maxlen + 1 characters
		cout << students[i].name
			 << string (maxlen + 1 - students[i].name.size(), ' ');

		//// compute and write the grade
		//try {
		//	double final_grade = grade (students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << students[i].subject_grade << setprecision(prec);
		//} catch (domain_error e) {
		//	cout << e.what();
		//}
		cout << endl;
	}


	return 0;

}