#include "../headers/parser.hpp"

std::optional<Parser::MessageSize> Parser::parseMessageLength(ItchType::Alpha messageType) noexcept {
    switch(messageType) {
        case 'S': return 12;
        case 'R': return 39;
        case 'H': return 25;
        case 'Y': return 20;
        case 'L': return 26;
        case 'V': return 35;
        case 'W': return 12;
        case 'K': return 28;
        case 'J': return 35;
        case 'h': return 21;
        case 'A': return 36;
        case 'F': return 40;
        case 'E': return 31;
        case 'C': return 36;
        case 'X': return 23;
        case 'D': return 19;
        case 'U': return 35;
        case 'P': return 44;
        case 'Q': return 40;
        case 'B': return 19;
        case 'I': return 50;
        case 'O': return 48;
        default: return std::nullopt;
    }
}

std::optional<Parser::ParsedVector> Parser::parseFile(Parser::FilePath filePath,
    const SizeT numberOfExpectedEntries) {
    Parser::ParsedVector itchVector;
    itchVector.reserve(numberOfExpectedEntries);

    int fd = open(filePath, O_RDONLY);
    if (fd == -1) {
        std::perror("Error opening file");
        return std::nullopt;
    }

    struct stat sb;
    if(fstat(fd, &sb) == -1) {
        std::perror("Error getting file size");
        close(fd);
        return std::nullopt;
    }
    SizeT fileSize = sb.st_size;

    void* mappedData = mmap(
        nullptr,
        fileSize,
        PROT_READ,
        MAP_PRIVATE,
        fd,
        0
    );

    if(mappedData == MAP_FAILED) {
        std::perror("Error mapping file.");
        close(fd);
        return std::nullopt;
    }

    std::byte* current_ptr = reinterpret_cast<std::byte*>(mappedData);
    std::byte* end_ptr = current_ptr + fileSize;
    SizeT jumper = 2;

    current_ptr = current_ptr + jumper;
    while(current_ptr < end_ptr) {
        ItchType::Alpha messageType = static_cast<ItchType::Alpha>(*current_ptr);
        std::optional<MessageSize> messageLengthDecode = Parser::parseMessageLength(messageType);
        if(!messageLengthDecode.has_value()) {
            std::perror("Could not parse messageType.");
            close(fd);
            return std::nullopt;
        }
        MessageSize messageLen = messageLengthDecode.value();

        switch (messageType) {
            case 'S':
                itchVector.push_back(ItchStructMapper::mapSystemEventMessage(current_ptr));
            case 'R':
                itchVector.push_back(ItchStructMapper::mapStockDirectory(current_ptr));
            case 'H':
                itchVector.push_back(ItchStructMapper::mapStockTradingAction(current_ptr));
            case 'Y':
                itchVector.push_back(ItchStructMapper::mapRegSHORestriction(current_ptr));
            case 'L':
                itchVector.push_back(ItchStructMapper::mapMarketParticipationPostion(current_ptr));
            case 'V':
                itchVector.push_back(ItchStructMapper::mapMWCBDeclineLevelMessage(current_ptr));
            case 'W':
                itchVector.push_back(ItchStructMapper::mapMWCBStatusMessage(current_ptr));
            case 'K':
                itchVector.push_back(ItchStructMapper::mapQuotingPeriodUpdate(current_ptr));
            case 'J':
                itchVector.push_back(ItchStructMapper::mapLULDAuctionCollar(current_ptr));
            case 'h':
                itchVector.push_back(ItchStructMapper::mapOperationalHalt(current_ptr));
            case 'A':
                itchVector.push_back(ItchStructMapper::mapAddOrderMessage(current_ptr));
            case 'F':
                itchVector.push_back(ItchStructMapper::mapAddOrderMPIDAttributionMessage(current_ptr));
            case 'E':
                itchVector.push_back(ItchStructMapper::mapOrderExecutedMessage(current_ptr));
            case 'C':
                itchVector.push_back(ItchStructMapper::mapOrderExecutedWithPriceMessage(current_ptr));
            case 'X':
                itchVector.push_back(ItchStructMapper::mapOrderCancelMessage(current_ptr));
            case 'D':
                itchVector.push_back(ItchStructMapper::mapOrderDeleteMessage(current_ptr));
            case 'U':
                itchVector.push_back(ItchStructMapper::mapOrderReplaceMessage(current_ptr));
            case 'P':
                itchVector.push_back(ItchStructMapper::mapTradeMessage(current_ptr));
            case 'Q':
                itchVector.push_back(ItchStructMapper::mapCrossTradeMessage(current_ptr));
            case 'B':
                itchVector.push_back(ItchStructMapper::mapBrokenTradeMessage(current_ptr));
            case 'I':
                itchVector.push_back(ItchStructMapper::mapNOIIMessage(current_ptr));
            case 'O':
                itchVector.push_back(ItchStructMapper::mapDLWCRPD(current_ptr));
            default:
                break;
        }

        current_ptr = current_ptr + messageLen + jumper;
    }

    if(munmap(mappedData, fileSize) == -1) {
        std::perror("Error unmapping");
    }
    close(fd);

    return itchVector;
}