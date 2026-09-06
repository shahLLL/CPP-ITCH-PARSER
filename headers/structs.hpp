#pragma once

#include "types.hpp"

#pragma pack(push, 1)

// Structs, organized from largest to smallest data type for mem optimisation.
struct SystemEventMessage final {
    const Alpha messageType = 'S';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha eventCode;
};

struct StockDirectory final {
    const Alpha messageType = 'R';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    Alpha marketCategory;
    Alpha financialStatusIndicator;
    UnsignedInt32 roundLotSize;
    Alpha roundLotsOnly;
    Alpha issueClassification;
    Alpha2 issueSubType{};
    Alpha authenticity;
    Alpha shortSaleThresholdIndicator;
    Alpha ipoFlag;
    Alpha luldReferencePriceTier;
    Alpha etpFlag;
    UnsignedInt32 etpLeverageFactor;
    Alpha inverseIndicator;
};

struct StockTradingAction final {
    const Alpha messageType = 'H';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    Alpha tradingState;
    Alpha reserved;
    Alpha4 reason{};
};

struct RegSHORestriction final {
    const Alpha messageType = 'Y';
    UnsignedInt16 locateCode;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    Alpha regSHOAction;
};

struct MarketParticipantPosition final {
    const Alpha messageType = 'L';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha4 mpid{};
    Alpha8 stock{};
    Alpha primaryMarketMaker;
    Alpha marketMakerMode;
    Alpha marketParticipantState;
};

struct MWCBDeclineLevelMessage final {
    const Alpha messageType = 'V';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 level1;
    UnsignedInt64 level2;
    UnsignedInt64 level3;
};

struct MWCBStatusMessage final {
    const Alpha messageType = 'V';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha breachedLevel;
};

struct QuotingPeriodUpdate final {
    const Alpha messageType = 'K';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    UnsignedInt32 ipoQuotationReleaseTime;
    Alpha ipoQuotationReleaseQualifier;
    UnsignedInt32 ipoPrice;
};

struct LULDAuctionCollar final {
    const Alpha messageType = 'J';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    UnsignedInt32 auctionCollarReferencePrice;
    UnsignedInt32 upperAuctionCollarPrice;
    UnsignedInt32 lowerAuctionCollarPrice;
    UnsignedInt32 auctionCollarExtension;
};

struct OperationalHalt final {
    const Alpha messageType = 'h';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    Alpha marketCode;
    Alpha operationalHaltAction;
};

struct AddOrderMessage final {
    const Alpha messageType = 'A';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
    Alpha buySellIndicator;
    UnsignedInt32 shares;
    Alpha8 stock{};
    UnsignedInt32 price;
};

struct AddOrderMPIDAttributionMessage final {
    const Alpha messageType = 'F';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
    Alpha buySellIndicator;
    UnsignedInt32 shares;
    Alpha8 stock{};
    UnsignedInt32 price;
    Alpha4 attribution{};
};

struct OrderExecutedMessage final {
    const Alpha messageType = 'E';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
    UnsignedInt32 executedShares;
    UnsignedInt64 matchNumber;
};

struct OrderExecutedWithPriceMessage final {
    const Alpha messageType = 'C';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
    UnsignedInt32 executedShares;
    UnsignedInt64 matchNumber;
    Alpha printable;
    UnsignedInt32 executionPrice;
};

struct OrderCancelMessage final {
    const Alpha messageType = 'X';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
    UnsignedInt32 cancelledShares;
};

struct OrderDeleteMessage final {
    const Alpha messageType = 'D';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
};

struct OrderReplaceMessage final {
    const Alpha messageType = 'U';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 originalOrderReferenceNumber;
    UnsignedInt64 newOrderReferenceNumber;
    UnsignedInt32 shares;
    UnsignedInt32 price;
};

struct TradeMessage final {
    const Alpha messageType = 'P';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 orderReferenceNumber;
    Alpha buySellIndicator;
    UnsignedInt32 shares;
    Alpha8 stock{};
    UnsignedInt32 price;
    UnsignedInt64 matchNumber;
};

struct CrossTradeMessage final {
    const Alpha messageType = 'Q';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp TimeStamp;
    UnsignedInt64 shares;
    Alpha8 stock{};
    UnsignedInt32 crossPrice;
    UnsignedInt64 matchNumber;
    Alpha crossType;
};

struct BrokenTradeMessage final {
    const Alpha messageType = 'B';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 matchNumber;
};

struct NOIIMessage final {
    const Alpha messageType = 'l';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    UnsignedInt64 pairedShares;
    UnsignedInt64 imbalanceShares;
    Alpha imbalanceDirection;
    Alpha8 stock{};
    UnsignedInt32 farPrice;
    UnsignedInt32 nearPrice;
    UnsignedInt32 currentReferencePrice;
    Alpha crossType;
    Alpha priceVariationIndicator;
};

// DLWCRPD = Direst Listing with Capital Raise Price Discovery
struct DLWCRPD final {
    const Alpha messageType = 'O';
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    TimeStamp timeStamp;
    Alpha8 stock{};
    Alpha openEligibilityStatus;
    UnsignedInt32 minimumAllowablePrice;
    UnsignedInt32 maximumAllowablePrice;
    UnsignedInt32 nearExecutionPrice;
    UnsignedInt64 nearExecutionTime;
    UnsignedInt32 lowerPriceRangeCollar;
    UnsignedInt32 upperPriceRangeCollar;
};

#pragma pack(pop)