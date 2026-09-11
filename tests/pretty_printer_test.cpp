#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_all.hpp>
#include <string>
#include "../headers/pretty_printer.hpp"
#include "../headers/structs.hpp"

TEST_CASE("ITCH PRINTER TESTCASE #1", "[pretty_print_system_event_message]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nSYSTEM EVENT MESSAGE\n" + 
        ItchPrinter::dashes + "\nStock Locate: 42" + 
        "\nTracking Number: 1001" + "\nTimestamp: 500" + "\nEvent Code: O\n\n";
    ItchStruct::SystemEventMessage test = ItchStruct::SystemEventMessage{};
    test.stockLocate = 42;
    test.trackingNumber = 1001;
    test.timeStamp = 500;
    test.eventCode = 'O';

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}