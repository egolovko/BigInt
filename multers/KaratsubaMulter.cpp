#include "KaratsubaMulter.h"
#include "BasicMulter.h"
#include "../BigInt.h"
#include <iostream>


BasicMulter* KaratsubaMulter::basic_multer = new BasicMulter;


void KaratsubaMulter::split_at_begin(BigInt& b, int m, BigInt& b1, BigInt& b2) {
    b2.numbers.assign(b.numbers.end()-m, b.numbers.end());
    b1.numbers.assign(b.numbers.begin(), b.numbers.end()-m);
}


void KaratsubaMulter::split_at_end(BigInt& b, int m, BigInt& b1, BigInt& b2) {
    b2.numbers.assign(b.numbers.begin(), b.numbers.begin()+m);
    b1.numbers.assign(b.numbers.begin()+m, b.numbers.end());
}


BigInt& KaratsubaMulter::big_pow_10(BigInt& b, int deg) {
    b.normalize();

    int n = b.size();


    for (int i = n; i < n+deg; ++i)
        b.numbers.push_back(0);


    for (int i = n+deg-1; i >= deg; --i) {
        b.numbers[i] = b.numbers[i-deg];
    }

    for (int i = 0; i < deg; ++i) {
        b.numbers[i] = 0;
    }

    return b;
}


BigInt KaratsubaMulter::mult(BigInt& b1, BigInt& b2) {
    if (b1.size() == 1 || b2.size() == 1) {
        return KaratsubaMulter::basic_multer->mult(b1, b2);
    }

    int m = min(b1.size(), b2.size()) / 2;
    int floor_m = (int) m;
    int ceil_m = (int)(m + 0.5);

    BigInt high1, low1;
    BigInt high2, low2;

    split_at_end(b1, m, high1, low1);
    split_at_end(b2, m, high2, low2);

    BigInt sum1 = low1 + high1;
    BigInt sum2 = low2 + high2;

    BigInt z0 = mult(low1, low2);
    BigInt z1 = mult(sum1, sum2);
    BigInt z2 = mult(high1, high2);

    BigInt temp1 = z1 - z2;
    BigInt temp2 = temp1 - z0;
    BigInt s1 = big_pow_10(z2, m*2);
    BigInt s2 = big_pow_10(temp2, m);
    BigInt s3 = s1 + s2;
    BigInt s4 = s3 + z0;

    return s4;
}


