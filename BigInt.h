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
    int base = 1e1;
    void str_init(string);

public:
    static AbstractMulter* multer;
    vector<int> numbers;

    BigInt() = default;
    BigInt(string);
    BigInt(const BigInt&);

    BigInt(long long);
    int get_base();

    void set_base(int);
    size_t size();
    void normalize();
    void resize(int);
    int& operator[](int i);
    friend ostream& operator<<(ostream&, const BigInt&);
    friend istream& operator>>(istream&, BigInt&);
    friend BigInt operator+(BigInt&, BigInt&);
    friend BigInt operator-(BigInt&, BigInt&);
    friend BigInt operator*(BigInt&, BigInt&);
};
