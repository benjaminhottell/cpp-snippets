/*
This is a small dummy file to confirm doctest is working on your system.

doctest: https://github.com/doctest/doctest
*/

#include <iostream>

inline int dummy(int x) {
	return 1 + (-x);
}


/* testing */

#include <doctest/doctest.h>

TEST_CASE("doctest-dummy") {
	CHECK(dummy(-1) == 2);
	CHECK(dummy(0) == 1);
	CHECK(dummy(1) == 0);
	CHECK(dummy(2) == -1);
	CHECK(dummy(100) == -99);
}
