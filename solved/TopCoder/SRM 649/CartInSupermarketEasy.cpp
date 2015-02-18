using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int dp[111][111];

int go(int n, int k) {
  if (n <= 2)
    return n;

  if (k == 0)
    return n;


  if (dp[n][k] != -1)
    return dp[n][k];

  int best = 100000;
  for (int j = 0; j < k; ++j) {
    for (int i = 1; i < n; ++i) {
      best = min(best, max(go(i, j), go(n - i, k - 1 - j)) + 1);
    }
  }

  return dp[n][k] = best;
}

class CartInSupermarketEasy {
  public:
    int calc(int N, int K) {
      memset(dp, -1, sizeof dp);
      return go(N, K);
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

  int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) {
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
                int N                     = 5;
                int K                     = 0;
                int expected__            = 5;

                std::clock_t start__      = std::clock();
                int received__            = CartInSupermarketEasy().calc(N, K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int N                     = 5;
                int K                     = 2;
                int expected__            = 4;

                std::clock_t start__      = std::clock();
                int received__            = CartInSupermarketEasy().calc(N, K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int N                     = 15;
                int K                     = 4;
                int expected__            = 6;

                std::clock_t start__      = std::clock();
                int received__            = CartInSupermarketEasy().calc(N, K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int N                     = 7;
                int K                     = 100;
                int expected__            = 4;

                std::clock_t start__      = std::clock();
                int received__            = CartInSupermarketEasy().calc(N, K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int N                     = 45;
                int K                     = 5;
                int expected__            = 11;

                std::clock_t start__      = std::clock();
                int received__            = CartInSupermarketEasy().calc(N, K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 5: {
                int N                     = 100;
                int K                     = 100;
                int expected__            = 8;

                std::clock_t start__      = std::clock();
                int received__            = CartInSupermarketEasy().calc(N, K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 6: {
                      int N                     = ;
                      int K                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = CartInSupermarketEasy().calc(N, K);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int N                     = ;
                      int K                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = CartInSupermarketEasy().calc(N, K);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 8: {
                      int N                     = ;
                      int K                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = CartInSupermarketEasy().calc(N, K);
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


