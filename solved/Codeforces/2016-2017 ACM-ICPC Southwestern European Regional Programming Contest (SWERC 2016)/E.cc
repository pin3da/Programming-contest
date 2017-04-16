#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

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

char get_real_char(char c) {
  if (c >= 'a' && c <= 'z')
    return c;

  if (c >= 'A' && c <= 'Z') {
    return (c - 'A') + 'a';
  }

  if (c == '0') return 'o';
  if (c == '1') return 'i';
  if (c == '3') return 'e';
  if (c == '5') return 's';
  if (c == '7') return 't';
  return c;
}

string alpha;
int A, B;

const int mod = 1000003;

int dp[1001][21][2][2][2];

int go(int state, int len, int upper, int lower, int digit) {
  if (len > B) return 0;

  if (dp[state][len][upper][lower][digit] != -1)
    return dp[state][len][upper][lower][digit];

  int ans = 0;
  if (len >= A && upper && lower && digit)
    ans += 1;

  for (char c : alpha) {
    int n_state = findNextState(state, get_real_char(c));
    if (out[n_state].any()) continue;
    int n_upper = upper || isupper(c);
    int n_lower = lower || islower(c);
    int n_digit = digit || isdigit(c);
    ans = (ans + go(n_state, len + 1, n_upper, n_lower, n_digit)) % mod;
  }
  return dp[state][len][upper][lower][digit] = ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  cin >> A >> B;
  int n; cin >> n;
  vector<string> words(n);
  for (auto &i : words)
    cin >> i;

  buildMatchingMachine(words);

  for (char c = 'a'; c <= 'z'; ++c)
    alpha.push_back(c);

  for (char c = 'A'; c <= 'Z'; ++c)
    alpha.push_back(c);

  for (char c = '0'; c <= '9'; ++c)
    alpha.push_back(c);

  memset(dp, -1, sizeof dp);
  cout << go(0, 0, 0, 0, 0) << endl;

  return 0;
}
