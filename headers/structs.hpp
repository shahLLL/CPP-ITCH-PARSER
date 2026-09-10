#pragma once

#include "types.hpp"

#pragma pack(push, 1)

namespace ItchStruct {
    struct SystemEventMessage final {
        const ItchType::Alpha messageType = 'S';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha eventCode;
    };

    struct StockDirectory final {
        const ItchType::Alpha messageType = 'R';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::Alpha marketCategory;
        ItchType::Alpha financialStatusIndicator;
        ItchType::UnsignedInt32 roundLotSize;
        ItchType::Alpha roundLotsOnly;
        ItchType::Alpha issueClassification;
        ItchType::Alpha2 issueSubType {};
        ItchType::Alpha authenticity;
        ItchType::Alpha shortSaleThresholdIndicator;
        ItchType::Alpha ipoFlag;
        ItchType::Alpha luldReferencePriceTier;
        ItchType::Alpha etpFlag;
        ItchType::UnsignedInt32 etpLeverageFactor;
        ItchType::Alpha inverseIndicator;
    };

    struct StockTradingAction final {
        const ItchType::Alpha messageType = 'H';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::Alpha tradingState;
        ItchType::Alpha reserved;
        ItchType::Alpha4 reason{};
    };

    struct RegSHORestriction final {
        const ItchType::Alpha messageType = 'Y';
        ItchType::UnsignedInt16 locateCode;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::Alpha regSHOAction;
    };

    struct MarketParticipantPosition final {
        const ItchType::Alpha messageType = 'L';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha4 mpid {};
        ItchType::Alpha8 stock {};
        ItchType::Alpha primaryMarketMaker;
        ItchType::Alpha marketMakerMode;
        ItchType::Alpha marketParticipantState;
    };

    struct MWCBDeclineLevelMessage final {
        const ItchType::Alpha messageType = 'V';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 level1;
        ItchType::UnsignedInt64 level2;
        ItchType::UnsignedInt64 level3;
    };

    struct MWCBStatusMessage final {
        const ItchType::Alpha messageType = 'W';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha breachedLevel;
    };

    struct QuotingPeriodUpdate final {
        const ItchType::Alpha messageType = 'K';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 ipoQuotationReleaseTime;
        ItchType::Alpha ipoQuotationReleaseQualifier;
        ItchType::UnsignedInt32 ipoPrice;
    };

    struct LULDAuctionCollar final {
        const ItchType::Alpha messageType = 'J';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 auctionCollarReferencePrice;
        ItchType::UnsignedInt32 upperAuctionCollarPrice;
        ItchType::UnsignedInt32 lowerAuctionCollarPrice;
        ItchType::UnsignedInt32 auctionCollarExtension;
    };

    struct OperationalHalt final {
        const ItchType::Alpha messageType = 'h';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::Alpha marketCode;
        ItchType::Alpha operationalHaltAction;
    };

    struct AddOrderMessage final {
        const ItchType::Alpha messageType = 'A';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
        ItchType::Alpha buySellIndicator;
        ItchType::UnsignedInt32 shares;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 price;
    };

    struct AddOrderMPIDAttributionMessage final {
        const ItchType::Alpha messageType = 'F';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
        ItchType::Alpha buySellIndicator;
        ItchType::UnsignedInt32 shares;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 price;
        ItchType::Alpha4 attribution {};
    };

    struct OrderExecutedMessage final {
        const ItchType::Alpha messageType = 'E';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
        ItchType::UnsignedInt32 executedShares;
        ItchType::UnsignedInt64 matchNumber;
    };

    struct OrderExecutedWithPriceMessage final {
        const ItchType::Alpha messageType = 'C';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
        ItchType::UnsignedInt32 executedShares;
        ItchType::UnsignedInt64 matchNumber;
        ItchType::Alpha printable;
        ItchType::UnsignedInt32 executionPrice;
    };

    struct OrderCancelMessage final {
        const ItchType::Alpha messageType = 'X';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
        ItchType::UnsignedInt32 cancelledShares;
    };

    struct OrderDeleteMessage final {
        const ItchType::Alpha messageType = 'D';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
    };

    struct OrderReplaceMessage final {
        const ItchType::Alpha messageType = 'U';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 originalOrderReferenceNumber;
        ItchType::UnsignedInt64 newOrderReferenceNumber;
        ItchType::UnsignedInt32 shares;
        ItchType::UnsignedInt32 price;
    };

    struct TradeMessage final {
        const ItchType::Alpha messageType = 'P';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 orderReferenceNumber;
        ItchType::Alpha buySellIndicator;
        ItchType::UnsignedInt32 shares;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 price;
        ItchType::UnsignedInt64 matchNumber;
    };

    struct CrossTradeMessage final {
        const ItchType::Alpha messageType = 'Q';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 shares;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 crossPrice;
        ItchType::UnsignedInt64 matchNumber;
        ItchType::Alpha crossType;
    };

    struct BrokenTradeMessage final {
        const ItchType::Alpha messageType = 'B';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 matchNumber;
    };

    struct NOIIMessage final {
        const ItchType::Alpha messageType = 'I';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::UnsignedInt64 pairedShares;
        ItchType::UnsignedInt64 imbalanceShares;
        ItchType::Alpha imbalanceDirection;
        ItchType::Alpha8 stock {};
        ItchType::UnsignedInt32 farPrice;
        ItchType::UnsignedInt32 nearPrice;
        ItchType::UnsignedInt32 currentReferencePrice;
        ItchType::Alpha crossType;
        ItchType::Alpha priceVariationIndicator;
    };

    // DLWCRPD = Direst Listing with Capital Raise Price Discovery
    struct DLWCRPD final {
        const ItchType::Alpha messageType = 'O';
        ItchType::UnsignedInt16 stockLocate;
        ItchType::UnsignedInt16 trackingNumber;
        ItchType::TimeStamp timeStamp;
        ItchType::Alpha8 stock {};
        ItchType::Alpha openEligibilityStatus;
        ItchType::UnsignedInt32 minimumAllowablePrice;
        ItchType::UnsignedInt32 maximumAllowablePrice;
        ItchType::UnsignedInt32 nearExecutionPrice;
        ItchType::UnsignedInt64 nearExecutionTime;
        ItchType::UnsignedInt32 lowerPriceRangeCollar;
        ItchType::UnsignedInt32 upperPriceRangeCollar;
    };
}

#pragma pack(pop)