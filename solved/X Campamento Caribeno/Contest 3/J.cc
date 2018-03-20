#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const long long mod = 1000000007;

struct fract {
    long long p, q;
    fract() : p(0), q(1) {}
    fract(long long a, long long b) {
        long long g = __gcd(a, b);
        p = a / g;
        q = b / g;
    }
};

fract mult(fract a, fract b) {
    return fract((a.p * b.p) % mod, (a.q * b.q) % mod);
}

fract sub(fract a, fract b) {
    return fract((mod + (a.p * b.q) % mod - (a.q * b.p) % mod) % mod, (a.q * b.q) % mod);
}

fract add(fract a, fract b) {
    return fract((a.p * b.q) % mod + (a.q * b.p) % mod, (a.q * b.q) % mod);
}

fract div(fract a, fract b) {
    return fract((a.p * b.q) % mod, (a.q * b.p) % mod);
}

long long mod_pow(long long b, long long e) {
    long long ans = 1;
    while (e > 0) {
        if (e & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return ans;
}

long long mod_inv(long long x) {
    return mod_pow(x, mod - 2);
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

    int n; cin >> n;
    vector<fract> prob(n);
    vector<fract> q(n);
    for (int i = 0; i < n; i++) {
        cin >> prob[i].p >> prob[i].q;
        q[i] = fract(prob[i].q - prob[i].p, prob[i].q);
    }
    vector<fract> prod(n);
    prod[0] = prob[0];
    for (int i = 1; i < n; i++) {
        prod[i] = mult(prod[i - 1], prob[i]);
    }

    fract num(1, 1);
    fract den(1, 1);

    for (int i = 0; i < n - 1; i++) {
        num = add(num, prod[i]);
    }

    den = sub(den, q[0]);

    for (int i = 1; i < n; i++) {
      den = sub(den, mult(prod[i - 1], q[i]));
    }

    num = div(num, den);

    long long b = mod_inv(num.q);
    cout << (num.p * b) % mod << endl;
    return 0;
}

