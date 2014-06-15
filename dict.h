#pragma once

#include <map>
#include "value.h"

class Dict
{
public:
	Dict();
	~Dict();

	bool Insert(int, Value*, bool);
	void Delete(int);
	bool IsPresent(int);

private:
	std::map<int, Value*> hashmap_;
};
