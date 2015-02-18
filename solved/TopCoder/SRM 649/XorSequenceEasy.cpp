using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int get_max(vector<int> &A, int pos) {

  int all = 0, ans = 0;
  for (int i = 0; i < A.size(); ++i) {
    for (int j = i + 1; j < A.size(); ++j) {
      all++;
      if ((A[i] & (1 << pos)) < (A[j] & (1 << pos)))
        ans++;
    }
  }
  D(ans);
  return max(all - ans, ans);

}


class XorSequenceEasy {
  public:
    int getmax(vector <int> A, int N) {
/*
 *      int mask = 0;
 *      vector<int> pref;
 *      for (int i = 0; i < N; ++i) {
 *        mask ^= (1 << i);
 *        pref.push_back(mask);
 *      }
 *      D(pref.back());
 *      int ans = 0;
 *      for (int i = 0; i < pref.size(); ++i) {
 *        ans += get_max(A, pref[i]);
 *      }
 *
 */
      int ans = get_max(A, N - 1);

      return ans;

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
                int A[]                   = {3,2,1,0,3,2};
                int N                     = 4;
                int expected__            = 8;

                std::clock_t start__      = std::clock();
                int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int A[]                   = {3,0,4,6,1,5,7,6};
                int N                     = 8;
                int expected__            = 21;

                std::clock_t start__      = std::clock();
                int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int A[]                   = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9};
                int N                     = 16;
                int expected__            = 76;

                std::clock_t start__      = std::clock();
                int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int A[]                   = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};
                int N                     = 8;
                int expected__            = 0;

                std::clock_t start__      = std::clock();
                int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int A[]                   = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295 ,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108 ,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169 ,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484 ,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667};
                int N                     = 1073741824;
                int expected__            = 720;

                std::clock_t start__      = std::clock();
                int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      int A[]                   = ;
                      int N                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int A[]                   = ;
                      int N                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int A[]                   = ;
                      int N                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = XorSequenceEasy().getmax(vector <int>(A, A + (sizeof A / sizeof A[0])), N);
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


