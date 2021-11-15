#include "QFT.h"
#include <cassert>
#include <algorithm>
#include <complex>
#include "MRT.h"
#include "../BigInt.h"

using namespace std;

int QFT::N = 10;
long double QFT::EPS = 1e-2;


int MOD(int a, int p) {
    return ((a % p) + p) % p;
}


bool QFT::odd(int n) {
    return n & 1;
}


int QFT::jacobi(int a, int b) {
    int g;
    assert(odd(b));

    if (a >= b) a %= b;
    if (a == 0) return 0;
    if (a == 1) return 1;
    if (a < 0)
        if ((b - 1) / 2 % 2 == 0)
            return jacobi(-a, b);
        else
            return -jacobi(-a, b);

    if (a % 2 == 0)
        if (((b * b - 1) /8 ) % 2 == 0)
            return +jacobi(a / 2, b);
        else
            return -jacobi(a / 2, b);

    g = __gcd(a, b);
    assert( odd(a) );

    if (g == a)
        return 0;
    else if (g != 1)
        return jacobi(g, b) * jacobi(a / g, b);
    else if (((a - 1) * (b - 1) / 4) % 2 == 0)
        return +jacobi(b, a);
    else
        return -jacobi(b, a);
}


bool QFT::_check_for_negative_one(int n) {
    complex<long long> z(2, 1);
    complex<long long> z_n = pow(z, n);
    complex<long long> z_conj = conj(z);
    complex<long long> z_n_mod_n(MOD(z_n.real(), n), MOD(z_n.imag(), n));
    complex<long long> z_conj_mod_n(MOD(z_conj.real(), n), MOD(z_conj.imag(), n));

    return (z_n_mod_n.real() == z_conj_mod_n.real()) && (z_n_mod_n.imag() == z_conj_mod_n.imag());
}


bool QFT::_check_for_positive_prime(int n, int c) {
    // TO DO
    // Rewrite algorithm from real to integer numbers

    long double z;
    if (c <= 2)
        z = 2 + sqrt(c);
    else
        z = 1 + sqrt(c);

    long double zn = pow(z, n);
    long double res = zn - 1 - sqrt(c);

    while ( (res - (n+EPS)) > 0) {
        res -= n;
        cout << res << endl;
    }

    if (res < -EPS)
        res += n;

    if ( fabs(res) < EPS || fabs((long double)n - res) < EPS )
        return true;
    return false;
}


bool QFT::is_prime(int n) {

    if (n !=2 && n & 0)
        return false;

    if (n < 2)
        return false;

    if (n < 4)
        return true;

    int c = -999999;

    if (jacobi(-1, n) == -1) {
        c = -1;
    } else {
        int prime_index = 0;
        int number_value = 2;

        while (prime_index < N) {

            if (MRT::is_prime({number_value}, 10)) {
                ++prime_index;
                if (jacobi(number_value, n) == -1) {
                    c = number_value;
                    break;
                }
            }

            ++number_value;
        }
    }

    if (c < -1)
        return false;

    if (c == -1)
        return _check_for_negative_one(n);

    return _check_for_positive_prime(n, c);
}