#include "../headers/struct_mapper.hpp"

[[nodiscard]] SystemEventMessage mapSystemEventMessage(const std::byte* msg) noexcept {
    SystemEventMessage systemEventMessage {};

    systemEventMessage.stockLocate = endianConvert16(msg + 1);
    systemEventMessage.trackingNumber = endianConvert16(msg + 3);
    systemEventMessage.timeStamp = endianConvert48(msg + 5);
    systemEventMessage.eventCode = static_cast<Alpha>(msg[11]);

    return systemEventMessage;
};

[[nodiscard]] StockDirectory mapStockDirectory(const std::byte* msg) noexcept {
    StockDirectory stockDirectory {};

    stockDirectory.stockLocate = endianConvert16(msg + 1);
    stockDirectory.trackingNumber =  endianConvert16(msg + 3);
    stockDirectory.timeStamp = endianConvert48(msg + 5);
    std::memcpy(stockDirectory.stock, msg + 11, alpha8Size);
    stockDirectory.marketCategory = static_cast<Alpha>(msg[19]);
    stockDirectory.financialStatusIndicator = static_cast<Alpha>(msg[20]);
    stockDirectory.roundLotSize = endianConvert32(msg + 21);
    stockDirectory.roundLotsOnly = static_cast<Alpha>(msg[25]);
    stockDirectory.issueClassification = static_cast<Alpha>(msg[26]);
    std::memcpy(stockDirectory.issueSubType, msg + 27, alpha2Size);
    stockDirectory.authenticity = static_cast<Alpha>(msg[29]);
    stockDirectory.shortSaleThresholdIndicator = static_cast<Alpha>(msg[30]);
    stockDirectory.ipoFlag = static_cast<Alpha>(msg[31]);
    stockDirectory.luldReferencePriceTier = static_cast<Alpha>(msg[32]);
    stockDirectory.etpFlag = static_cast<Alpha>(msg[33]);
    stockDirectory.etpLeverageFactor = endianConvert32(msg + 34);
    stockDirectory.inverseIndicator = static_cast<Alpha>(msg[38]);

    return stockDirectory;
}

[[nodiscard]] StockTradingAction mapStockTradingAction(const std::byte* msg) noexcept {
    StockTradingAction stockTradingAction {};

    stockTradingAction.stockLocate = endianConvert16(msg + 1);
    stockTradingAction.trackingNumber = endianConvert16(msg + 3);
    stockTradingAction.timeStamp = endianConvert48(msg + 5);
    std::memcpy(stockTradingAction.stock, msg + 11, alpha8Size);
    stockTradingAction.tradingState = static_cast<Alpha>(msg[19]);
    stockTradingAction.reserved = static_cast<Alpha>(msg[20]);
    std::memcpy(stockTradingAction.reason, msg + 21, alpha4Size);

    return stockTradingAction;
}

[[nodiscard]] RegSHORestriction mapRegSHORestriction(const std::byte* msg) noexcept {
    RegSHORestriction regSHORestriction {};

    regSHORestriction.locateCode = endianConvert16(msg + 1);
    regSHORestriction.trackingNumber = endianConvert16(msg + 3);
    regSHORestriction.timeStamp = endianConvert48(msg + 5);
    std::memcpy(regSHORestriction.stock, msg + 11, alpha8Size);
    regSHORestriction.regSHOAction = static_cast<Alpha>(msg[19]);

    return regSHORestriction;
}

[[nodiscard]] MarketParticipantPosition mapMarketParticipationPostion(const std::byte* msg) noexcept {
    MarketParticipantPosition marketParticipationPosition {};

    marketParticipationPosition.stockLocate = endianConvert16(msg + 1);
    marketParticipationPosition.trackingNumber = endianConvert16(msg + 3);
    marketParticipationPosition.timeStamp = endianConvert48(msg + 5);
    std::memcpy(marketParticipationPosition.mpid, msg + 11, alpha4Size);
    std::memcpy(marketParticipationPosition.stock, msg + 15, alpha8Size);
    marketParticipationPosition.primaryMarketMaker = static_cast<Alpha>(msg[23]);
    marketParticipationPosition.marketMakerMode = static_cast<Alpha>(msg[24]);
    marketParticipationPosition.marketParticipantState = static_cast<Alpha>(msg[25]);

    return marketParticipationPosition;
}

