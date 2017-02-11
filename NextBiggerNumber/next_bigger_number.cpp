#include "../catch.hpp"

int FindNextBiggerNumber(int number)
{
	return -1;
}

TEST_CASE("Find next bigger number with the same digits", "[2-digits: 12]")
{
	REQUIRE(FindNextBiggerNumber(12) == 21);
}
