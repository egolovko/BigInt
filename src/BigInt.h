#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cassert>

using namespace std;

class AbstractMulter;
class AbstractDivider;

class BigInt {
private:
    int base = 10;
    void str_init(string);
    static AbstractMulter* multer;
    static AbstractDivider* divider;

public:
    int sign = 1;

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
    static BigInt gcd(BigInt, BigInt);
    static AbstractMulter& get_multer();
    static AbstractDivider& get_divider();
    static void set_multer(AbstractMulter*);
    static void set_divider(AbstractDivider*);

    int get_base();
    void set_base(int);

    size_t size();
    void normalize();
    void resize(int);
    vector<int>::iterator begin();
    vector<int>::iterator end();
    BigInt& left_shift(int);
    BigInt& right_shift(int);
    bool even();
    bool odd();

    int& operator[](int i);
    friend ostream& operator<<(ostream&, const BigInt&);
    friend istream& operator>>(istream&, BigInt&);
    friend BigInt operator-(BigInt);
    friend BigInt operator+(BigInt);
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
