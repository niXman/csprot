
#include <iostream>
#include <cstring>
#include <cassert>

#include "csprot.hpp"

using csprot::operator"" _S;
using csprot::operator"" _XS;

#define TEST(...) \
	static_assert(__VA_ARGS__, #__VA_ARGS__)

/**************************************************************************/

void test_prop() {
	TEST("1"_S.plain() == true);
	TEST("1"_S.xored() == false);
	TEST("1"_XS.plain() == false);
	TEST("1"_XS.xored() == true);
}

void test_size() {
	TEST(""_S.size() == 0 && ""_S.length() == 0 && ""_S.empty() == true);
	TEST("1"_S.size() == 1 && "1"_S.length() == 1 && "1"_S.empty() == false);
}

void test_cat() {
	struct {
		constexpr int operator()(const char *a, const char *b) const {
			return
				*a == 0 && *b == 0 ? 0 :
				*a == 0 ? -1 :
				*b == 0 ? 1 :
				*a < *b ? -1 :
				*a > *b ? 1 :
				*a == *b ? operator()(a+1, b+1) : throw "compare::operator(a, b) error";
		}
	} compare{};

	auto s = "1"_S + "2"_S;
	TEST(compare(s.c_str(), "12") == 0);
}

void test_compare() {
	TEST("1"_S == "1"_S);
	TEST("1"_XS == "1"_XS);
	TEST("1"_S != "1"_XS);
	TEST("1"_S == "1"_S);
	TEST("1"_S != "2"_S);
	TEST(""_S == ""_S);
}

void test_xored_string() {
	TEST("1"_S.data()[0] == '1');
	TEST("1"_XS.data()[0] != '1');
}

/**************************************************************************/

int main() {
	test_prop();
	test_size();
	test_cat();
	test_compare();
	test_xored_string();

	auto s0 = "some xor`ed string 0"_XS;
	assert(std::strcmp(s0.data (), "some xor`ed string 0") != 0);
	assert(std::strcmp(s0.c_str(), "some xor`ed string 0") == 0);
	std::cout << "s0.data()=" << s0.data() << std::endl;
	std::cout << "s0.c_str()=" << s0.c_str() << std::endl;

	auto s1 = "some plain string 0"_S;
	assert(std::strcmp(s1.data (), "some plain string 0") == 0);
	assert(std::strcmp(s1.c_str(), "some plain string 0") == 0);
	std::cout << "s1.data()=" << s1.data() << std::endl;
	std::cout << "s1.c_str()=" << s1.c_str() << std::endl;
}

/**************************************************************************/
