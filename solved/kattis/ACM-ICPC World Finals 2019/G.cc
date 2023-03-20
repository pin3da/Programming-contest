#include <bits/stdc++.h>

using namespace std;

struct Lady {
  char initial;
  int parent;
};

std::vector<Lady> ReadLadies(int num_ladies) {
  std::vector<Lady> ladies(num_ladies);
  for (auto& lady : ladies) {
    cin >> lady.initial;
    cin >> lady.parent;
    lady.parent--;
  }
  return ladies;
}

void debug(vector<int> arr) {
  for (auto i : arr) cout << i;
  cout << endl;
}

vector<int> SortLadies(const vector<Lady>& ladies) {
  using RankPair = pair<int, int>;

  vector<int> lady_rank(ladies.size());
  for (int i = 0; i < ladies.size(); ++i) {
    lady_rank[i] = ladies[i].initial;
  }
  std::vector<int> lady_ancestors(ladies.size());
  for (int i = 0; i < lady_ancestors.size(); ++i) {
    lady_ancestors[i] = ladies[i].parent;
  }
  for (int len = 1; len <= ladies.size(); len *= 2) {
    vector<pair<RankPair, int>> new_rank(lady_rank.size());
    vector<int> new_lady_ancestors = lady_ancestors;
    for (int i = 0; i < lady_rank.size(); i++) {
      int ancestor_rank =
          lady_ancestors[i] == -1 ? -1 : lady_rank[lady_ancestors[i]];
      new_rank[i] = {{lady_rank[i], ancestor_rank}, i};
      if (lady_ancestors[i] != -1)
        new_lady_ancestors[i] = lady_ancestors[lady_ancestors[i]];
    }
    sort(new_rank.begin(), new_rank.end());
    int rank = 0;
    for (int i = 0; i < lady_rank.size(); i++) {
      if (i > 0 && new_rank[i - 1].first != new_rank[i].first) rank++;
      lady_rank[new_rank[i].second] = rank;
    }

    lady_ancestors = std::move(new_lady_ancestors);
  }

  vector<int> lady_in_pos(ladies.size());
  for (int i = 0; i < ladies.size(); ++i) lady_in_pos[lady_rank[i]] = i;
  return lady_in_pos;
}

// Returns the index of the first T in FFFFTTTTTT
int binary_search(int num_ladies, function<bool(int)> cmp) {
  int lo = 0;
  int hi = num_ladies;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (cmp(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int main(int argc, char* argv[]) {
  int num_ladies, num_queries;
  cin >> num_ladies >> num_queries;
  std::vector<Lady> ladies = ReadLadies(num_ladies);
  std::vector<int> lady_in_pos = SortLadies(ladies);

  while (num_queries--) {
    string query;
    cin >> query;
    // cmp(query, lady_in_pos[rank].substr(0, query.size()));
    auto cmp = [&](int rank) {
      int lady_index = lady_in_pos[rank];
      for (int i = 0; i < query.size(); ++i) {
        if (query[i] != ladies[lady_index].initial) {
          return query[i] < ladies[lady_index].initial ? -1 : 1;
        }
        lady_index = ladies[lady_index].parent;
        if (lady_index == -1 && (i + 1 < query.size())) return 1;
      }
      return 0;
    };
    // start: first idx, query <= lady
    int start =
        binary_search(num_ladies, [&cmp](int rank) { return cmp(rank) <= 0; });
    // end: fist idx, query < lady
    int end =
        binary_search(num_ladies, [&cmp](int rank) { return cmp(rank) < 0; });
    cout << end - start << endl;
  }
  return 0;
}
