#include <snippets/array_io.hpp>
#include <doctest/doctest.h>

#include <climits>
#include <vector>
#include <sstream>

template<typename T = int>
void test_print_array(std::vector<T> v, const std::string& expect) {
	std::ostringstream out {};
	print_array(v, out);
	CHECK(out.str() == expect);
}

TEST_CASE("array_io-print") {
	test_print_array({}, "[]");
	test_print_array({1}, "[1]");
	test_print_array({1,2}, "[1,2]");
	test_print_array({-1,2,3,100,-3}, "[-1,2,3,100,-3]");
}

