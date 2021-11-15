#pragma once

class BigInt;
class LCG;

// Lehmann`s primality test
class LT {
private:
    static LCG* generator;
    static bool _test();

public:
    static bool is_prime(BigInt, int);
};
