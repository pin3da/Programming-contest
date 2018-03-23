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

const int MX = 1000005;

vector<long long> primes;
bool check[MX];

void gen_primes() {
    primes.push_back(-1);
    primes.push_back(2);
    for (int i = 3; i < MX; i += 2) {
        if (!check[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MX; j += i) check[j] = true;
        }
    }
}

int solve(long long n) {
    int ans = 0;
    for (int i  = 1; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        int pow = 0;
        while ((n % primes[i]) == 0) { n /= primes[i]; pow++; }
        if (pow % 2) ans ^= i;
    }
    if (n > 1) return (primes[ans] != n);
    return ans;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#else
    freopen("i3.in", "r", stdin);
#endif

    long long n;
    cin >> n;

    gen_primes();

    int ans = solve(n);
    if (ans)
        cout << "David" << endl;
    else
        cout << "Vasya" << endl;

    return 0;
}

