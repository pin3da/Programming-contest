#include<bits/stdc++.h>

using namespace std;

void ext_euclid(long long a, long long b, long long &x, long long &y, long long &g) {
    x = 0, y = 1, g = b;
    long long m, n, q, r;
    for (long long u = 1, v = 0; a != 0; g = a, a = r) {
        q = g / a, r = g % a;
        m = x - u * q, n = y - v * q;
        x = u, y = v, u = m, v = n;
    }
}

long long mod_inv(long long n, long long m) {
    long long x, y, gcd;
    ext_euclid(n, m, x, y, gcd);
    if (gcd != 1)
        return 0;
    return (x + m) % m;
}

void factorize(long long n, long long &p, long long &q) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i) continue;
        p = i;
        q = n / i;
        return;
    }
    assert(false);
}

long long mod_pow(long long b, long long e, long long m) {
    long long a = 1;
    while (e > 0) {
        if (e & 1) a = (a * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return a;
}

int main() {
    long long n, e, c; cin >> n >> e >> c;
    long long p, q;
    factorize(n, p, q);
    long long phi = (p - 1) * (q - 1);
    long long d = mod_inv(e, phi);
    cout << mod_pow(c, d, n) << endl;
    return 0;
}
