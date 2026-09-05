#include <catch2/catch_test_macros.hpp>
#include "../headers/parser.hpp"

TEST_CASE("PARSER TESTCASES #1", "[parse_message_length]") {
    // Test cases for the parseMessageLength function.
    REQUIRE(!parseMessageLength('1').has_value());
    REQUIRE(!parseMessageLength('?').has_value());
    REQUIRE(!parseMessageLength('o').has_value());
    REQUIRE(!parseMessageLength('Z').has_value());

    REQUIRE(parseMessageLength('S').has_value());
    REQUIRE(parseMessageLength('S').value() == 12);
    REQUIRE(parseMessageLength('R').has_value());
    REQUIRE(parseMessageLength('R').value() == 39);
    REQUIRE(parseMessageLength('H').has_value());
    REQUIRE(parseMessageLength('H').value() == 25);
    REQUIRE(parseMessageLength('Y').has_value());
    REQUIRE(parseMessageLength('Y').value() == 20);
    REQUIRE(parseMessageLength('L').has_value());
    REQUIRE(parseMessageLength('L').value() == 26);
    REQUIRE(parseMessageLength('V').has_value());
    REQUIRE(parseMessageLength('V').value() == 35);
    REQUIRE(parseMessageLength('W').has_value());
    REQUIRE(parseMessageLength('W').value() == 12);
    REQUIRE(parseMessageLength('K').has_value());
    REQUIRE(parseMessageLength('K').value() == 28);
    REQUIRE(parseMessageLength('J').has_value());
    REQUIRE(parseMessageLength('J').value() == 35);
    REQUIRE(parseMessageLength('h').has_value());
    REQUIRE(parseMessageLength('h').value() == 21);
    REQUIRE(parseMessageLength('A').has_value());
    REQUIRE(parseMessageLength('A').value() == 36);
    REQUIRE(parseMessageLength('F').has_value());
    REQUIRE(parseMessageLength('F').value() == 40);
    REQUIRE(parseMessageLength('E').has_value());
    REQUIRE(parseMessageLength('E').value() == 31);
    REQUIRE(parseMessageLength('C').has_value());
    REQUIRE(parseMessageLength('C').value() == 36);
    REQUIRE(parseMessageLength('X').has_value());
    REQUIRE(parseMessageLength('X').value() == 23);
    REQUIRE(parseMessageLength('D').has_value());
    REQUIRE(parseMessageLength('D').value() == 19);
    REQUIRE(parseMessageLength('U').has_value());
    REQUIRE(parseMessageLength('U').value() == 35);
    REQUIRE(parseMessageLength('P').has_value());
    REQUIRE(parseMessageLength('P').value() == 44);
    REQUIRE(parseMessageLength('Q').has_value());
    REQUIRE(parseMessageLength('Q').value() == 40);
    REQUIRE(parseMessageLength('B').has_value());
    REQUIRE(parseMessageLength('B').value() == 19);
    REQUIRE(parseMessageLength('l').has_value());
    REQUIRE(parseMessageLength('l').value() == 50);
    REQUIRE(parseMessageLength('O').has_value());
    REQUIRE(parseMessageLength('O').value() == 48);
}