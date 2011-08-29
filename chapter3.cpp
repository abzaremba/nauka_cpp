// ask for a name and then use it in a greeting
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;


int nonmain3()
{

	// ask for and read the student's name
	cout << "Please enter the number of students: ";
	int number_of_students;
	cin >> number_of_students;
	
	cout << "Please enter all of the students' names: ";
	vector<string> names_vec;
	string name;
	for (int i = 0; i != number_of_students; ++i){
		if (cin >> name)
			names_vec.push_back(name);
		else {
			cout << endl << "You said there'd be more students!! "
						"Please start again." << endl;
			return 1;
		}
	}

	cout << "Please enter all of the students' midterm grades: ";
	vector<double> midterms;
	double grade;
	for (int i = 0; i != number_of_students; ++i){
		if (cin >> grade)
			midterms.push_back(grade);
		else {
			cout << endl << "You didn't enter enough grades!! "
						"Please start again." << endl;
			return 1;
		}
	}


	cout << "Now, please enter all of the students' final grades: ";
	vector<double> finals;
	for (int i = 0; i != number_of_students; ++i){
		if (cin >> grade)
			finals.push_back(grade);
		else {
			cout << endl << "You didn't enter enough grades!! "
						"Please start again." << endl;
			return 1;
		}
	}

	cout << "How many homework grades does each student have? ";
	int homework_number;
	cin >> homework_number;

	cout << "Now, enter homework grades for all of the students: "
		"Please note, there should be " << homework_number * number_of_students << " grades. ";
	vector<double> homework_grades;
	for (int i = 0; i != homework_number * number_of_students; ++i){
		if (cin >> grade)
			homework_grades.push_back(grade);
		else {
			cout << endl << "You didn't enter enough grades!! "
						"Please start again." << endl;
			return 1;
		}
	}


	// calculation of all homework medians, for each student separately:
	typedef vector<double>::size_type doublevec_size;
	double temp_median;
	int halfsize = homework_number/2;

	vector<double> medians, final_grades;
	vector<double> current_grades(homework_number,0);

	cout << endl;
	for (int i=0; i != number_of_students; ++i){
		for (int j = 0; j != homework_number; ++j) {
			current_grades[j] = homework_grades[i * number_of_students + j];
		}
		//now start calculating median

		sort(current_grades.begin(), current_grades.end());
		temp_median = homework_number % 2 == 0 ? (current_grades[halfsize] + current_grades[halfsize-1]) / 2
									      : current_grades[halfsize];
		medians.push_back(temp_median);
		final_grades.push_back(0.2 * midterms[i] + 0.4 * finals[i] + 0.4 * temp_median);

	}

	cout << endl;
	for (int i=0; i != number_of_students; ++i)
		cout << "final grade for " << names_vec[i] << " is: "  << final_grades[i] << endl;
	

	//
	//typedef vector<string>::size_type strvec_size;
	//strvec_size number_of_students = names_vec.size();

	//// sort the grades
	//sort(homework.begin(), homework.end());

	//// compute median homework grade
	//vec_sz mid = size/2;
	//double median;
	//median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
	//					   :	homework[mid];

	//// compute and write final grade
	//streamsize prec = cout.precision();
	//cout << "Your final grade is " << setprecision(3)
	//	 << 0.2 * midterm + 0.4 * final + 0.4 * median
	//	 << setprecision(prec) << endl;


	//// ask for and reads some numbers
	//cout << "Enter a list of numbers and finish with end of file: " ;
	//vector<double> numbers;
	//double x;
	//while (cin >> x) 
	//	numbers.push_back(x);
	//vector<double>::size_type size, half_size, quarter_size, quarter3_size;
	//size = numbers.size();

	//// calculate quartiles
	//double quartile2;
	//half_size = size / 2;
	//quartile2 = size % 2 == 0 ? (numbers[half_size] + numbers[half_size-1]) / 2
	//						  : numbers[half_size];


	//double quartile1, quartile3;
	//quarter_size = size / 4;
	//quartile1 = size % 4 == 0 ? (numbers[quarter_size] + numbers[quarter_size-1]) / 2
	//						  : numbers[quarter_size];

	//quarter3_size = (size * 3) / 4;
	//quartile3 = size % 4 == 0 ? (numbers[quarter3_size] + numbers[quarter3_size-1]) / 2
	//						  : numbers[quarter3_size];

	//cout << endl;
	//cout << "The quartiles are equal to: first quartile " << quartile1 << ", second quartile " << quartile2 
	//	<< ", third quartile " << quartile3;



	//// asks for and reads a set of strings
	//cout << "Enter a set of strings: ";
	//string x;
	//vector<string> string_set;

	//while (cin >> x)
	//	string_set.push_back(x);

	//// check that the some strings were entered
	//vector<string>::size_type string_set_size;
	//string_set_size = string_set.size();
	//if (string_set_size == 0){
	//	cout << endl << "You must enter some strings. "
	//					"Please start again." << endl;
	//	return 1;
	//}
	//
	//vector<string>::size_type shortest_size, longest_size;
	//shortest_size = string_set[0].size();
	//longest_size = string_set[0].size();

	//for (int i=1; i!=string_set_size; ++i) {
	//	if (shortest_size > string_set[i].size())
	//		shortest_size = string_set[i].size();
	//	if (longest_size < string_set[i].size())
	//		longest_size = string_set[i].size();
	//}	
	//
	//cout << "Size of the longest string is: " << longest_size << ". And size of the shortest string is: " << shortest_size;


	return 0;


}
