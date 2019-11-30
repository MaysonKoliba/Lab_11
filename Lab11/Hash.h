#pragma once
#include "time.h"
#include <stdlib.h>
#include <vector>
using namespace std;

class Node
{
public:
	Node(int size);
	int key;
	int data;
	void changeKey(int size);
};


class Hash
{
public:
	Hash();
	Hash(int size);
	~Hash();
	Node* addItem();
	Node* removeItem(int index);
	Node* getItem(int index);
	int getLength();

private:
	int maxSize;
	int curSize;
	vector<Node*> table;
	int hashFunction(int key);

};