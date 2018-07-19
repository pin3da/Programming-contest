#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  pair<bool, int> GetRight(map<long long, int> &small, long long target) {
    if (small.size() == 0) return {false, -1};
    auto it = small.upper_bound(target);
    if (it == small.begin()) return {false, -1};
    it--;
    return {true, int(it->second)};
  }

  public:
  int shortestSubarray(vector<int>& A, int K) {
    map<long long, int> small;
    small[0] = -1;
    long long acc = 0;
    int best = A.size() + 10;
    for (int i = 0; i < int(A.size()); i++) {
      acc += A[i];

      auto prev = GetRight(small, acc - K);
      if (prev.first) {
        best = min(best, i - prev.second);
      }

      while (small.size() && (--small.end())->first >= acc)
        small.erase(--small.end());

      small[acc] = i;
    }

    return best <= int(A.size()) ? best : -1;
  }
};

int main(int argc, char **argv) {
  Solution sol;

  vector<pair<vector<int>, int>> dataset;

  dataset.emplace_back(vector<int>({1}), 1);
  dataset.emplace_back(vector<int>({1, 2}), 4);
  dataset.emplace_back(vector<int>({2, -1, 2}), 3);
  dataset.emplace_back(vector<int>({2, -1, 2}), 3);
  dataset.emplace_back(vector<int>({48, 99, 37, 4, -31}), 140);
  dataset.emplace_back(vector<int>({-1, -2}), 0);
  dataset.emplace_back(vector<int>({56, -21, 56, 35, -9}), 61);

  if (argc == 2) {
    int tid = atoi(argv[1]);
    auto t = dataset[tid];
    cout << sol.shortestSubarray(t.first, t.second) << endl;
  } else {
    for (auto t : dataset) {
      cout << sol.shortestSubarray(t.first, t.second) << endl;
    }
  }
  return 0;
}
