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

TEST_CASE("STRUCT MAPPER TESTCASE #4", "[map_reg_sho_restriction]") {
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

TEST_CASE("STRUCT MAPPER TESTCASE #5", "[map_market_participation_position]") { 
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

TEST_CASE("STRUCT MAPPER TESTCASE #6", "[map_mwcb_decline_level_message]") {
    std::byte testcase[] = {
        std::byte{0x56},
        std::byte{0x00}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x01},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x0C}, std::byte{0xE0}, std::byte{0x7F}, std::byte{0x23}, 
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x10}, std::byte{0x4C}, std::byte{0x53}, std::byte{0x3C}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x12}, std::byte{0xA0}, std::byte{0x5F}, std::byte{0x20}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x14}, std::byte{0xF4}, std::byte{0x6B}, std::byte{0x04}, std::byte{0x00}
    };

    MWCBDeclineLevelMessage mwcbDeclineLevelMessage = mapMWCBDeclineLevelMessage(testcase);
    REQUIRE(mwcbDeclineLevelMessage.messageType == 'V');
    REQUIRE(mwcbDeclineLevelMessage.stockLocate == 0);
    REQUIRE(mwcbDeclineLevelMessage.trackingNumber == 1);
    REQUIRE(mwcbDeclineLevelMessage.timeStamp == 216039203);
    REQUIRE(mwcbDeclineLevelMessage.level1 == 70000000000);
    REQUIRE(mwcbDeclineLevelMessage.level2 == 80000000000);
    REQUIRE(mwcbDeclineLevelMessage.level3 == 90000000000);
}

TEST_CASE("STRUCT MAPPER TESTCASE #7", "[map_mwcb_status_message]") {
    std::byte testcase[] = {
        std::byte{0x57},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x31}
    };

    MWCBStatusMessage mwcbStatusMessage = mapMWCBStatusMessage(testcase);
    REQUIRE(mwcbStatusMessage.messageType == 'V');
    REQUIRE(mwcbStatusMessage.stockLocate == 1324);
    REQUIRE(mwcbStatusMessage.trackingNumber == 456);
    REQUIRE(mwcbStatusMessage.timeStamp == 3456627252);
    REQUIRE(mwcbStatusMessage.breachedLevel == '1');

}

TEST_CASE("STRUCT MAPPER TESTCASE #8", "[map_quotation_period_update]") {
    std::byte testcase[] = {
        std::byte{0x4B},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x4E}, std::byte{0x56}, std::byte{0x44}, std::byte{0x41}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x85}, std::byte{0x98},
        std::byte{0x41},
        std::byte{0x00}, std::byte{0x02}, std::byte{0x49}, std::byte{0xF0}
    };

    QuotingPeriodUpdate quotationPeriodUpdate = mapQuotingPeriodUpdate(testcase);
    REQUIRE(quotationPeriodUpdate.messageType == 'K');
    REQUIRE(quotationPeriodUpdate.stockLocate == 1324);
    REQUIRE(quotationPeriodUpdate.trackingNumber == 456);
    REQUIRE(quotationPeriodUpdate.timeStamp == 3456627252);
    REQUIRE(std::string_view(quotationPeriodUpdate.stock, alpha8Size) == "NVDA    ");
    REQUIRE(quotationPeriodUpdate.ipoQuotationReleaseTime == 34200);
    REQUIRE(quotationPeriodUpdate.ipoQuotationReleaseQualifier == 'A');
    REQUIRE(quotationPeriodUpdate.ipoPrice == 150000);
}

TEST_CASE("STRUCT MAPPER TESTCASE #9", "[map_luld_auction_collar]") {
    std::byte testcase[] = {
        std::byte{0x4A},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x41}, std::byte{0x41}, std::byte{0x50}, std::byte{0x4C}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x00}, std::byte{0x1A}, std::byte{0xB3}, std::byte{0xF0},
        std::byte{0x00}, std::byte{0x1D}, std::byte{0x5F}, std::byte{0x88},
        std::byte{0x00}, std::byte{0x18}, std::byte{0x08}, std::byte{0x58},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}
    };

    LULDAuctionCollar luldAuctionCollar = mapLULDAuctionCollar(testcase);
    REQUIRE(luldAuctionCollar.messageType == 'J');
    REQUIRE(luldAuctionCollar.stockLocate == 1324);
    REQUIRE(luldAuctionCollar.trackingNumber == 456);
    REQUIRE(luldAuctionCollar.timeStamp == 3456627252);
    REQUIRE(std::string_view(luldAuctionCollar.stock, alpha8Size) == "AAPL    ");
    REQUIRE(luldAuctionCollar.auctionCollarReferencePrice == 1750000);
    REQUIRE(luldAuctionCollar.upperAuctionCollarPrice == 1925000);
    REQUIRE(luldAuctionCollar.lowerAuctionCollarPrice == 1575000);
    REQUIRE(luldAuctionCollar.auctionCollarExtension == 2);
}

