#ifndef INCLUDED_PRINT_ARRAY_HPP
#define INCLUDED_PRINT_ARRAY_HPP

/*
Print a one-dimensional iterable data structure (e.g. a std::vector<int>) to
std::cout with formatting similar to Python lists or JavaScript arrays.
*/

#include <iostream>

template <typename IteratorType>
inline void print_array(
		const IteratorType& begin,
		const IteratorType& end,
		std::ostream& out = std::cout) {

	auto it = begin;

	out << '[';

	if (it != end) {
		out << *it;
		++it;
	}

	for (; it != end; ++it) {
		out << ',' << *it;
	}

	out << ']';

}

template <typename IterableType>
inline void print_array(
		const IterableType& iterable,
		std::ostream& out = std::cout) {
	print_array(iterable.begin(), iterable.end(), out);
}

#endif
