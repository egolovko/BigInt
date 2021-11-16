#pragma once
#include <utility>
#include "AbstractDivider.h"

class BigInt;
class NewtonRaphsonDivider;


// Combination of Pow2 for int part and NewtonRaphson for real part dividers
class CombinedP2NRDivider : public AbstractDivider {
private:
    static NewtonRaphsonDivider* aprox_divider;
    pair<BigInt, BigInt> calc_int_part(BigInt, BigInt);

public:
    virtual pair<BigInt, BigInt> div(BigInt, BigInt) override;
};
