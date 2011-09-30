#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <stdexcept>

template <class T> class Ptr {
public:
	// new member to copy object conditionally when needed
	void make_unique() {
		if (*refptr != 1) {
			--*refptr;
			refptr = new size_t(1);
			p = p? p->clone(): =;
		}
	}

	Ptr(): p(0), refptr(new size_t(1)) { }
	Ptr(T* t): p(t), refptr(new size_t(1)) { }
	Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++*refptr; }

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const { return p; }
	T& operator*() const {
		if (p)
			return *p;
		throw std::runtime_error("unbound Ptr");
	}
	T* operator->() const {
		if (p)
			return p;
		throw std::runtime_error("unbound Ptr");
	}

private:
	T* p;
	std::size_t* refptr;

};

template <class T> Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
	++*rhs.refptr;
	// free the left-hand side, destroying pointers if appropriate
	if (--*refptr == 0) {
		delete refptr;
		delete p;
	}

	// copy in values from the rhs
	refptr = rhs.refptr;
	p = rhs.p;
	return *this
}

template <class T> Ptr<T>::~Ptr()
{
	if (*refptr == 0) {
		delete refptr;
		delete p;
	} 
}



#endif