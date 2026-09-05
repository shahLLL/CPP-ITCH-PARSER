#pragma once

#include <cstdint>

#pragma pack(push, 1)

// Aliases
using Alpha = char;
using UnsignedInt16 = std::uint16_t;
using UnsignedInt32 = std::uint32_t;
using UnsignedInt64 = std::uint64_t;
using Alpha2 = Alpha[2];
using Alpha4 = Alpha[4];
using TimeStamp = std::uint8_t[6];
using Alpha8 = Alpha[8];

// Structs, organized from largest to smallest data type for mem optimisation.
struct SystemEventMessage final {
    TimeStamp timeStamp;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'S';
    Alpha eventCode;
};

struct StockDirectory final {
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt32 roundLotSize;
    UnsignedInt32 etpLeverageFactor;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    Alpha2 issueSubType;
    const Alpha messageType = 'R';
    Alpha inverseIndicator;
    Alpha marketCategory;
    Alpha financialStatusIndicator;
    Alpha roundLotsOnly;
    Alpha issueClassification;
    Alpha authenticity;
    Alpha shortSaleThresholdIndicator;
    Alpha ipoFlag;
    Alpha luldReferencePriceTier;
    Alpha etpFlag;
};

struct StockTradingAction final {
    Alpha8 stock;
    TimeStamp timeStamp;
    Alpha4 reason;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'H';
    Alpha tradingState;
    Alpha reserved;
};

struct RegSHORestriction final {
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt16 locateCode;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'Y';
    Alpha regSHOAction;
};

struct MarketParticipantPosition final {
    Alpha8 stock;
    TimeStamp timeStamp;
    Alpha4 mpid;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'L';
    Alpha primaryMarketMaker;
    Alpha marketMakerMode;
    Alpha marketParticipantState;
};

struct MWCBDeclineLevelMessage final {
    UnsignedInt64 level1;
    UnsignedInt64 level2;
    UnsignedInt64 level3;
    TimeStamp timeStamp;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'V';
};

struct MWCBStatusMessage final {
    TimeStamp timeStamp;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'V';
    Alpha breachedLevel;
};

struct QuotingPeriodUpdate final {
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt32 ipoQuotationReleaseTime;
    UnsignedInt32 ipoPrice;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'K';
    Alpha ipoQuotationReleaseQualifier;
    
};

struct LULDAuctionCollar final {
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt32 auctionCollarReferencePrice;
    UnsignedInt32 upperAuctionCollarPrice;
    UnsignedInt32 lowerAuctionCollarPrice;
    UnsignedInt32 auctionCollarExtension;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'J';
};

struct OperationalHalt final {
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'h';
    Alpha marketCode;
    Alpha operationalHaltAction;
};

struct AddOrderMessage final {
    UnsignedInt64 orderReferenceNumber;
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt32 price;
    UnsignedInt32 shares;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'A';
    Alpha buySellIndicator;
};

struct AddOrderMPIDAttributionMessage final {
    UnsignedInt64 orderReferenceNumber;
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt32 price;
    UnsignedInt32 shares;
    Alpha4 attribution;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'F';
    Alpha buySellIndicator;
};

struct OrderExecutedMessage final {
    UnsignedInt64 orderReferenceNumber;
    UnsignedInt64 matchNumber;
    TimeStamp timeStamp;
    UnsignedInt32 executedShares;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'E';
};

struct OrderExecutedWithPriceMessage final {
    UnsignedInt64 orderReferenceNumber;
    UnsignedInt64 matchNumber;
    TimeStamp timeStamp;
    UnsignedInt32 executedShares;
    UnsignedInt32 executionPrice;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'C';
    Alpha printable;
};

struct OrderCancelMessage final {
    UnsignedInt64 orderReferenceNumber;
    TimeStamp timeStamp;
    UnsignedInt32 cancelledShares;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'X';
};

struct OrderDeleteMessage final {
    UnsignedInt64 orderReferenceNumber;
    TimeStamp timeStamp;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'D';
};

struct OrderReplaceMessage final {
    UnsignedInt64 originalOrderReferenceNumber;
    UnsignedInt64 newOrderReferenceNumber;
    TimeStamp timeStamp;
    UnsignedInt32 shares;
    UnsignedInt32 price;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'U';
};

struct TradeMessage final {
    Alpha8 stock;
    UnsignedInt64 orderReferenceNumber;
    UnsignedInt64 matchNumber;
    TimeStamp timeStamp;
    UnsignedInt32 shares;
    UnsignedInt32 price;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'P';
    Alpha buySellIndicator;
};

struct CrossTradeMessage final {
    UnsignedInt64 shares;
    Alpha8 stock;
    UnsignedInt64 matchNumber;
    TimeStamp TimeStamp;
    UnsignedInt32 crossPrice;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'Q';
    Alpha crossType;

};

struct BrokenTradeMessage final {
    UnsignedInt64 matchNumber;
    TimeStamp timeStamp;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'B';
};

struct NOIIMessage final {
    UnsignedInt64 pairedShares;
    UnsignedInt64 imbalanceShares;
    Alpha8 stock;
    TimeStamp timeStamp;
    UnsignedInt32 farPrice;
    UnsignedInt32 nearPrice;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'l';
    Alpha crossType;
    Alpha priceVariationIndicator;
    Alpha imbalanceDirection;
};

// DLWCRPD = Direst Listing with Capital Raise Price Discovery
struct DLWCRPD final {
    Alpha8 stock;
    Alpha openEligibilityStatus;
    UnsignedInt64 nearExecutionTime;
    TimeStamp timeStamp;
    UnsignedInt32 minimumAllowablePrice;
    UnsignedInt32 maximumAllowablePrice;
    UnsignedInt32 nearExecutionPrice;
    UnsignedInt32 lowerPriceRangeCollar;
    UnsignedInt32 upperPriceRangeCollar;
    UnsignedInt16 stockLocate;
    UnsignedInt16 trackingNumber;
    const Alpha messageType = 'O';
};

#pragma pop()