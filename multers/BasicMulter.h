#pragma once
#include "AbstractMulter.h"

class BigInt;

class BasicMulter : public AbstractMulter {
public:
    BasicMulter() = default;
    BasicMulter(const BasicMulter&) = default;

    virtual BigInt mult(BigInt&, BigInt&) override;
};
