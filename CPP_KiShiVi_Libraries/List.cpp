#include "List.h"

template <class T>
class List<T>::Node {
	T m_value;
	Node* p_next;
	Node* p_prev;
};

template <class T>
List<T>::List() {
	p_head = nullptr;
}

template<class T>
T List<T>::push_back(const T& value) const
{
	return value;	// plug
}



