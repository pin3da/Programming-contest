// WA
#include <string>
#include <vector>
using namespace std;

class ANewHope {
  public:
    int count( vector <int> f, vector <int> l, int D ) {
      vector<int> b(f.size()), e(f.size());
      int n = f.size();
      for (int i = 0; i < f.size(); ++i) {
        b[f[i] - 1] = i;
        e[l[i] - 1] = i;
      }
      vector<int> d(n);
      int total = 0;
      for (int i = 0; i < n; ++i) {
        d[i] = n - 1 - b[i] + e[i];
        if (d[i] < D)
          total += D - d[i];
      }
      return max(total, 1);
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
                int firstWeek[]           = {1,2,3,4};
                int lastWeek[]            = {4,3,2,1};
                int D                     = 3;
                int expected__            = 4;

                std::clock_t start__      = std::clock();
                int received__            = ANewHope().count(vector <int>(firstWeek, firstWeek + (sizeof firstWeek / sizeof firstWeek[0])), vector <int>(lastWeek, lastWeek + (sizeof lastWeek / sizeof lastWeek[0])), D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int firstWeek[]           = {8,5,4,1,7,6,3,2};
                int lastWeek[]            = {2,4,6,8,1,3,5,7};
                int D                     = 3;
                int expected__            = 3;

                std::clock_t start__      = std::clock();
                int received__            = ANewHope().count(vector <int>(firstWeek, firstWeek + (sizeof firstWeek / sizeof firstWeek[0])), vector <int>(lastWeek, lastWeek + (sizeof lastWeek / sizeof lastWeek[0])), D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int firstWeek[]           = {1,2,3,4};
                int lastWeek[]            = {1,2,3,4};
                int D                     = 2;
                int expected__            = 1;

                std::clock_t start__      = std::clock();
                int received__            = ANewHope().count(vector <int>(firstWeek, firstWeek + (sizeof firstWeek / sizeof firstWeek[0])), vector <int>(lastWeek, lastWeek + (sizeof lastWeek / sizeof lastWeek[0])), D);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 3: {
                      int firstWeek[]           = ;
                      int lastWeek[]            = ;
                      int D                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = ANewHope().count(vector <int>(firstWeek, firstWeek + (sizeof firstWeek / sizeof firstWeek[0])), vector <int>(lastWeek, lastWeek + (sizeof lastWeek / sizeof lastWeek[0])), D);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 4: {
                      int firstWeek[]           = ;
                      int lastWeek[]            = ;
                      int D                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = ANewHope().count(vector <int>(firstWeek, firstWeek + (sizeof firstWeek / sizeof firstWeek[0])), vector <int>(lastWeek, lastWeek + (sizeof lastWeek / sizeof lastWeek[0])), D);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 5: {
                      int firstWeek[]           = ;
                      int lastWeek[]            = ;
                      int D                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = ANewHope().count(vector <int>(firstWeek, firstWeek + (sizeof firstWeek / sizeof firstWeek[0])), vector <int>(lastWeek, lastWeek + (sizeof lastWeek / sizeof lastWeek[0])), D);
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
