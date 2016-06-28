#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MAXS = 1000 * 1000 + 1000;
const int MAXC = 'z' - 'a' + 1;
vector<int> out[MAXS];
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.

int buildMatchingMachine(const vector<string> &words,
                         char lowestChar = 'a',
                         char highestChar = 'z') {

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
                                    char lowestChar = 'a') {
  int answer = currentState;
  int c = nextInput - lowestChar;
  while (g[answer][c] == -1) answer = f[answer];
  return g[answer][c];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    vector<string> a(n);
    for (auto &i : a) cin >> i;
    int states = buildMatchingMachine(a);

    vector<vector<int>> g2(n);
    vector<int> inc(n);
    for (int i = 0; i < n; ++i) {
      string &from = a[i];
      int state = 0;
      for (int j = 0; j < from.size(); ++j) {
        state = findNextState(state, from[j]);
        for (auto &to : out[state]) {
          if (a[to].size() < from.size()) {
            g2[to].push_back(i);
            inc[i]++;
          }
        }
      }
    }

    vector<int> ans(n);
    deque<int> q;
    for (int i = 0; i < n; ++i)
      if (inc[i] == 0) {
        q.push_back(i);
        ans[i] = 1;
      }

    while (!q.empty()) {
      int cur = q.front();q.pop_front();
      for (auto &to : g2[cur]) {
        inc[to]--;
        ans[to] = max(ans[to], ans[cur] + 1);
        if (inc[to] == 0)
          q.push_back(to);
      }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
  }

  return 0;
}
