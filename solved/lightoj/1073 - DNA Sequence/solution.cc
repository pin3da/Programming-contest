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
  return ov[a][b] = 0;
}


int dp[111][(1 << 15) + 10];
int op[111][(1 << 15) + 10];

int go(vector<string> &words, int last, int seen) {
  if (seen == target)
    return 0;

  if (dp[last + 1][seen] != 1)
    return dp[last + 1][seen];

  int ans = inf;

  for (int i = 0; i < words.size(); ++i) if (!((seen >> i) & 1)) {
    int opt =  go(words, i, seen | (1 << i)) + inter(words, last, i);
    // ans = min(ans, go(words, i, seen | (1 << i)) + inter(words, last, i));
    if (opt < ans) {
      ans = opt;
      op[last + 1][seen] = i;
    }
  }
  return dp[last + 1][seen] = ans;
}

void solve() {
  int n;
  cin >> n;
  target = (1 << n) - 1;
  vector<string> words(n);
  for (int i = 0; i < n; ++i) {
    cin >> words[i];
  }

  memset(ov, -1, sizeof ov);
  memset(dp, -1, sizeof dp);
  memset(op, -1, sizeof op);

  cout << go(words, -1, 0) << endl;
  /*int state = 0, seen = 0;
  while (op[state][seen] != -1) {
    printf("%c", alphabet[op[state][seen]]);
    state = findNextState(state, alphabet[op[state][seen]]);
    seen = seen | out[state];
  }
  puts("");*/
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
