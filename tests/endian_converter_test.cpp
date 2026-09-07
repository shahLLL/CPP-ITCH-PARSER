#include <catch2/catch_test_macros.hpp>
#include <cstddef>
#include "../headers/endian_converter.hpp"

TEST_CASE("ENDIAN CONVERTER TESTCASE #1", "[endian_convert_16]") {
    UnsignedInt16  testcase1 = 0;
    std::byte* testcase1Ptr = reinterpret_cast<std::byte*>(&testcase1);
    UnsignedInt16 testcase2 = 1;
    std::byte* testcase2Ptr = reinterpret_cast<std::byte*>(&testcase2);
    UnsignedInt16 testcase3 = 65535;
    std::byte* testcase3Ptr = reinterpret_cast<std::byte*>(&testcase3);
    UnsignedInt16 testcase4 = 61446;
    std::byte* testcase4Ptr = reinterpret_cast<std::byte*>(&testcase4);

    REQUIRE(EndianConverter::endianConvert16(testcase1Ptr) == 0);
    REQUIRE(EndianConverter::endianConvert16(testcase2Ptr) == 256);
    REQUIRE(EndianConverter::endianConvert16(testcase3Ptr) == 65535);
    REQUIRE(EndianConverter::endianConvert16(testcase4Ptr) == 1776);
}

TEST_CASE("ENDIAN CONVERTER TESTCASE #2", "[endian_convert_32]") {
    UnsignedInt32  testcase1 = 0;
    std::byte* testcase1Ptr = reinterpret_cast<std::byte*>(&testcase1);
    UnsignedInt32 testcase2 = 1;
    std::byte* testcase2Ptr = reinterpret_cast<std::byte*>(&testcase2);
    UnsignedInt32 testcase3 = 134480385;
    std::byte* testcase3Ptr = reinterpret_cast<std::byte*>(&testcase3);
    UnsignedInt32 testcase4 = 256988845;
    std::byte* testcase4Ptr = reinterpret_cast<std::byte*>(&testcase4);

    REQUIRE(EndianConverter::endianConvert32(testcase1Ptr) == 0);
    REQUIRE(EndianConverter::endianConvert32(testcase2Ptr) == 16777216);
    REQUIRE(EndianConverter::endianConvert32(testcase3Ptr) == 16909320);
    REQUIRE(EndianConverter::endianConvert32(testcase4Ptr) == 2908115215);
}

TEST_CASE("ENDIAN CONVERTER TESTCASE #3", "[endian_convert_48]") {
    UnsignedInt64  testcase1 = 0;
    std::byte* testcase1Ptr = reinterpret_cast<std::byte*>(&testcase1);
    UnsignedInt64 testcase2 = 281474976710655;
    std::byte* testcase2Ptr = reinterpret_cast<std::byte*>(&testcase2);
    UnsignedInt64 testcase3 = 250569738154767;
    std::byte* testcase3Ptr = reinterpret_cast<std::byte*>(&testcase3);
    UnsignedInt64 testcase4 = 8924960432608;
    std::byte* testcase4Ptr = reinterpret_cast<std::byte*>(&testcase4);

    REQUIRE(EndianConverter::endianConvert48(testcase1Ptr) == 0);
    REQUIRE(EndianConverter::endianConvert48(testcase2Ptr) == 281474976710655);
    REQUIRE(EndianConverter::endianConvert48(testcase3Ptr) == 17537346626787);
    REQUIRE(EndianConverter::endianConvert48(testcase4Ptr) == 246982497082888);
}

TEST_CASE("ENDIAN CONVERTER TESTCASE #4", "[endian_convert_64]") {
    UnsignedInt64  testcase1 = 0;
    std::byte* testcase1Ptr = reinterpret_cast<std::byte*>(&testcase1);
    UnsignedInt64 testcase2 = 0xFFFFFFFFFFFFFFFF;
    std::byte* testcase2Ptr = reinterpret_cast<std::byte*>(&testcase2);
    UnsignedInt64 testcase3 = 7136817;
    std::byte* testcase3Ptr = reinterpret_cast<std::byte*>(&testcase3);
    UnsignedInt64 testcase4 = 1784445853624421461;
    std::byte* testcase4Ptr = reinterpret_cast<std::byte*>(&testcase4);

    REQUIRE(EndianConverter::endianConvert64(testcase1Ptr) == 0);
    REQUIRE(EndianConverter::endianConvert64(testcase2Ptr) == 0xFFFFFFFFFFFFFFFF);
    REQUIRE(EndianConverter::endianConvert64(testcase3Ptr) == 3595680099757719552);
    REQUIRE(EndianConverter::endianConvert64(testcase4Ptr) == 6182373193922167576);
}