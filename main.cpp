#include <iostream>
#include <cstdint>
#include "numword.h"
#include <format>

// format-style print()
constexpr void print(const std::string_view str_fmt, auto&&... args) {
    fputs(std::vformat(str_fmt, std::make_format_args(args...)).c_str(), stdout);
}

int main() {
    evgn::numword nw{};
    uint64_t n{};

//    print("n is {}, {}\n", nw.getnum(), nw);

//    nw = 3; print("n is {}, {}\n", nw.getnum(), nw);
//    nw = 47; print("n is {}, {}\n", nw.getnum(), nw);
//    nw = 73; print("n is {}, {}\n", nw.getnum(), nw);
//    nw = 1492; print("n is {}, {}\n", nw.getnum(), nw);
//    nw = 10012; print("n is {}, {}\n", nw.getnum(), nw);
//
//    n = 100073; print("n is {}, {}\n", n, evgn::numword{n});
//    n = 1000000; print("n is {}, {}\n", n, evgn::numword{n});
//    n = 1000000001; print("n is {}, {}\n", n, evgn::numword{n});
//    n = 123000000000; print("n is {}, {}\n", n, evgn::numword{n});
//
//    n = 474142398123; print("n is {}, {}\n", n, nw(n));
//    n = 1474142398007; print("n is {}, {}\n", n, nw(n));
//    n = 999000000000000; print("n is {}, {}\n", n, nw(n));
//    n = 999999999999999999; print("n is {}, {}\n", n, nw(n));
//    n = 1000000000000000000; print("n is {}, {}\n", n, nw(n));
}
