#include <functions.h>
#include <algorithm>
#include <cctype>

std::string remove_whitespaces(std::string line) {
    line = line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
    return line;
}