#include <bits/stdc++.h>
#include "BigInt.h"
#include "multers/BasicMulter.h"
#include "multers/KaratsubaMulter.h"
#include "multers/ShonhageMulter.h"

using namespace std;

int main() {
    BigInt::multer = new KaratsubaMulter;

    BigInt b1("632");
    BigInt b2("340");
    BigInt b3 = b1 * b2;
    cout << b3;
}