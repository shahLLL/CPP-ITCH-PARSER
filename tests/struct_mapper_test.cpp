#include <catch2/catch_test_macros.hpp>
#include "../headers/struct_mapper.hpp"

TEST_CASE("STRUCT MAPPER TESTCASE #1", "[map_system_event_message]") {
    std::byte testcase[] = {
        std::byte{0x53},
        std::byte{0x00}, std::byte{0x2A},
        std::byte{0x03}, std::byte{0xE9},
        std::byte{0x00}, std::byte{0x00}, std::byte{0x00},
        std::byte{0x00}, std::byte{0x01}, std::byte{0xF4},
        std::byte{0x4F}
    };

    SystemEventMessage systemEventMessage = mapSystemEventMessage(testcase);
    REQUIRE(systemEventMessage.messageType == 'S');
    REQUIRE(systemEventMessage.stockLocate == 42);
    REQUIRE(systemEventMessage.trackingNumber == 1001);
    REQUIRE(systemEventMessage.timeStamp == 500);
    REQUIRE(systemEventMessage.eventCode == 'O');
}