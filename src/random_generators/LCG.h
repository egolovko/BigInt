#pragma once

#include "../BigInt.h"

class BigInt;

using namespace std;


class LCG {
private:
    BigInt x;
    BigInt a;
    BigInt c;
    BigInt lower_bound;
    BigInt upper_bound;
    BigInt _upper_bound;

public:
    LCG(BigInt x);
    BigInt next_int();

    void set_x(BigInt x);
    void set_a(BigInt a);
    void set_c(BigInt c);
    void set_lower_bound(BigInt lb);
    void set_upper_bound(BigInt ub);

    BigInt& get_x();
    BigInt& get_a();
    BigInt& get_c();
    BigInt& get_lower_bound();
    BigInt& get_upper_bound();

};
