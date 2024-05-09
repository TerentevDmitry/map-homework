#pragma once
#include "./Catch2/src/catch2/catch_test_macros.hpp"
#include "./Catch2/src/catch2/catch_session.hpp"
#include "shape.h"
#include "Catch2/extras/catch_amalgamated.hpp"



TEST_CASE("test string", "[testString]")
{
	SECTION("std::string")
	{
		CHECK(stri("Hello Dima") == "Hello Dima");
	}
}


TEST_CASE("test num", "[testNum]")
{
	SECTION("int")
	{
		CHECK(nume(89240) == 89240);
	}
}





int main(int argc, char* argv[])
{

	return Catch::Session().run(argc, argv);
}