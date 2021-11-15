#include "Pow2Divider.h"
#include "../BigInt.h"

pair<BigInt, int> Pow2Divider::div(BigInt x, BigInt y) {
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
    return {res, 0};
}