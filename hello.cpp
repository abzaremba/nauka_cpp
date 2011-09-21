#include "Vec.h"
#include <iostream>
#include "Str.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;



int main()
{

	Str example_str(3,'a');

	Str example_str2 = example_str + example_str;

	for(Str::size_type i = 0; i != example_str2.size(); ++i)
		cout << "\n" << example_str2[i];

	cout << endl;

	example_str += example_str2;

	for(Str::size_type i = 0; i != example_str.size(); ++i)
		cout << "\n" << example_str[i];

	Str example_str3(3,'b');
	example_str3 = example_str3 + example_str3;

	cout << endl;
	for(Str::size_type i = 0; i != example_str3.size(); ++i)
		cout << "\n" << example_str3[i];

	return 0;

}