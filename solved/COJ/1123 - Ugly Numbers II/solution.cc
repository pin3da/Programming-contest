#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const long long MN = 1000000001LL;

set<long long> sieve;
vector<long long> ugly;
int c;

void gen(long long cur) {
  if (cur >= MN) return;
  if (sieve.count(cur)) return;
  sieve.insert(cur);
  ugly.emplace_back(cur);
  gen(cur * 2);
  gen(cur * 3);
  gen(cur * 5);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  gen(1);
  sort(ugly.begin(), ugly.end());
  ugly.resize(unique(ugly.begin(), ugly.end()) - ugly.begin());

  int n;
  while (cin >> n && n) {
    cout << ugly[n - 1] << endl;
  }
  return 0;
}


