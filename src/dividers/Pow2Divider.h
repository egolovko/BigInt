#pragma once
#include <utility>
#include "AbstractDivider.h"

using namespace std;


class BigInt;

// Works good, with 100% accuracy, when need to get only integer part of division
// Check resoursec/long div.png
class Pow2Divider : public AbstractDivider {
public:
    virtual pair<BigInt, BigInt> div(BigInt, BigInt) override;
};