[[nodiscard]] MWCBDeclineLevelMessage mapMWCBDeclineLevelMessage(const std::byte* msg) noexcept {
    MWCBDeclineLevelMessage mwcbDeclineLevelMessage {};

    mwcbDeclineLevelMessage.stockLocate = endianConvert16(msg + 1);
    mwcbDeclineLevelMessage.trackingNumber = endianConvert16(msg + 3);
    mwcbDeclineLevelMessage.timeStamp = endianConvert48(msg + 5);
    mwcbDeclineLevelMessage.level1 = endianConvert64(msg + 11);
    mwcbDeclineLevelMessage.level2 = endianConvert64(msg + 19);
    mwcbDeclineLevelMessage.level3 = endianConvert64(msg + 27);

    return mwcbDeclineLevelMessage;
}

[[nodiscard]] MWCBStatusMessage mapMWCBStatusMessage(const std::byte* msg) noexcept {
    MWCBStatusMessage mwcbStatusMessage {};

    mwcbStatusMessage.stockLocate = endianConvert16(msg + 1);
    mwcbStatusMessage.trackingNumber = endianConvert16(msg + 3);
    mwcbStatusMessage.timeStamp = endianConvert48(msg + 5);
    mwcbStatusMessage.breachedLevel = static_cast<Alpha>(msg[11]);

    return mwcbStatusMessage;
}

[[nodiscard]] QuotingPeriodUpdate mapQuotingPeriodUpdate(const std::byte* msg) noexcept {
    QuotingPeriodUpdate quotingPeriodUpdate {};

    quotingPeriodUpdate.stockLocate = endianConvert16(msg + 1);
    quotingPeriodUpdate.trackingNumber = endianConvert16(msg + 3);
    quotingPeriodUpdate.timeStamp = endianConvert48(msg + 5);
    std::memcpy(quotingPeriodUpdate.stock, msg + 11, alpha8Size);
    quotingPeriodUpdate.ipoQuotationReleaseTime = endianConvert32(msg + 19);
    quotingPeriodUpdate.ipoQuotationReleaseQualifier = static_cast<Alpha>(msg[23]);
    quotingPeriodUpdate.ipoPrice = endianConvert32(msg + 24);

    return quotingPeriodUpdate;
}

[[nodiscard]] LULDAuctionCollar mapLULDAuctionCollar(const std::byte* msg) noexcept {
    LULDAuctionCollar luldAuctionCollar {};

    luldAuctionCollar.stockLocate = endianConvert16(msg + 1);
    luldAuctionCollar.trackingNumber = endianConvert16(msg + 3);
    luldAuctionCollar.timeStamp = endianConvert48(msg + 5);
    std::memcpy(luldAuctionCollar.stock, msg + 11, alpha8Size);
    luldAuctionCollar.auctionCollarReferencePrice = endianConvert32(msg + 19);
    luldAuctionCollar.upperAuctionCollarPrice = endianConvert32(msg + 23);
    luldAuctionCollar.lowerAuctionCollarPrice = endianConvert32(msg + 27);
    luldAuctionCollar.auctionCollarExtension = endianConvert32(msg + 31);

    return luldAuctionCollar;
}

[[nodiscard]] OperationalHalt mapOperationalHalt(const std::byte* msg) noexcept {
    OperationalHalt operationalHalt {};

    operationalHalt.stockLocate = endianConvert16(msg + 1);
    operationalHalt.trackingNumber = endianConvert16(msg + 3);
    operationalHalt.timeStamp = endianConvert48(msg + 5);
    std::memcpy(operationalHalt.stock, msg + 11, alpha8Size);
    operationalHalt.marketCode = static_cast<Alpha>(msg[19]);
    operationalHalt.operationalHaltAction = static_cast<Alpha>(msg[20]);

    return operationalHalt;
}

