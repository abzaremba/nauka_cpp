#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "string_care.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;




int main()
{
	// ask for lots of words
	cout << "Enter your words: " ;
	
	vector<string> string_vec = use_strings(cin);
	cout << endl;

	for (vector<string>::size_type i=0; i != string_vec.size(); ++i)

	 



			//string word;
			//vector<string> words;

			//while (cin >> word)
			//	words.push_back(word);
			//
			//vector<string> reorganise (const vector<string>& wds)
			//{sort (wds.begin(), wds.end(), compare);
			//}

			//int numberlength;
			//numberlength = 2 * ceil ( log10 (maxnumber) );

			//for (int i=0; i != maxnumber; ++i){
			//	cout << std::setw(numberlength) << i << " " << i*i << endl;
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
	//// alphabetise the student records
	//sort (students.begin(), students.end(), compare);

	//// write the names and grades
	//for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
	//	// write the name padden on the right to maxlen + 1 characters
	//	cout << students[i].name
	//		 << string (maxlen + 1 - students[i].name.size(), ' ');

	//	// compute and write the grade
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

