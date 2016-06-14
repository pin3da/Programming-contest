#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MAXS = 20 * 50 + 10 ;
const int MAXC = '~' - ' ' + 1;
bitset<111> out[MAXS];
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.

int buildMatchingMachine(const vector<string> &words,
                         char lowestChar = ' ',
                         char highestChar = '~') {

  for (int i = 0; i < MAXS; ++i)
    out[i].reset();

  memset(f, -1, sizeof f);
  memset(g, -1, sizeof g);

  int states = 1; // Initially, we just have the 0 state

  for (int i = 0; i < words.size(); ++i) {
    const string &keyword = words[i];
    int currentState = 0;
    for (int j = 0; j < keyword.size(); ++j) {
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

int findNextState(int currentState, char nextInput,
                                    char lowestChar = ' ') {
  int answer = currentState;
  int c = nextInput - lowestChar;
  while (g[answer][c] == -1) answer = f[answer];
  return g[answer][c];
}

int dp[100][MAXS + 100];
int go(const string &line, int id, int state) {
  if (id == line.size()) return 0;

  if (dp[id][state] != -1)
    return dp[id][state];

  int ans = go(line, id + 1, 0) + 1;
  int next_state = findNextState(state, line[id]);
  if (out[next_state].count() == 0)
    ans = min(ans, go(line, id + 1, next_state));
  return dp[id][state] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m, n;
  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> n >> m;
    if ((n + m) == 0) break;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, words[i]);
    }
    int ans = 0;
    int states = buildMatchingMachine(words);

    while (m--) {
      getline(cin, line);
      memset(dp, -1, sizeof dp);
      ans += go(line, 0, 0);
    }
    cout << ans << endl;
  }
  return 0;
}
