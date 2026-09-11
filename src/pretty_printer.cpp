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

void prettyPrintMWCBDeclineLevelMessage(const ItchStruct::MWCBDeclineLevelMessage& mwcbDeclineLevelMessage) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "MWCB DECLINE LEVEL MESSAGE" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << mwcbDeclineLevelMessage.stockLocate << std::endl;
    std::cout << "Tracking Number: " << mwcbDeclineLevelMessage.trackingNumber << std::endl;
    std::cout << "Timestamp: " << mwcbDeclineLevelMessage.timeStamp << std::endl;
    std::cout << "Level I: " << mwcbDeclineLevelMessage.level1 << std::endl;
    std::cout << "Level II: " << mwcbDeclineLevelMessage.level2 << std::endl;
    std::cout << "Level III: " << mwcbDeclineLevelMessage.level3 << std::endl;
    std::cout << std::endl;
}

void prettyPrintMWCBStatusMessage(const ItchStruct::MWCBStatusMessage &mwcbStatusMessage) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "MWCB STATUS MESSAGE" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << mwcbStatusMessage.stockLocate << std::endl;
    std::cout << "Tracking Number: " << mwcbStatusMessage.trackingNumber << std::endl;
    std::cout << "Timestamp: " << mwcbStatusMessage.timeStamp << std::endl;
    std::cout << "Breached Level: " << mwcbStatusMessage.breachedLevel << std::endl;
    std::cout << std::endl;
}

void prettyPrintQuotingPeriodUpdate(const ItchStruct::QuotingPeriodUpdate &quotingPeriodUpdate) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "QUOTING PERIOD UPDATE" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << quotingPeriodUpdate.stockLocate << std::endl;
    std::cout << "Tracking Number: " << quotingPeriodUpdate.trackingNumber << std::endl;
    std::cout << "Timestamp: " << quotingPeriodUpdate.timeStamp << std::endl;
    std::cout << "Stock: " << quotingPeriodUpdate.stock << std::endl;
    std::cout << "IPO Quotation Release Time: " << quotingPeriodUpdate.ipoQuotationReleaseTime << std::endl;
    std::cout << "IPO Quotation Release Qualifier: " << quotingPeriodUpdate.ipoQuotationReleaseQualifier << std::endl;
    std::cout << "IPO Price: " << quotingPeriodUpdate.ipoPrice << std::endl;
    std::cout << std::endl;
}

void prettyPrintLULDAuctionCollar(const ItchStruct::LULDAuctionCollar &luldAuctionCollar) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "LULD AUCTION COLLAR" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << luldAuctionCollar.stockLocate << std::endl;
    std::cout << "Tracking Number: " << luldAuctionCollar.trackingNumber << std::endl;
    std::cout << "Timestamp: " << luldAuctionCollar.timeStamp << std::endl;
    std::cout << "Stock: " << luldAuctionCollar.stock << std::endl;
    std::cout << "Auction Collar Reference Price: " << luldAuctionCollar.auctionCollarReferencePrice << std::endl;
    std::cout << "Upper Auction Collar Price: " << luldAuctionCollar.upperAuctionCollarPrice << std::endl;
    std::cout << "Lower Auction Collar Price: " << luldAuctionCollar.lowerAuctionCollarPrice << std::endl;
    std::cout << "Auction Collar Extension: " << luldAuctionCollar.auctionCollarExtension << std::endl;
    std::cout << std::endl;
}

void prettyPrintOperationalHalt(const ItchStruct::OperationalHalt& operationalHalt) noexcept {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "OPERATIONAL HALT" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << operationalHalt.stockLocate << std::endl;
    std::cout << "Tracking Number: " << operationalHalt.trackingNumber << std::endl;
    std::cout << "Timestamp: " << operationalHalt.timeStamp << std::endl;
    std::cout << "Stock: " << operationalHalt.stock << std::endl;
    std::cout << "Market Code: " << operationalHalt.marketCode << std::endl;
    std::cout << "Operational Halt Action: " << operationalHalt.operationalHaltAction << std::endl;
    std::cout << std::endl;
}

void ItchPrinter::printItchData(const ItchStruct::ItchData& data) noexcept {
    std::visit(overloaded{
        [](const ItchStruct::SystemEventMessage& sytemEventMessage)  { prettyPrintSystemEventMessage(sytemEventMessage); },
        [](const ItchStruct::StockDirectory& stockDirectory)  { prettyPrintStockDirectory(stockDirectory); },
        [](const ItchStruct::StockTradingAction& stockTradingAction)  { prettyPrintStockTradingAction(stockTradingAction); },
        [](const ItchStruct::RegSHORestriction& regSHORestriction)  { prettyPrintRegSHORestriction(regSHORestriction); },
        [](const ItchStruct::MarketParticipantPosition& marketParticipantPosition)  { prettyPrintMarketParticipantPosition(marketParticipantPosition); },
        [](const ItchStruct::MWCBDeclineLevelMessage& mwcbDeclineLevelMessage)  { prettyPrintMWCBDeclineLevelMessage(mwcbDeclineLevelMessage); },
        [](const ItchStruct::MWCBStatusMessage& mwcbStatusMessage)  { prettyPrintMWCBStatusMessage(mwcbStatusMessage); },
        [](const ItchStruct::QuotingPeriodUpdate& quotingPeriodUpdate)  { prettyPrintQuotingPeriodUpdate(quotingPeriodUpdate); },
        [](const ItchStruct::LULDAuctionCollar& luldAuctionCollar)  { prettyPrintLULDAuctionCollar(luldAuctionCollar); },
        [](const ItchStruct::OperationalHalt& operationalHalt)  { prettyPrintOperationalHalt(operationalHalt); },
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