[[nodiscard]] AddOrderMessage mapAddOrderMessage(const std::byte* msg) noexcept {
    AddOrderMessage addOrderMessage {};

    addOrderMessage.stockLocate = endianConvert16(msg + 1);
    addOrderMessage.trackingNumber = endianConvert16(msg + 3);
    addOrderMessage.timeStamp = endianConvert48(msg + 5);
    addOrderMessage.orderReferenceNumber = endianConvert64(msg + 11);
    addOrderMessage.buySellIndicator = static_cast<Alpha>(msg[19]);
    addOrderMessage.shares = endianConvert32(msg + 20);
    std::memcpy(addOrderMessage.stock, msg + 24, alpha8Size);
    addOrderMessage.price = endianConvert32(msg + 32);

    return addOrderMessage;
}

[[nodiscard]] AddOrderMPIDAttributionMessage mapAddOrderMPIDAttributionMessage(const std::byte* msg) noexcept {
    AddOrderMPIDAttributionMessage addOrderMPIDAttributionMessage = AddOrderMPIDAttributionMessage {};

    addOrderMPIDAttributionMessage.stockLocate = endianConvert16(msg + 1);
    addOrderMPIDAttributionMessage.trackingNumber = endianConvert16(msg + 3);
    addOrderMPIDAttributionMessage.timeStamp = endianConvert48(msg + 5);
    addOrderMPIDAttributionMessage.orderReferenceNumber = endianConvert64(msg + 11);
    addOrderMPIDAttributionMessage.buySellIndicator = static_cast<Alpha>(msg[19]);
    addOrderMPIDAttributionMessage.shares = endianConvert32(msg + 20);
    std::memcpy(addOrderMPIDAttributionMessage.stock, msg + 24, alpha8Size);
    addOrderMPIDAttributionMessage.price = endianConvert32(msg + 32);
    std::memcpy(addOrderMPIDAttributionMessage.attribution, msg + 36, alpha4Size);

    return addOrderMPIDAttributionMessage;
}

[[nodiscard]] OrderExecutedMessage mapOrderExecutedMessage(const std::byte* msg) noexcept {
    OrderExecutedMessage orderExecutedMessage {};

    orderExecutedMessage.stockLocate = endianConvert16(msg + 1);
    orderExecutedMessage.trackingNumber = endianConvert16(msg + 3);
    orderExecutedMessage.timeStamp = endianConvert48(msg + 5);
    orderExecutedMessage.orderReferenceNumber = endianConvert64(msg + 11);
    orderExecutedMessage.executedShares = endianConvert32(msg + 19);
    orderExecutedMessage.matchNumber = endianConvert64(msg + 23);

    return orderExecutedMessage;
}

[[nodiscard]] OrderExecutedWithPriceMessage mapOrderExecutedWithPriceMessage(const std::byte* msg) noexcept {
    OrderExecutedWithPriceMessage orderExecutedWithPriceMessage {};

    orderExecutedWithPriceMessage.stockLocate = endianConvert16(msg + 1);
    orderExecutedWithPriceMessage.trackingNumber = endianConvert16(msg + 3);
    orderExecutedWithPriceMessage.timeStamp = endianConvert48(msg + 5);
    orderExecutedWithPriceMessage.orderReferenceNumber = endianConvert64(msg + 11);
    orderExecutedWithPriceMessage.executedShares = endianConvert32(msg + 19);
    orderExecutedWithPriceMessage.matchNumber = endianConvert64(msg + 23);
    orderExecutedWithPriceMessage.printable = static_cast<Alpha>(msg[31]);
    orderExecutedWithPriceMessage.executionPrice = endianConvert32(msg + 32);

    return orderExecutedWithPriceMessage;
}
