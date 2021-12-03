#include "List.h"

template <class T>
class List<T>::Node {
	T m_value;
	Node* p_next;
	Node* p_prev;

	Node(const T &value) : m_value{ value }, p_next{ nullptr }, p_prev{ nullptr } {}
};

template <class T>
List<T>::List() {
	p_head = nullptr;
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (p_head == nullptr) {
		p_head = new Node(value);
		return;
	}
}



