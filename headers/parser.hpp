#include <cstdint>
#include <optional>

// Aliases
using MessageLength = std::uint8_t;

// Returns the message length, given message type.
std::optional<MessageLength> parseMessageLength(char messageType);