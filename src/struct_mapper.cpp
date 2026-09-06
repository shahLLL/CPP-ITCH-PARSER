#include "../headers/struct_mapper.hpp"

[[nodiscard]] SystemEventMessage mapSystemEventMessage(const std::byte* msg) noexcept {
    SystemEventMessage systemEventMessage{};

    systemEventMessage.stockLocate = endianConvert16(msg + 1);
    systemEventMessage.trackingNumber = endianConvert16(msg + 3);
    systemEventMessage.timeStamp = endianConvert48(msg + 5);
    systemEventMessage.eventCode = static_cast<Alpha>(msg[11]);

    return systemEventMessage;
};

[[nodiscard]] StockDirectory mapStockDirectory(const std::byte* msg) noexcept {
    StockDirectory stockDirectory{};

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