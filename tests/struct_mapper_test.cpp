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
    REQUIRE(std::string_view(stockDirectory.stock, 8) == "AAPL    ");
    REQUIRE(stockDirectory.marketCategory == 'Q');
    REQUIRE(stockDirectory.financialStatusIndicator == 'N');
    REQUIRE(stockDirectory.roundLotSize == 100);
    REQUIRE(stockDirectory.roundLotsOnly == 'Y');
    REQUIRE(stockDirectory.issueClassification == 'C');
    REQUIRE(std::string_view(stockDirectory.issueSubType, 2) == "NA");
    REQUIRE(stockDirectory.authenticity == 'P');
    REQUIRE(stockDirectory.shortSaleThresholdIndicator == 'N');
    REQUIRE(stockDirectory.ipoFlag == 'N');
    REQUIRE(stockDirectory.luldReferencePriceTier == '1');
    REQUIRE(stockDirectory.etpFlag == 'N');
    REQUIRE(stockDirectory.etpLeverageFactor == 0);
    REQUIRE(stockDirectory.inverseIndicator == 'N');
}