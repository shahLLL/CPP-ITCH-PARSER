#include <catch2/catch_test_macros.hpp>
#include "../headers/parser.hpp"

TEST_CASE("PARSER TESTCASES #1", "[parse_message_length]") {
    // Test cases for the parseMessageLength function.
    REQUIRE(!Parser::parseMessageLength('1').has_value());
    REQUIRE(!Parser::parseMessageLength('?').has_value());
    REQUIRE(!Parser::parseMessageLength('o').has_value());
    REQUIRE(!Parser::parseMessageLength('Z').has_value());

    REQUIRE(Parser::parseMessageLength('S').has_value());
    REQUIRE(Parser::parseMessageLength('S').value() == 12);
    REQUIRE(Parser::parseMessageLength('R').has_value());
    REQUIRE(Parser::parseMessageLength('R').value() == 39);
    REQUIRE(Parser::parseMessageLength('H').has_value());
    REQUIRE(Parser::parseMessageLength('H').value() == 25);
    REQUIRE(Parser::parseMessageLength('Y').has_value());
    REQUIRE(Parser::parseMessageLength('Y').value() == 20);
    REQUIRE(Parser::parseMessageLength('L').has_value());
    REQUIRE(Parser::parseMessageLength('L').value() == 26);
    REQUIRE(Parser::parseMessageLength('V').has_value());
    REQUIRE(Parser::parseMessageLength('V').value() == 35);
    REQUIRE(Parser::parseMessageLength('W').has_value());
    REQUIRE(Parser::parseMessageLength('W').value() == 12);
    REQUIRE(Parser::parseMessageLength('K').has_value());
    REQUIRE(Parser::parseMessageLength('K').value() == 28);
    REQUIRE(Parser::parseMessageLength('J').has_value());
    REQUIRE(Parser::parseMessageLength('J').value() == 35);
    REQUIRE(Parser::parseMessageLength('h').has_value());
    REQUIRE(Parser::parseMessageLength('h').value() == 21);
    REQUIRE(Parser::parseMessageLength('A').has_value());
    REQUIRE(Parser::parseMessageLength('A').value() == 36);
    REQUIRE(Parser::parseMessageLength('F').has_value());
    REQUIRE(Parser::parseMessageLength('F').value() == 40);
    REQUIRE(Parser::parseMessageLength('E').has_value());
    REQUIRE(Parser::parseMessageLength('E').value() == 31);
    REQUIRE(Parser::parseMessageLength('C').has_value());
    REQUIRE(Parser::parseMessageLength('C').value() == 36);
    REQUIRE(Parser::parseMessageLength('X').has_value());
    REQUIRE(Parser::parseMessageLength('X').value() == 23);
    REQUIRE(Parser::parseMessageLength('D').has_value());
    REQUIRE(Parser::parseMessageLength('D').value() == 19);
    REQUIRE(Parser::parseMessageLength('U').has_value());
    REQUIRE(Parser::parseMessageLength('U').value() == 35);
    REQUIRE(Parser::parseMessageLength('P').has_value());
    REQUIRE(Parser::parseMessageLength('P').value() == 44);
    REQUIRE(Parser::parseMessageLength('Q').has_value());
    REQUIRE(Parser::parseMessageLength('Q').value() == 40);
    REQUIRE(Parser::parseMessageLength('B').has_value());
    REQUIRE(Parser::parseMessageLength('B').value() == 19);
    REQUIRE(Parser::parseMessageLength('I').has_value());
    REQUIRE(Parser::parseMessageLength('I').value() == 50);
    REQUIRE(Parser::parseMessageLength('O').has_value());
    REQUIRE(Parser::parseMessageLength('O').value() == 48);
}