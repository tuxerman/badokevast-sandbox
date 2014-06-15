#pragma once

#include <map>
#include "value.h"

class Dict
{
public:
	Dict();
	~Dict();

	bool Put(int, Value*, bool);
	void Delete(int);
	bool IsPresent(int);
	Value* Get(int key);

private:
	std::map<int, Value*> hashmap_;
};
