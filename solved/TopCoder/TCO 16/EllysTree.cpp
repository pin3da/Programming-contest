#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x " = " << (x) << endl

typedef vector<vector<int>> graph;

const int MN = 111;
int ans[MN], seen[MN];

bool bt(graph &g, int node, int id) {
  if (g.size() - 1 == id)
    return true;

  seen[node] = true;
  for (int i = 0; i < g.size(); ++i) {
    if (g[node][i] && !seen[i]) {
      seen[i] = true;
      ans[id] = i;
      if (bt(g, i, id + 1))
        return true;
      seen[i] = false;
    }
  }
  return false;
}

class EllysTree {
  public:
    vector <int> getMoves( vector <int> p ) {
      int n = p.size() + 1;
      graph mat(n, vector<int>(n, 0));
      for (int i = 0; i < p.size(); ++i) {
        mat[p[i]][i + 1] = 1;
      }

      for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);

      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          mat[i][j] = mat[i][j] || mat[j][i];

      vector<int> cur;
      memset(seen, 0, sizeof seen);
      if (bt(mat, 0, 0)) {
        for (int i = 0; i < n - 1; ++i)
          cur.emplace_back(ans[i]);
      }
      return cur;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
  using std::string;
  using std::vector;
  int run_test_case(int);
  void run_test(int casenum = -1, bool quiet = false) {
    if (casenum != -1) {
      if (run_test_case(casenum) == -1 && !quiet) {
        std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
      }
      return;
    }

    int correct = 0, total = 0;
    for (int i=0;; ++i) {
      int x = run_test_case(i);
      if (x == -1) {
        if (i >= 100) break;
        continue;
      }
      correct += x;
      ++total;
    }

    if (total == 0) {
      std::cerr << "No test cases run." << std::endl;
    } else if (correct < total) {
      std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
    } else {
      std::cerr << "All " << total << " tests passed!" << std::endl;
    }
  }

  template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

  int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) {
    std::cerr << "Example " << casenum << "... ";

    string verdict;
    vector<string> info;
    char buf[100];

    if (elapsed > CLOCKS_PER_SEC / 200) {
      std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
      info.push_back(buf);
    }

    if (expected == received) {
      verdict = "PASSED";
    } else {
      verdict = "FAILED";
    }

    std::cerr << verdict;
    if (!info.empty()) {
      std::cerr << " (";
      for (size_t i=0; i<info.size(); ++i) {
        if (i > 0) std::cerr << ", ";
        std::cerr << info[i];
      }
      std::cerr << ")";
    }
    std::cerr << std::endl;

    if (verdict == "FAILED") {
      std::cerr << "    Expected: " << expected << std::endl;
      std::cerr << "    Received: " << received << std::endl;
    }

    return verdict == "PASSED";
  }

  int run_test_case(int casenum__) {
    switch (casenum__) {
      case 0: {
                int parent[]              = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
                int expected__[]          = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };

                std::clock_t start__      = std::clock();
                vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 1: {
                int parent[]              = {3, 4, 5, 0, 2};
                int expected__[]          = {1, 2, 3, 4, 5 };

                std::clock_t start__      = std::clock();
                vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 2: {
                int parent[]              = {0, 0};
                int expected__[]          = { };

                std::clock_t start__      = std::clock();
                vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }
      case 3: {
                int parent[]              = {0, 6, 6, 2, 6, 1, 3, 5};
                int expected__[]          = {2, 4, 1, 3, 7, 6, 5, 8 };

                std::clock_t start__      = std::clock();
                vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
              }

              // custom cases

              /*      case 4: {
                      int parent[]              = ;
                      int expected__[]          = ;

                      std::clock_t start__      = std::clock();
                      vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                      return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
              /*      case 5: {
                      int parent[]              = ;
                      int expected__[]          = ;

                      std::clock_t start__      = std::clock();
                      vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                      return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int parent[]              = ;
                      int expected__[]          = ;

                      std::clock_t start__      = std::clock();
                      vector <int> received__   = EllysTree().getMoves(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])));
                      return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                      }*/
      default:
              return -1;
    }
  }
}


#include <cstdlib>
int main(int argc, char *argv[]) {
  if (argc == 1) {
    moj_harness::run_test();
  } else {
    for (int i=1; i<argc; ++i)
      moj_harness::run_test(std::atoi(argv[i]));
  }
}
// END CUT HERE
