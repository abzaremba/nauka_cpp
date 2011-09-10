#ifndef GRAMMAR_h
#define GRAMMAR_h

#include <vector>
#include <string>
#include <map>
#include <iostream>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;


Grammar read_grammar(std::istream& in);
int nrand(int n);
void gen_aux(const Grammar& g, const std::string& word, std::vector<std::string>& ret);
std::vector<std::string> gen_sentence(const Grammar& g);
bool bracketed(const std::string& s);

#endif