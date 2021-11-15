#include <bits/stdc++.h>
#include "BigInt.h"
#include "multers/BasicMulter.h"
#include "multers/KaratsubaMulter.h"
#include "multers/ShonhageMulter.h"
#include "multers/Toom3Multer.h"
#include "prime_testers/LLT.h"
#include "prime_testers/MRT.h"
#include "prime_testers/SST.h"
#include "prime_testers/LT.h"
#include "prime_testers/QFT.h"
#include "dividers/NewtonRaphsonDivider.h"
#include "dividers/Pow2Divider.h"


using namespace std;


void show_division_res(pair<BigInt, int> res_e) {
    BigInt& res = res_e.first;
    int& e= res_e.second;

    BigInt int_part(res.begin()+e, res.end(), res.get_base(), 1);
    BigInt float_part(res.begin(), res.begin()+e, res.get_base(), 1);

    cout << int_part << "." << float_part;
}


int main() {
    BigInt::multer = new BasicMulter;
    BigInt::divider = new NewtonRaphsonDivider;

    BigInt x(14);
    BigInt y(7);

    cout << "NewtonRaphsonDivider:" << endl;
    cout << "int(x/y) = " << x / y << endl;
    cout << "x/y      = ";
    show_division_res(BigInt::divider->div(x, y));
    cout << endl << endl;

    BigInt::divider = new Pow2Divider;
    cout << "Pow2Divider:" << endl;
    cout << "int(x/y) = " << x / y << endl;
    cout << "x/y      = ";
    show_division_res(BigInt::divider->div(x, y));
    cout << endl;
}
