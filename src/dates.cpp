#include "dates.hpp"

namespace {
    constexpr std::string january[31] = {
        "testjan"
    };
    constexpr std::string february[29] = {
    };
    constexpr std::string march[31] = {
    };
    constexpr std::string april[30] = {
    };
    constexpr std::string may[31] = {
    };
    constexpr std::string june[30] = {
    };
    constexpr std::string july[31] = {
    };
    constexpr std::string august[31] = {
    };
    constexpr std::string september[30] = {
    };
    constexpr std::string october[31] = {
    };
    constexpr std::string november[30] = {
        [23] = "self",
    };
    constexpr std::string december[31] = {
    };
}

const Months months {
    .jan = january,
    .feb = february,
    .mar = march,
    .apr = april,
    .may = may,
    .jun = june,
    .jul = july,
    .aug = august,
    .sep = september,
    .oct = october,
    .nov = november,
    .dec = december
};
