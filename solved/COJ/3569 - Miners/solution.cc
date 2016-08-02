
#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MAXS = 100;
const int MAXC = 'M' - 'B' + 1;
vector<int> out[MAXS];
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.

int buildMatchingMachine(const vector<string> &words,
                         char lowestChar = 'B',
                         char highestChar = 'M') {

  for (int i = 0; i < MAXS; ++i)
    out[i].clear();

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
    out[currentState].push_back(i); // There's a match of keywords[i] at node currentState.
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
        out[g[state][c]].insert(out[g[state][c]].end(), out[failure].begin(), out[failure].end()); // Merge out values
        q.push(g[state][c]);
      }
    }
  }

  return states;
}

int findNextState(int currentState, char nextInput,
                                    char lowestChar = 'B') {
  int answer = currentState;
  int c = nextInput - lowestChar;
  while (g[answer][c] == -1) answer = f[answer];
  return g[answer][c];
}

set<string> seen;
vector<string> words;
vector<int> price;

void gen(string w) {
  if (seen.count(w) || w.size() > 3) return;
  seen.insert(w);
  if (w.size()) words.push_back(w);
  gen(w + "B");
  gen(w + "M");
  gen(w + "F");
}

int dp[3][41][41];
int nxt[41][300];


int states;

int fill_dp(string &line) {

  for (int i = 0; i < states; ++i) {
    for (int j = 0; j < states; ++j) {
      dp[0][i][j] = 0;
    }
  }

  int cur = 1;
  for (int i = line.size() - 1; i >= 0; --i) {
    for (int j = 0; j < states; ++j) {
      for (int k = 0; k < states; ++k) {
        int ns1 = nxt[j][line[i]];
        int ns2 = nxt[k][line[i]];
        int op1 = dp[cur ^ 1][ns1][k] + price[ns1];
        int op2 = dp[cur ^ 1][j][ns2] + price[ns2];
        dp[cur][j][k] = max(op1, op2);
      }
    }
    cur ^= 1;
  }
  return dp[cur ^ 1][0][0];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  gen("");
  states = buildMatchingMachine(words);
  price.resize(states + 10);
  sort(words.begin(), words.end(), [](const string & a, const string & b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
  });

  set<int> last;
  for (auto &i: words) {
    set<char> s;
    int state = 0;
    for (auto &j : i) {
      s.insert(j);
      state = findNextState(state, j);
    }
    price[state] = s.size();
  }

  string tmp = "BFM";
  for (int i = 0; i < states; ++i) {
    for (auto &j : tmp)
      nxt[i][j] = findNextState(i, j);
  }
  int n;
  string line;
  while (cin >> n >> line) {
    cout << fill_dp(line) << endl;
  }
  return 0;
}
