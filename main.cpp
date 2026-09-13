#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include "headers/parser.hpp"
#include "headers/struct_mapper.hpp"
#include "headers/structs.hpp"
#include "headers/pretty_printer.hpp"

constexpr std::size_t defaultExpectedEntries = 12012;
constexpr std::string_view expectedNumEntryPrefix = "-n=";

int main(int argc, char* argv[]) {
    // Check for proper usage
    if(argc < 2 || argc > 4) {
        std::cout << "Usage: itchparse <inputfile> [<outputfile>] [-n]" << std::endl;
        return 1;
    }
    
    // Only input file provided.
    if(argc == 2) {        
        const char* filepath = argv[1];

        // Parse Data and Print.
        std::cout << "ITCH PARSER" << std::endl;
        std::vector<ItchStruct::ItchData> parsedData = Parser::parseFile(filepath, defaultExpectedEntries).value();
        for(auto &itchData: parsedData) {
            ItchPrinter::printItchData(itchData);
        }
    } 
    
    // Input File + Output File or Expected Num of Entries.
    else if (argc == 3) {
        std::string_view lastArg(argv[2]);

        // Expected number of entries provided.
        if(lastArg.rfind(expectedNumEntryPrefix, 0) == 0) {
            const char* filepath = argv[1];
            const std::string_view expectedEntryNumStr = lastArg.substr(expectedNumEntryPrefix.size());
            std::size_t expectedEntries;

            // Parse/Extract value from -n expected num of entries flag.
            try {
                expectedEntries = std::stoi(std::string(expectedEntryNumStr));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: '" << expectedEntryNumStr << "' is not a valid integer.\n";
                return 1;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Value '" << expectedEntryNumStr << "' is out of range for an int.\n";
                return 1;
            }

            // Parse Data and Print.
            std::cout << "ITCH PARSER" << std::endl;
            std::vector<ItchStruct::ItchData> parsedData = Parser::parseFile(filepath, expectedEntries).value();
            for(auto &itchData: parsedData) {
                ItchPrinter::printItchData(itchData);
            }
        }

        // Output File path provided.
        else {
            const char* inputFilePath = argv[1];
            const char* outputFilePath = argv[2];
            std::ofstream outFile;
            std::streambuf* initialOutputBuf = nullptr;

            // Open outputfile and swap buffer with std::cout
            outFile.open(outputFilePath, std::ios::out | std::ios::trunc);
            if(!outFile) {
                std::cerr << "Failed to open output file: " << argv[2] << std::endl;
                return 1;
            }
            initialOutputBuf = std::cout.rdbuf(outFile.rdbuf());

            // Parse Data and Print.
            std::cout << "ITCH PARSER" << std::endl;
            std::vector<ItchStruct::ItchData> parsedData = Parser::parseFile(inputFilePath, defaultExpectedEntries).value();
            for(auto &itchData: parsedData) {
                ItchPrinter::printItchData(itchData);
            }

            // Undo Buffer Swap
            if(initialOutputBuf) {
                std::cout.rdbuf(initialOutputBuf);
            }
        }
    } 
    
    // Input File + Output File + Expected Num of Entries Flag Provided.
    else {
        const char* inputFilePath = argv[1];
        const char* outputFilePath = argv[2];
        std::ofstream outFile;
        std::streambuf* initialOutputBuf = nullptr;
        std::string_view lastArg(argv[3]);
        const std::string_view expectedEntryNumStr = lastArg.substr(expectedNumEntryPrefix.size());
        std::size_t expectedEntries;

        // Parse/Extract value from -n expected num of entries flag.
        try {
            expectedEntries = std::stoi(std::string(expectedEntryNumStr));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: '" << expectedEntryNumStr << "' is not a valid integer.\n";
            return 1;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Value '" << expectedEntryNumStr << "' is out of range for an int.\n";
            return 1;
        }

        // Open outputfile and swap buffer with std::cout
        outFile.open(outputFilePath, std::ios::out | std::ios::trunc);
        if(!outFile) {
            std::cerr << "Failed to open output file: " << argv[2] << std::endl;
            return 1;
        }
        initialOutputBuf = std::cout.rdbuf(outFile.rdbuf());

        // Parse Data and Print.
        std::cout << "ITCH PARSER" << std::endl;
        std::vector<ItchStruct::ItchData> parsedData = Parser::parseFile(inputFilePath, expectedEntries).value();
        for(auto &itchData: parsedData) {
            ItchPrinter::printItchData(itchData);
        }

        // Undo Buffer Swap
        if(initialOutputBuf) {
            std::cout.rdbuf(initialOutputBuf);
        }
    }
    
    return 0; 
}