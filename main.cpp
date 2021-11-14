#include <bits/stdc++.h>
#include "BigInt.h"
#include "multers/BasicMulter.h"
#include "multers/KaratsubaMulter.h"
#include "multers/ShonhageMulter.h"
#include "multers/Toom3Multer.h"
#include "prime_testers/LLT.h"
#include "prime_testers/MRT.h"

using namespace std;


int main() {
    int k = 7;

    for (int i = 0; i < 100; ++i) {
        if (MRT::is_prime(BigInt(i), k))
            cout << i << endl;
    }
}