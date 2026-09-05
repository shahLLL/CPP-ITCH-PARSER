#pragma once
#include <cstdint>
#include <array>
#include <chrono>

// Aliases
using EnumType = std::uint8_t;
using MessageType = char;
using StockLocate = std::uint16_t;
using TrackingNumber = std::uint16_t;
using TimeStamp = std::uint64_t;
using Stock = std::array<char, 8>;
using RoundLotSize = std::uint32_t;
using ETPLeverageFactor = std::uint32_t;
using Reserved = bool;
using LocateCode = std::uint16_t;
using MPID = std::array<char, 4>;
using Price = std::uint32_t;
using IPOQuotationReleaseTime = std::uint32_t;
using AuctionCollarExtension = std::uint32_t;
using OrderReferenceNumber = std::uint64_t;
using Shares = std::uint32_t;
using MatchNumber = std::uint64_t;
using BigShares = std::uint64_t;
using ExecutionTime = std::chrono::high_resolution_clock::time_point;


// Enums
// View Nasdaq ITCH spec for more details on enums below.
enum class SystemEventCode : EnumType {O, S, Q, M, E, C};
enum class MarketCategory : EnumType {Q, G, S, N, A, P, Z, V};
enum class FinancialStatusIndicator : EnumType {D, E, Q, S, G, H, J, K, C, N};
enum class YesNo : EnumType {Y, N};
enum class YesNoOptional : EnumType {Y, N, SPACE};
enum class IssueClassification : EnumType {A, B, C, F, I, L, N, O, P, Q, R, S,
    T, U, V, W};
enum class IssueSubType : EnumType {A, AI, B, C, CB, CF, CL, CM, CO, CT, CU,
    CW, D, E, EG, EI, EM, EN, EU, F, FI, FL, G, I, IR, IW, IX, J, L, LL, M,
    MF, ML, MT, N, O, P, PP, Q, R, RC, RF, RT, RU, S, SC, SI, T, TC, TU, U,
    V, W, WC, X, Y, Z};
enum class Authenticity : EnumType {P, T};
enum class PriceTier : EnumType {ONE, TWO, SPACE};
enum class TradingActionReason : EnumType {};
enum class TradingState : EnumType {H, P, Q, T};
enum class RegSHOAction : EnumType {ZERO, ONE, TWO};
enum class MarketMakerMode : EnumType {N, P, S, R, L};
enum class MarketParticipantState : EnumType {A, E, W, S, D};
enum class BreachedLevel : EnumType {ONE, TWO, THREE};
enum class IPOQuotationReleaseQualifier : EnumType {A, C};
enum class MarketCode : EnumType {Q, B, X};
enum class OperationalHaltAction : EnumType {H, T};
enum class BuySellIndicator : EnumType {B, S};
enum class CrossType : EnumType {O, C, H, A};
enum class ImbalanceDirection : EnumType {B, S, N, O, P};
enum class PriceVariationIndicator : EnumType {L, ONE, TWO, THREE,
    FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, A, B, C, SPACE};

// Structs
#pragma pack(1)
struct SystemEventMessage final {
    TimeStamp timeStamp;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'S';
    SystemEventCode eventCode;
};
#pragma pack()

#pragma pack(1)
struct StockDirectory final {
    Stock stock{};
    TimeStamp timeStamp;
    RoundLotSize roundLotSize;
    ETPLeverageFactor etpLeverageFactor;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'R';
    MarketCategory marketCategory;
    FinancialStatusIndicator financialStatusIndicator;
    YesNo roundLotsOnly;
    IssueClassification issueClassification;
    IssueSubType issueSubType;
    Authenticity authenticity;
    YesNoOptional shortSaleThresholdIndicator;
    YesNoOptional IPOFlag;
    PriceTier LULDReferencePriceTier;
    YesNoOptional ETPFlag;
    YesNo InverseIndicator;
};
#pragma pack()

#pragma pack(1)
struct StockTradingAction final {
    Stock stock{};
    TimeStamp timeStamp;
    TradingActionReason reason;
    StockLocate StockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'H';
    TradingState tradingState;
    Reserved reserved;
};
#pragma pack()

#pragma pack(1)
struct RegSHORestriction final {
    Stock stock{};
    TimeStamp timeStamp;
    LocateCode locateCode;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'Y';
    RegSHOAction regSHOAction;
};
#pragma pack()

#pragma pack(1)
struct MarketParticipationPostion final {
    Stock stock{};
    TimeStamp timeStamp;
    MPID mpid{};
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'L';
    YesNo primaryMarketMaker;
    MarketMakerMode marketMakerMode;
    MarketParticipantState marketParticipantState;
};
#pragma pack()

#pragma pack(1)
struct MWCBDeclineLevelMessage final {
    TimeStamp timeStamp;
    Price levelOne;
    Price levelTwo;
    Price levelThree;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'V';
};
#pragma pack()

