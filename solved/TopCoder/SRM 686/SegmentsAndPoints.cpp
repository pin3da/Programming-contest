#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x " = " << (x) << endl

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

class SegmentsAndPoints {
  public:
    string isPossible( vector <int> p, vector <int> l, vector <int> r ) {
      int n = p.size();
      VVI w(n, VI(n));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (p[i] >= l[j] && p[i] <= r[j])
            w[i][j] = 1;
        }
      }

      VI lb, rb;
      int t = BipartiteMatching(w, lb, rb);
      if (t == n) return "Possible";
      return "Impossible";
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

  int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) {
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
      std::cerr << "    Expected: \"" << expected << "\"" << std::endl;
      std::cerr << "    Received: \"" << received << "\"" << std::endl;
    }

    return verdict == "PASSED";
  }

  int run_test_case(int casenum__) {
    switch (casenum__) {
      case 0: {
                int p[]                   = {1, 2};
                int l[]                   = {0, 0};
                int r[]                   = {1, 3};
                string expected__         = "Possible";

                std::clock_t start__      = std::clock();
                string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int p[]                   = {0};
                int l[]                   = {2};
                int r[]                   = {3};
                string expected__         = "Impossible";

                std::clock_t start__      = std::clock();
                string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int p[]                   = {0, 1, 2};
                int l[]                   = {0, 0, 1};
                int r[]                   = {1, 2, 1};
                string expected__         = "Possible";

                std::clock_t start__      = std::clock();
                string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int p[]                   = {0, 1};
                int l[]                   = {-1, 0};
                int r[]                   = {0, 0};
                string expected__         = "Impossible";

                std::clock_t start__      = std::clock();
                string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int p[]                   = {434, 63, 241, 418, -380, -46, 397, -205, -262, -282, 260, -106, -389, -286, 422, -75, 127, 382, 52, -383};
                int l[]                   = {-447, -226, -411, 287, -83, -228, -390, 358, 422, 395, -461, -112, 49, 75, -160, -152, 372, -447, -337, -362};
                int r[]                   = {-102, 348, -70, 466, 168, -61, -389, 469, 433, 471, -75, -41, 52, 236, 299, -48, 383, -353, 346, -217};
                string expected__         = "Possible";

                std::clock_t start__      = std::clock();
                string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      int p[]                   = ;
                      int l[]                   = ;
                      int r[]                   = ;
                      string expected__         = ;

                      std::clock_t start__      = std::clock();
                      string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int p[]                   = ;
                      int l[]                   = ;
                      int r[]                   = ;
                      string expected__         = ;

                      std::clock_t start__      = std::clock();
                      string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int p[]                   = ;
                      int l[]                   = ;
                      int r[]                   = ;
                      string expected__         = ;

                      std::clock_t start__      = std::clock();
                      string received__         = SegmentsAndPoints().isPossible(vector <int>(p, p + (sizeof p / sizeof p[0])), vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(r, r + (sizeof r / sizeof r[0])));
                      return verify_case(casenum__, expected__, received__, clock()-start__);
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
