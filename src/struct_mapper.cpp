#include "../headers/struct_mapper.hpp"

[[nodiscard]] SystemEventMessage mapSystemEventMessage(const std::byte* msg) noexcept {
    SystemEventMessage systemEventMessage {};

    systemEventMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    systemEventMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    systemEventMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    systemEventMessage.eventCode = static_cast<Alpha>(msg[11]);

    return systemEventMessage;
};

[[nodiscard]] StockDirectory mapStockDirectory(const std::byte* msg) noexcept {
    StockDirectory stockDirectory {};

    stockDirectory.stockLocate = EndianConverter::endianConvert16(msg + 1);
    stockDirectory.trackingNumber =  EndianConverter::endianConvert16(msg + 3);
    stockDirectory.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(stockDirectory.stock, msg + 11, alpha8Size);
    stockDirectory.marketCategory = static_cast<Alpha>(msg[19]);
    stockDirectory.financialStatusIndicator = static_cast<Alpha>(msg[20]);
    stockDirectory.roundLotSize = EndianConverter::endianConvert32(msg + 21);
    stockDirectory.roundLotsOnly = static_cast<Alpha>(msg[25]);
    stockDirectory.issueClassification = static_cast<Alpha>(msg[26]);
    std::memcpy(stockDirectory.issueSubType, msg + 27, alpha2Size);
    stockDirectory.authenticity = static_cast<Alpha>(msg[29]);
    stockDirectory.shortSaleThresholdIndicator = static_cast<Alpha>(msg[30]);
    stockDirectory.ipoFlag = static_cast<Alpha>(msg[31]);
    stockDirectory.luldReferencePriceTier = static_cast<Alpha>(msg[32]);
    stockDirectory.etpFlag = static_cast<Alpha>(msg[33]);
    stockDirectory.etpLeverageFactor = EndianConverter::endianConvert32(msg + 34);
    stockDirectory.inverseIndicator = static_cast<Alpha>(msg[38]);

    return stockDirectory;
}

[[nodiscard]] StockTradingAction mapStockTradingAction(const std::byte* msg) noexcept {
    StockTradingAction stockTradingAction {};

    stockTradingAction.stockLocate = EndianConverter::endianConvert16(msg + 1);
    stockTradingAction.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    stockTradingAction.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(stockTradingAction.stock, msg + 11, alpha8Size);
    stockTradingAction.tradingState = static_cast<Alpha>(msg[19]);
    stockTradingAction.reserved = static_cast<Alpha>(msg[20]);
    std::memcpy(stockTradingAction.reason, msg + 21, alpha4Size);

    return stockTradingAction;
}

[[nodiscard]] RegSHORestriction mapRegSHORestriction(const std::byte* msg) noexcept {
    RegSHORestriction regSHORestriction {};

    regSHORestriction.locateCode = EndianConverter::endianConvert16(msg + 1);
    regSHORestriction.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    regSHORestriction.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(regSHORestriction.stock, msg + 11, alpha8Size);
    regSHORestriction.regSHOAction = static_cast<Alpha>(msg[19]);

    return regSHORestriction;
}

[[nodiscard]] MarketParticipantPosition mapMarketParticipationPostion(const std::byte* msg) noexcept {
    MarketParticipantPosition marketParticipationPosition {};

    marketParticipationPosition.stockLocate = EndianConverter::endianConvert16(msg + 1);
    marketParticipationPosition.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    marketParticipationPosition.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(marketParticipationPosition.mpid, msg + 11, alpha4Size);
    std::memcpy(marketParticipationPosition.stock, msg + 15, alpha8Size);
    marketParticipationPosition.primaryMarketMaker = static_cast<Alpha>(msg[23]);
    marketParticipationPosition.marketMakerMode = static_cast<Alpha>(msg[24]);
    marketParticipationPosition.marketParticipantState = static_cast<Alpha>(msg[25]);

    return marketParticipationPosition;
}

