#include "util.h"

Vector2 Util::posZero { 0, 0 };

vector<string> split(const string &s, char delimiter)
{
	vector<std::string> tokens;
	string token;
	std::istringstream tokenStream(s);

	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}

	return tokens;
}

// trim from start (in place)
void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
std::string trim_copy(std::string s) {
	trim(s);
	return s;
}

void free_array(char** array_string)
{
	int i = 0;

	while (array_string[i])
	{
		free(array_string[i]);
		i++;
	}

	free(array_string);
	array_string = NULL;
}

void free_matrix_ints(int** matrix_ints, int h)
{
	for (int i = 0; i < h; i++)
		free(matrix_ints[i]);

	/*int i = 0;

	while (array_ints[i])
	{
		free(array_ints[i]);
		i++;
	}*/

	free(matrix_ints);
	matrix_ints = NULL;
}
