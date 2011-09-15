#ifndef GUARD_Vec_h
#define GUARD_Vec_h

template <class T> class Vec {
public: 
	typedef T iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
			
	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, T); }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec& operator= (const Vec&);
	~Vec() { uncreate(); }

	T& operarator[](size_type i) { return data[i]; }

	void push_back(constT& t) {
		if (avail == limit)
			grow();
		unchecked_append(t);
	}

	size_type size() const { return avail - data; }
	iterator begin() { return data; }
	iterator end() { return avail; }

private:
	iterator data; // first element in the Vec
	iterator avail; // (one past) the last element in the Vec
	iterator limimt; // (one past) the allocated memory

	// facilities for memory allocation
	allocator<T> alloc; // object to handle memory allocation

	// allocate and initialize the underlying array
	void create();
	void create (size_type, const T&);
	void create (const_iterator, const_iterator);

	// destroy elements in array and free memory
	void uncreate();

	// support functions to push_back
	void grow();
	void unchecked_uppend(const T&);

}


#endif