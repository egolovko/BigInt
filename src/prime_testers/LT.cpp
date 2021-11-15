#include "LT.h"
#include "../BigInt.h"
#include "../random_generators/LCG.h"


LCG* LT::generator = new LCG(BigInt(42));


bool LT::is_prime(BigInt p, int k) {
    if (p != BigInt(2) && p.even())
        return false;

    if (p < BigInt(2))
        return false;

    if (p < BigInt(4))
        return true;


    generator->set_lower_bound({2});
    generator->set_upper_bound({p-1});

    BigInt deg = (p - BigInt(1)) / BigInt(2);

    for (int i = 0; i < k; ++i) {
        BigInt a = generator->next_int();
        BigInt res = BigInt::binpow(a, deg, p);

        // res != BigInt(1) || res != (p - BigInt(1)) => return false; Do not work. Why?????
        if (res == BigInt(1) || res == (p - BigInt(1)))
            continue;
        else
            return false;
    }

    return true;
}