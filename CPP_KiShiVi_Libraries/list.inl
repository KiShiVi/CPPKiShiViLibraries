#include "list.h"

template <class T>
class list<T>::Node {
public:
	T m_value;
	Node* p_next;
	Node* p_prev;

	Node(const T& value) : m_value(value), p_next(nullptr), p_prev(nullptr) {};
};


template <class T>
class list<T>::iterator {
private:
	Node* p_ptr;
	iterator(Node* ptr) : p_ptr(ptr) {};
public:
	iterator(const iterator& it) : p_ptr(it.p_ptr) {};
	iterator& operator++ () {
		p_ptr = p_ptr->p_next;
		return *this;
	}
	iterator& operator-- () {
		p_ptr = p_ptr->p_prev;
		return *this;
	}
	T& operator* () {
		return p_ptr->m_value;
	}
	iterator& operator=(const iterator& it) {
		p_ptr = it.p_ptr;
		return *this;
	}
	friend bool operator==(const iterator& it1, const iterator& it2) {
		if (it1.p_ptr == it2.p_ptr)
			return true;
		return false;
	}
	friend bool operator!=(const iterator& it1, const iterator& it2) {
		return !(it1 == it2);
	}
	friend class list;
};


template<class T>
typename list<T>::iterator list<T>::begin() {
	return iterator(p_head);
}


template<class T>
typename list<T>::iterator list<T>::last() {
	return iterator(p_tail);
}


template<class T>
typename list<T>::iterator list<T>::end() {
	return iterator(p_tail->p_next);
}

template<class T>
void list<T>::push_back(const T& value)
{
	if (p_head == nullptr) {
		p_head = new Node(value);
		p_tail = p_head;
		return;
	}
	p_tail->p_next = new Node(value);
	p_tail->p_next->p_prev = p_tail;
	p_tail = p_tail->p_next;
}


template<class T>
void list<T>::push_front(const T& value)
{
	if (p_head == nullptr) {
		push_front(value);
		return;
	}
	p_head->p_prev = new Node(value);
	p_head->p_prev->p_next = p_head;
	p_head = p_head->p_prev;
}