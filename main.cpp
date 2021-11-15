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

using namespace std;


int main() {
    int k = 2;

    for (int i = 0; i < 100; ++i) {
        if (LT::is_prime(BigInt(i), k))
            cout << i << endl;
    }
}