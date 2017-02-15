#include "../catch.hpp"
#include <algorithm>
#include <vector>

std::vector<unsigned int> BreakIntoDigits(unsigned int number)
{
	if (number < 10)
		return {number};

	std::vector<unsigned int> digits{number % 10};
	for (unsigned int base = 10;; base *= 10) {
		const auto digit = number / base % 10;
		if (digit == 0)
			break;
		
		digits.push_back(digit);
	}

	return digits;
}

unsigned int ConvertDigitsToNumber(const std::vector<unsigned int>& digits)
{
	unsigned int new_number = digits[0];
	for (int i = 1, base = 10; i < digits.size(); ++i, base *= 10) {
		new_number += digits[i] * base;
	}
	return new_number;
}

unsigned int FindNextBiggerNumber(unsigned int number)
{
	auto digits = BreakIntoDigits(number);
	if (digits.size() == 1)
		return -1;

//	for (auto it = begin(digits); it < end(digits); ++it) {
//		std::iter_swap(digits.begin(), std::min_element(digits.begin(), digits.end()));
//	}

	const auto new_number = ConvertDigitsToNumber(digits);
	return (new_number > number) ? new_number : -1;
}

TEST_CASE("Find next bigger number with the same digits", "[vector]")
{
	SECTION("2-digits") {
		REQUIRE(FindNextBiggerNumber(12) == 21);
		REQUIRE(FindNextBiggerNumber(32) == -1);
		REQUIRE(FindNextBiggerNumber(77) == -1);
		REQUIRE(FindNextBiggerNumber(89) == 98);
	}

	SECTION("3-digits") {
		REQUIRE(FindNextBiggerNumber(123) == 132);
		REQUIRE(FindNextBiggerNumber(132) == 213);
		REQUIRE(FindNextBiggerNumber(122) == 212);
	}
}

TEST_CASE("Break number into digits then save in container", "[vector]")
{
	SECTION("Single digit") {
		REQUIRE(BreakIntoDigits(7).size() == 1);
	}

	SECTION("2 digits") {
		const auto digits = BreakIntoDigits(89);
		REQUIRE(digits.size() == 2);
		REQUIRE(digits[0] == 9);
		REQUIRE(digits[1] == 8);
	}

	SECTION("Many digits") {
		const auto digits = BreakIntoDigits(12345678);
		REQUIRE(digits.size() == 8);
	}
}

TEST_CASE("Convert digits to number", "[vector]")
{
	REQUIRE(ConvertDigitsToNumber({1, 2}) == 21);
	REQUIRE(ConvertDigitsToNumber({1, 2, 3}) == 321);
}
