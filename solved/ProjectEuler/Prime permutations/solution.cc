using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define MP 1000010
char sieve[MP];
int primes[MP];
int prime_counter;

void fill_sieve(){
  prime_counter = 0;
  memset(sieve,1,sizeof sieve);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i < MP; ++i) {
    if (sieve[i]) {
      primes[prime_counter++] = i;
      if (i * i < MP and i * i > 0)
        for (int j = i * i; j < MP; j += i)
          sieve[j] = 0;
    }
  }
}

int main() {
  fill_sieve();
  vector<int> cool;
  map<tuple<int, int, int, int>, vector<int>> ans;
  for (int i = 0; i < prime_counter; ++i) {
    int p = primes[i], j = 0;
    vector<int> t;
    while (p) { t.push_back(p % 10); p/= 10; ++j;}
    if (j == 4) {
      sort(t.begin(), t.end());
      ans[make_tuple(t[0], t[1], t[2], t[2])].push_back(primes[i]);
    }
  }
  for (auto &v : ans) {
    vector<int> &t = v.second;
    for (int i = 0; i < t.size(); ++i)
      for (int j = i + 1; j < t.size(); ++j)
        for (int k = j + 1; k < t.size(); ++k)
          if ((t[j] - t[i]) == (t[k] - t[j]) and (t[j] - t[i] == 3330))
            cout << t[i] << " " << t[j] << " " << t[k] << endl;

  }
}
