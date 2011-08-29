// ask for a name and then use it in a greeting
#include <iostream>
#include <string>

// what standard library names we use:
using std::cin;  using std::cout;
using std::endl; using std::string;


int nonmain2()

{
	
	// ask for a name
	cout << "Please enter your first name: ";

	// read the name
	string name;    //defines name
	cin >> name;    //read into name!
	
	// build the message
	const string greeting = "Hello, " + name + "!";

	// get the pad number to use user input
	int pad;
	cout << "Please enter number of spaces used as padding: ";
	cin >> pad;
	cout<<endl;

	// the number of blanks surrounding the message:
	const int pad_vertical = pad;
	const int pad_horizontal = pad;
	


	// the number of rows and columns to write
	const int rows = pad_vertical * 2 + 3;
	const string::size_type cols = greeting.size() + pad_horizontal * 2 + 2;

	// write a blank line to separate output from input
	cout << endl;


	// write the rows of ouput
	//invariant - we have written r rows so far
	for (int r = 0; r != rows; ++r) {
		string::size_type c = 0;

		// invariant - we have written c characters in the current row
		while (c != cols) {
			// time to write greeting?
			if (r == pad_vertical + 1 && c == pad_horizontal + 1) {
				cout << greeting;
				c += greeting.size();
			} else {
				// are we on the border?
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
					cout << "*";
					++c;
				} else {
					if (r == pad_vertical + 1) {
						string signs1(pad_vertical,' '); 
						cout << signs1;
						//cout << (pad_vertical,' ');
						c += pad_vertical;
					} else {
						string signs2(pad_vertical * 2 + greeting.size(),' '); 
						cout << signs2;
						//cout << (pad_vertical * 2 + greeting.size(),' ');
						c += pad_vertical * 2 + greeting.size();
					}
					
				}
				

			}
		}
		cout << endl;
	}


	// countdown
	for (int i=10; i!=-6; --i ) 
		cout << i << " ";
	
	int product = 1;
	for (int i=0; i!=10; ++i ) 
		product = product * ( i + 1);

	cout << endl;
	cout << product;

	int usernumber;
	cout << "Please enter a number: ";
	cin >> usernumber;
	cout << endl;

	int usernumber2;
	cout << "Please enter another number: ";
	cin >> usernumber2;
	cout << endl;

	if (usernumber>usernumber2) 
		cout << "Number " << usernumber << "is greater than " <<  usernumber2 << endl;
	else
		cout << "Number " << usernumber2 << "is greater than " <<  usernumber << endl;

	return 0;
}

