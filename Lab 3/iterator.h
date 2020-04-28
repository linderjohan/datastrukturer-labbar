#include "BinarySearchTree.h"

#pragma once

/* **********************************************************
 * Class to represent a bi-directional iterator for BSTs     *
 * Bi-directional iterators can be moved in both directions, *
 * increasing and decreasing order of items keys             *
 * ***********************************************************/

template <typename Comparable>
class BinarySearchTree<Comparable>::Iterator {
public:
	Iterator() : node_ptr{nullptr} {}

	~Iterator() = default;

	//return a reference to the element
	Comparable& operator*() const {
		return node_ptr->element;
	}
	
	//Return the adress of the element
	Comparable* operator->() const{
		return &node_ptr->element;
	}

	bool operator==(const Iterator& _it) const {
		return operator->() == _it.operator->();
		// return node_ptr == _it.node_ptr;
	}

	bool operator!=(Const Iterator& _it) const {
		return !(this == _it);
	}
	//Post Increment
	Iterator operator++(Iterator) {
		//return copy of *this
		const Iterator* old{*this};
		++(*this);
		return old;
	}

	//Pre increment
	Iterator& operator++() {
		node_ptr = BinarySearchTree<Comparable>::find_successor(node_ptr);
		// node_ptr = find_successor(node_ptr);
		return *this;
	}
	
	//Post decrement
	Iterator operator--(Iterator) {
		//return copy of *this
		const Iterator* old{*this};
		--(*this);
		return old;
	}

	//Pre decrement
	Iterator& operator--() {
		node_ptr = BinarySearchTree<Comparable>::find_predecessor(node_ptr);
		// node_ptr = find_predecessor(node_ptr);
		return *this;
	}

private:
	Node* node_ptr;

protected:
	Iterator(Node* _ptr) : node_ptr{_ptr} {}
};
