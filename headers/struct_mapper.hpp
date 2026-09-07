#include "structs.hpp"
#include "types.hpp"
#include "endian_converter.hpp"


namespace StructMapper {
    [[nodiscard]] ItchStruct::SystemEventMessage mapSystemEventMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::StockDirectory mapStockDirectory(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::StockTradingAction mapStockTradingAction(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::RegSHORestriction mapRegSHORestriction(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::MarketParticipantPosition mapMarketParticipationPostion(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::MWCBDeclineLevelMessage mapMWCBDeclineLevelMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::MWCBStatusMessage mapMWCBStatusMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::QuotingPeriodUpdate mapQuotingPeriodUpdate(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::LULDAuctionCollar mapLULDAuctionCollar(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::OperationalHalt mapOperationalHalt(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::AddOrderMessage mapAddOrderMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::AddOrderMPIDAttributionMessage mapAddOrderMPIDAttributionMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::OrderExecutedMessage mapOrderExecutedMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::OrderExecutedWithPriceMessage mapOrderExecutedWithPriceMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::OrderCancelMessage mapOrderCancelMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::OrderDeleteMessage mapOrderDeleteMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::OrderReplaceMessage mapOrderReplaceMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::TradeMessage mapTradeMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::CrossTradeMessage mapCrossTradeMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::BrokenTradeMessage mapBrokenTradeMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::NOIIMessage mapNOIIMessage(const std::byte* msg) noexcept;
    [[nodiscard]] ItchStruct::DLWCRPD mapDLWCRPD(const std::byte* msg) noexcept;
}