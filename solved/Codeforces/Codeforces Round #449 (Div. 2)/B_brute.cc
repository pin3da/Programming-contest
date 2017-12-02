#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MX = 3e5 + 10;

void gen(deque<int> s, vector<deque<int>> &all) {
  deque<deque<int>> q;
  q.push_back(s);
  while (all.size() < MX) {
    deque<int> next = q.front(); q.pop_front();
    next.push_front(1);
    next.push_back(1);
    int last = next.size() - 1;
    for (int i = 1; i < 10; i++) {
      next[0] = next[last] = i;
      all.push_back(next);
      q.push_back(next);
    }
  }
}

long long eval(deque<int> in, long long p) {
  long long ans = 0;
  for (auto it : in) {
    ans = (ans * 10) % p;
    ans = (ans + it) % p;
  }
  return ans;
}

void deg(deque<int> a) {
  for (auto it: a)
    cerr << it;
  cerr << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  vector<deque<int>> all;
  deque<int> s;
  gen(s, all);

  int tmp = 0;
  for (int i = 0; i < 1000; i++)
    tmp += all[i].size() == 6;

  debug(tmp);

  sort(all.begin(), all.end(), [](const deque<int> &a, const deque<int> &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
  });


  long long n, p;
  cin >> n >> p;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + eval(all[i], p)) % p;
  }
  cout << ans << endl;
  return 0;
}
