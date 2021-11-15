#include "MRT.h"
#include "../BigInt.h"
#include "../random_generators/LCG.h"



LCG* MRT::generator = new LCG(42);


bool MRT::_test(BigInt& d, BigInt& n) {
    BigInt a(generator->next_int());
    BigInt x = BigInt::binpow(a, d, n);


    if (x == BigInt(1) || x == n-1)
        return true;

    while (d != n-1) {
        x = (x * x) % n;
        d = d * BigInt(2);

        if (x == BigInt(1)) return false;
        if (x == n-1) return true;
    }
    return false;
}


bool MRT::is_prime(BigInt n, int k) {
    if (n != BigInt(2) && n.even())
        return false;

    if (n <= BigInt(1) || n == BigInt(4))
        return false;

    if (n < BigInt(4))
        return true;

    generator->set_lower_bound(BigInt(2));
    generator->set_upper_bound(BigInt(n-2));

    BigInt d(n-1);
    while (d.even()) // d % 2 == 0
        d = d / BigInt(2);

    for (int i = 0; i < k; ++i) {
        if (!_test(d, n))
            return false;
    }

    return true;
}