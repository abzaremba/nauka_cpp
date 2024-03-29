#ifndef GUARD_text_care_h
#define GUARD_text_care_h

#include <string>
#include <vector>
#include <map>

std::vector<std::string> split(const std::string& s);
std::string::size_type width(const std::vector<std::string>& v);
std::vector<std::string> frame(const std::vector<std::string>& v);
std::vector<std::string> vcat(const std::vector<std::string>& top,  const std::vector<std::string>& bottom);
std::vector<std::string> hcat(const std::vector<std::string>& left, const std::vector<std::string>& right);
std::map<std::string, std::vector<int> > xref(std::istream& in, std::vector<std::string> find_words(const std::string&) = split);

#endif