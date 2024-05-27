//
// Created by evgn on 2024-05-26.
//

#include "numword.h"

namespace evgn {

    // assignment operator
    uint64_t numword::operator= (const uint64_t& num) {
        return getnum();
    }

    const string& numword::words()
    {
        return words(_num);
    }

    const string& numword::words(const uint64_t& num)
    {
        return *_words;
    }


} // evgn