#pragma once
#include "AbstractMulter.h"

class BigInt;
class BasicMulter;

class Toom3Multer : public AbstractMulter{
private:
    static BasicMulter* multer;
    const int K = 3;
    BigInt _mult(BigInt&, BigInt&);

public:
    virtual BigInt mult(BigInt&, BigInt&) override;
};