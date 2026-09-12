#include <iostream>
#include <fstream>
#include "headers/parser.hpp"
#include "headers/struct_mapper.hpp"
#include "headers/structs.hpp"
#include "headers/pretty_printer.hpp"

void printUsage() {
    std::cout << "Usage: itchparse <inputfile> [<outputfile>]" << std::endl;
}

int main(int argc, char* argv[]) {
    if(argc < 2 || argc > 3) {
        printUsage();
        return 1;
    }
    
    if(argc == 2) {
        std::cout << "ITCH PARSER" << std::endl;
        const char* filepath = argv[1];
        std::vector<ItchStruct::ItchData> parsedData = Parser::parseFile(filepath, 12012).value();
        for(auto &itchData: parsedData) {
            ItchPrinter::printItchData(itchData);
        }
    } else {
        const char* inputFilePath = argv[1];
        const char* outputFilePath = argv[2];
        std::ofstream outFile;
        std::streambuf* initialOutputBuf = nullptr;

        outFile.open(outputFilePath, std::ios::out | std::ios::trunc);
        if(!outFile) {
            std::cerr << "Failed to open output file: " << argv[2] << std::endl;
            return 1;
        }
        initialOutputBuf = std::cout.rdbuf(outFile.rdbuf());

        std::cout << "ITCH PARSER" << std::endl;
        std::vector<ItchStruct::ItchData> parsedData = Parser::parseFile(inputFilePath, 12012).value();
        for(auto &itchData: parsedData) {
            ItchPrinter::printItchData(itchData);
        }

        if(initialOutputBuf) {
            std::cout.rdbuf(initialOutputBuf);
        }

    }
    
    return 0; 
}