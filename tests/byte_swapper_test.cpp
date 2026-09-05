#include <catch2/catch_test_macros.hpp>
#include "../headers/byte_swapper.hpp"

TEST_CASE("BYTE SWAPPER TESTCASE #1", "[byte_swap_16]") {
    UnsignedInt16 testcase1 = 0;
    UnsignedInt16 testcase2 = 1;
    UnsignedInt16 testcase3 = 65535;
    UnsignedInt16 testcase4 = 61446;
    REQUIRE(byteSwap16(testcase1) == 0);
    REQUIRE(byteSwap16(testcase2) == 256);
    REQUIRE(byteSwap16(testcase3) == 65535);
    REQUIRE(byteSwap16(testcase4) == 1776);
}

TEST_CASE("BYTE SWAPPER TESTCASE #2", "[byte_swap_32]") {
    UnsignedInt32 testcase1 = 0;
    UnsignedInt32 testcase2 = 1;
    UnsignedInt32 testcase3 = 134480385;
    UnsignedInt32 testcase4 = 256988845;
    REQUIRE(byteSwap32(testcase1) == 0);
    REQUIRE(byteSwap32(testcase2) == 16777216);
    REQUIRE(byteSwap32(testcase3) == 16909320);
    REQUIRE(byteSwap32(testcase4) == 2908115215);
}

TEST_CASE("BYTE SWAPPER TESTCASE #3", "[byte_swap_48]") {
    UnsignedInt64 testcase1 = 0;
    UnsignedInt64 testcase2 = 281474976710655;
    UnsignedInt64 testcase3 = 250569738154767;
    UnsignedInt64 testcase4 = 8924960432608;
    REQUIRE(byteSwap48(testcase1) == 0);
    REQUIRE(byteSwap48(testcase2) == 281474976710655);
    REQUIRE(byteSwap48(testcase3) == 17537346626787);
    REQUIRE(byteSwap48(testcase4) == 246982497082888);
}

TEST_CASE("BYTE SWAPPER TESTCASE #4", "[byte_swap_64]") {
    UnsignedInt64 testcase1 = 0;
    UnsignedInt64 testcase2 = 0xFFFFFFFFFFFFFFFF;
    UnsignedInt64 testcase3 = 7136817;
    UnsignedInt64 testcase4 = 1784445853624421461;
    REQUIRE(byteSwap64(testcase1) == 0);
    REQUIRE(byteSwap64(testcase2) == 0xFFFFFFFFFFFFFFFF);
    REQUIRE(byteSwap64(testcase3) == 3595680099757719552);
    REQUIRE(byteSwap64(testcase4) == 6182373193922167576);
}
