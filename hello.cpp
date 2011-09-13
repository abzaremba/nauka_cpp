#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

template <class In, class Pred> In find_if(In begin, In end, Pred f)
{
	while (begin != end && !f(*begin))
		++begin;
	return begin;
}

bool is_negative(int n)
{
	return n < 0;
}


int main()
{
	// read a vector of ints
	cout << "gimme a vector ";
	vector<int> v;
	int number;
	while (cin >> number)
		v.push_back(number);

	vector<int>::iterator i = find_if(v.begin(), v.end(), is_negative);

	cout << "your element " << *i;

	return 0;

}