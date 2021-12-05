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

	iterator operator++ (T) {
		iterator it(*this);
		++(*this);
		return it;
	}

	iterator& operator-- () {
		p_ptr = p_ptr->p_prev;
		return *this;
	}

	iterator& operator-- (T) {
		iterator it(*this);
		--(*this);
		return it;
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
list<T>::~list() {
	erase();
}


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
	return nullptr;
}


template<class T>
int list<T>::size() {
	iterator it = begin();
	int result = 0;
	while (it != end()) {
		++result;
		++it;
	}
	return result;
}


template<class T>
void list<T>::erase() {
	while (p_head != nullptr) pop(0);
	return;
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


template<class T>
T list<T>::pop(const int index)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("index out of range");
	if (p_head == nullptr)
		throw std::out_of_range("index out of range");
	if (size() == 1) {
		T temp{ p_head->m_value };
		delete p_head;
		p_head = nullptr;
		p_tail = nullptr;
		return temp;
	}
	else if (index == 0) {
		T temp{ p_head->m_value };
		p_head = p_head->p_next;
		delete p_head->p_prev;
		p_head->p_prev = nullptr;
		return temp;
	}
	else if (index == size() - 1) {
		T temp{ p_tail->m_value };
		p_tail = p_tail->p_prev;
		delete p_tail->p_next;
		p_tail->p_next = nullptr;
		return temp;
	}
	else {
		iterator it = begin();;
		for (int i = 0; i < index - 1; ++i) ++it;
		Node* deletingNode = it.p_ptr->p_next;
		T temp{ deletingNode->m_value };
		it.p_ptr->p_next = deletingNode->p_next;
		deletingNode->p_next->p_prev = deletingNode->p_prev;
		delete deletingNode;
		return temp;
	}

}