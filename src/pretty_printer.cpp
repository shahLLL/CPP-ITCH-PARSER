#include "../headers/pretty_printer.hpp"

void prettyPrintSystemEventMessage(const ItchStruct::SystemEventMessage& systemEventMessage) {
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "SYSTEM EVENT MESSAGE" << std::endl;
    std::cout << ItchPrinter::dashes << std::endl;
    std::cout << "Stock Locate: " << systemEventMessage.stockLocate << std::endl;
    std::cout << "Tracking Number: " << systemEventMessage.trackingNumber << std::endl;
    std::cout << "Timestamp: " << systemEventMessage.timeStamp << std::endl;
    std::cout << "Event Code: " << systemEventMessage.eventCode << std::endl;
    std::cout << std::endl;
}

void ItchPrinter::printItchData(const ItchStruct::ItchData& data) noexcept {
    std::visit(overloaded{
        [](const ItchStruct::SystemEventMessage& sytemEventMessage)  { prettyPrintSystemEventMessage(sytemEventMessage); },
        [](const ItchStruct::StockDirectory& stockDirectory)  { },
        [](const ItchStruct::StockTradingAction& stockTradingAction)  { },
        [](const ItchStruct::RegSHORestriction& regSHORestriction)  { },
        [](const ItchStruct::MarketParticipantPosition& marketParticipantPosition)  { },
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
