/**
 * likelihood String.contains()
 */

#include <assert.h>

static int onePassHashMod(int last, int ch, int seed, int m) {
    return (last * seed + ch) % m;
}

// x ^ n % m
static int powMod(int x, int n, int m) {
    assert(n >= 0);
    x = x % m;
    int result = 1;
    while (n != 0) {
        if (n & 0x01 != 0) {
            result = result * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return result;
}

int String_contains(byte * s, int sn, byte * p, int pn) {
    const int seed = 233;
    const int m = 31;

    int pk = 0;
    for (int i = 0; i < pn; i++) {
        pk = onePassHashMod(pk, p[i], seed, m);
    }

    int pm = powMod(seed, pn, m);

    int ska[sn + 1];
    ska[0] = 0;
    for (int i = 1; i <= sn; i++) {
        ska[i] = onePassHashMod(ska[i - 1], s[i], seed, m);
        if (i < pn) {
            continue;
        }
        int k = (s[i - pn] * pm + pk) % m;
        if (k == s[i]) {
            return i - pn;
        }
    }
    return -1;
}
