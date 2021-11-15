#include "BasicMulter.h"
#include "../BigInt.h"


BigInt BasicMulter::_mult(BigInt& b1, BigInt& b2) {
    if (b1.get_base() != b2.get_base())
        throw "Different bases";

    BigInt b3;
    b3.set_base(b1.get_base());

    b3.resize(b1.size() + b2.size());

    for (int i = 0; i < (int)b1.size(); ++i) {
        for (int j = 0, carry = 0; j < (int)b2.size() || carry; ++j) {
            long long curr = b3[i + j] + b1[i] * (j < (int) b2.size() ? b2[j] : 0) + carry;
            b3[i + j] = (int) (curr % b3.get_base());
            carry = (int) (curr / b3.get_base());
        }
    }

    b3.normalize();

    return b3;
}


BigInt BasicMulter::mult(BigInt& b1, BigInt& b2) {
    BigInt res = _mult(b1, b2);
    res.sign = b1.sign * b2.sign;
    return res;
}