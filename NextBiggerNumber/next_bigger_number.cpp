#include "../catch.hpp"

unsigned int FindNextBiggerNumber(unsigned int number)
{
	const auto ones = number % 10;
	const auto tens = number / 10 % 10;
	const auto new_number = ones * 10 + tens;
	return (new_number > number) ? new_number : -1;
}

TEST_CASE("Find next bigger number with the same digits", "[2-digits]")
{
	REQUIRE(FindNextBiggerNumber(12) == 21);
	REQUIRE(FindNextBiggerNumber(32) == -1);
}