[[nodiscard]] MWCBDeclineLevelMessage mapMWCBDeclineLevelMessage(const std::byte* msg) noexcept {
    MWCBDeclineLevelMessage mwcbDeclineLevelMessage {};

    mwcbDeclineLevelMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    mwcbDeclineLevelMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    mwcbDeclineLevelMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    mwcbDeclineLevelMessage.level1 = EndianConverter::endianConvert64(msg + 11);
    mwcbDeclineLevelMessage.level2 = EndianConverter::endianConvert64(msg + 19);
    mwcbDeclineLevelMessage.level3 = EndianConverter::endianConvert64(msg + 27);

    return mwcbDeclineLevelMessage;
}

[[nodiscard]] MWCBStatusMessage mapMWCBStatusMessage(const std::byte* msg) noexcept {
    MWCBStatusMessage mwcbStatusMessage {};

    mwcbStatusMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    mwcbStatusMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    mwcbStatusMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    mwcbStatusMessage.breachedLevel = static_cast<Alpha>(msg[11]);

    return mwcbStatusMessage;
}

[[nodiscard]] QuotingPeriodUpdate mapQuotingPeriodUpdate(const std::byte* msg) noexcept {
    QuotingPeriodUpdate quotingPeriodUpdate {};

    quotingPeriodUpdate.stockLocate = EndianConverter::endianConvert16(msg + 1);
    quotingPeriodUpdate.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    quotingPeriodUpdate.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(quotingPeriodUpdate.stock, msg + 11, alpha8Size);
    quotingPeriodUpdate.ipoQuotationReleaseTime = EndianConverter::endianConvert32(msg + 19);
    quotingPeriodUpdate.ipoQuotationReleaseQualifier = static_cast<Alpha>(msg[23]);
    quotingPeriodUpdate.ipoPrice = EndianConverter::endianConvert32(msg + 24);

    return quotingPeriodUpdate;
}

[[nodiscard]] LULDAuctionCollar mapLULDAuctionCollar(const std::byte* msg) noexcept {
    LULDAuctionCollar luldAuctionCollar {};

    luldAuctionCollar.stockLocate = EndianConverter::endianConvert16(msg + 1);
    luldAuctionCollar.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    luldAuctionCollar.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(luldAuctionCollar.stock, msg + 11, alpha8Size);
    luldAuctionCollar.auctionCollarReferencePrice = EndianConverter::endianConvert32(msg + 19);
    luldAuctionCollar.upperAuctionCollarPrice = EndianConverter::endianConvert32(msg + 23);
    luldAuctionCollar.lowerAuctionCollarPrice = EndianConverter::endianConvert32(msg + 27);
    luldAuctionCollar.auctionCollarExtension = EndianConverter::endianConvert32(msg + 31);

    return luldAuctionCollar;
}

[[nodiscard]] OperationalHalt mapOperationalHalt(const std::byte* msg) noexcept {
    OperationalHalt operationalHalt {};

    operationalHalt.stockLocate = EndianConverter::endianConvert16(msg + 1);
    operationalHalt.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    operationalHalt.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(operationalHalt.stock, msg + 11, alpha8Size);
    operationalHalt.marketCode = static_cast<Alpha>(msg[19]);
    operationalHalt.operationalHaltAction = static_cast<Alpha>(msg[20]);

    return operationalHalt;
}

[[nodiscard]] AddOrderMessage mapAddOrderMessage(const std::byte* msg) noexcept {
    AddOrderMessage addOrderMessage {};

    addOrderMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    addOrderMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    addOrderMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    addOrderMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    addOrderMessage.buySellIndicator = static_cast<Alpha>(msg[19]);
    addOrderMessage.shares = EndianConverter::endianConvert32(msg + 20);
    std::memcpy(addOrderMessage.stock, msg + 24, alpha8Size);
    addOrderMessage.price = EndianConverter::endianConvert32(msg + 32);

    return addOrderMessage;
}

