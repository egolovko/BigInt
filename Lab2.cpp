#include <iostream>
#include "bigint.h"

using namespace std;

int main() {
	BigInt big1("512345");
	BigInt big2("512345");
	BigInt big3;

	cout << big1 << endl << big2 << endl;
	big3 = big1 + big2;
	cout << big3 << endl << big3.size();
}