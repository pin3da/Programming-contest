#include <bits/stdc++.h>
using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Trie {
  struct Node {
    bool is_end;
    map<char, Node*> next;
    Node() : is_end(false), next() {}
  };

  Node *root;

  Trie() {
    root = new Node();
  }

  void Add(string w) {
    Node *cur = root;
    for (auto c : w) {
      if (cur->next.count(c) == 0) cur->next[c] = new Node();
      cur = cur->next[c];
    }
    cur->is_end = true;
  }
};

const int inf = 1000000;
pair<bool, int> memo[1000000];

class Solution {
  Trie trie;
  int getMax(string &w, int pos) {
    if (pos >= int(w.size())) return 0;
    if (memo[pos].first) return memo[pos].second;

    memo[pos].first = true;

    Trie::Node* cur_state = trie.root;
    int best = -inf;
    for (int i = pos; i < int(w.size()); i++) {
      if (cur_state->next.count(w[i]) == 0) break;
      cur_state = cur_state->next[w[i]];
      if (cur_state->is_end) {
        best = max(best, 1 + getMax(w, i + 1));
        if (best > 1) break;
      }
    }
    return memo[pos].second = best;
  }

  int GetMaxWords(string &w) {
    for (int i = 0; i < int(w.size()); i++) memo[i].first = false;
    return getMax(w, 0);
  }
  public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    for (auto w : words) trie.Add(w);
    vector<string> ans;

    for (auto w : words) {
      if (GetMaxWords(w) > 1) ans.push_back(w);
    }

    return ans;
  }
};

int main() {
  vector<string> input = {"a","b","ab","abc"};
  Solution sol;
  auto ans = sol.findAllConcatenatedWordsInADict(input);
  for (auto it : ans)
    cout << it << endl;
  return 0;
}
