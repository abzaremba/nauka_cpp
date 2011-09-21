#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <algorithm>
#include <cstddef>
#include <memory>


using std::max;

template <class T> class Vec {
public: 
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
			
	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t); }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator= (const Vec&);
	~Vec() { uncreate(); }

	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

	void push_back(const T& t) {
		if (avail == limit)
			grow();
		unchecked_append(t);
	}

	size_type size() const { return avail - data; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }                 
	const_iterator end() const { return avail; }     

	void clear() { uncreate(); }
	void erase(T*);

private:
	iterator data; // first element in the Vec
	iterator avail; // (one past) the last element in the Vec
	iterator limit; // (one past) the allocated memory

	// facilities for memory allocation
	std::allocator<T> alloc; // object to handle memory allocation

	// allocate and initialize the underlying array
	void create();
	void create (size_type, const T&);
	void create (const_iterator, const_iterator);

	// destroy elements in array and free memory
	void uncreate();

	// support functions to push_back
	void grow();
	void unchecked_append(const T&);

};

template <class T> void Vec<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
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


template <class T> void Vec<T>::grow()
{
	//when growing allocate twice as much space as currently in use
	size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

	// allocatenew space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}


// assumes avail points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
}

template <class T> void Vec<T>::erase(T* iter_to_remove) 
{
	T* i = iter_to_remove;
	while (i != avail)
	{
		alloc.construct(i, *(++i));
	}
	--avail;
}


#endif