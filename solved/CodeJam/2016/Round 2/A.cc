#include <bits/stdc++.h>

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

// PRS
int match(int a, int b) {
  if (a == 0 && b == 2) return -1;
  if (a == 0 && b == 1) return 1;
  if (a == 0 && b == 0) return 0;
  if (a == 1 && b == 2) return 1;
  if (a == 1 && b == 1) return 0;
  if (a == 1 && b == 0) return -1;
  if (a == 2 && b == 2) return 0;
  if (a == 2 && b == 1) return -1;
  if (a == 2 && b == 0) return 1;
}

bool simulate(vector<int> a) {
  while (a.size() > 1) {
    vector<int> next;
    for (int i = 0; i < a.size(); i += 2) {
      if (match(a[i], a[i + 1]) == 0) return false;
      if (match(a[i], a[i + 1]) == 1)
        next.emplace_back(a[i]);
      else
        next.emplace_back(a[i + 1]);
    }
    a = next;
  }
  return true;
}

string PRS = "PRS";
void print(vector<int> &a) {
  for (auto &i : a)
    cout << PRS[i];
  cout << endl;
}


void brute_force(int n, int r, int p, int s) {
  vector<int> all;
  for (int i = 0; i < p; ++i)
    all.emplace_back(0);
  for (int i = 0; i < r; ++i)
    all.emplace_back(1);
  for (int i = 0; i < s; ++i)
    all.emplace_back(2);
  int seen = 0;
  do {
    if (simulate(all)) {
      seen = true;
      print(all);
      break;
    }
  } while (next_permutation(all.begin(), all.end()));
  if (!seen)
    cout << "IMPOSSIBLE" << endl;
}


void gen(int t, int level, int &p, int &r, int &s) {
  if (level == 0) {
    if (t == 0) p++;
    if (t == 1) r++;
    if (t == 2) s++;
    return;
  }

  gen(t, level - 1, p, r, s);
  gen((t + 1) % 3, level - 1, p, r, s);
}


int iter;
string tmp;

typedef pair<int, pair<int, int>> st;


st memo[3][1 << 13];
int dp[3][1 << 13];
st compute(int t, int level) {
  if (level == 0) {
    st ans;
    if (t == 0) ans.first++;
    if (t == 1) ans.second.first++;
    if (t == 2) ans.second.second++;
    return ans;
  }
  if (dp[t][level] != -1)
    return memo[t][level];

  dp[t][level] = 10;
  st ans = compute(t, level - 1);
  st ans2 = compute((t + 1) % 3, level - 1);
  ans.first += ans2.first;
  ans.second.first += ans2.second.first;
  ans.second.second += ans2.second.second;
  return memo[t][level] = ans;
}


void print(int t, int level) {
  if (level == 0) {
    tmp[iter++] = PRS[t];
    return;
  }
  st ans = compute(t, level - 1);
  st ans2 = compute((t + 1) % 3, level - 1);
  if (ans > ans2) {
    print(t, level - 1);
    print((t + 1) % 3, level - 1);
  } else {
    print((t + 1) % 3, level - 1);
    print(t, level - 1);
  }
}

void solve() {
  int n, r, p, s;
  cin >> n >> r >> p >> s;
  int seen = 0;
  int target = - 1;
  string ans;
  tmp.resize(1 << n);
  for (int i = 0; i < 3; ++i) {
    int a = 0, b = 0, c = 0;
    gen(i, n, a, b, c);
    if (a == p && b == r && c == s) {
      iter = 0;
      print(i, n);
      if (!seen) {
        ans = tmp;
      } else {
        ans = min(ans, tmp);
      }
      seen = true;
      target = i;
    }
  }
  if (!seen)
    cout << "IMPOSSIBLE" << endl;
  else {
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  memset(dp, -1, sizeof dp);
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}