[[nodiscard]] AddOrderMPIDAttributionMessage mapAddOrderMPIDAttributionMessage(const std::byte* msg) noexcept {
    AddOrderMPIDAttributionMessage addOrderMPIDAttributionMessage = AddOrderMPIDAttributionMessage {};

    addOrderMPIDAttributionMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    addOrderMPIDAttributionMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    addOrderMPIDAttributionMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    addOrderMPIDAttributionMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    addOrderMPIDAttributionMessage.buySellIndicator = static_cast<Alpha>(msg[19]);
    addOrderMPIDAttributionMessage.shares = EndianConverter::endianConvert32(msg + 20);
    std::memcpy(addOrderMPIDAttributionMessage.stock, msg + 24, alpha8Size);
    addOrderMPIDAttributionMessage.price = EndianConverter::endianConvert32(msg + 32);
    std::memcpy(addOrderMPIDAttributionMessage.attribution, msg + 36, alpha4Size);

    return addOrderMPIDAttributionMessage;
}

[[nodiscard]] OrderExecutedMessage mapOrderExecutedMessage(const std::byte* msg) noexcept {
    OrderExecutedMessage orderExecutedMessage {};

    orderExecutedMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    orderExecutedMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    orderExecutedMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    orderExecutedMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    orderExecutedMessage.executedShares = EndianConverter::endianConvert32(msg + 19);
    orderExecutedMessage.matchNumber = EndianConverter::endianConvert64(msg + 23);

    return orderExecutedMessage;
}

[[nodiscard]] OrderExecutedWithPriceMessage mapOrderExecutedWithPriceMessage(const std::byte* msg) noexcept {
    OrderExecutedWithPriceMessage orderExecutedWithPriceMessage {};

    orderExecutedWithPriceMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    orderExecutedWithPriceMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    orderExecutedWithPriceMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    orderExecutedWithPriceMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    orderExecutedWithPriceMessage.executedShares = EndianConverter::endianConvert32(msg + 19);
    orderExecutedWithPriceMessage.matchNumber = EndianConverter::endianConvert64(msg + 23);
    orderExecutedWithPriceMessage.printable = static_cast<Alpha>(msg[31]);
    orderExecutedWithPriceMessage.executionPrice = EndianConverter::endianConvert32(msg + 32);

    return orderExecutedWithPriceMessage;
}

[[nodiscard]] OrderCancelMessage mapOrderCancelMessage(const std::byte* msg) noexcept {
    OrderCancelMessage orderCancelMessage {};

    orderCancelMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    orderCancelMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    orderCancelMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    orderCancelMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    orderCancelMessage.cancelledShares = EndianConverter::endianConvert32(msg + 19);

    return orderCancelMessage;
}

[[nodiscard]] OrderDeleteMessage mapOrderDeleteMessage(const std::byte* msg) noexcept {
    OrderDeleteMessage orderDeleteMessage;

    orderDeleteMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    orderDeleteMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    orderDeleteMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    orderDeleteMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);

    return orderDeleteMessage;
}

[[nodiscard]] OrderReplaceMessage mapOrderReplaceMessage(const std::byte* msg) noexcept {
    OrderReplaceMessage orderReplaceMessage {};

    orderReplaceMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    orderReplaceMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    orderReplaceMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    orderReplaceMessage.originalOrderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    orderReplaceMessage.newOrderReferenceNumber = EndianConverter::endianConvert64(msg + 19);
    orderReplaceMessage.shares = EndianConverter::endianConvert32(msg + 27);
    orderReplaceMessage.price = EndianConverter::endianConvert32(msg + 31);

    return orderReplaceMessage;
}

