#include <string>
#include <iostream>
#include <vector>
#include "text_care.h"


using std::cin; using std::cout; using std::endl;
using std::string;
using std::getline;
using std::vector;


int main()
{
	string s;
	// read and store in vector of strings string_vec
	vector<string> string_vec;

	while (getline(cin, s))
		string_vec.push_back(s);

	vector<string> framed_string_vec = frame(string_vec);

	// print the concatenated vector of strings
	vector<string> concatenated_string_vec = hcat(string_vec, framed_string_vec);

		for (vector<string>::size_type i = 0; i != concatenated_string_vec.size(); ++i)
	{
		cout << concatenated_string_vec[i] << endl;
	}


	cout << endl;
	
	
	//string s;
	////read and split each line of input
	//while (getline(cin, s)) {
	//	vector<string> v = split(s);

	//	//write each workd in v
	//	for (vector<string>::size_type i =0; i != v.size(); ++i)
	//		cout << v[i] << endl;
	//}

	// alternative version of the thing above (i.e. splitting lines into words)

	//string s;
	//while (cin >> s)
	//	cout << s << endl;


	return 0;

}