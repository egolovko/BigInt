#include "Toom3Multer.h"
#include <iostream>
#include <algorithm>
#include "../BigInt.h"
#include "BasicMulter.h"

using namespace std;


BasicMulter* Toom3Multer::multer = new BasicMulter;


BigInt Toom3Multer::_mult(BigInt& m, BigInt& n) {

    if (m.size() < 3 || n.size() < 3) {
        return multer->mult(m, n);
    }

    if (n.get_base() != m.get_base())
        throw "Invalid bases";

    int b = n.get_base();
    int max_size = max(m.size(), n.size());
    while (max_size % 3 != 0) {++max_size;}
    int part_size = max_size / 3;

    m.resize(max_size);
    n.resize(max_size);

    BigInt m0(m.begin(), m.begin() + part_size, b, m.sign);
    BigInt m1(m.begin() + part_size, m.begin() + 2*part_size, b, m.sign);
    BigInt m2(m.begin() + 2*part_size, m.begin() + 3*part_size, b, m.sign);

    BigInt n0(n.begin(), n.begin() + part_size, b, n.sign);
    BigInt n1(n.begin() + part_size, n.begin() + 2*part_size, b, n.sign);
    BigInt n2(n.begin() + 2*part_size, n.begin() + 3*part_size, b, n.sign);

    m0.normalize();
    m1.normalize();
    m2.normalize();
    n0.normalize();
    n1.normalize();
    n2.normalize();

    BigInt pp0 = m0;        // p(positive 0) = p(0) - pp0
    BigInt pp1 = m0 + m1 + m2;
    BigInt pn1 = m0 - m1 + m2;
    BigInt pn2 = m0 - 2 * m1 + 4 * m2;
    BigInt pinf = m2;

    BigInt qp0 = n0;
    BigInt qp1 = n0 + n1 + n2;
    BigInt qn1 = n0 - n1 + n2;
    BigInt qn2 = n0 - n1 * 2 + n2 * 4;
    BigInt qinf = n2;

    BigInt rp0 = mult(pp0, qp0);
    BigInt rp1 = mult(pp1, qp1);
    BigInt rn1 = mult(pn1, qn1);
    BigInt rn2 = mult(pn2, qn2);
    BigInt rinf = mult(pinf, qinf);

    BigInt r0 = rp0;
    BigInt r4 = rinf;
    BigInt r3 = (rn2 - rp1) / 3;
    BigInt r1 = (rp1 - rn1) / 2;
    BigInt r2 = rn1 - rp0;
    r3 = (r2 - r3) / 2 + rinf * 2;
    r2 = r2 + r1 - r4;
    r1 = r1 - r3;

    return r0 +
            r1.left_shift(part_size) +
            r2.left_shift(part_size*2) +
            r3.left_shift(part_size*3) +
            r4.left_shift(part_size*4);
}


BigInt Toom3Multer::mult(BigInt& b1, BigInt& b2) {
    BigInt res = _mult(b1, b2);
    res.sign = b1.sign * b2.sign;
    return res;
}