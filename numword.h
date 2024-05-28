//
// Created by evgn on 2024-05-26.
//

#ifndef NUMWORDCPP_NUMWORD_H
#define NUMWORDCPP_NUMWORD_H

#include <cstdint>
#include <string>
#include <memory>
#include <string_view>

namespace evgn {
    using std::string;
    using std::string_view;

    constexpr string_view _numbers[]{ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    constexpr string_view _teens[]{ "ten", "eleven", "tvelve", "thirteen", "fourteen", "fivteen", "sixteen", "seventeen", "eightteen", "nineteen" };

    constexpr string_view _tens[]{ "", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    constexpr string_view _bigs[]{ "hundred", "thousand", "million", "billion", "trillion", "quadrillion" };

    constexpr uint64_t _max = 999999999999999999;

    constexpr uint64_t _quadrillion = 1000000000000000;

    constexpr uint64_t _trillion = 1000000000000;

    constexpr uint64_t _billion = 1000000000;

    constexpr uint64_t _million = 1000000;

    constexpr uint64_t _thousand = 1000;

    constexpr uint64_t _hundred = 100;

    class numword {
        uint64_t _num{};
        std::unique_ptr<string> _words = std::make_unique<string>(string{});
        void appendword(const string_view& s);
        void appenderror();
        void appendthousands(const uint64_t& num);
    public:
        numword(const uint64_t& n = 0) : _num(n) {};
        numword(const numword& nw) : _num(nw._num) {}
        const string& operator() (const uint64_t& num) { return "words"; };
        uint64_t getnum() const { return _num; }
        uint64_t operator= (const uint64_t& num);
        const string& words();
        const string& words(const uint64_t& num);
        void setnum(const uint64_t& n) { _num = n; };
    };

} // evgn

#endif //NUMWORDCPP_NUMWORD_H
