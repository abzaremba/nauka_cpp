#ifndef GUARD_string_care_h
#define GUARD_string_care_h

// median.h - final version
#include <vector>
#include <string>
#include <iostream>
#include <map>

std::istream& read_strings(std::istream& an_istream, std::vector<std::string>& str_vec);
int count_strings (const std::vector<std::string>& str_vec);
std::vector<std::string> use_strings(std::istream& an_istream);


#endif