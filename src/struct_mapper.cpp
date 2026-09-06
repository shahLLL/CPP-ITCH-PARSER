#include "../headers/struct_mapper.hpp"

[[nodiscard]] SystemEventMessage mapSystemEventMessage(const std::byte* msg) noexcept {
    SystemEventMessage systemEventMessage{};

    systemEventMessage.stockLocate = endianConvert16(msg + 1);
    systemEventMessage.trackingNumber = endianConvert16(msg + 3);
    systemEventMessage.timeStamp = endianConvert48(msg + 5);
    systemEventMessage.eventCode = static_cast<Alpha>(msg[11]);

    return systemEventMessage;
};