#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cassert>

using namespace std;


class BigInt {
private:
    int base = 1e1;
    vector<int> numbers;

    void str_init(string);
public:
    BigInt() = default;
    BigInt(string);
    BigInt(const BigInt&);
    BigInt(long long);
    size_t size();
    friend ostream& operator<<(ostream&, const BigInt&);
    friend istream& operator>>(istream&, BigInt&);
    friend BigInt operator+(BigInt&, BigInt&);
    friend BigInt operator-(BigInt&, BigInt&);
};
