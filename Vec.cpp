#include "Vec.h"


template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::uncreate()
{
	if (data) {
		// destroy (in revere order) the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		//return all the spce that was allocated
		alloc.deallocate(data, limit - data);
	}
	// reset pointers to indicate that Vec is empty again
	data = limit = avail = 0;
}




template <class T> Vec<T>& Vec<T>::operator= (const Vec& rhs)
{
	// check for self - assignment
	if (&rhs != this) {

		// free the array in the left-hand side
		uncreate();

		//copy elements from the right-hand to the left-hand side
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

