#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm> 
#include <cctype>
#include <locale>
#include "raylib.h"

using std::string;
using std::vector;

class Util
{
    public:

        static Vector2 posZero;
};

vector<string> split(const string &s, char delimiter);
void ltrim(string &s);
void rtrim(string &s);
void trim(string &s);
string ltrim_copy(string s);
string rtrim_copy(string s);
string trim_copy(string s);
void free_array(char** array_string);
void free_matrix_ints(int** matrix_ints, int h);

#endif // UTIL_H
