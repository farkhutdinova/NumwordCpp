//
// Created by evgn on 2024-05-26.
//

#ifndef NUMWORDCPP_NUMWORD_H
#define NUMWORDCPP_NUMWORD_H

#include <cstdint>
#include <string>
#include <memory>

namespace evgn {
    using std::string;

    class numword {
        uint64_t _num{};
        std::unique_ptr<string> _words = std::make_unique<string>(string{});
    public:
        numword(const uint64_t& n = 0) : _num(n) {};
        numword(const numword& nw) : _num(nw._num) {}
        const string& operator() (const uint64_t& num) { return "words"; };
        uint64_t getnum() const { return _num; }
        uint64_t operator= (const uint64_t& num);
        const string& words();
        const string& words(const uint64_t& num);
    };

} // evgn

#endif //NUMWORDCPP_NUMWORD_H
