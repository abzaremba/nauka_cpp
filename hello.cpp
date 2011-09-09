#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "string_care.h"
#include "text_care.h"

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{

	// call xref using split by default
	map<string,vector<int> > ret = xref(cin);

	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it){
		// write the words
		cout << it->first << " occurs on line(s): ";

		// followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it;

		++line_it;
		// followed by the rest of the numbers if any
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		// write a new line to separate each word from the next
		cout << endl;
	}

	return 0;
}