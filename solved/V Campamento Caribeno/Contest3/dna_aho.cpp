using namespace std;
#include<bits/stdc++.h>

vector<string> all;



const int MAXS = 20*50 + 10 ;
const int MAXC = 26;
bitset<500> out[MAXS];
int f[MAXS]; // Failure function
int g[MAXS][MAXC]; // Goto function, or -1 if fail.


int buildMatchingMachine(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z') {
    for(int  i = 0 ; i< MAXS; ++i)
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

int findNextState(int currentState, char nextInput, char lowestChar = 'a') {
    int answer = currentState;
    int c = nextInput - lowestChar;
    while (g[answer][c] == -1) answer = f[answer];
    return g[answer][c];
}

string line;

int memo[1000][1000];


int arr [] = { 'A', 'G', 'C', 'T'};

int num(char c) {
  if (c == 'A') return 0;
  if (c == 'G') return 1;
  if (c == 'C') return 2;
  return 3;
}

int dp(int id, int state) {
  if (id == line.size() ) return 0;
  if (memo[id][state] != -1) return memo[id][state];
  int ans = 20000;
  for (int i = 0; i < 4; ++i) {
    int llevo = (num(line[id]) != i);
    int next_state = findNextState(state, arr[i], 'A');
    int ok = 1;
    for (int j = 0; j < all.size(); ++j)
        if (out[next_state].test(j)) ok = 0;
    if (ok)
      ans = min(ans, llevo + dp(id + 1, next_state));

  }
  return memo[id][state] = ans;
}
int main() {
  int n;
  int caso = 0;
  while(cin>>n and n) {
    all.resize(n);

    for (int i = 0; i<  n; ++i)
      cin>>all[i];

    cin>>line;

    buildMatchingMachine(all, 'A', 'Z');
    memset(memo, -1, sizeof memo);
    int ans = dp(0,0);
    if (ans == 20000) ans  = -1;
    cout<<"Case "<<++caso<<": "<<ans<<endl;
  }
  return 0;
}
