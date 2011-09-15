#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cerr;



int main(int argc, char** argv)
{
	int fail_count = 0;
	//for each file in the input list
	for (int i = 1; i < argc; ++i) {
		string str = argv[i];
		ifstream in(str.c_str());

		// if it exists, write its contents, otherwise geerate an error message
		if (in) {
			string s;
			while (getline(in, s))
				cout << s << endl;
		} else {
			cerr << "cannot open file " << argv[i] << endl;
			++fail_count;
		}
	}

	return fail_count;

}


//int main()
//{
//	int fail_count = 0;
//	//for each file in the input list
//	cout << "Gimme list of files\n";
//
//	string str;
//	vector<string> file_names;
//	while (cin >> str) 
//		file_names.push_back(str);
//	
//	for (vector<string>::size_type i = 1; i != file_names.size(); ++i) {
//		ifstream in(file_names[i]);
//
//		// if it exists, write its contents, otherwise geerate an error message
//		if (in) {
//			string s;
//			while (getline(in, s))
//				cout << s << endl;
//		} else {
//			cerr << "cannot open file " << file_names[i] << endl;
//			++fail_count;
//		}
//	}
//
//	return fail_count;
//
//}