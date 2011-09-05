#include "text_care.h"
#include <algorithm>


using std::vector;
using std::string;
using std::max;



vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i=0;

	// invariant: we have processed characters [original value of i, i)
	while (i != s.size()) {
		// ignore leading blanks
		//invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the character isn range [original j, current j) is a space
		while (j != s.size() && !isspace(s[j]))
			++j;

		//if we found some nonwhitespace characters
		if (i != j) {
			//copy from s starting at i and taking j-i chars
			ret.push_back(s.substr(i, j-i));
			i=j;
		}
	}
	return ret;
}


string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for(vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());
	return maxlen;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::size_type i = 0; i != v.size(); ++i) {
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}

	// write the bottom border
	ret.push_back(border);
	return ret;
}

vector<string> vcat (const vector<string>& top, const vector<string>& bottom)
{
	// copy the top picture
	vector<string> ret = top;

	// copy entire bottom picture
	/*for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
		ret.push_back(*it);*/
	ret.insert(ret.end(), bottom.begin(), bottom.end());

	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;
	
	// add 1 to leave a space between pictures
	string::size_type width1= width(left) + 1;

	// indices to look at elements from left and right respectively
	vector<string>::size_type i=0, j=0;

	// continue until we've seen all rows from both pictures
	while (i != left.size() || j != right.size()) {
		// construct new string to hold characters from both pictures
		string s;
		// copy a row from the left-hand side, if there is one
		if (i != left.size())
			s = left[i++];

		// pad to full witdth
		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand side, if there is one
		if (j != right.size())
			s += right[j++];

		// add s to the picture we're ctrreating
		ret.push_back(s);

	}
	return ret;
}