#include "NewtonRaphsonDivider.h"
#include "../BigInt.h"
#include "../multers/AbstractMulter.h"
#include "../multers/ShonhageMulter.h"

AbstractMulter* NewtonRaphsonDivider::multer = new ShonhageMulter;


pair<BigInt, int> NewtonRaphsonDivider::div(BigInt a, BigInt b) {
    BigInt x_numerator = {1};
    BigInt x_denominator = {10};
    int e = 1;

    for (int i = 0; i < COUNT_OF_ITERATIONS; ++i) {
        x_numerator = BigInt(2) * x_denominator * x_numerator - b * x_numerator * x_numerator;
        x_denominator = x_denominator * x_denominator;
        e *= 2;
    }

    x_numerator = x_numerator * a;
    return {x_numerator, e};
}