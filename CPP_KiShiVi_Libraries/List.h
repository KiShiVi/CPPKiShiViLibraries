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
	iterator begin() const;
	iterator last() const;
	iterator end() const;

	int size() const;
	void erase();
	void push_back(const T& value);
	void push_front(const T& value);
	T pop(const int index);

	T& operator[] (int index);
};

#include "list.inl"


