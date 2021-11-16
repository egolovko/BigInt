#pragma once
#include <utility>

using namespace std;

class BigInt;

class AbstractDivider {
public:
    virtual pair<BigInt, BigInt> div(BigInt, BigInt) = 0;
};

