#include "..\\Lab11\Hash.h"

Node::Node(int size)
{
	srand(time(0));
	key = rand() % size;
	data = rand() % size;
}

void Node::changeKey(int size)
{
	this->key = rand() % size;
}

Hash::Hash()
{
	maxSize = 100;
	for (int i = 0; i < maxSize; i++) {
		table.push_back(nullptr);
	}

	curSize = 0;
}

Hash::Hash(int size)
{
	maxSize = size;
	for (int i = 0; i < maxSize; i++) {
		table.push_back(nullptr);
	}

	curSize = 0;
}

Hash::~Hash()
{
	for (int i = 0; i < maxSize; i++) {
		delete table[i];
	}
}

int Hash::hashFunction(int key)
{
	int spot = key % maxSize;
	return spot;
}

Node* Hash::addItem() 
{
	if (getLength() == maxSize) {
		return nullptr;
	}

	Node* node = new Node(maxSize);
	int index = hashFunction(node->key);

	while(table[index] != nullptr) {
		node->changeKey(maxSize);
		index = hashFunction(node->key);
	}

	table[index] = node;
	curSize++;
	return node;

}

Node* Hash::removeItem(int index)
{
	if (table[index] == nullptr) {
		return nullptr;
	}
	else {
		Node* temp = table[index];
		table[index] = nullptr;
		curSize--;
		return temp;
	}
}

Node* Hash::getItem(int index)
{
	return table[index];
}

int Hash::getLength()
{
	return curSize;
}