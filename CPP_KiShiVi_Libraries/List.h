#pragma once

template <class T>
class List {
private:
	class Node;
	Node* p_head;
public:
	List();
	T push_back (const T &value) const;
};