#pragma pack(1)
struct MWCBStatusMessage final {
    TimeStamp timeStamp;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'W';
    BreachedLevel breachedLevel;
};
#pragma pack()

#pragma pack(1)
struct QuotingPeriodUpdate final {
    Stock stock{};
    TimeStamp timeStamp;
    Price ipoPrice;
    IPOQuotationReleaseTime ipoQuotationReleaseTime;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'K';
    IPOQuotationReleaseQualifier ipoQuotationReleaseQualifier;

};
#pragma pack()

#pragma pack(1)
struct LULDAuctionCollar final {
    Stock stock{};
    TimeStamp timeStamp;
    Price auctionCollarReferencePrice;
    Price upperAuctionCollarPrice;
    Price lowerAuctionCollarPrice;
    AuctionCollarExtension auctionCollarExtension;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'J';
};
#pragma pack()

#pragma pack(1)
struct OperationalHalt final {
    Stock stock{};
    TimeStamp timeStamp;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'h';
    MarketCode marketCode;
    OperationalHaltAction operationalHaltAction;
};
#pragma pack()

#pragma pack(1)
struct AddOrderMessage final {
    Stock stock{};
    TimeStamp timeStamp;
    OrderReferenceNumber orderReferenceNumber;
    Price price;
    Shares shares;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'A';
    BuySellIndicator buySellIndicator;
};
#pragma pack()

#pragma pack(1)
struct AddOrderMessageMPID final {
    Stock stock{};
    TimeStamp timeStamp;
    OrderReferenceNumber orderReferenceNumber;
    Price price;
    Shares shares;
    MPID attribution{};
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'F';
    BuySellIndicator buySellIndicator;
};
#pragma pack()

#pragma pack(1)
struct OrderExecutedMessage final {
    MatchNumber matchNumber;
    OrderReferenceNumber OrderReferenceNumber;
    TimeStamp timeStamp;
    Shares executedShares;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'E';
};
#pragma pack()

#pragma pack(1)
struct OrderExecutedWithPriceMessage final {
    OrderReferenceNumber orderReferenceNumber;
    MatchNumber matchNumber;
    TimeStamp timeStamp;
    Price executionPrice;
    Shares executedShares;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'C';
    YesNo printable;
};
#pragma pack()

#pragma pack(1)
struct OrderCancelMessage final {
    OrderReferenceNumber orderReferenceNumber;
    TimeStamp timeStamp;
    Shares cancelledShares;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'X';
};
#pragma pack()

#pragma pack(1)
struct OrderDeletelMessage final {
    OrderReferenceNumber orderReferenceNumber;
    TimeStamp timeStamp;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'D';
};
#pragma pack()

#pragma pack(1)
struct OrderReplaceMessage final {
    OrderReferenceNumber originalOrderReferenceNumber;
    OrderReferenceNumber newOrderReferenceNumber;
    TimeStamp timeStamp;
    Price price;
    Shares shares;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'U';
};
#pragma pack()

#pragma pack(1)
struct TradeMessage final {
    OrderReferenceNumber orderReferenceNumber;
    MatchNumber matchNumber;
    Stock stock{};
    TimeStamp timeStamp;
    Price price;
    Shares shares;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    BuySellIndicator buySellIndicator;
    const MessageType messageType = 'P';
};
#pragma pack()

#pragma pack(1)
struct CrossTradeMessage final {
    Stock stock{};
    MatchNumber matchNumber;
    BigShares shares;
    TimeStamp timeStamp;
    Price crossPrice;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'Q';
    CrossType crossType;
};
#pragma pack()

#pragma pack(1)
struct BrokenTradeMessage final {
    MatchNumber matchNumber;
    TimeStamp timeStamp;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'B';
};
#pragma pack()

#pragma pack(1)
struct NOIIMessage final {
    Stock stock{};
    BigShares pairedShares;
    BigShares imbalanceShares;
    TimeStamp timeStamp;
    Price farPrice;
    Price nearPrice;
    Price currentReferencePrice;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'l';
    ImbalanceDirection imbalanceDirection;
    CrossType crossType;
    PriceVariationIndicator priceVariationIndicator;
};
#pragma pack()

// DLWCRPD = Direct Lisiting with Capital Raise Price Discovery.
#pragma pack(1)
struct DLWCRPDMessage final {
    Stock stock{};
    ExecutionTime nearExecutionTime;
    TimeStamp timeStamp;
    Price minimumAllowablePrice;
    Price maximumAllowablePrice;
    Price nearExecutionPrice;
    Price lowerPriceRangeCollar;
    Price upperPriceRangeCollar;
    StockLocate stockLocate;
    TrackingNumber trackingNumber;
    const MessageType messageType = 'O';
    YesNo openEligibilityStatus;
};
#pragma pack()