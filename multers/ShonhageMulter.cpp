#include "ShonhageMulter.h"
#include "../BigInt.h"

const double PI = acos(-1);

void ShonhageMulter::fft(vector<base>& a, bool invert) {
    int n = (int)a.size();
    if (n == 1) return;

    vector<base> a0 (n/2), a1 (n/2);
    for (int i = 0, j = 0; i < n; i += 2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
    }
    fft (a0, invert);
    fft (a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    base w (1),  wn(cos(ang), sin(ang));
    for (int i = 0; i < n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if (invert)
            a[i] /= 2, a[i+n/2] /= 2;
        w *= wn;
    }
}


BigInt ShonhageMulter::mult(BigInt& b1, BigInt& b2) {
    BigInt res;
    res.set_base(b1.get_base());

    vector<base> f1(b1.numbers.begin(), b1.numbers.end()),  f2(b2.numbers.begin(), b2.numbers.end());
    size_t n = 1;

    while (n < max(f1.size(), f2.size())) n <<= 1;
    n <<= 1;
    f1.resize(n), f2.resize(n);

    fft (f1, false),  fft(f2, false);
    for (size_t i = 0; i < n; ++i)
        f1[i] *= f2[i];
    fft (f1, true);

    int carry = 0;
    int temp;
    for (size_t i = 0; i < n; ++i) {
        temp = int(f1[i].real() + 0.5) + carry;
        carry = temp / res.get_base();
        temp %= res.get_base();

        res.numbers.push_back(temp);
    }

    res.numbers.push_back(carry);
    res.normalize();

    return res;
}