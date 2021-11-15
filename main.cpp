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

using namespace std;


int main() {
    int k = 7;

    cout << QFT::is_prime(19);
}