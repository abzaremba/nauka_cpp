// source file for the median function
#include <algorithm> //to get declaration of sort
#include <vector> //to get declaration of vector

#include <string>
#include <iostream>

using std::sort;
using std::vector;

using std::istream;
using std::string;
using std::cin;
using std::cout;
using std::endl;



// reads a vector of strings
istream& read_strings(istream& an_istream, vector<string>& str_vec) 
{
	if (an_istream) {
		string string_x;
		while (an_istream >> string_x)
			str_vec.push_back(string_x);
		an_istream.clear();
	}
	return an_istream;
};

// gives a vector of numbers showing how many times each string have been used
vector<int> count_strings (vector<string> str_vec)
{
	sort(str_vec.begin(), str_vec.end());
	vector<int> str_numbers;
	str_numbers.push_back(1);
	for (vector<string>::size_type i=0; i != str_vec.size()-1; ++i){
		if (str_vec[i]==str_vec[i+1]){
			vector<double>::size_type index = str_numbers.size()-1;
			++str_numbers[index];
		}
		else
			str_numbers.push_back(1);
	}
	return str_numbers;
}

vector<string> use_strings(istream& an_istream) 
{
	vector<string> str_vec;
	read_strings(an_istream, str_vec);
	vector<int> str_numbers;
	str_numbers = count_strings (str_vec);
	cout << endl;
	for (vector<int>::size_type i=0; i != str_numbers.size(); ++i)
		cout << i << " " << str_numbers[i] << endl;


	return str_vec;
};


