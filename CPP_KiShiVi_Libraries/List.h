#pragma once

template <class T>
class list {
private:
	class Node;
	Node* p_head;
	Node* p_tail;
public:
	list(): p_head(nullptr), p_tail(nullptr) {};
	~list();
	class iterator;
	iterator begin();
	iterator last();
	iterator end();

	int size();
	void erase();
	void push_back(const T& value);
	void push_front(const T& value);
	T pop(const int index);
};

#include "list.inl"


