#include <vector>
#include <string>
#include <iostream>
#include "grammar.h"

using std::cin;
using std::vector;
using std::cout;
using std::string;
using std::endl;



int main_OLD7()
{
	// generate sentence
	vector<string> sentence = gen_sentence(read_grammar(cin));

	// write the first word if any
	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence.end()) {
		cout << " " << *it;
		++it;
	}

	cout << endl;
	return 0;

}
