#pragma once

#include <string>

class Value
{
public:
	Value();
	Value(std::string newValue) { this->_value = newValue; }
	~Value();

	std::string getValue() { return _value; }

	void putValue(std::string newValue)
	{
		this->_value = newValue;
	}

private:
	std::string _value;
};

