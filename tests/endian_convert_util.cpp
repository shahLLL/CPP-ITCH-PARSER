#include <catch2/catch_test_macros.hpp>
#include "../headers/endian_convert_util.hpp"

TEST_CASE("ENDIAN CONVERT UTIL TESTCASE #1", "[endian_convert_util_16]") {
    UnsignedInt16 testcase1 = 0;
    UnsignedInt16 testcase2 = 1;
    UnsignedInt16 testcase3 = 65535;
    UnsignedInt16 testcase4 = 61446;
    REQUIRE(bigEndianConvert16(testcase1) == 0);
    REQUIRE(bigEndianConvert16(testcase2) == 256);
    REQUIRE(bigEndianConvert16(testcase3) == 65535);
    REQUIRE(bigEndianConvert16(testcase4) == 1776);
}

TEST_CASE("ENDIAN CONVERT UTIL TESTCASE #2", "[endian_convert_util_32]") {
    UnsignedInt32 testcase1 = 0;
    UnsignedInt32 testcase2 = 1;
    UnsignedInt32 testcase3 = 134480385;
    UnsignedInt32 testcase4 = 256988845;
    REQUIRE(bigEndianConvert32(testcase1) == 0);
    REQUIRE(bigEndianConvert32(testcase2) == 16777216);
    REQUIRE(bigEndianConvert32(testcase3) == 16909320);
    REQUIRE(bigEndianConvert32(testcase4) == 2908115215);
}

TEST_CASE("ENDIAN CONVERT UTIL TESTCASE #3", "[endian_convert_util_48]") {
    UnsignedInt64 testcase1 = 0;
    UnsignedInt64 testcase2 = 281474976710655;
    UnsignedInt64 testcase3 = 250569738154767;
    UnsignedInt64 testcase4 = 8924960432608;
    REQUIRE(bigEndianConvert48(testcase1) == 0);
    REQUIRE(bigEndianConvert48(testcase2) == 281474976710655);
    REQUIRE(bigEndianConvert48(testcase3) == 17537346626787);
    REQUIRE(bigEndianConvert48(testcase4) == 246982497082888);
}

TEST_CASE("ENDIAN CONVERT UTIL TESTCASE #4", "[endian_convert_util_64]") {
    UnsignedInt64 testcase1 = 0;
    UnsignedInt64 testcase2 = 0xFFFFFFFFFFFFFFFF;
    UnsignedInt64 testcase3 = 7136817;
    UnsignedInt64 testcase4 = 1784445853624421461;
    REQUIRE(bigEndianConvert64(testcase1) == 0);
    REQUIRE(bigEndianConvert64(testcase2) == 0xFFFFFFFFFFFFFFFF);
    REQUIRE(bigEndianConvert64(testcase3) == 3595680099757719552);
    REQUIRE(bigEndianConvert64(testcase4) == 6182373193922167576);
}
