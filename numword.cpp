//
// Created by evgn on 2024-05-26.
//

#include "numword.h"

namespace evgn {

    // assignment operator
    uint64_t numword::operator= (const uint64_t& num) {
        setnum(num);
        return getnum();
    }

    const string& numword::words()
    {
        return words(_num);
    }

    const string& numword::words(const uint64_t& num)
    {
        if (num / 10 < 1) appendword(_numbers[num]);
        else {

        }

        return *_words;
    }

    void numword::appendword(const string_view& s) {
        _words->append(s);
    }
} // evgn