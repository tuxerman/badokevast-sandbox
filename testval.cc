#include "common.h"

#include <iostream>
#include <map>
#include "value.h"
#include "dict.h"

using namespace std;

void testrun(int times)
{
	int keyPrefix = 123400;

	map<int, Value*> hashtable;

	for (int i = 0; i < times; i++)
	{
		// GENERATE KEY
		int keyUid = keyPrefix*100 + i;

		// GENERATE RANDOM VALUE JSON
		string valueBuffer = "{'iter': '" + toString(i) +"', 'data': 'The quick brown fox jumps over the lazy dog'}";
		cout << "Value: " << valueBuffer;

		//ADD TO MAP
		Value *newValue = new Value(valueBuffer);
		hashtable[keyUid] = newValue;
	}

	// LIST ITEMS IN THE DICT
	cout << "Printing stuff now..";
	for (int i = 0; i < times; i ++)
	{
		int key = keyPrefix * 100 + i;
		cout << "\n Key: " << key << ", Value: " << hashtable[key]->getValue();
	}
}

void dictrun(int times) {
	Dict kvdict;

	for (int i = 0; i < times; i++) {
		// generate key
		int newKey = 1000 + i;

		// generate value
		string valueBuffer = "{'iter': '" + toString(i) +"', 'data': 'The quick brown fox jumps over the lazy dog'}";

		// insert into kvdict
		Value *newVal = new Value(valueBuffer);
		kvdict.Put(newKey, newVal, false);
	}

	cout << "Finished inserting, let's try other operations\n";

	cout << "Check for keys";
	cout << kvdict.IsPresent(1008) << endl;
	cout << kvdict.IsPresent(10050) << endl;

	cout << "Deletion" << endl;
	kvdict.Delete(1008);
	kvdict.Delete(109999);
	cout << kvdict.Get(1005)->getValue() << endl;
}

int main()
{
	typedef unsigned char BYTE;

//	testrun(10);
	dictrun(15);
}
