#include "BigInt.h"
#include "multers/AbstractMulter.h"
#include "multers/BasicMulter.h"


AbstractMulter* BigInt::multer = new BasicMulter;


BigInt::BigInt(const BigInt& b) {
    this->base = b.base;
    this->numbers = b.numbers;
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


int BigInt::get_base() {
    return base;
}


void BigInt::set_base(int base) {
    this->base = base;
}


size_t BigInt::size() {
    return numbers.size();
}


void BigInt::normalize() {
    while (numbers.size() > 1 && numbers.back() == 0)
        numbers.pop_back();

    if (numbers.empty())
        numbers.push_back(0);
}


void BigInt::resize(int n) {
    numbers.resize(n);
}


int& BigInt::operator[](int i) {
    return numbers[i];
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


BigInt operator-(BigInt& b1, BigInt& b2) {
    assert(b1.base == b2.base);

    BigInt b3 = b1;

    int carry = 0;
    for (size_t i = 0; i < b2.size() || carry; ++i) {
        b3[i] -= carry + (i < b2.size() ? b2[i] : 0);
        carry = b3[i] < 0;
        if (carry)
            b3[i] += b3.get_base();
    }
    while (b3.numbers.size() > 1 && b3.numbers.back() == 0)
        b3.numbers.pop_back();

    return b3;
}


BigInt operator*(BigInt& b1, BigInt& b2) {
    return BigInt::multer->mult(b1, b2);
}