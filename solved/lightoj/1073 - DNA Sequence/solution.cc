using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int inf  = 1 << 20;

char alphabet[] = "ACGT";
int target;

int ov[111][111];
int inter(vector<string> &words, int a, int b) {
  if (a == -1)
    return words[b].size();

  if (ov[a][b] != -1)
    return ov[a][b];

  for (int i = 0; i < words[a].size(); ++i) {
    bool suffix = true;
    for (int j = 0; j < words[b].size() && i + j < words[a].size() && suffix; ++j) {
      if (words[a][i + j] != words[b][j])
        suffix = false;
    }
    if (suffix) {
      int overlap = words[a].size() - i;
      return ov[a][b] = words[b].size() - overlap;
    }
  }
  return ov[a][b] = words[b].size();
}


int dp[111][(1 << 15) + 10];
int op[111][(1 << 15) + 10];

int go(vector<string> &words, int last, int seen) {
  if (seen == target)
    return dp[last + 1][seen] = 0;

   if (dp[last + 1][seen] != -1)
    return dp[last + 1][seen];

  int ans = inf;
  for (int i = 0; i < words.size(); ++i) if (!((seen >> i) & 1)) {
    ans = min(ans, go(words, i, seen | (1 << i)) + inter(words, last, i));
  }
  return dp[last + 1][seen] = ans;
}

string best;
void find_best(vector<string> &w, int last, int seen, string cur) {
  if (cur > best)
    return;

  if (seen == target) {
    if (cur < best)
      best = cur;
   return;
  }

  for (int i = 0; i < w.size(); ++i) if (!((seen >> i) & 1)) {
    int need = inter(w, last, i);
    if (dp[last + 1][seen] == (dp[i + 1][seen | (1 << i)] + need)) {
      int index = w[i].size() - need;
      find_best(w, i, seen | (1 << i), cur + w[i].substr(index, need));
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if(i != j) if (words[i].find(words[j]) != string::npos)
        words[j] = "";


  vector<string> cleaned;
  for (int i = 0; i < n; ++i)
    if (words[i] != "")
      cleaned.push_back(words[i]);

  memset(ov, -1, sizeof ov);
  memset(dp, -1, sizeof dp);
  memset(op, -1, sizeof op);

  target = (1 << cleaned.size()) - 1;
  go(cleaned, -1, 0);
  best = "Z";
  find_best(cleaned, -1, 0, "");
  cout << best << endl;

}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
