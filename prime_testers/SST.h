#pragma once

class LCG;
class BigInt;


// Solovay–Strassen primality test
class SST {
private:
    static LCG* generator;
    static BigInt jacobi(BigInt a, BigInt b);

public:
    static bool is_prime(BigInt n, int k);
};

