#pragma once


// Quadratic Frobenius test
class QFT {
private:
    static long double EPS;
    static bool odd(int a);
    static int jacobi(int a, int b);
    static bool _check_for_negative_one(int n);
    static bool _check_for_positive_prime(int n, int c);

public:
    static int N;
    static bool is_prime(int n);
};
