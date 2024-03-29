#include "Ptr.h"
#include "Picture.h"
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;


int main()
{
	vector<string> v;
	v.push_back("abc");
	v.push_back("dupa");
	//Picture origin_pic();
	Picture origin_pic2(v);

	cout << origin_pic2 << endl;
	cout << frame(origin_pic2) << endl;
	cout << vcat(frame(origin_pic2), origin_pic2) << endl;
	cout << hcat(frame(origin_pic2), origin_pic2) << endl;

	return 0;
}


//#include <vector>
//#include "Student_info.h"
//#include <string>
//#include <algorithm>
//#include <iostream>
//#include <ios>
//#include <iomanip>
//#include <stdexcept>
//
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::vector;
//using std::string;
//using std::streamsize;
//using std::setprecision;
//using std::max;
//using std::domain_error;
//
//
//int main()
//{
//
//	vector <Student_info> students;
//	Student_info record;
//	string::size_type maxlen = 0;
//
//	// read and store the data
//	while (record.read(cin)) {
//		maxlen = max(maxlen, record.name().size());
//		students.push_back(record);
//	}
//
//	// alphabetize the student records
//	sort(students.begin(), students.end(), Student_info::compare);
//
//	// write the names and grades
//	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i ) {
//		cout << students[i].name() <<
//			    string(maxlen + 1 - students[i].name().size(), ' ');
//		try {
//			double final_grade = students[i].grade();
//			streamsize prec = cout.precision();
//			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
//		} catch (domain_error e){
//			cout << e.what() << endl;
//		}
//	}
//
//	return 0;
//
//}