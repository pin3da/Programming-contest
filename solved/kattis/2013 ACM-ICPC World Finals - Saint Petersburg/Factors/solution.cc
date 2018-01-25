#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

typedef __int128 bigint;

bigint primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

const bigint inf = numeric_limits<long long>::max();

map<long long, long long> best;

vector<int> factors(int n) {
  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    while ((n % i) == 0) {
      ans.push_back(i);
      n /= i;
    }
  }
  return ans;
}

void add(bigint cur, vector<int> &exponents, int &sum_exp) {
  if (cur == 1) return;

  vector<int> fact(sum_exp + 1);

  for (int i = 2; i <= sum_exp; i++) {
    for (auto f : factors(i)) fact[f]++;
  }
  for (auto e : exponents) {
    for (int i = 2; i <= e; i++) {
      for (auto f : factors(i)) fact[f]--;
    }
  }

  bigint ans = 1;

  for (int i = 2; i <= sum_exp; i++) {
    assert(fact[i] >= 0);
    for (int j = 0; j < fact[i]; j++) {
      if (ans * i > inf) return;
      ans *= i;
    }
  }

  if (best.count(ans) == 0)
    best[ans] = cur;
  else if (best[ans] > cur)
    best[ans] = cur;
}

void gen(int p, int e, bigint cur, vector<int> &exponents, int &sum_exp) {
  add(cur, exponents, sum_exp);

  for (int i = 1; i <= e; i++) {
    if (cur * primes[p] > inf) break;
    cur *= primes[p];
    exponents.push_back(i); sum_exp += i;
    gen(p + 1, i, cur, exponents, sum_exp);
    exponents.pop_back(); sum_exp -= i;
  }
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  vector<int> exponents;
  int sum_exp = 0;
  gen(0, 62, 1, exponents, sum_exp);

  long long n;
  while (cin >> n) {
    cout << n << " " << best[n] << endl;
  }
  return 0;
}
