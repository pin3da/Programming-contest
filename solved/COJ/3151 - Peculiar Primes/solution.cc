#include<bits/stdc++.h>
#define endl '\n'
#define D(x) cout << #x << " = " << x << endl
using namespace std;

unordered_set<long long> seen;

vector<int> ans;
long long x, y;
void gen(vector<long long> &p, long long cur) {
  if (seen.count(cur) || cur > y) return;
  seen.insert(cur);
  ans.emplace_back(cur);
  for (auto &i : p) gen(p, cur * i);
}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  ans.reserve(1000000);
  while (cin >> n && n) {
    vector<long long> p(n);
    for (auto &i : p) cin >> i;

    cin >> x >> y;
    seen.clear();
    ans.clear();
    gen(p, 1);
    sort(ans.begin(), ans.end());
    auto it  = lower_bound(ans.begin(), ans.end(), x);
    int first = true;
    for (; it != ans.end(); ++it) {
      if (!first) cout << ",";
      first = false;
      cout << *it;
    }
    if (first)
      cout << "none" << endl;
    else
      cout << endl;
  }
  return 0;
}
