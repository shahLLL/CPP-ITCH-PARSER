#include <memory>
#include <bit>
#include "types.hpp"
#include "byte_swapper.hpp"

[[nodiscard]] inline UnsignedInt16 endianConvert16(const void* p) noexcept {
    UnsignedInt16 buf;
    std::memcpy(&buf, p, sizeof(buf));
    return byteSwap16(buf);
}

[[nodiscard]] inline UnsignedInt32 endianConvert32(const void* p) noexcept {
    UnsignedInt32 buf;
    std::memcpy(&buf, p, sizeof(buf));
    return byteSwap32(buf);
}

[[nodiscard]] inline UnsignedInt64 endianConvert48(const void* p) noexcept {
    UnsignedInt64 buf;
    std::memcpy(&buf, p, sizeof(buf));
    return byteSwap48(buf);
}

[[nodiscard]] inline UnsignedInt64 endianConvert64(const void* p) noexcept {
    UnsignedInt64 buf;
    std::memcpy(&buf, p, sizeof(buf));
    return byteSwap64(buf);
}