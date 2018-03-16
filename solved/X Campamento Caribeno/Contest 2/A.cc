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

int main() {
    vector<long long> rem(2), mod(2);
    for (auto &it : rem) cin >> it;
    for (auto &it : mod) cin >> it;

    long long z = 0;
    long long n = 1;

    for (int i = 0; i < rem.size(); i++)
        n *= mod[i];

    for (int i = 0; i < mod.size(); i++) {
        long long tmp = (rem[i] * (n / mod[i])) % n;
        tmp = (tmp * mod_inv(n / mod[i], mod[i])) % n;
        z = (z + tmp) % n;
    }
    cout << (z + n) % n;
    return 0;
}
