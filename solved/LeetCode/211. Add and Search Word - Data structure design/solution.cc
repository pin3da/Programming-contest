class WordDictionary {
  struct TrieNode {
    map<char, int> next;
    bool is_end;
    TrieNode() : is_end(false) {}
  };
  vector<TrieNode> nodes;

  public:

  WordDictionary() {
    genNode();
  }

  int genNode() {
    nodes.push_back(TrieNode());
    return nodes.size() - 1;
  }


  void addWord(string word) {
    int node = 0;
    for (auto c : word) {
      if (nodes[node].next.count(c) == 0) nodes[node].next[c] = genNode();
      node = nodes[node].next[c];
    }
    nodes[node].is_end = true;
  }

  bool dfs(string word, int pos, int node) {
    if (pos >= word.size()) return nodes[node].is_end;
    if (word[pos] == '.') {
      for (auto to : nodes[node].next) {
        if (dfs(word, pos + 1, to.second)) return true;
      }
      return false;
    }

    if (nodes[node].next.count(word[pos]) == 0) return false;
    return dfs(word, pos + 1, nodes[node].next[word[pos]]);
  }

  bool search(string word) {
    return dfs(word, 0, 0);
  }
};
