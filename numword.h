//
// Created by evgn on 2024-05-26.
//

#ifndef NUMWORDCPP_NUMWORD_H
#define NUMWORDCPP_NUMWORD_H

#include <cstdint>
#include <string>

namespace evgn {
    using std::string;

    class numword {
        uint64_t _num{};
    public:
        numword(const uint64_t& n = 0) : _num(n) {}; // assignment ctor
        numword(const numword& nw) : _num(nw._num) {} // copy ctor
        const string& operator() (const uint64_t& num) { return {}; };
        uint64_t getnum() const { return _num; }
    };

} // evgn

#endif //NUMWORDCPP_NUMWORD_H
