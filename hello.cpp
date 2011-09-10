// testing generic functions

#include <vector>
#include <iostream>
#include "templates.h"


using std::vector;
using std::cin;
using std::cout;
using std::endl;

template <class For, class X> void replace(For beg, For end, const X& x, const X& y)
{
	while (beg != end) {
		if (*beg == x)
			*beg = y;
		++beg;
	}
}

int main()
{
	vector<double> vec;
	double i;

	while(cin >> i)
	{
		vec.push_back(i);
	}

	cout << endl << median(vec) <<endl;

	double first, last;
	first = *(vec.begin());
	last = *(vec.end()-1);
	replace(vec.begin(), vec.end(), first, last);

	cout << endl << median(vec) <<endl;

	double temp;
	cin >> temp;

}