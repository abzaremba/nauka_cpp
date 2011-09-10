#include <string>
#include <stdexcept>
#include "grammar.h"
#include "text_care.h"

using std::istream;
using std::string;
using std::vector;
using std::domain_error;
using std::logic_error;

// read a grammar from a given input stream
Grammar read_grammar(istream& in)
{
	Grammar ret;
	string line;

	// read the input
	while (getline(in, line)) {
		// split input into words
		vector<string> entry = split(line);

		if(!entry.empty())
			// use the category to store the associated rule
			ret[entry[0]].push_back(
				Rule(entry.begin() + 1, entry.end()) );
	}
	return ret;
}


// return a random integer in the range [0, n)
int nrand(int n)
{
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to rand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}


void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
	if (!bracketed(word)) {
		ret.push_back(word);
	} else {
		// locate the rule that corresponds toword
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// from which we select at random
		const Rule& r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(g, *i, ret);
	}
}

vector<string> gen_sentence(const Grammar& g)
{
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
}

bool bracketed(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}