TEST_CASE("STRUCT MAPPER TESTCASE #10", "[map_operational_halt]") {
    std::byte testcase[] = {
        std::byte{0x68},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x41}, std::byte{0x4D}, std::byte{0x5A}, std::byte{0x4E}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x51},
        std::byte{0x48}
    };

    OperationalHalt operationalHalt = mapOperationalHalt(testcase);
    REQUIRE(operationalHalt.messageType == 'h');
    REQUIRE(operationalHalt.stockLocate == 1324);
    REQUIRE(operationalHalt.trackingNumber == 456);
    REQUIRE(operationalHalt.timeStamp == 3456627252);
    REQUIRE(std::string_view(operationalHalt.stock, alpha8Size) == "AMZN    ");
    REQUIRE(operationalHalt.marketCode == 'Q');
    REQUIRE(operationalHalt.operationalHaltAction == 'H');
}

TEST_CASE("STRUCT MAPPER TESTCASE #11", "[map_add_order_message]") {
    std::byte testcase[] = {
        std::byte{0x41},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}, std::byte{0x4C}, std::byte{0xBC}, std::byte{0x6B}, std::byte{0x4A},
        std::byte{0x42},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
        std::byte{0x4D}, std::byte{0x53}, std::byte{0x46}, std::byte{0x54}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x00}, std::byte{0x40}, std::byte{0x2A}, std::byte{0x88}
    };

    AddOrderMessage addOrderMessage = mapAddOrderMessage(testcase);
    REQUIRE(addOrderMessage.messageType == 'A');
    REQUIRE(addOrderMessage.stockLocate == 1324);
    REQUIRE(addOrderMessage.trackingNumber == 456);
    REQUIRE(addOrderMessage.timeStamp == 3456627252);
    REQUIRE(addOrderMessage.orderReferenceNumber == 9877351242);
    REQUIRE(addOrderMessage.buySellIndicator == 'B');
    REQUIRE(addOrderMessage.shares == 500);
    REQUIRE(std::string_view(addOrderMessage.stock, alpha8Size) == "MSFT    ");
    REQUIRE(addOrderMessage.price == 4205192);
}

TEST_CASE("STRUCT MAPPER TESTCASE #12", "[map_add_order_mpid_attribution_message]") {
    std::byte testcase[] = {
        std::byte{0x46},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0xCE}, std::byte{0x07}, std::byte{0xF2}, std::byte{0x34},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}, std::byte{0x4C}, std::byte{0xBC}, std::byte{0x6B}, std::byte{0x4A},
        std::byte{0x42},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
        std::byte{0x4D}, std::byte{0x53}, std::byte{0x46}, std::byte{0x54}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20}, std::byte{0x20},
        std::byte{0x00}, std::byte{0x40}, std::byte{0x2A}, std::byte{0x88},
        std::byte{0x41}, std::byte{0x42}, std::byte{0x43}, std::byte{0x44}
    };

    AddOrderMPIDAttributionMessage addOrderMPIDAttributionMessage = mapAddOrderMPIDAttributionMessage(testcase);
    REQUIRE(addOrderMPIDAttributionMessage.messageType == 'F');
    REQUIRE(addOrderMPIDAttributionMessage.stockLocate == 1324);
    REQUIRE(addOrderMPIDAttributionMessage.trackingNumber == 456);
    REQUIRE(addOrderMPIDAttributionMessage.timeStamp == 3456627252);
    REQUIRE(addOrderMPIDAttributionMessage.orderReferenceNumber == 9877351242);
    REQUIRE(addOrderMPIDAttributionMessage.buySellIndicator == 'B');
    REQUIRE(addOrderMPIDAttributionMessage.shares == 500);
    REQUIRE(std::string_view(addOrderMPIDAttributionMessage.stock, alpha8Size) == "MSFT    ");
    REQUIRE(addOrderMPIDAttributionMessage.price == 4205192);
    REQUIRE(std::string_view(addOrderMPIDAttributionMessage.attribution, alpha4Size) == "ABCD");
}

