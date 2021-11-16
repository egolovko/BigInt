#pragma once
#include <utility>
#include "AbstractDivider.h"

using namespace std;

class BigInt;
class AbstractMulter;

// Newton-Raphson division
class NewtonRaphsonDivider : public AbstractDivider {
private:
    static AbstractMulter* multer;

public:
    static const int COUNT_OF_ITERATIONS = 5;
    virtual pair<BigInt, BigInt> div(BigInt, BigInt) override;
};
