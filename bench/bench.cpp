#include <iostream>
#include <string>
#include <string_view>
#include <optional>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <chrono>
#include <algorithm>
#include "../headers/types.hpp"
#include "../headers/structs.hpp"
#include "../headers/struct_mapper.hpp"
#include "../headers/parser.hpp"

// Constants
constexpr double tenExpNegativeNine = 1e-9;
constexpr double tenExpThree = 1e3;
constexpr double tenExpSix = 1e6;
constexpr double pointFive = 0.5;
constexpr double pointSevenFive = 0.75;
constexpr double pointNine = 0.9;
constexpr double pointNineNine = 0.99;
constexpr double pointNineNineNine = 0.999;
constexpr std::size_t defaultExpectedEntries = 12012;
constexpr std::string_view expectedNumEntryPrefix = "-n=";

int main(int argc, char* argv[]) {
    // Check Usage
    if((argc < 2) || (argc > 3)) {
        std::cout << "Usage: bench <inputfile> [-n]" << std::endl;;
        return 1;
    }

    size_t numberOfExpectedEntries = defaultExpectedEntries;
    // Parse -n flag, if provided.
    if(argc == 3) {
        std::string_view lastArg(argv[2]);
        const std::string_view expectedEntryNumStr = lastArg.substr(expectedNumEntryPrefix.size());

        try {
            numberOfExpectedEntries = std::stoi(std::string(expectedEntryNumStr));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: '" << expectedEntryNumStr << "' is not a valid integer.\n";
            return 1;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Value '" << expectedEntryNumStr << "' is out of range for an int.\n";
            return 1;
        }

    }
    size_t numberofEntries = 0;
    std::vector<long long> latencies;
    latencies.reserve(numberOfExpectedEntries);
    const char* filePath = argv[1];
    

    // Open Input File.
    int fd = open(filePath, O_RDONLY);
    if (fd == -1) {
        std::perror("Error opening file");
        return 1;
    }

    struct stat sb;
    if(fstat(fd, &sb) == -1) {
        std::perror("Error getting file size");
        close(fd);
        return 1;
    }
    size_t fileSize = sb.st_size;

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
        return 1;
    }

    // Benchmark
    std::cout << "BENCHING MARKING" << std::endl;
    std::byte* current_ptr = reinterpret_cast<std::byte*>(mappedData);
    const std::byte* end_ptr = current_ptr + fileSize;
    const size_t jumper = 2;

    current_ptr = current_ptr + jumper;
    auto wallStart = std::chrono::high_resolution_clock::now();

    while(current_ptr < end_ptr) {
        auto t0 = std::chrono::high_resolution_clock::now();
        ItchType::Alpha messageType = static_cast<ItchType::Alpha>(*current_ptr);
        std::optional<Parser::MessageSize> messageLengthDecode = Parser::parseMessageLength(messageType);
        if(!messageLengthDecode.has_value()) {
            std::perror("Could not parse messageType.");
            close(fd);
            return 1;
        }
        Parser::MessageSize messageLen = messageLengthDecode.value();

        switch (messageType) {
            case 'S':
                (void) ItchStructMapper::mapSystemEventMessage(current_ptr);
                break;
            case 'R':
                (void) ItchStructMapper::mapStockDirectory(current_ptr);
                break;
            case 'H':
                (void) ItchStructMapper::mapStockTradingAction(current_ptr);
                break;
            case 'Y':
                (void) ItchStructMapper::mapRegSHORestriction(current_ptr);
                break;
            case 'L':
                (void) ItchStructMapper::mapMarketParticipationPostion(current_ptr);
                break;
            case 'V':
                (void) ItchStructMapper::mapMWCBDeclineLevelMessage(current_ptr);
                break;
            case 'W':
                (void) ItchStructMapper::mapMWCBStatusMessage(current_ptr);
                break;
            case 'K':
                (void) ItchStructMapper::mapQuotingPeriodUpdate(current_ptr);
                break;
            case 'J':
                (void) ItchStructMapper::mapLULDAuctionCollar(current_ptr);
                break;
            case 'h':
                (void) ItchStructMapper::mapOperationalHalt(current_ptr);
                break;
            case 'A':
                (void) ItchStructMapper::mapAddOrderMessage(current_ptr);
                break;
            case 'F':
                (void) ItchStructMapper::mapAddOrderMPIDAttributionMessage(current_ptr);
                break;
            case 'E':
                (void) ItchStructMapper::mapOrderExecutedMessage(current_ptr);
                break;
            case 'C':
                (void) ItchStructMapper::mapOrderExecutedWithPriceMessage(current_ptr);
                break;
            case 'X':
                (void) ItchStructMapper::mapOrderCancelMessage(current_ptr);
                break;
            case 'D':
                (void) ItchStructMapper::mapOrderDeleteMessage(current_ptr);
                break;
            case 'U':
                (void) ItchStructMapper::mapOrderReplaceMessage(current_ptr);
                break;
            case 'P':
                (void) ItchStructMapper::mapTradeMessage(current_ptr);
                break;
            case 'Q':
                (void) ItchStructMapper::mapCrossTradeMessage(current_ptr);
                break;
            case 'B':
                (void) ItchStructMapper::mapBrokenTradeMessage(current_ptr);
                break;
            case 'I':
                (void) ItchStructMapper::mapNOIIMessage(current_ptr);
                break;
            case 'O':
                (void) ItchStructMapper::mapDLWCRPD(current_ptr);
                break;
            default:
                break;
        }

        numberofEntries = numberofEntries + 1;
        current_ptr = current_ptr + messageLen + jumper;
        auto t1 = std::chrono::high_resolution_clock::now();
        latencies.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count());
    }

    if(munmap(mappedData, fileSize) == -1) {
        std::perror("Error unmapping");
        close(fd);
        return 1;
    }
    close(fd);
    auto wallEnd = std::chrono::high_resolution_clock::now();

    // Calculate Results
    double elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(wallEnd - 
        wallStart).count() * tenExpNegativeNine;
    double throughput = numberofEntries / elapsedTime;

    std::sort(latencies.begin(), latencies.end());
    auto p50  = latencies[numberofEntries * pointFive];
    auto p75  = latencies[numberofEntries * pointSevenFive];
    auto p90  = latencies[numberofEntries * pointNine];
    auto p99  = latencies[numberofEntries * pointNineNine];
    auto p999 = latencies[numberofEntries * pointNineNineNine];

    // Output Results
    std::cout << "============================================" << std::endl;
    std::cout << "  Itch Parser Benchmark  (" << numberofEntries << " ops)" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "  Elapsed:     " << elapsedTime * tenExpThree << " ms" << std::endl;
    std::cout << "  Throughput:  " << throughput / tenExpSix   << " M ops/sec" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "  Latency (per op, including chrono overhead ~10 ns):" << std::endl;
    std::cout << "    p50  : " << p50  << " ns" << std::endl;
    std::cout << "    p75  : " << p75  << " ns" << std::endl;
    std::cout << "    p90  : " << p90  << " ns" << std::endl;
    std::cout << "    p99  : " << p99  << " ns" << std::endl;
    std::cout << "    p99.9: " << p999 << " ns" << std::endl;
    std::cout << "============================================" << std::endl;

    return 0;
}