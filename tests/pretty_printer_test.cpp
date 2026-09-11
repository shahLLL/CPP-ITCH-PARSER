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

TEST_CASE("ITCH PRINTER TESTCASE #2", "[pretty_print_stock_directory]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nSTOCK DIRECTORY\n" + 
        ItchPrinter::dashes + "\nStock Locate: 100" + 
        "\nTracking Number: 1" + "\nTimestamp: 500" + "\nStock: MSFT" +
        "\nMarket Category: Q" + "\nFinancial Status Indicator: N" + 
        "\nRound Lot Size: 100" + "\nRound Lots Only: N" +
        "\nIssue Classification: C" + "\nIssue Subtype: NA" +
        "\nAuthenticity: P" + "\nShort Sale Threshold Indicator: N" +
        "\nIPO Flag: N" + "\nLULD Reference Price Tier: 1" +
        "\nETP Flag: N" + "\nETP Leverage Factor: 20" + 
        "\nInverse Indicator: N\n\n";

    ItchStruct::StockDirectory test = ItchStruct::StockDirectory{};
    test.stockLocate = 100;
    test.trackingNumber = 1;
    test.timeStamp = 500;
    test.stock[0] = 'M';
    test.stock[1] = 'S';
    test.stock[2] = 'F';
    test.stock[3] = 'T';
    test.marketCategory = 'Q';
    test.financialStatusIndicator = 'N';
    test.roundLotSize = 100;
    test.roundLotsOnly = 'N';
    test.issueClassification = 'C';
    test.issueSubType[0] = 'N';
    test.issueSubType[1] = 'A';
    test.authenticity = 'P';
    test.shortSaleThresholdIndicator = 'N';
    test.ipoFlag = 'N';
    test.luldReferencePriceTier = '1';
    test.etpFlag = 'N';
    test.etpLeverageFactor = 20;
    test.inverseIndicator = 'N';

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}


