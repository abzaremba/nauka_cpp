#ifndef GUARD_str_h
#define GUARD_str_h

#include "Vec.h"
#include <iterator>
#include <algorithm>

class Str {
	//input operator implemented on page 216
	friend std::istream& operator>> (std::istream&, Str&);
public:
	Str& operator+=(const Str& s) {
		std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
		return *this;
	}

	typedef Vec<char>::size_type size_type;
	Str() { }
	Str(size_type n, char c): data(n,c) { }
	Str(const char* cp) {
		std::copy(cp, cp + std::strlen(cp),std::back_inserter(data));
	}
	template <class In> Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }
	size_type size() const { return data.size(); }

	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin() { return data.begin(); }
	const_iterator begin() const { return data.begin(); }

	iterator end() { return data.end(); }
	const_iterator end() const { return data.end(); }

private:
	Vec<char> data;
	 
};

// output iterator from page 216
std::ostream& operator<<(std::ostream&, const Str&);

Str operator+(const Str&, const Str&);

#endif