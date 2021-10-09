#include "bigint.h"


BigInt::BigInt(const BigInt& dec) {
    this->base = dec.base;
    this->numbers = dec.numbers;
}

BigInt::BigInt(string str_num) {
    str_init(str_num);
}

BigInt::BigInt(long long number) {
    while (number > base) {
        numbers.push_back(number % base);
        number /= base;
    }
    numbers.push_back(number);
}

void BigInt::str_init(string str_num) {
    int base_len = 0;
    int temp_base = base;
    while (temp_base > 0) {
        ++base_len;
        temp_base /= 10;
    }
    --base_len;

    for (int i = (int)str_num.length(); i > 0; i -= base_len)
        if (i < base_len)
            numbers.push_back (atoi (str_num.substr (0, i).c_str()));
        else
            numbers.push_back (atoi (str_num.substr (i-base_len, base_len).c_str()));
}

size_t BigInt::size() {
    return numbers.size();
}

ostream& operator<<(ostream& out, const BigInt& num) {
    for (int i = num.numbers.size()-1; i >= 0; --i)
        cout << num.numbers[i];
    return out;
}


istream& operator>>(istream& in, BigInt& num) {
    string str_num;
    in >> str_num;

    num.str_init(str_num);

    return in;
}

BigInt operator+(BigInt& d1, BigInt& d2) {
    assert(d1.base == d2.base);

    BigInt d3 = d1;

    int carry = 0;
    int m = max(d3.size(), d2.size());

    for (int i = 0; i < m || carry; ++i) {
        if (i == d3.size())
            d3.numbers.push_back(0);
        
        d3.numbers[i] += carry + (i < d2.size() ? d2.numbers[i] : 0);
        carry = d3.numbers[i] >= d3.base;

        if (d3.numbers[i] >= d3.base)
            d3.numbers[i] -= d3.base;
    
    }

    return d3; // move(d3)
}


BigInt operator-(BigInt& d1, BigInt& d2) {
    assert(d1.base == d2.base);

    BigInt d3 = d1;

    int carry = 0;
    for (int i = 0; i < d2.size() || carry; ++i) {
        if (i == d3.size())
            d3.numbers.push_back(0);

        d3.numbers[i] -= carry + (i < d2.size() ? d2.numbers[i] : 0);
        carry = d3.numbers[i] >= d3.base;
        if (carry)
            d3.numbers[i] -= d3.base;
    }

    return d3; // move(d3)
}