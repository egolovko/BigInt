#include "BigInt.h"
#include "multers/AbstractMulter.h"
#include "multers/BasicMulter.h"


AbstractMulter* BigInt::multer = new BasicMulter;


BigInt::BigInt(const BigInt& b) {
    this->base = b.base;
    this->numbers = b.numbers;
    this->sign = b.sign;
}


BigInt::BigInt(string str_num) {
    str_init(str_num);
}


BigInt::BigInt(long long number) {
    if (number < 0) {
        this->sign = -1;
    } else {
        this->sign = 1;
    }
    number = abs(number);
    while (number > base) {
        numbers.push_back(number % base);
        number /= base;
    }
    numbers.push_back(number);
}


BigInt::BigInt(vector<int>::iterator i1, vector<int>::iterator i2, int base, int sign) {
    this->sign = sign;
    this->numbers.assign(i1, i2);
    this->base = base;

    int carry = 0;
    for (int& item : numbers) {
        carry = item / base;
        if (carry)
            item %= base;
    }

    if (carry)
        numbers.push_back(carry);

}


BigInt BigInt::add(BigInt d1, BigInt d2) {
    assert(d1.base == d2.base);

    BigInt res;
    int m = max(d1.size(), d2.size());
    res.resize(m);

    for (int i = 0; i < m; ++i) {
        int num1 = (i < d1.size() ? d1.sign * d1[i] : 0);
        int num2 = (i < d2.size() ? d2.sign * d2[i] : 0);
        res[i] = num1 + num2;
    }

    res.normalize();

    if (res[res.size()-1] < 0) {
        res.sign = -1;
        for (int& item : res.numbers)
            item = -item;
    }

    int carry = 0;
    for (int i = 0; i < res.size(); ++i) {
        res[i] += carry;

        if (res[i] < 0) {
            res[i] += d1.base;
            carry = -1;
        } else if (res[i] > 9) {
            res[i] -= d1.base;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    if (carry)
        res.numbers.push_back(carry);

    res.normalize();

    return res;
}


BigInt BigInt::sub(BigInt b1, BigInt b2) {
    assert(b1.base == b2.base);

    BigInt res;
    int m = max(b1.size(), b2.size());
    res.resize(m);

    for (int i = 0; i < m; ++i) {
        int num1 = (i < b1.size() ? b1.sign * b1[i] : 0);
        int num2 = (i < b2.size() ? b2.sign * b2[i] : 0);
        res[i] = num1 - num2;
    }

    // after sub can be leading zero
    res.normalize();

    if (res[res.size()-1] < 0) {
        res.sign = -1;
        for (int& item : res.numbers)
            item = -item;
    }

    int carry = 0;
    for (int i = 0; i < res.size(); ++i) {
        res[i] += carry;

        if (res[i] < 0) {
            res[i] += b1.base;
            carry = -1;
        } else if (res[i] > 9) {
            res[i] -= b1.base;
            carry = 1;
        } else {
            carry = 0;
        }

    }

    if (carry)
        res.numbers.push_back(carry);

    res.normalize();

    return res;
}


BigInt BigInt::binpow(BigInt a, int n) {
    BigInt res(1);

    while (n) {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;  // n /= 2
    }

    return res;
}


BigInt BigInt::binpow(BigInt a, int n, BigInt m) {
    BigInt res(1);
    a = a % m;

    while (n) {
        if (n & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }

    return res;
}


BigInt BigInt::binpow(BigInt a, BigInt n) {
    BigInt res(1);

    while (n > BigInt(0)) {
        if (n.odd())
            res = res * a;
        a = a * a;
        n = n / 2;
    }

    return res;
}


BigInt BigInt::binpow(BigInt a, BigInt n, BigInt m) {
    BigInt res(1);
    a = a % m;

    while (n > BigInt(0)) {
        if (n.odd())
            res = (res * a) % m;
        a = (a * a) % m;
        n = n / 2;
    }

    return res;
}


BigInt BigInt::gcd(BigInt a, BigInt b) {
    while (b > 0) {
        a = a % b;
        swap(a, b);
    }
    return a;
}


void BigInt::str_init(string str_num) {
    if (str_num[0] == '-') {
        str_num = str_num.substr(1, str_num.length());
        cout << str_num << endl;
        this->sign = -1;
    }

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


vector<int>::iterator BigInt::begin() {
    return numbers.begin();
}


vector<int>::iterator BigInt::end() {
    return numbers.end();
}


BigInt& BigInt::left_shift(int shift) {
    normalize();

    int n = size();

    for (int i = n; i < n+shift; ++i)
        numbers.push_back(0);

    for (int i = n+shift-1; i >= shift; --i)
        numbers[i] = numbers[i-shift];

    for (int i = 0; i < shift; ++i)
        numbers[i] = 0;

    return *this;
}


BigInt& BigInt::right_shift(int shift) {
    int n = size();

    for (int i = 0; i < n - shift; ++i)
        numbers[i] = numbers[i+shift];

    for (int i = shift; i < n; ++i)
        numbers[i] = 0;

    normalize();
    return *this;
}


bool BigInt::even() {
    if ((*this) == BigInt(0))
        return false;
    return numbers[0] % 2 == 0;
}


bool BigInt::odd() {
    if ((*this) == BigInt(0))
        return false;
    return numbers[0] % 2 == 1;
}


int& BigInt::operator[](int i) {
    return numbers[i];
}


ostream& operator<<(ostream& out, const BigInt& num) {

    if (num.sign == -1) {
        cout << '-';
    }

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


BigInt operator-(BigInt b) {
    b.sign *= -1;
    return b;
}


BigInt operator+(BigInt b) {
    return b;
}

bool operator==(BigInt b1, BigInt b2) {
    assert(b1.base == b2.base);

    if (b1.sign != b2.sign)
        return 0;

    b1.normalize();
    b2.normalize();

    if (b1.size() != b2.size())
        return 0;

    for (int i = 0; i < b1.size(); ++i) {
        if (b1[i] != b2[i])
            return 0;
    }

    return 1;
}


bool operator!=(BigInt b1, BigInt b2) {
    return !(b1 == b2);
}


bool operator>(BigInt b1, BigInt b2) {
    int m = max(b1.size(), b2.size());
    b1.resize(m);
    b2.resize(m);

    for (int i = m-1; i >= 0; --i) {
        if (b1.sign * b1.numbers[i] > b2.sign * b2.numbers[i])
            return true;
        else if (b1.sign * b1.numbers[i] < b2.sign * b2.numbers[i]) {
            return false;
        }
    }
    return false;
}


bool operator<(BigInt b1, BigInt b2) {
    int m = max(b1.size(), b2.size());
    b1.resize(m);
    b2.resize(m);

    for (int i = m-1; i >= 0; --i) {
        if (b1.sign * b1.numbers[i] < b2.sign * b2.numbers[i])
            return true;
        else if (b1.sign * b1.numbers[i] > b2.sign * b2.numbers[i])
            return false;
    }
    return false;
}


bool operator>=(BigInt b1, BigInt b2) {
    return b1 > b2 || b1 == b2;
}


bool operator<=(BigInt b1, BigInt b2) {
    return b1 < b2 || b1 == b2;
}


BigInt operator+(BigInt b1, BigInt b2) {
    return BigInt::add(b1, b2);
}


BigInt operator-(BigInt b1, BigInt b2) {
    return BigInt::sub(b1, b2);
}


BigInt operator*(BigInt b, int l) {
    BigInt res = b;

    int lsign = ((l >= 0) * 2 - 1);
    res.sign = b.sign * lsign;
    l *= lsign;


    int carry = 0;
    for (int& item : res) {
        item *= l;
        item += carry;
        carry = item / b.base;
        if (carry)
            item %= b.base;
    }

    if (carry)
        res.numbers.push_back(carry);

    return res;
}


BigInt operator*(int l, BigInt b) {
    return b * l;
}


BigInt operator*(BigInt b1, BigInt b2) {
    return BigInt::multer->mult(b1, b2);
}


BigInt operator/(BigInt b, int l) {
    BigInt c(b);

    int lsign = ((l >= 0) * 2 - 1);
    c.sign = b.sign * lsign;
    l *= lsign;

    int carry = 0;
    for (int i=(int)c.size()-1; i>=0; --i) {
        long long cur = c[i] + carry * 1ll * c.get_base();
        c[i] = int (cur / l);
        carry = int (cur % l);
    }
    while (c.size() > 1 && c.numbers.back() == 0)
        c.numbers.pop_back();


    return c;
}


BigInt operator/(BigInt x, BigInt y) {
    BigInt res("0"), z("1");
    int k = 0;

    while (!(y > x))
    {
        y = y + y;
        z = z + z;
        ++k;
    }
    while (k)
    {
        y = y / 2;
        z = z / 2;
        --k;
        while (!(y > x))
        {
            x = x - y;
            res = res + z;
        }
    }

    res.sign = x.sign * y.sign;
    return res;
}


BigInt operator%(BigInt x, BigInt y) {
//    while (x >= y)
//        x = x - y;
//    return x;

    BigInt res("0"), z("1");
    int k = 0;

    while (!(y > x))
    {
        y = y + y;
        z = z + z;
        ++k;
    }
    while (k)
    {
        y = y / 2;
        z = z / 2;
        --k;
        while (!(y > x))
        {
            x = x - y;
            res = res + z;
        }
    }

    res.sign = x.sign * y.sign;
    return x;
}