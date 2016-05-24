#include <bits/stdc++.h>

#define MAXS 100005
using namespace std;

struct Trie {
  int G[MAXS][26];
  int stateCount;

  Trie() {
    clear();
  }

  void clear() {
    stateCount = 1;
    memset(G[0], -1, sizeof(G[0]));
  }

  void add(const string &s) {
    int state = 0; //root
    for (int i = 0; i < s.size(); ++i) {
      int next = s[i] - 'a';
      if (G[state][next] == -1) { // add new state
        G[state][next] = stateCount;
        memset(G[stateCount], -1, sizeof(G[stateCount]));
        stateCount++;
      }
      state = G[state][next];
    }
  }
};

int meet[26];
Trie prefix_tree;
Trie suffix_tree;

void prefix_dfs(int state = 0, int depth = 0) {
  for (int i = 0; i < 26; ++i) {
    if (prefix_tree.G[state][i] == -1) continue;
    if (depth > 0) meet[i]++;
    prefix_dfs(prefix_tree.G[state][i], depth + 1);
  }
}

long long suffix_dfs(int state = 0, int depth = 0) {
  long long ans = 0;
  if ( depth > 0) ans = prefix_tree.stateCount - 1;
  for (int i = 0; i < 26; ++i) {
    if (suffix_tree.G[state][i] == -1)continue;
    if (depth > 0) ans-= meet[i]; // meet
    ans += suffix_dfs(suffix_tree.G[state][i],depth + 1);
  }
  return ans;
}

int main() {
  int p, s;
  while (cin >> p >> s && p + s) {
    string prefix,suffix;
    prefix_tree.clear();
    suffix_tree.clear();
    memset(meet, 0, sizeof(meet));
    for (int i = 0; i < p; ++i) {
      cin >> prefix;
      prefix_tree.add(prefix);
    }
    for (int i = 0; i < s; ++i) {
      cin >> suffix;
      reverse(suffix.begin(), suffix.end());
      suffix_tree.add(suffix);
    }
    prefix_dfs();
    cout << suffix_dfs() << endl;
  }
  return 0;
}

