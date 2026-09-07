#pragma once
#include <cstdint>
#include <cstddef>

namespace ItchType {
    // Constant Expressions
    constexpr std::size_t alpha2Size = 2;
    constexpr std::size_t alpha4Size = 4;
    constexpr std::size_t alpha8Size = 8;

    // Aliases
    using Alpha = char;
    using UnsignedInt8 = std::uint8_t;
    using UnsignedInt16 = std::uint16_t;
    using UnsignedInt32 = std::uint32_t;
    using UnsignedInt64 = std::uint64_t;
    using Alpha2 = Alpha[alpha2Size];
    using Alpha4 = Alpha[alpha4Size];
    using TimeStamp = std::uint64_t;
    using Alpha8 = Alpha[alpha8Size];
}