TEST_CASE("STRUCT MAPPER TESTCASE #13", "[map_order_executed_message]") {
    std::byte testcase[] = {
        std::byte{0x45},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0x54}, std::byte{0x02}, std::byte{0x34},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}, std::byte{0x72}, std::byte{0x03}, std::byte{0xDB}, std::byte{0x4A},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x07}, std::byte{0x5B}, std::byte{0xCD}, std::byte{0x15}
    };

    OrderExecutedMessage orderExecutedMessage = mapOrderExecutedMessage(testcase);
    REQUIRE(orderExecutedMessage.messageType == 'E');
    REQUIRE(orderExecutedMessage.stockLocate == 1324);
    REQUIRE(orderExecutedMessage.trackingNumber == 456);
    REQUIRE(orderExecutedMessage.timeStamp == 22282804);
    REQUIRE(orderExecutedMessage.orderReferenceNumber == 10502789962);
    REQUIRE(orderExecutedMessage.executedShares == 500);
    REQUIRE(orderExecutedMessage.matchNumber == 123456789);
}

TEST_CASE("STRUCT MAPPER TESTCASE #14", "[map_order_executed_with_price_message]") {
    std::byte testcase[] = {
        std::byte{0x43},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0x54}, std::byte{0x02}, std::byte{0x34},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}, std::byte{0x72}, std::byte{0x03}, std::byte{0xDB}, std::byte{0x4A},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x07}, std::byte{0x5B}, std::byte{0xCD}, std::byte{0x15},
        std::byte{0x59},
        std::byte{0x00}, std::byte{0x40}, std::byte{0x2A}, std::byte{0x88}
    };

    OrderExecutedWithPriceMessage orderExecutedWithPriceMessage = mapOrderExecutedWithPriceMessage(testcase);
    REQUIRE(orderExecutedWithPriceMessage.messageType == 'C');
    REQUIRE(orderExecutedWithPriceMessage.stockLocate == 1324);
    REQUIRE(orderExecutedWithPriceMessage.trackingNumber == 456);
    REQUIRE(orderExecutedWithPriceMessage.timeStamp == 22282804);
    REQUIRE(orderExecutedWithPriceMessage.orderReferenceNumber == 10502789962);
    REQUIRE(orderExecutedWithPriceMessage.executedShares == 500);
    REQUIRE(orderExecutedWithPriceMessage.matchNumber == 123456789);
    REQUIRE(orderExecutedWithPriceMessage.printable == 'Y');
    REQUIRE(orderExecutedWithPriceMessage.executionPrice == 4205192);
}

TEST_CASE("STRUCT MAPPER TESTCASE #15", "[map_order_cancel_message]") {
    std::byte testcase[] = {
        std::byte{0x58},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0x54}, std::byte{0x02}, std::byte{0x34},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}, std::byte{0x72}, std::byte{0x03}, std::byte{0xDB}, std::byte{0x4A},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
    };

    OrderCancelMessage orderCancelMessage = mapOrderCancelMessage(testcase);
    REQUIRE(orderCancelMessage.messageType == 'X');
    REQUIRE(orderCancelMessage.stockLocate == 1324);
    REQUIRE(orderCancelMessage.trackingNumber == 456);
    REQUIRE(orderCancelMessage.timeStamp == 22282804);
    REQUIRE(orderCancelMessage.orderReferenceNumber == 10502789962);
    REQUIRE(orderCancelMessage.cancelledShares == 500);
}

TEST_CASE("STRUCT MAPPER TESTCASE #15", "[map_order_delete_message]") {
    std::byte testcase[] = {
        std::byte{0x44},
        std::byte{0x05}, std::byte{0x2C},
        std::byte{0x01}, std::byte{0xC8},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x01}, std::byte{0x54}, std::byte{0x02}, std::byte{0x34},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00}, std::byte{0x02}, std::byte{0x72}, std::byte{0x03}, std::byte{0xDB}, std::byte{0x4A},
    };

    OrderDeleteMessage orderDeleteMessage = mapOrderDeleteMessage(testcase);
    REQUIRE(orderDeleteMessage.messageType == 'D');
    REQUIRE(orderDeleteMessage.stockLocate == 1324);
    REQUIRE(orderDeleteMessage.trackingNumber == 456);
    REQUIRE(orderDeleteMessage.timeStamp == 22282804);
    REQUIRE(orderDeleteMessage.orderReferenceNumber == 10502789962);
}
