#pragma once
#include <utility>
#include "AbstractDivider.h"

using namespace std;

class BigInt;
class AbstractMulter;

// Newton-Raphson division
class NewtonRaphsonDivider : public AbstractDivider {
private:
    static const int COUNT_OF_ITERATIONS = 5;
    static AbstractMulter* multer;

public:
    virtual pair<BigInt, int> div(BigInt, BigInt) override;
};
