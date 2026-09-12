#pragma once
#include <iostream>
#include <string>
#include "structs.hpp"

namespace ItchPrinter {
    static const std::string dashes = "----------------------------------";

    // Helper for std::visit with multiple lambdas
    template<class... Ts>
    struct overloaded : Ts... {
        using Ts::operator()...;
    };
    template<class... Ts>
    overloaded(Ts...) -> overloaded<Ts...>;

    void printItchData(const ItchStruct::ItchData& data) noexcept;
}