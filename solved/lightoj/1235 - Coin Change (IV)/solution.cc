using namespace std;
#include <bits/stdc++.h>

void gen(const vector<int> &a, int i, long long acc, vector<long long> &ans) {
  ans.push_back(acc);
  if (i < a.size()) {
    gen(a, i + 1, acc, ans);
    gen(a, i + 1, acc + a[i], ans);
    gen(a, i + 1, acc + a[i] + a[i], ans);
  }
}


void solve() {
  int n, t;
  long long w;
  cin >> n >> w;
  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (i & 1) a.push_back(t);
    else       b.push_back(t);
  }

  vector<long long> sa, sb;
  gen(a, 0, 0, sa);
  gen(b, 0, 0, sb);
  // sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());

  for (int i = 0; i < sa.size(); ++i) {
    long long t = w - sa[i];
    if (binary_search(sb.begin(), sb.end(), t)) {
      puts("Yes");
      return;
    }
  }

  /*int i = 0, j = sb.size() - 1;
  while (i < sa.size() && j >= 0) {
    if(sa[i] + sb[j] == w) {
      puts("Yes");
      return;
    }
    if(sa[i] + sb[j] > w)
      j--;
    else
      i++;
  }*/
  puts("No");
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
