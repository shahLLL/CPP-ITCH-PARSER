#include <memory>
#include <bit>
#include "types.hpp"

namespace EndianConverter {
    [[nodiscard]] inline ItchType::UnsignedInt16 endianConvert16(const void* p) noexcept {
        ItchType::UnsignedInt16 rtn;
        std::memcpy(&rtn, p, sizeof(rtn));
        return static_cast<ItchType::UnsignedInt16>((rtn << 8) | (rtn >> 8));
    }

    [[nodiscard]] inline ItchType::UnsignedInt32 endianConvert32(const void* p) noexcept {
        ItchType::UnsignedInt32 rtn;
        std::memcpy(&rtn, p, sizeof(rtn));
        return (rtn << 24) | ((rtn << 8) & 0x00FF0000) |
           ((rtn >> 8) & 0x0000FF00) | (rtn >> 24);
    }

    [[nodiscard]] inline ItchType::UnsignedInt64 endianConvert48(const void* p) noexcept {
        ItchType::UnsignedInt64 rtn;
        std::memcpy(&rtn, p, sizeof(rtn));
        rtn &= 0x0000'FFFF'FFFF'FFFFULL;
        return ((rtn & 0x0000'0000'0000'00FFULL) << 40) |
           ((rtn & 0x0000'0000'0000'FF00ULL) << 24) |
           ((rtn & 0x0000'0000'00FF'0000ULL) <<  8) |
           ((rtn & 0x0000'0000'FF00'0000ULL) >>  8) |
           ((rtn & 0x0000'00FF'0000'0000ULL) >> 24) |
           ((rtn & 0x0000'FF00'0000'0000ULL) >> 40);
    }

    [[nodiscard]] inline ItchType::UnsignedInt64 endianConvert64(const void* p) noexcept {
        ItchType::UnsignedInt64 rtn;
        std::memcpy(&rtn, p, sizeof(rtn));
        return (rtn << 56) |
           ((rtn << 40) & 0x00FF000000000000ULL) |
           ((rtn << 24) & 0x0000FF0000000000ULL) |
           ((rtn <<  8) & 0x000000FF00000000ULL) |
           ((rtn >>  8) & 0x00000000FF000000ULL) |
           ((rtn >> 24) & 0x0000000000FF0000ULL) |
           ((rtn >> 40) & 0x000000000000FF00ULL) |
           (rtn >> 56);
    }
}