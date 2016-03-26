#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x " = " << (x) << endl

const int inf = 1000000000 + 1000;

const int MN = 1000 + 10;
int dp[MN][MN];

void fill_dp(vector<int> &s, int P) {
  for (int i = 1;  i <= P; ++i) {
    dp[s.size()][i] = inf;
    dp[s.size() + 1][i] = inf;
  }

  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = 0; j <= P; ++j) {
      dp[i][j] = dp[i + 1][j];
      if (j && i + 1 < s.size())
        dp[i][j] = min(dp[i][j], max(dp[i + 2][j - 1], s[i + 1] - s[i]));
    }
  }
}

class EllysSocks {
  public:
    int getDifference( vector <int> S, int P ) {
      sort(S.begin(), S.end());
      fill_dp(S, P);
      return dp[0][P];
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
                int S[]                   = {42, 37, 84, 36, 41, 42};
                int P                     = 2;
                int expected__            = 1;

                std::clock_t start__      = std::clock();
                int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int S[]                   = {42, 37, 84, 36, 41, 42};
                int P                     = 3;
                int expected__            = 42;

                std::clock_t start__      = std::clock();
                int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int S[]                   = {5, 2, 8, 8, 6, 7, 3, 7, 4, 2, 4, 5, 3, 6};
                int P                     = 7;
                int expected__            = 0;

                std::clock_t start__      = std::clock();
                int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int S[]                   = {17, 3, 13, 3, 2, 17, 11, 5, 5, 7, 11, 7, 13, 19};
                int P                     = 7;
                int expected__            = 4;

                std::clock_t start__      = std::clock();
                int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int S[]                   = {795755685, 581869303, 404620563, 708632712, 545404205, 133711906, 372047868, 949333986, 579004999, 323567404, 418932836, 944672732, 196140741, 809094427, 946129058, 30574577, 182506778, 15198493, 150802600, 138749191, 676943010, 177512688, 126303054, 81133258, 183966551, 471852627, 84672537, 867128744, 857788837, 275731772, 609397213, 20544910, 811450930, 483031419, 361913171, 547204602, 892462744, 522136404, 173978710, 131752569, 478582453, 867889991, 153380496, 551745921, 647984700, 910208077, 283496852, 368550363, 379821990, 712568903, 40498239, 113911604, 103237637, 39073007, 684602223, 812852787, 479711181, 746745228, 735241235, 296707007, 262522458, 870676136, 136721027, 359573809, 189375153, 547914047, 198304613, 640439653, 417177802, 25475624, 758242872, 764919655, 310701088, 537655880, 361931892, 14685971, 213794688, 107063881, 147944789, 444803289, 884392679, 540721924, 638781100, 902841101, 7097711, 219972874, 879609715, 156513984, 802611721, 755486970, 103522060, 967048445, 913778155, 94092596, 519074050, 884870761, 248268555, 339840186, 53612697, 826647953};
                int P                     = 42;
                int expected__            = 12866316;

                std::clock_t start__      = std::clock();
                int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

      case 5: {
                int S[]                   = {1, 3, 5, 20};
                int P                     = 2;
                int expected__            = 15;

                std::clock_t start__      = std::clock();
                int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
              /*      case 6: {
                      int S[]                   = ;
                      int P                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int S[]                   = ;
                      int P                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = EllysSocks().getDifference(vector <int>(S, S + (sizeof S / sizeof S[0])), P);
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
