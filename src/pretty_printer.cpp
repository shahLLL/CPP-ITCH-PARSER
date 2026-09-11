#include "../headers/pretty_printer.hpp"

void prettyPrintSystemEventMessage(const ItchStruct::SystemEventMessage& systemEventMessage) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "SYSTEM EVENT MESSAGE" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << systemEventMessage.stockLocate << std::endl;
    std::cout << "Tracking Number: " << systemEventMessage.trackingNumber << std::endl;
    std::cout << "Timestamp: " << systemEventMessage.timeStamp << std::endl;
    std::cout << "Event Code: " << systemEventMessage.eventCode << std::endl;
    std::cout << std::endl;
}

void prettyPrintStockDirectory(const ItchStruct::StockDirectory& stockDirectory) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "STOCK DIRECTORY" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << stockDirectory.stockLocate << std::endl;
    std::cout << "Tracking Number: " << stockDirectory.trackingNumber << std::endl;
    std::cout << "Timestamp: " << stockDirectory.timeStamp << std::endl;
    std::cout << "Stock: " << stockDirectory.stock << std::endl;
    std::cout << "Market Category: " << stockDirectory.marketCategory << std::endl;
    std::cout << "Financial Status Indicator: " << stockDirectory.financialStatusIndicator << std::endl;
    std::cout << "Round Lot Size: " << stockDirectory.roundLotSize << std::endl;
    std::cout << "Round Lots Only: " << stockDirectory.roundLotsOnly << std::endl;
    std::cout << "Issue Classification: " << stockDirectory.issueClassification << std::endl;
    std::cout << "Issue Subtype: " << stockDirectory.issueSubType << std::endl;
    std::cout << "Authenticity: " << stockDirectory.authenticity << std::endl;
    std::cout << "Short Sale Threshold Indicator: " << stockDirectory.shortSaleThresholdIndicator << std::endl;
    std::cout << "IPO Flag: " << stockDirectory.ipoFlag << std::endl;
    std::cout << "LULD Reference Price Tier: " << stockDirectory.luldReferencePriceTier << std::endl;
    std::cout << "ETP Flag: " << stockDirectory.etpFlag << std::endl;
    std::cout << "ETP Leverage Factor: " << stockDirectory.etpLeverageFactor << std::endl;
    std::cout << "Inverse Indicator: " << stockDirectory.inverseIndicator << std::endl;
    std::cout << std::endl;
}

void prettyPrintStockTradingAction(const ItchStruct::StockTradingAction& stockTradingAction) {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "STOCK TRADING ACTION" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << stockTradingAction.stockLocate << std::endl;
    std::cout << "Tracking Number: " << stockTradingAction.trackingNumber << std::endl;
    std::cout << "Timestamp: " << stockTradingAction.timeStamp << std::endl;
    std::cout << "Stock: " << stockTradingAction.stock << std::endl;
    std::cout << "Trading State: " << stockTradingAction.tradingState << std::endl;
    std::cout << "Reserved: " << stockTradingAction.reserved << std::endl;
    std::cout << "Reason: " << stockTradingAction.reason << std::endl;
    std::cout << std::endl;
}

void prettyPrintRegSHORestriction(const ItchStruct::RegSHORestriction& regSHORestriction) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "REG SHO RESTRICTION" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Locate Code: " << regSHORestriction.locateCode << std::endl;
    std::cout << "Tracking Number: " << regSHORestriction.trackingNumber << std::endl;
    std::cout << "Timestamp: " << regSHORestriction.timeStamp << std::endl;
    std::cout << "Stock: " << regSHORestriction.stock << std::endl;
    std::cout << "RegSHO Action: " << regSHORestriction.regSHOAction << std::endl;
    std::cout << std::endl;
}

void prettyPrintMarketParticipantPosition(const ItchStruct::MarketParticipantPosition& marketParticipantPosition) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "MARKET PARTICIPANT POSITION" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << marketParticipantPosition.stockLocate << std::endl;
    std::cout << "Tracking Number: " << marketParticipantPosition.trackingNumber << std::endl;
    std::cout << "Timestamp: " << marketParticipantPosition.timeStamp << std::endl;
    std::cout << "MPID: " << marketParticipantPosition.mpid << std::endl;
    std::cout << "Stock: " << marketParticipantPosition.stock << std::endl;
    std::cout << "Primary Market Maker: " << marketParticipantPosition.primaryMarketMaker << std::endl;
    std::cout << "Market Maker Mode: " << marketParticipantPosition.marketMakerMode << std::endl;
    std::cout << "Market Participant State: " << marketParticipantPosition.marketParticipantState << std::endl;
    std::cout << std::endl;
}

void ItchPrinter::printItchData(const ItchStruct::ItchData& data) noexcept {
    std::visit(overloaded{
        [](const ItchStruct::SystemEventMessage& sytemEventMessage)  { prettyPrintSystemEventMessage(sytemEventMessage); },
        [](const ItchStruct::StockDirectory& stockDirectory)  { prettyPrintStockDirectory(stockDirectory); },
        [](const ItchStruct::StockTradingAction& stockTradingAction)  { prettyPrintStockTradingAction(stockTradingAction); },
        [](const ItchStruct::RegSHORestriction& regSHORestriction)  { prettyPrintRegSHORestriction(regSHORestriction); },
        [](const ItchStruct::MarketParticipantPosition& marketParticipantPosition)  { prettyPrintMarketParticipantPosition(marketParticipantPosition); },
        [](const ItchStruct::MWCBDeclineLevelMessage& mwcbDeclineLevelMessage)  { },
        [](const ItchStruct::MWCBStatusMessage& mwcbStatusMessage)  { },
        [](const ItchStruct::QuotingPeriodUpdate& quotingPeriodUpdate)  { },
        [](const ItchStruct::LULDAuctionCollar& luldAuctionCollar)  { },
        [](const ItchStruct::OperationalHalt& operationalHalt)  { },
        [](const ItchStruct::AddOrderMessage& addOrderMessage)  { },
        [](const ItchStruct::AddOrderMPIDAttributionMessage& addOrderMPIDAttributionMessage)  { },
        [](const ItchStruct::OrderExecutedMessage& orderExecutedMessage)  { },
        [](const ItchStruct::OrderExecutedWithPriceMessage& orderExecutedWithPriceMessage)  { },
        [](const ItchStruct::OrderCancelMessage& orderCancelMessage)  { },
        [](const ItchStruct::OrderDeleteMessage& orderDeleteMessage)  { },
        [](const ItchStruct::OrderReplaceMessage& orderReplaceMessage)  { },
        [](const ItchStruct::TradeMessage& tradeMessage)  { },
        [](const ItchStruct::CrossTradeMessage& crossTradeMessage)  { },
        [](const ItchStruct::BrokenTradeMessage& brokenTradeMessage)  { },
        [](const ItchStruct::NOIIMessage& noiiMessage)  { },
        [](const ItchStruct::DLWCRPD& dlwcrpd)  { },
    }, data);
}
