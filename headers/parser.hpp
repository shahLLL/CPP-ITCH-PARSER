#pragma once
#include <optional>
#include <vector>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "types.hpp"
#include "structs.hpp"
#include "struct_mapper.hpp"

namespace Parser {
    // Aliases
    using FilePath = const char*;
    using SizeT = const std::size_t;
    using ParsedVector = std::vector<ItchStruct::ItchData>;
    using MessageSize = std::uint8_t;

    // Returns the message length, given message type.
    std::optional<MessageSize> parseMessageLength(ItchType::Alpha messageType) noexcept;
    // Returns a vector of ItchData type given a file with NASDAQ ITCH data.
    std::optional<ParsedVector> parseFile(FilePath filePath,
        SizeT expectedNumberOfEntry);
}