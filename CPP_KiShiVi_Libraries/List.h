#pragma once

template <class T>
class List {
private:
	private class Node;
	Node* p_head;
public:
	List();
	void push_back (const T &value);
};