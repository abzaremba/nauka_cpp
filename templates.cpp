#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using std::domain_error;
using std::vector;


template <class T> T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

//template <class For, class X> void replace(For beg, For end, const X& x, const X& y)
//{
//	while (beg != end) {
//		if (*beg == x)
//			*beg = y;
//		++beg;
//	}
//}