#include<bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl;

const int MX = 100000;
vector<long long> primes;
bool check[MX];

void gen_prim() {
    primes.push_back(2);
    for (int i = 3; i < MX; i += 2) {
        if (!check[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MX; j += i) check[j] = true;
        }
    }
}

long long factorize(long long n, map<long long, long long> &np) {
    if (n == 1) return 1;
    long long ans = n;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if ((n % primes[i]) == 0) {
            while ((n % primes[i]) == 0) {
                np[primes[i]]++;
                n /= primes[i];
            }
            ans -= ans / primes[i];
        }
    }
    if (n > 1) {
        np[n]++;
        ans -= ans / n;
    }

    return ans;
}


int main() {
    gen_prim();
    int n;
    cin >> n;
    long long f = 0, t = 1, o = 1;
    map<long long, long long> np;
    f = factorize(n, np);

    for (auto it : np) {
        //cout << it.first << ", " << it.second << endl;
        t *= (it.second + 1);
    }
    long long sd = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i) continue;
        sd += i;
        if (i != (n / i)) sd += (n / i);
    }
    cout << f << " " << t << " " << sd << endl;

    return 0;
}
