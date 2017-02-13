#include "../catch.hpp"

int FindNextBiggerNumber(int number)
{
	const auto ones = number % 10;
	const auto tens = number / 10 % 10;
	return ones * 10 + tens;
}

TEST_CASE("Find next bigger number with the same digits", "[2-digits: 12]")
{
	REQUIRE(FindNextBiggerNumber(12) == 21);
}
