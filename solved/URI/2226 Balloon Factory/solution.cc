#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

const int MAXS = 4000 * 19 + 100;
const int MAXC = '9' - '0' + 1;
bitset<5001> out[MAXS];
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.

int buildMatchingMachine(const vector<string> &words,
    char lowestChar = '0',
    char highestChar = '9') {

  for (int i = 0; i < MAXS; ++i)
    out[i].reset();

  memset(f, -1, sizeof f);
  memset(g, -1, sizeof g);

  int states = 1; // Initially, we just have the 0 state

  for (int i = 0; i < int(words.size()); ++i) {
    const string &keyword = words[i];
    int currentState = 0;
    for (int j = 0; j < int(keyword.size()); ++j) {
      int c = keyword[j] - lowestChar;
      if (g[currentState][c] == -1) { // Allocate a new node
        g[currentState][c] = states++;
      }
      currentState = g[currentState][c];
    }
    out[currentState].set(i); // There's a match of keywords[i] at node currentState.
  }

  for (int c = 0; c < MAXC; ++c) {
    if (g[0][c] == -1) {
      g[0][c] = 0;
    }
  }

  queue<int> q;
  for (int c = 0; c <= highestChar - lowestChar; ++c) {  // Iterate over every possible input
    // All nodes s of depth 1 have f[s] = 0
    if (g[0][c] != -1 and g[0][c] != 0) {
      f[g[0][c]] = 0;
      q.push(g[0][c]);
    }
  }
  while (q.size()) {
    int state = q.front();
    q.pop();
    for (int c = 0; c <= highestChar - lowestChar; ++c) {
      if (g[state][c] != -1) {
        int failure = f[state];
        while (g[failure][c] == -1) {
          failure = f[failure];
        }
        failure = g[failure][c];
        f[g[state][c]] = failure;
        out[g[state][c]] |= out[failure]; // Merge out values
        q.push(g[state][c]);
      }
    }
  }

  return states;
}

int findNextState(int currentState, char nextInput, char lowestChar = 0) {
  int answer = currentState;
  int c = nextInput - lowestChar;
  while (g[answer][c] == -1) answer = f[answer];
  return g[answer][c];
}


long long dp[20][MAXS][2];

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  long long n;
  while (cin >> n && n) {
    string border = to_string(n);
    int m; cin >> m;
    vector<string> bad(m);
    for (auto &w : bad)
      cin >> w;

    debug(border.size());

    int states = buildMatchingMachine(bad);
    debug(states);

    for (int i = 0; i < states; i++) {
      for (int j = 0; j < 2; j++) {
        dp[border.size()][i][j] = 1;
      }
    }

    for (int id = border.size() - 1; id >= 0; id--) {
      for (int state = 0; state < states; state++) {
        for (int top = 0;  top < 2; top++) {
          int mmax = top ? border[id] - '0' : 9;
          long long ans = 0;
          for (int i = 0; i <= mmax; i++) {
            int nxt = findNextState(state, i);
            if (out[nxt].count() == 0) {
              ans += dp[id + 1][nxt][top && i == mmax];
            }
          }
          dp[id][state][top] = ans;
        }
      }
    }

    debug(n);

    cout << n - dp[0][0][1] + 1 << endl;
  }
  return 0;
}

