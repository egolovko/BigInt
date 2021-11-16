#include "CombinedP2NRDivider.h"
#include <cassert>
#include "../BigInt.h"
#include "NewtonRaphsonDivider.h"


NewtonRaphsonDivider* CombinedP2NRDivider::aprox_divider = new NewtonRaphsonDivider;


pair<BigInt, BigInt> CombinedP2NRDivider::calc_int_part(BigInt x, BigInt y) {
    BigInt res("0"), z("1");
    int k = 0;

    while (!(y > x))
    {
        y = y + y;
        z = z + z;
        ++k;
    }
    while (k)
    {
        y = y / 2;
        z = z / 2;
        --k;
        while (!(y > x))
        {
            x = x - y;
            res = res + z;
        }
    }

    res.sign = x.sign * y.sign;
    return {res, x};
}


pair<BigInt, BigInt> CombinedP2NRDivider::div(BigInt x, BigInt y) {
    // x/y = [x/y] + {x/y} = [x/y].{x/y}
    // {x/y} = (x - [x/y]) / y

    //  int_part, mod
    pair<BigInt, BigInt> res1 = calc_int_part(x, y);
    pair<BigInt, BigInt> res2 = aprox_divider->div(res1.second, y);
    assert(res2.first == BigInt(0));
    return {res1.first, res2.second};
}