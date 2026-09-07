#include <optional>
#include "types.hpp"

namespace Parser {
    // Returns the message length, given message type.
    std::optional<ItchType::UnsignedInt8> parseMessageLength(ItchType::Alpha messageType) noexcept;
}