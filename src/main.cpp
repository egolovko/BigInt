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
#include "dividers/CombinedP2NRDivider.h"


using namespace std;


void show_division_res(pair<BigInt, BigInt> int_float) {
    BigInt& int_part = int_float.first;
    BigInt& float_part = int_float.second;
    cout << int_part << "." << float_part;
}


int main() {
    BigInt::set_multer(new ShonhageMulter);
    BigInt::set_divider(new Pow2Divider);

    BigInt x(10);
    BigInt y(7);

    AbstractDivider* divider;

    // Warning! Many algorithms may work bad, when using NewtonRaphsonDivider divider!!!!
    // Because int(14/7) == int(1.9999(9)) == 1 != 2 :(
    divider = new NewtonRaphsonDivider;
    BigInt::set_divider(divider);
    cout << "NewtonRaphsonDivider:" << endl;
    cout << "int(x/y) = " << x / y << endl;
    cout << "x/y      = ";
    show_division_res(divider->div(x, y));
    cout << endl << endl;

    divider = new Pow2Divider;
    BigInt::set_divider(divider);
    cout << "Pow2Divider:" << endl;
    cout << "int(x/y) = " << x / y << endl;
    cout << "x/y      = ";
    show_division_res(divider->div(x, y));
    cout << endl << endl;

    divider = new CombinedP2NRDivider;
    BigInt::set_divider(divider);
    cout << "CombinedP2NRDivider:" << endl;
    cout << "int(x/y) = " << x / y << endl;
    cout << "x/y      = ";
    show_division_res(divider->div(x, y));
    cout << endl;
}
