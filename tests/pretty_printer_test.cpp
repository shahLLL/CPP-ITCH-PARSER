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

TEST_CASE("ITCH PRINTER TESTCASE #3", "[pretty_print_stock_trading_action]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nSTOCK TRADING ACTION\n" + 
        ItchPrinter::dashes + "\nStock Locate: 22" + 
        "\nTracking Number: 44" + "\nTimestamp: 100990" + "\nStock: AAPL" +
        "\nTrading State: T" + "\nReserved: Y" + "\nReason: MVI\n\n";
    ItchStruct::StockTradingAction test = ItchStruct::StockTradingAction{};
    test.stockLocate = 22;
    test.trackingNumber = 44;
    test.timeStamp = 100990;
    test.stock[0] = 'A';
    test.stock[1] = 'A';
    test.stock[2] = 'P';
    test.stock[3] = 'L';
    test.tradingState = 'T';
    test.reserved = 'Y';
    test.reason[0] = 'M';
    test.reason[1] = 'V';
    test.reason[2] = 'I';

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}

TEST_CASE("ITCH PRINTER TESTCASE #4", "[pretty_print_reg_sho_restriction]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nREG SHO RESTRICTION\n" + 
        ItchPrinter::dashes + "\nLocate Code: 34" + 
        "\nTracking Number: 12" + "\nTimestamp: 123456" + "\nStock: TSLA" +
        "\nRegSHO Action: 1\n\n";
    ItchStruct::RegSHORestriction test = ItchStruct::RegSHORestriction{};
    test.locateCode = 34;
    test.trackingNumber = 12;
    test.timeStamp = 123456;
    test.stock[0] = 'T';
    test.stock[1] = 'S';
    test.stock[2] = 'L';
    test.stock[3] = 'A';
    test.regSHOAction = '1';

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}

TEST_CASE("ITCH PRINTER TESTCASE #5", "[pretty_print_market_participant_position]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nMARKET PARTICIPANT POSITION\n" + 
        ItchPrinter::dashes + "\nStock Locate: 134" + 
        "\nTracking Number: 90" + "\nTimestamp: 788990" +  "\nMPID: BARC" + 
        "\nStock: TSLA" + "\nPrimary Market Maker: Y" + 
        "\nMarket Maker Mode: N" + "\nMarket Participant State: A\n\n";

    ItchStruct::MarketParticipantPosition test = ItchStruct::MarketParticipantPosition{};
    test.stockLocate = 134;
    test.trackingNumber = 90;
    test.timeStamp = 788990;
    test.mpid[0] = 'B';
    test.mpid[1] = 'A';
    test.mpid[2] = 'R';
    test.mpid[3] = 'C';
    test.stock[0] = 'T';
    test.stock[1] = 'S';
    test.stock[2] = 'L';
    test.stock[3] = 'A';
    test.primaryMarketMaker = 'Y';
    test.marketMakerMode = 'N';
    test.marketParticipantState = 'A';

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}

TEST_CASE("ITCH PRINTER TESTCASE #6", "[pretty_print_mwcb_decline_level_message]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nMWCB DECLINE LEVEL MESSAGE\n" + 
        ItchPrinter::dashes + "\nStock Locate: 221" + 
        "\nTracking Number: 51" + "\nTimestamp: 62700" + "\nLevel I: 700000" +
        "\nLevel II: 900000" + "\nLevel III: 1100000\n\n";

    ItchStruct::MWCBDeclineLevelMessage test = ItchStruct::MWCBDeclineLevelMessage{};
    test.stockLocate = 221;
    test.trackingNumber = 51;
    test.timeStamp = 62700;
    test.level1 = 700000;
    test.level2 = 900000;
    test.level3 = 1100000;

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}

TEST_CASE("ITCH PRINTER TESTCASE #7", "[pretty_print_mwcb_status_message]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nMWCB STATUS MESSAGE\n" + 
        ItchPrinter::dashes + "\nStock Locate: 308" + 
        "\nTracking Number: 22" + "\nTimestamp: 89000" + "\nBreached Level: 1\n\n";

    ItchStruct::MWCBStatusMessage test = ItchStruct::MWCBStatusMessage{};
    test.stockLocate = 308;
    test.trackingNumber = 22;
    test.timeStamp = 89000;
    test.breachedLevel = '1';

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}

TEST_CASE("ITCH PRINTER TESTCASE #8", "[pretty_print_quoting_period_update]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nQUOTING PERIOD UPDATE\n" + 
        ItchPrinter::dashes + "\nStock Locate: 412" + 
        "\nTracking Number: 20" + "\nTimestamp: 540000" + "\nStock: AMZN" +
        "\nIPO Quotation Release Time: 40000" + "\nIPO Quotation Release Qualifier: A" +
        "\nIPO Price: 32000\n\n";

    ItchStruct::QuotingPeriodUpdate test = ItchStruct::QuotingPeriodUpdate{};
    test.stockLocate = 412;
    test.trackingNumber = 20;
    test.timeStamp = 540000;
    test.stock[0] = 'A';
    test.stock[1] = 'M';
    test.stock[2] = 'Z';
    test.stock[3] = 'N';
    test.ipoQuotationReleaseTime = 40000;
    test.ipoQuotationReleaseQualifier = 'A';
    test.ipoPrice = 32000;

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}

TEST_CASE("ITCH PRINTER TESTCASE #9", "[pretty_print_luld_auction_collar]") {
    Catch::RedirectedStdOut redirectedOutput;
    std::string expected = ItchPrinter::dashes + "\nLULD AUCTION COLLAR\n" + 
        ItchPrinter::dashes + "\nStock Locate: 918" + 
        "\nTracking Number: 17" + "\nTimestamp: 98000" + "\nStock: TSLA" +
        "\nAuction Collar Reference Price: 175000" + 
        "\nUpper Auction Collar Price: 1925000" +
        "\nLower Auction Collar Price: 150000" +
        "\nAuction Collar Extension: 2\n\n";

    ItchStruct::LULDAuctionCollar test = ItchStruct::LULDAuctionCollar{};
    test.stockLocate = 918;
    test.trackingNumber = 17;
    test.timeStamp = 98000;
    test.stock[0] = 'T';
    test.stock[1] = 'S';
    test.stock[2] = 'L';
    test.stock[3] = 'A';
    test.auctionCollarReferencePrice = 175000;
    test.upperAuctionCollarPrice = 1925000;
    test.lowerAuctionCollarPrice = 150000;
    test.auctionCollarExtension = 2;

    ItchPrinter::printItchData(test);
    std::string output = redirectedOutput.str();
    REQUIRE(output == expected);
}
