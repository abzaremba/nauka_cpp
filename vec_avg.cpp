// source file for the median function
#include <stdexcept> //to get declaration of domain_error
#include <vector> //to get declaration of vector
#include <numeric> //to get declaration of accumulate

using std::domain_error;
using std::vector;

// compute sum of a vector<double>
double vec_sum (vector<double> vec)
{
	return accumulate(vec.begin(), vec.end(),0);
}

// compute average of a vector<double>
double vec_average (vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size==0)
	{
		throw domain_error("median of an empty vector");
		return 0;
	}

	
	return vec_sum(vec) / size;
}