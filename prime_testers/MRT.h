#pragma once

class BigInt;
class LCG;

// Miller–Rabin primality test
class MRT {
private:
    static LCG* generator;
    static bool _test(BigInt&, BigInt&);

public:
    static bool is_prime(BigInt n, int k = 50);
};

