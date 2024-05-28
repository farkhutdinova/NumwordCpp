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
        if (num > _max) {
            appenderror();
            return *_words;
        }

        if (num < 10) {
            appenddigits(num);
            return *_words;
        }

        auto rest = num;
        if (rest > _quadrillion) {
            auto quadrillions = rest / _quadrillion;
            appendthousands(quadrillions);
            appendword(_bigs[5]);
            rest %= _quadrillion;
        }

        if (rest > _trillion) {
            auto trillions = rest / _trillion;
            appendthousands(trillions);
            appendword(_bigs[4]);
            rest %= _trillion;
        }

        if (rest > _billion) {
            auto billions = rest / _billion;
            appendthousands(billions);
            appendword(_bigs[3]);
            rest %= _billion;
        }

        if (rest >= _million) {
            auto millions = rest / _million;
            appendthousands(millions);
            appendword(_bigs[2]);
            rest %= _million;
        }

        if (rest >= _thousand) appendthousands(rest);
        else if (rest >= _hundred) appendhundreds(rest);
        else if (rest > 0) appendtens(rest);

        return *_words;
    }

    void numword::appenderror() {
        _words->clear();
        _words->append("error");
    }

    void numword::appendthousands(const uint64_t& num)
    {
        auto rest = num;
        if (rest >= _thousand) {
            auto h = rest / _thousand;
            appendhundreds(h);
            appendword(_bigs[1]);
            rest %= _thousand;
        }
        if (rest > 20) {
            auto t = rest / 10;
            appendword(_tens[t]);
            rest %= 10;
            if (rest > 0) appendword(_numbers[rest]);
            return;
        }
        if (rest > 9) appendword(_teens[rest % 10]);
        else appendword(_numbers[rest]);
    }

    void numword::appendhundreds(const uint64_t& num)
    {
        auto rest = num;
        if (rest >= _hundred) {
            auto t = rest / _hundred;
            appendword(_numbers[t]);
            appendword(_bigs[0]);
            rest %= _hundred;
            if (rest > 0) appendtens(rest);
        }
        else appendtens(rest);
    }

    void numword::appendtens(const uint64_t& num)
    {
        auto rest = num;
        if (rest > 10) {
            auto t = rest / 10;
            appendword(_tens[t]);
            rest %= 10;
            if (rest > 0) appendword(_numbers[rest]);
            return;
        }
        if (rest > 9) appendword(_teens[rest % 10]);
        else appendword(_numbers[rest]);
    }

    void numword::appenddigits(const uint64_t& num)
    {
        appendword(_numbers[num]);
    }

    void numword::appendword(const string_view& s) {
        _words->append(s);
        _words->append(" ");
    }
} // evgn