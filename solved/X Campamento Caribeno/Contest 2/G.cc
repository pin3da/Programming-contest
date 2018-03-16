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

void mod_inv(long long n, long long m) {
    long long x, y, gcd;
    ext_euclid(n, m, x, y, gcd);
    if (gcd != 1)
        cout << -1 << endl;
    else
        cout << (x + m) % m << endl;
}

int main() {
    long long n, m;
    cin >> n >> m;
    mod_inv(n, m);
    return 0;
}
