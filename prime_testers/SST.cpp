#include "SST.h"
#include "../BigInt.h"
#include "../random_generators/LCG.h"


LCG* SST::generator = new LCG(42);


BigInt SST::jacobi(BigInt a, BigInt b) {
    BigInt g;
    assert( b.odd() );

    if (a >= b) a = a % b; /* по правилу 4 */
    if (a == BigInt(0)) return BigInt(0); /* по определению 1 */
    if (a == BigInt(1)) return BigInt(1); /* по правилу 1 */
    if (a < BigInt(0))
        if ((b-BigInt(1)) / BigInt(2) % BigInt(2) == BigInt(0))
            return jacobi(-a,b);
        else
            return -jacobi(-a,b);

    if (a % BigInt(2) == BigInt(0)) /* a четно */
        if (((b*b - BigInt(1))/BigInt(8)) % BigInt(2) == BigInt(0))
            return +jacobi(a / BigInt(2), b);
        else
            return -jacobi(a / BigInt(2), b); /* по правилам 3 и 2 */

    g = BigInt::gcd(a,b);
    assert(a.odd()); /* это обеспечивается проверкой (a % 2 == 0) */

    if (g == a) /* b делится на a */
        return BigInt(0); /* по правилу 5 */
    else if (g != BigInt(1))
        return jacobi(g,b) * jacobi(a / g,b); /* по правилу 2 */
    else if (((a - BigInt(1)) * (b - BigInt(1)) / BigInt(4)) % BigInt(2) == BigInt(0))
        return +jacobi(b,a); /* по правилу 6a */
    else
        return -jacobi(b,a); /* по правилу 6b */
}

bool SST::is_prime(BigInt n, int k) {
    if (n < BigInt(2))
        return false;

    if (n < BigInt(4))
        return true;

    if (n.even())
        return false;

    generator->set_lower_bound({2});
    generator->set_upper_bound(n-1);

    for (int i = 0; i < k; i++)
    {
        BigInt a = generator->next_int();

        if (BigInt::gcd(a, n) > 1)
            return false;

        BigInt jacobian = jacobi(a, n);
        BigInt temp = BigInt::binpow(a, (n - BigInt(1)) / BigInt(2));
        if ( ((temp - jacobian) % n) != BigInt(0) )
            return false;
    }
    return true;
}