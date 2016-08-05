#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


const int MAXS = 100000 + 1000 ; // Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.

const int MAXC = 'j' - 'a' + 1; // Number of characters in the alphabet.

bool out[MAXS]; // true if any match

// Used internally in the algorithm.
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.

int buildMatchingMachine(const vector<string> &words,
    char lowestChar = 'a',
    char highestChar = 'j') {

  memset(out, 0, sizeof out);
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
    out[currentState] = true; // There's a match of keywords[i] at node currentState.
  }

  // State 0 should have an outgoing edge for all characters.
  for (int c = 0; c < MAXC; ++c) {
    if (g[0][c] == -1) {
      g[0][c] = 0;
    }
  }

  // Now, let's build the failure function
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


int findNextState(int currentState, int c) {
  int answer = currentState;
  while (g[answer][c] == -1) answer = f[answer];
  return g[answer][c];
}


int color[55][MAXS];
int dp[55][MAXS];
int curcol;

int go(int l, int mw, int state) {
  if (mw == 0) return 0;
  if (out[state]) return 0;

  if (color[mw][state] == curcol) return dp[mw][state];
  color[mw][state] = curcol;

  int mex[11];
  memset(mex, 0, sizeof mex);
  for (int i = 0; i < l; ++i) {
    int tmp = go(l, mw - 1, findNextState(state, i));
    if (tmp < 11)
      mex[tmp] = true;
  }
  for (int i = 0; i < 11; ++i) {
    if (!mex[i])
      return dp[mw][state] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int d, l;
  memset(color, 0, sizeof color);
  while (cin >> d >> l) {
    vector<string> adj(d);
    for (int i = 0; i < d; ++i) {
      cin >> adj[i];
    }

    int tot_states = buildMatchingMachine(adj);

    int w; cin >> w;
    int win = 0;
    curcol = 1;
    for (int i = 0; i < w; ++i) {
      string line;
      int maxw;
      cin >> line >> maxw;
      int state = 0;
      for (int j = 0; j < line.size(); ++j) {
        state = findNextState(state, line[j] - 'a');
      }

      curcol++;
      win ^= go(l, maxw, state);
    }

    puts(win != 0 ? "Tyrion" : "Daenerys");
  }

  return 0;
}
