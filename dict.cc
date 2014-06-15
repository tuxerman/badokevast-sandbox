#include "dict.h"

Dict::Dict() {
}

Dict::~Dict() {
}

bool Dict::Put(int key, Value* val, bool overWrite=true) {
	if (!overWrite) {
		if (IsPresent(key))
			return false;
	}
	hashmap_[key] = val;
}

void Dict::Delete(int key) {
	hashmap_.erase(key);
}

bool Dict::IsPresent(int checkKey) {
	if (hashmap_.find(checkKey) != hashmap_.end())
		return true;
	else
		return false;
}

Value* Dict::Get(int key){
	if (IsPresent(key))
		return hashmap_[key];
	else
		return NULL;
}
