#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include "raylib.h"

using std::string;
using std::vector;

vector<string> split(const string &s, char delimiter);
void ltrim(string &s);
void rtrim(string &s);
void trim(string &s);
string ltrim_copy(string s);
string rtrim_copy(string s);
string trim_copy(string s);

#endif // UTIL_H
