#pragma once

template <class T>
class list {
private:
	class Node;
	Node* p_head;
	Node* p_tail;
public:
	list(): p_head(nullptr), p_tail(nullptr) {};
	class iterator;
	iterator begin();
	iterator last();
	iterator end();

	void push_back(const T& value);
};

#include "list.inl"


