#include <cstddef>
#include "structs.hpp"
#include "endian_converter.hpp"

constexpr std::size_t alpha2Size = 2;
constexpr std::size_t alpha4Size = 4;
constexpr std::size_t alpha8Size = 8;

[[nodiscard]] SystemEventMessage mapSystemEventMessage(const std::byte* msg) noexcept;
[[nodiscard]] StockDirectory mapStockDirectory(const std::byte* msg) noexcept;
[[nodiscard]] StockTradingAction mapStockTradingAction(const std::byte* msg) noexcept;
[[nodiscard]] RegSHORestriction mapRegSHORestriction(const std::byte* msg) noexcept;
[[nodiscard]] MarketParticipantPosition mapMarketParticipationPostion(const std::byte* msg) noexcept;
[[nodiscard]] MWCBDeclineLevelMessage mapMWCBDeclineLevelMessage(const std::byte* msg) noexcept;
[[nodiscard]] MWCBStatusMessage mapMWCBStatusMessage(const std::byte* msg) noexcept;
[[nodiscard]] QuotingPeriodUpdate mapQuotingPeriodUpdate(const std::byte* msg) noexcept;
[[nodiscard]] LULDAuctionCollar mapLULDAuctionCollar(const std::byte* msg) noexcept;
[[nodiscard]] OperationalHalt mapOperationalHalt(const std::byte* msg) noexcept;
[[nodiscard]] AddOrderMessage mapAddOrderMessage(const std::byte* msg) noexcept;
[[nodiscard]] AddOrderMPIDAttributionMessage mapAddOrderMPIDAttributionMessage(const std::byte* msg) noexcept;
[[nodiscard]] OrderExecutedMessage mapOrderExecutedMessage(const std::byte* msg) noexcept;
[[nodiscard]] OrderExecutedWithPriceMessage mapOrderExecutedWithPriceMessage(const std::byte* msg) noexcept;
[[nodiscard]] OrderCancelMessage mapOrderCancelMessage(const std::byte* msg) noexcept;
[[nodiscard]] OrderDeleteMessage mapOrderDeleteMessage(const std::byte* msg) noexcept;
[[nodiscard]] OrderReplaceMessage mapOrderReplaceMessage(const std::byte* msg) noexcept;
[[nodiscard]] TradeMessage mapTradeMessage(const std::byte* msg) noexcept;
[[nodiscard]] CrossTradeMessage mapCrossTradeMessage(const std::byte* msg) noexcept;
[[nodiscard]] BrokenTradeMessage mapBrokenTradeMessage(const std::byte* msg) noexcept;
[[nodiscard]] NOIIMessage mapNOIIMessage(const std::byte* msg) noexcept;
[[nodiscard]] DLWCRPD mapDLWCRPD(const std::byte* msg) noexcept;