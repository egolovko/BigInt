#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cassert>

using namespace std;

class AbstractMulter;

class BigInt {
private:
    int base = 10;
    void str_init(string);
public:

    int sign = 1;
    static AbstractMulter* multer;

    vector<int> numbers;

    BigInt() = default;
    BigInt(string);
    BigInt(const BigInt&);
    BigInt(vector<int>::iterator, vector<int>::iterator, int, int);
    BigInt(long long);

    static BigInt add(BigInt, BigInt);
    static BigInt sub(BigInt, BigInt);
    static BigInt binpow(BigInt, int);
    static BigInt binpow(BigInt, int, BigInt);
    static BigInt binpow(BigInt, BigInt);
    static BigInt binpow(BigInt, BigInt, BigInt);

    int get_base();
    void set_base(int);

    size_t size();
    void normalize();
    void resize(int);
    int& operator[](int i);
    vector<int>::iterator begin();
    vector<int>::iterator end();
    BigInt& left_shift(int);
    BigInt& right_shift(int);
    bool even();
    bool odd();

    friend ostream& operator<<(ostream&, const BigInt&);
    friend istream& operator>>(istream&, BigInt&);
    friend bool operator==(BigInt, BigInt);
    friend bool operator!=(BigInt, BigInt);
    friend bool operator>(BigInt, BigInt);
    friend bool operator<(BigInt, BigInt);
    friend bool operator>=(BigInt, BigInt);
    friend bool operator<=(BigInt, BigInt);
    friend BigInt operator+(BigInt, BigInt);
    friend BigInt operator-(BigInt, BigInt);
    friend BigInt operator*(BigInt, int);
    friend BigInt operator*(int, BigInt);
    friend BigInt operator*(BigInt, BigInt);
    friend BigInt operator/(BigInt, int);
    friend BigInt operator/(BigInt, BigInt);
    friend BigInt operator%(BigInt, BigInt);
};
