#pragma once

class BigInt;

class AbstractMulter {
public:
    virtual BigInt mult(BigInt&, BigInt&) = 0;
};

