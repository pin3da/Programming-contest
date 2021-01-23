class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    memo = vector<vector<int>>(501, vector<int>(501, -1));

    vector<set<int>> lang(languages.size());
    for (int i = 0; i < languages.size(); i++) {
      for (auto it : languages[i])  lang[i].insert(it);
    }

    int best = languages.size();
    for (int cur = 0; cur < n; cur++) {
      set<int> toTeach;
      for (auto& fri : friendships) {
        assert(fri.size() == 2);
        if (!CanTalk(fri[0] - 1, fri[1] - 1, languages)) {
          for (auto person : fri) {
            if (lang[person - 1].count(cur) == 0) {
              toTeach.insert(person);
            }
          }
        }
      }
      best = min<int>(toTeach.size(), best);
    }
    return best;
  }

 private:
  bool CanTalk(int a, int b, const vector<vector<int>>& lang) {
    if (memo[a][b] != -1) return memo[a][b];

    set<int> A(lang[a].begin(), lang[a].end());
    for (auto it : lang[b]) {
      if (A.count(it)) {
        return memo[a][b] = 1;
      }
    }
    return memo[a][b] = 0;
  }

  vector<vector<int>> memo;
};
