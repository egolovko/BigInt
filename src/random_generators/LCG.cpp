#include "LCG.h"

LCG::LCG(BigInt x) : a(4), c(4), lower_bound(0), upper_bound(10007), _upper_bound(10007), x(x) {}

BigInt LCG::next_int() {
    x = lower_bound + (a*x + c) % _upper_bound;
    return x;
}

void LCG::set_x(BigInt x) {
    this->x = x;
}

void LCG::set_a(BigInt a) {
    this->a = a;
}


void LCG::set_c(BigInt c) {
    this->c = c;
}


void LCG::set_lower_bound(BigInt lb) {
    this->lower_bound = lb;
}


void LCG::set_upper_bound(BigInt ub) {
    this->upper_bound = ub;
    this->_upper_bound = upper_bound - lower_bound;
}


BigInt& LCG::get_x() {
    return x;
}


BigInt& LCG::get_a() {
    return a;
}


BigInt& LCG::get_c() {
    return c;
}


BigInt& LCG::get_lower_bound() {
    return lower_bound;
}


BigInt& LCG::get_upper_bound() {
    return upper_bound;
}