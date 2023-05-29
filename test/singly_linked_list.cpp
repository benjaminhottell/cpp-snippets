#include <snippets/singly_linked_list.hpp>

#include <doctest/doctest.h>

sll_node<int>* new_sll(const std::initializer_list<int>& vals) {
	return sll_copy_from_iterable<int>(vals);
}

TEST_CASE("sll-empty-is-nullptr") {
	CHECK(new_sll({}) == nullptr);
}

TEST_CASE("sll-equals") {
	CHECK(sll_equals<int>(nullptr, nullptr));
	CHECK(sll_equals<int>(new_sll({}), nullptr));

	auto sll1 = new_sll({1,2,3});
	auto sll2 = new_sll({1,2,3});
	CHECK(sll_equals<int>(sll1, sll2));
	CHECK_FALSE(sll_equals<int>(nullptr, sll2));
	CHECK_FALSE(sll_equals<int>(sll1, nullptr));
	sll_delete_all(sll1);
	sll_delete_all(sll2);

	sll1 = new_sll({1,2,5});
	sll2 = new_sll({1,2,3});
	CHECK_FALSE(sll_equals<int>(sll1, sll2));
	sll_delete_all(sll2);


	sll2 = new_sll({1,2});
	CHECK_FALSE(sll_equals<int>(sll1, sll2));
	sll_delete_all(sll1);
	sll_delete_all(sll2);
}

void test_sll_remove_all(
		const std::initializer_list<int>& vals_in,
		const std::initializer_list<int>& vals_out,
		int remove_value) {

	auto sll_in = new_sll(vals_in);
	auto sll_out = new_sll(vals_out);

	sll_remove_all(sll_in, remove_value);

	CHECK(sll_equals(sll_in, sll_out));

	sll_delete_all(sll_in);
	sll_delete_all(sll_out);
}

TEST_CASE("sll-remove_all") {

	{
		sll_node<int>* null_value = nullptr;
		sll_remove_all<int>(null_value, 1);
		CHECK(null_value == nullptr);
	}

	test_sll_remove_all({}, {}, 5);

	test_sll_remove_all({1}, {1}, -1);
	test_sll_remove_all({1}, {}, 1);
	test_sll_remove_all({1,1}, {}, 1);
	test_sll_remove_all({1,1,1}, {}, 1);
	test_sll_remove_all({2,1,1,1,2}, {2,2}, 1);

	test_sll_remove_all({1,2,3}, {1,2,3}, 5);
	test_sll_remove_all({1,2,3}, {2,3}, 1);
	test_sll_remove_all({1,2,3}, {1,3}, 2);
	test_sll_remove_all({1,2,3}, {1,2}, 3);

}
