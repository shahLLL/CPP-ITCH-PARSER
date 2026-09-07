#include <optional>
#include "types.hpp"

namespace Parser {
    // Returns the message length, given message type.
    std::optional<UnsignedInt8> parseMessageLength(char messageType) noexcept;
}