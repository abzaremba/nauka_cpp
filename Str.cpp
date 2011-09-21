#include "Str.h"
#include <iostream>

using std::istream;
using std::ostream;

std::istream& operator>> (istream& is, Str& s)
{
	//obliterate existing value(s)
	s.data.clear();

	//read and discard leading whitespace
	char c;
	while (is.get(c) && isspace(c))
		;  // nothing to do, except testing the condition

	// if still something to read, do so until next whitespace character
	if (is) {
		do s.data.push_back(c);
		while(is.get(c) && !isspace(c));

		// if we read whitespace, then put it back on stream
		if(is)
			is.unget();
	}
	return is;
}

std::ostream& operator<<(ostream& os, const Str& s)
{
	for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

Str operator+(const Str& s, const Str& t)
{
	Str r = s;
	r += t;
	return r;
}