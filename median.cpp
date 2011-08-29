// source file for the median function
#include <algorithm> //to get declaration of sort
#include <stdexcept> //to get declaration of domain_error
#include <vector> //to get declaration of vector

using std::domain_error;
using std::sort;
using std::vector;

// compute median of a vector<double>
double median (vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size==0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 : vec[mid];
}