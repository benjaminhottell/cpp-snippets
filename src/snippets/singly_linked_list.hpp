#ifndef INCLUDED_SINGLY_LINKED_LIST_HPP
#define INCLUDED_SINGLY_LINKED_LIST_HPP

/*
Code for working with C-like singly linked lists.

This code probably isn't useful for 'real' programs, but it demonstrates how
singly linked list algorithms might work in practice.

Abbreviation: sll = singly linked list

A null pointer (nullptr) is used to represent an empty list. All list nodes
(sll_nodes) must have a value.
*/

#include <utility>

template <typename T = int>
struct sll_node {
	T val;
	sll_node* next = nullptr;

	sll_node() = default;
	sll_node(const T& t_value) : val(t_value) {}
	sll_node(T&& t_value) : val(std::move(t_value)) {}
};

// delete all nodes in the list ('destruct' the list)
template<typename T>
inline void sll_delete_all(sll_node<T>* head) {
	sll_node<T>* to_delete;
	while (head != nullptr) {
		to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

// check if two singly linked lists are equal, which means that they are equal
// in length and that all their nodes have equal values. (a singly linked list
// is also equal to itself).
template<typename T>
inline bool sll_equals(sll_node<T>* sll1, sll_node<T>* sll2) {
	if (sll1 == sll2) return true;

	if (sll1 == nullptr || sll2 == nullptr) return false;

	while (sll1 != nullptr && sll2 != nullptr) {
		if (sll1->val != sll2->val) {
			return false;
		}
		sll1 = sll1->next;
		sll2 = sll2->next;
	}

	// both should equal nullptr
	return sll1 == sll2;
}

// construct a new singly linked list by copying all elements from a contiguous
// iterator
template<typename T, typename IteratorType>
inline sll_node<T>* sll_copy_from_iterator(
		IteratorType const& begin,
		IteratorType const& end) {

	if (begin == end) return nullptr;

	IteratorType it = begin;

	sll_node<T>* ret = new sll_node<T>(*it);
	++it;

	sll_node<T>* cursor = ret;

	for (; it != end; ++it) {
		cursor->next = new sll_node<T>(*it);
		cursor = cursor->next;
	}

	return ret;
}

// construct a new singly linked list by copying all elements from another data
// structure that implements begin and end (e.g. a std::vector<T>)
template<typename T, typename IterableType>
inline sll_node<T>* sll_copy_from_iterable(IterableType const& it) {
	return sll_copy_from_iterator<T>(it.begin(), it.end());
}

// removes all nodes in the list that have a value equal to val
template<typename T>
inline void sll_remove_all(sll_node<T>*& head, const T& val) {
	if (head == nullptr) return;

	while (head != nullptr && head->val == val) {
		sll_node<T>* to_delete = head;
		head = head->next;
		delete to_delete;
	}

	sll_node<T>* cursor = head;

	while (cursor != nullptr && cursor->next != nullptr) {
		if (cursor->next->val == val) {
			sll_node<T>* to_delete = cursor->next;
			cursor->next = cursor->next->next;
			delete to_delete;
		} else {
			cursor = cursor->next;
		}
	}
}

#endif

