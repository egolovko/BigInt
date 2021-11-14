#include "LLT.h"
#include "../BigInt.h"

bool LLT::test(int p) {
    int k = 1;
    BigInt S(4);
    BigInt M = BigInt::binpow(BigInt(2), p) - BigInt(1);

    while (k != p - 1) {
        S = ((S * S) - BigInt(2)) % M;
        ++k;
    }

    if (S == BigInt(0))
        return true;
    return false;
}