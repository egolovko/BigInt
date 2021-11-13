#include <bits/stdc++.h>
#include "BigInt.h"
#include "multers/BasicMulter.h"
#include "multers/KaratsubaMulter.h"
#include "multers/ShonhageMulter.h"
#include "multers/Toom3Multer.h"

using namespace std;


int main() {
    BigInt::multer = new Toom3Multer;

    BigInt b1("1234567890123456789012");
    BigInt b2("987654321987654321098");
    BigInt b3 = b1 * b2;

    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;


}