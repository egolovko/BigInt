#include <bits/stdc++.h>
#include "BigInt.h"
#include "multers/BasicMulter.h"
#include "multers/KaratsubaMulter.h"
#include "multers/ShonhageMulter.h"
#include "multers/Toom3Multer.h"
#include "prime_testers/LLT.h"

using namespace std;


int main() {
    BigInt b1(7);
    BigInt b2(4);

    cout << LLT::test(11);
}