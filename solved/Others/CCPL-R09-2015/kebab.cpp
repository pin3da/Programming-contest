using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const int MN = 10000001;
bool sieve[MN];
vector<int> p;

void fillp() {
  memset(sieve, 0, sizeof sieve);
  sieve[1] = sieve[0] = 1;
  for (int i = 2; i < MN; ++i) {
    if (!sieve[i]) {
      p.push_back(i);
      for (long long j = i + i; j < MN; j += i)
        sieve[j] = true;
    }
  }
}


long long npf(long long n) {
  long long ans = 0;
  for (int i = 0; i < p.size() && p[i] <= n; ++i) {
    if (n % p[i] == 0) {
      int e = 0;
      while (n % p[i] == 0) {
        e++;
        n /= p[i];
      }
      ans += e ;
    }
  }  
  
  if (n > 1)
    ans++;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;  
  fillp();
  while (cin >> n && (n > 1)) {
    cout << npf(n) << endl;
  }
  return 0;
}
