#pragma once

#include <cstdint>
#include <bit>
#include <string>

// Aliases
using Byte16 = uint16_t;
using Byte32 = uint32_t;
using Byte64 = uint64_t;

[[nodiscard]] constexpr Byte16 bigEndianConvert16(Byte16 inputData) noexcept {
    return static_cast<Byte16>((inputData << 8) | (inputData >> 8));
}

[[nodiscard]] constexpr Byte32 bigEndianConvert32(Byte32 inputData) noexcept {
    return (inputData << 24) | ((inputData << 8) & 0x00FF0000) |
           ((inputData >> 8) & 0x0000FF00) | (inputData >> 24);
}

[[nodiscard]] constexpr Byte64 bigEndianConvert48(Byte64 inputData) noexcept {
    inputData &= 0x0000'FFFF'FFFF'FFFFULL;
    return ((inputData & 0x0000'0000'0000'00FFULL) << 40) |
           ((inputData & 0x0000'0000'0000'FF00ULL) << 24) |
           ((inputData & 0x0000'0000'00FF'0000ULL) <<  8) |
           ((inputData & 0x0000'0000'FF00'0000ULL) >>  8) |
           ((inputData & 0x0000'00FF'0000'0000ULL) >> 24) |
           ((inputData & 0x0000'FF00'0000'0000ULL) >> 40);
}

[[nodiscard]] constexpr Byte64 bigEndianConvert64(Byte64 inputData) noexcept {
    return (inputData << 56) |
           ((inputData << 40) & 0x00FF000000000000ULL) |
           ((inputData << 24) & 0x0000FF0000000000ULL) |
           ((inputData <<  8) & 0x000000FF00000000ULL) |
           ((inputData >>  8) & 0x00000000FF000000ULL) |
           ((inputData >> 24) & 0x0000000000FF0000ULL) |
           ((inputData >> 40) & 0x000000000000FF00ULL) |
           (inputData >> 56);
}