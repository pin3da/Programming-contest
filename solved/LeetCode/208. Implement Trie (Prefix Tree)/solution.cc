#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Trie {
  vector<vector<int>> tree;
  vector<int> words;

  int addNode() {
    tree.push_back(vector<int>(27, -1));
    words.push_back(0);
    return words.size() - 1;
  }

  public:
  /** Initialize your data structure here. */
  Trie() {
    addNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    int state = 0;
    for (auto c : word) {
      int idx = c - 'a';
      int nxt = tree[state][idx];
      if (nxt == - 1) {
        nxt = addNode();
        tree[state][idx] = nxt;
      }
      state = nxt;
    }
    words[state]++;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    int state = 0;
    for (auto c : word) {
      int idx = c - 'a';
      int nxt = tree[state][idx];
      if (nxt == - 1) {
        return false;
      }
      state = nxt;
    }
    return words[state] > 0;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    int state = 0;
    for (auto c : prefix) {
      int idx = c - 'a';
      int nxt = tree[state][idx];
      if (nxt == - 1) {
        return false;
      }
      state = nxt;
    }
    return true;
  }
};

int main() {
  Trie obj;
  obj.insert("a");
  cout << obj.search("a") << endl;
  cout << obj.startsWith("a") << endl;
}
