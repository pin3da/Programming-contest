#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  long long n, p;
  cin >> n >> p;

  deque<long long> cur;
  for (int i = 0; i < 10; i++)
    cur.push_back((i * 10 + i) % p);

  deque<long long> all;
  all.insert(all.end(), cur.begin() + 1, cur.end());

  long long pp = 100 % p;
  while ((int)all.size() < n) {
    int s = cur.size();
    deque<long long> nxt;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < s; j++) {
        long long tmp = cur[j] % p;
        tmp = (tmp + (i * pp) % p) % p;
        tmp = (tmp * 10 + i) % p;
        nxt.push_back(tmp);
      }
    }
    cur = nxt;
    all.insert(all.end(), cur.begin() + s, cur.end());
    pp = (pp * 100) % p;
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + all[i]) % p;
  }
  cout << ans << endl;
  return 0;
}
