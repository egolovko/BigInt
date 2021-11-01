#pragma once
#include <complex>
#include <vector>
#include "AbstractMulter.h"

using namespace std;

typedef complex<double> base;

class ShonhageMulter : public AbstractMulter {
private:
    void fft(vector<base>& a, bool invert);

public:
    BigInt mult(BigInt&, BigInt&);
};

