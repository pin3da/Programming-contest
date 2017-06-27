#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

void add(string &s, int times, char c) {
  while (times--)
    s.push_back(c);
}

class ConstructLCS {
  public:
    string construct( int ab, int bc, int ca ) {
      vector<pair<int, int>> tmp = {{ab, 0}, {bc, 1}, {ca, 2}};
      vector<string> ans(3);
      sort(tmp.begin(), tmp.end());
      int cur = tmp[0].first;
      add(ans[0], cur, '0');
      add(ans[1], cur, '0');
      add(ans[2], cur, '0');

      int second = tmp[1].first - cur;
      if (second) {
        int id = tmp[1].second;
        add(ans[id], second, '1');
        add(ans[(id + 1) % 3], second, '1');

        int end = tmp[2].first - cur;
        id = tmp[2].second;
        add(ans[id], end, '0');
        add(ans[(id + 1) % 3], end, '0');
      } else {
        int end = tmp[2].first - cur;
        int id = tmp[2].second;
        add(ans[id], end, '1');
        add(ans[(id + 1) % 3], end, '1');
      }

      return ans[0] + " " + ans[1] + " " + ans[2];
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
                int ab                    = 3;
                int bc                    = 4;
                int ca                    = 2;
                string expected__         = "101 1010101 1111";

                std::clock_t start__      = std::clock();
                string received__         = ConstructLCS().construct(ab, bc, ca);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int ab                    = 7;
                int bc                    = 4;
                int ca                    = 4;
                string expected__         = "10101010 1010101 1011";

                std::clock_t start__      = std::clock();
                string received__         = ConstructLCS().construct(ab, bc, ca);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int ab                    = 8;
                int bc                    = 7;
                int ca                    = 8;
                string expected__         = "110101001011 010101101 10101010";

                std::clock_t start__      = std::clock();
                string received__         = ConstructLCS().construct(ab, bc, ca);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int ab                    = 8;
                int bc                    = 6;
                int ca                    = 7;
                string expected__         = "110101010 10101010 1111010";

                std::clock_t start__      = std::clock();
                string received__         = ConstructLCS().construct(ab, bc, ca);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int ab                    = 15;
                int bc                    = 17;
                int ca                    = 19;
                string expected__         = "000100101101111011000 11110111010011101010 100100001010101001010101000011111";

                std::clock_t start__      = std::clock();
                string received__         = ConstructLCS().construct(ab, bc, ca);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 5: {
                int ab                    = 50;
                int bc                    = 50;
                int ca                    = 50;
                string expected__         = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111";

                std::clock_t start__      = std::clock();
                string received__         = ConstructLCS().construct(ab, bc, ca);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

                    case 6: {
                      int ab                    = 1;
                      int bc                    = 10;
                      int ca                    = 20;
                      string expected__         = "12";

                      std::clock_t start__      = std::clock();
                      string received__         = ConstructLCS().construct(ab, bc, ca);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }
              /*      case 7: {
                      int ab                    = ;
                      int bc                    = ;
                      int ca                    = ;
                      string expected__         = ;

                      std::clock_t start__      = std::clock();
                      string received__         = ConstructLCS().construct(ab, bc, ca);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 8: {
                      int ab                    = ;
                      int bc                    = ;
                      int ca                    = ;
                      string expected__         = ;

                      std::clock_t start__      = std::clock();
                      string received__         = ConstructLCS().construct(ab, bc, ca);
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
