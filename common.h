#pragma once

#include <string>
#include <sstream>

std::string toString(int i)
{
	std::string s;
	std::stringstream out;
	out << i;
	s = out.str();

	return s;
}

