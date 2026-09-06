#include <catch2/catch_test_macros.hpp>
#include "../headers/struct_mapper.hpp"

TEST_CASE("STRUCT MAPPER TESTCASE #1", "[map_system_event_message]") {
    std::byte testcase[] = {
        std::byte{0x53},
        std::byte{0x00}, std::byte{0x2A},
        std::byte{0x03}, std::byte{0xE9},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
        std::byte{0x4F}
    };

    SystemEventMessage systemEventMessage = mapSystemEventMessage(testcase);
    REQUIRE(systemEventMessage.messageType == 'S');
    REQUIRE(systemEventMessage.stockLocate == 42);
    REQUIRE(systemEventMessage.trackingNumber == 1001);
    REQUIRE(systemEventMessage.timeStamp == 500);
    REQUIRE(systemEventMessage.eventCode == 'O');
}

TEST_CASE("STRUCT MAPPER TESTCASE #2", "[map_stock_directory]") {
    std::byte testcase[] = {
        std::byte{0x52},
        std::byte{0x00}, std::byte{0x64},
        std::byte{0x01}, std::byte{0xF4},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x03}, std::byte{0xE8},
        std::byte{0x41}, std::byte{0x41}, std::byte{0x50}, std::byte{0x4C},
        std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x51},
        std::byte{0x4E},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x64},
        std::byte{0x59},
        std::byte{0x43},
        std::byte{0x4E}, std::byte{0x41},
        std::byte{0x50},
        std::byte{0x4E},
        std::byte{0x4E},
        std::byte{0x31},
        std::byte{0x4E},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x00},
        std::byte{0x4E}
    };

    StockDirectory stockDirectory = mapStockDirectory(testcase);
    REQUIRE(stockDirectory.messageType == 'R');
    REQUIRE(stockDirectory.stockLocate == 100);
    REQUIRE(stockDirectory.trackingNumber == 500);
    REQUIRE(stockDirectory.timeStamp == 1000);
    REQUIRE(std::string_view(stockDirectory.stock, alpha8Size) == "AAPL    ");
    REQUIRE(stockDirectory.marketCategory == 'Q');
    REQUIRE(stockDirectory.financialStatusIndicator == 'N');
    REQUIRE(stockDirectory.roundLotSize == 100);
    REQUIRE(stockDirectory.roundLotsOnly == 'Y');
    REQUIRE(stockDirectory.issueClassification == 'C');
    REQUIRE(std::string_view(stockDirectory.issueSubType, alpha2Size) == "NA");
    REQUIRE(stockDirectory.authenticity == 'P');
    REQUIRE(stockDirectory.shortSaleThresholdIndicator == 'N');
    REQUIRE(stockDirectory.ipoFlag == 'N');
    REQUIRE(stockDirectory.luldReferencePriceTier == '1');
    REQUIRE(stockDirectory.etpFlag == 'N');
    REQUIRE(stockDirectory.etpLeverageFactor == 0);
    REQUIRE(stockDirectory.inverseIndicator == 'N');
}

TEST_CASE("STRUCT MAPPER TESTCASE #3", "[map_stock_trading_action]") {
    std::byte testcase[] = {
        std::byte{0x48},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x00}, std::byte{0x07},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x3A}, std::byte{0xDE}, std::byte{0x68}, std::byte{0xB1},
        std::byte{0x41}, std::byte{0x41}, std::byte{0x50}, std::byte{0x4C}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x54},
        std::byte{0x00},
        std::byte{0x4D}, std::byte{0x56}, std::byte{0x49}, std::byte{0x20},
    };

    StockTradingAction stockTradingAction = mapStockTradingAction(testcase);
    REQUIRE(stockTradingAction.messageType == 'H');
    REQUIRE(stockTradingAction.stockLocate == 1324);
    REQUIRE(stockTradingAction.trackingNumber == 7);
    REQUIRE(stockTradingAction.timeStamp == 987654321);
    REQUIRE(stockTradingAction.tradingState == 'T');
    REQUIRE(stockTradingAction.reserved == '\0');
    REQUIRE(std::string_view(stockTradingAction.reason, alpha4Size) == "MVI ");
}

TEST_CASE("STRUCT MAPPER TESCASE #4", "[map_reg_sho_restriction]") {
    std::byte testcase[] = {
        std::byte{0x59},
        std::byte{0x02}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x0C},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x08}, std::byte{0x4A}, std::byte{0xEA},
        std::byte{0x4D}, std::byte{0x53}, std::byte{0x46}, std::byte{0x54}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x31}
    };

    RegSHORestriction regSHORestriction = mapRegSHORestriction(testcase);
    REQUIRE(regSHORestriction.messageType == 'Y');
    REQUIRE(regSHORestriction.locateCode == 512);
    REQUIRE(regSHORestriction.trackingNumber == 12);
    REQUIRE(regSHORestriction.timeStamp == 543466);
    REQUIRE(std::string_view(regSHORestriction.stock, alpha8Size) == "MSFT    ");
    REQUIRE(regSHORestriction.regSHOAction == '1');
}

TEST_CASE("STRUCT MAPPER TESCASE #4", "[map_market_participation_position]") { 
    std::byte testcase[] = {
        std::byte{0x4C},
        std::byte{0x20}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x03},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x42}, std::byte{0x41}, std::byte{0x52}, std::byte{0x43},
        std::byte{0x54}, std::byte{0x53}, std::byte{0x4C}, std::byte{0x41}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x59},
        std::byte{0x4E},
        std::byte{0x41}
    };

    MarketParticipantPosition marketParticipationPosition = mapMarketParticipationPostion(testcase);
    REQUIRE(marketParticipationPosition.messageType == 'L');
    REQUIRE(marketParticipationPosition.stockLocate == 8192);
    REQUIRE(marketParticipationPosition.trackingNumber == 3);
    REQUIRE(marketParticipationPosition.timeStamp == 3456627252);
    REQUIRE(std::string_view(marketParticipationPosition.mpid, alpha4Size) == "BARC");
    REQUIRE(std::string_view(marketParticipationPosition.stock, alpha8Size) == "TSLA    ");
    REQUIRE(marketParticipationPosition.primaryMarketMaker == 'Y');
    REQUIRE(marketParticipationPosition.marketMakerMode == 'N');
    REQUIRE(marketParticipationPosition.marketParticipantState == 'A');
}