[[nodiscard]] TradeMessage mapTradeMessage(const std::byte* msg) noexcept {
    TradeMessage tradeMessage {};

    tradeMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    tradeMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    tradeMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    tradeMessage.orderReferenceNumber = EndianConverter::endianConvert64(msg + 11);
    tradeMessage.buySellIndicator = static_cast<Alpha>(msg[19]);
    tradeMessage.shares = EndianConverter::endianConvert32(msg + 20);
    std::memcpy(tradeMessage.stock, msg + 24, alpha8Size);
    tradeMessage.price = EndianConverter::endianConvert32(msg + 32);
    tradeMessage.matchNumber = EndianConverter::endianConvert64(msg + 36);

    return tradeMessage;
}

[[nodiscard]] CrossTradeMessage mapCrossTradeMessage(const std::byte* msg) noexcept {
    CrossTradeMessage crossTradeMessage {};

    crossTradeMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    crossTradeMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    crossTradeMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    crossTradeMessage.shares = EndianConverter::endianConvert64(msg + 11);
    std::memcpy(crossTradeMessage.stock, msg + 19, alpha8Size);
    crossTradeMessage.crossPrice = EndianConverter::endianConvert32(msg + 27);
    crossTradeMessage.matchNumber = EndianConverter::endianConvert64(msg + 31);
    crossTradeMessage.crossType = static_cast<Alpha>(msg[39]);

    return crossTradeMessage;
}

[[nodiscard]] BrokenTradeMessage mapBrokenTradeMessage(const std::byte* msg) noexcept {
    BrokenTradeMessage brokenTradeMessage {};

    brokenTradeMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    brokenTradeMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    brokenTradeMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    brokenTradeMessage.matchNumber = EndianConverter::endianConvert64(msg + 11);

    return brokenTradeMessage;
}

[[nodiscard]] NOIIMessage mapNOIIMessage(const std::byte* msg) noexcept {
    NOIIMessage noiiMessage {};

    noiiMessage.stockLocate = EndianConverter::endianConvert16(msg + 1);
    noiiMessage.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    noiiMessage.timeStamp = EndianConverter::endianConvert48(msg + 5);
    noiiMessage.pairedShares = EndianConverter::endianConvert64(msg + 11);
    noiiMessage.imbalanceShares = EndianConverter::endianConvert64(msg + 19);
    noiiMessage.imbalanceDirection = static_cast<Alpha>(msg[27]);
    std::memcpy(noiiMessage.stock, msg + 28, alpha8Size);
    noiiMessage.farPrice = EndianConverter::endianConvert32(msg + 36);
    noiiMessage.nearPrice = EndianConverter::endianConvert32(msg + 40);
    noiiMessage.currentReferencePrice = EndianConverter::endianConvert32(msg + 44);
    noiiMessage.crossType = static_cast<Alpha>(msg[48]);
    noiiMessage.priceVariationIndicator = static_cast<Alpha>(msg[49]);

    return noiiMessage;
}

[[nodiscard]] DLWCRPD mapDLWCRPD(const std::byte* msg) noexcept {
    DLWCRPD dlwcrpd {};

    dlwcrpd.stockLocate = EndianConverter::endianConvert16(msg + 1);
    dlwcrpd.trackingNumber = EndianConverter::endianConvert16(msg + 3);
    dlwcrpd.timeStamp = EndianConverter::endianConvert48(msg + 5);
    std::memcpy(dlwcrpd.stock, msg + 11, alpha8Size);
    dlwcrpd.openEligibilityStatus = static_cast<Alpha>(msg[19]);
    dlwcrpd.minimumAllowablePrice = EndianConverter::endianConvert32(msg + 20);
    dlwcrpd.maximumAllowablePrice = EndianConverter::endianConvert32(msg + 24);
    dlwcrpd.nearExecutionPrice = EndianConverter::endianConvert32(msg + 28);
    dlwcrpd.nearExecutionTime = EndianConverter::endianConvert64(msg + 32);
    dlwcrpd.lowerPriceRangeCollar = EndianConverter::endianConvert32(msg + 40);
    dlwcrpd.upperPriceRangeCollar = EndianConverter::endianConvert32(msg + 44);

    return dlwcrpd;
}
