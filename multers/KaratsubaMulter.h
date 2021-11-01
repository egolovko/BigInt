#pragma once
#include <vector>
#include <algorithm>
#include "AbstractMulter.h"

class BigInt;
class AbstractMulter;
class BasicMulter;


class KaratsubaMulter : public AbstractMulter {
private:
    static BasicMulter* basic_multer;

    void split_at_begin(BigInt&, int, BigInt&, BigInt&);
    void split_at_end(BigInt&, int, BigInt&, BigInt&);
    BigInt& big_pow_10(BigInt&, int);

public:
    virtual BigInt mult(BigInt&, BigInt&) override;
};
