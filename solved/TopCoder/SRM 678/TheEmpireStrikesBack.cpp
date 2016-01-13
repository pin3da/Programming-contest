// WA
#include <bits/stdc++.h>
using namespace std;

struct point{
  long long x, y;
  bool operator < (const point &o) const {
    if (y == o.y) return x < o.x;
    return y > o.y;
  }
};

long long fun(vector<long long> &p, long long dist, int M) {
  long long cur = p[0];
  while (M > 0) {
    vector<long long>::iterator place = lower_bound(p.begin(), p.end(), cur + dist);
    if (place == p.end()) return true;
    if (*(place) > cur + dist) place--;

    vector<long long>::iterator next = upper_bound(p.begin(), p.end(), *(place) + dist);
    if (next == p.end()) return true;
    cur = *next - dist + 1;
    M--;
  }
  return false;
}

int process(vector<point> &a, int M) {
  long long best = 1000000007LL;
  sort(a.begin(), a.end());
  vector<point> border;
  border.push_back(a[0]);
  for (int i = 1; i < a.size(); ++i) {
    if (a[i].y < border.back().y &&
        a[i].x > border.back().x) {
      border.push_back(a[i]);
    }
  }

  vector<long long> p(border.size());
  for (int i = 0; i < border.size(); ++i) {
    p[i] = border[i].x;
  }

  long long lo = 0, hi = best;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (fun(p, mid, M))
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

const long long mod = 1000000007LL;

class TheEmpireStrikesBack {
  public:
    int find( int AX, int BX, int CX, int AY, int BY, int CY, int N, int M ) {
      vector<point> a(N);
      a[0].x = AX;
      a[0].y = AY;
      for (int i = 1; i < N; ++i) {
        a[i].x = ((a[i-1].x * BX) % mod + CX) % 1000000007LL;
        a[i].y = ((a[i-1].y * BY) % mod + CY) % 1000000007LL;
      }
      int op1 = process(a, M);
      for (int i = 0; i < a.size(); ++i) {
        swap(a[i].x, a[i].y);
      }
      return min(op1, process(a, M));
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
                int AX                    = 2;
                int BX                    = 2;
                int CX                    = 2;
                int AY                    = 2;
                int BY                    = 2;
                int CY                    = 2;
                int N                     = 2;
                int M                     = 1;
                int expected__            = 0;

                std::clock_t start__      = std::clock();
                int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 1: {
                int AX                    = 2;
                int BX                    = 2;
                int CX                    = 2;
                int AY                    = 2;
                int BY                    = 4;
                int CY                    = 1000000000;
                int N                     = 2;
                int M                     = 1;
                int expected__            = 1;

                std::clock_t start__      = std::clock();
                int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 2: {
                int AX                    = 1;
                int BX                    = 3;
                int CX                    = 8;
                int AY                    = 10000;
                int BY                    = 10;
                int CY                    = 999910000;
                int N                     = 3;
                int M                     = 1;
                int expected__            = 30;

                std::clock_t start__      = std::clock();
                int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 3: {
                int AX                    = 0;
                int BX                    = 0;
                int CX                    = 0;
                int AY                    = 0;
                int BY                    = 0;
                int CY                    = 0;
                int N                     = 100000;
                int M                     = 1000;
                int expected__            = 0;

                std::clock_t start__      = std::clock();
                int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }
      case 4: {
                int AX                    = 10;
                int BX                    = 20;
                int CX                    = 30;
                int AY                    = 40;
                int BY                    = 50;
                int CY                    = 60;
                int N                     = 100000;
                int M                     = 10;
                int expected__            = 15720;

                std::clock_t start__      = std::clock();
                int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                return verify_case(casenum__, expected__, received__, clock()-start__);
              }

              // custom cases

              /*      case 5: {
                      int AX                    = ;
                      int BX                    = ;
                      int CX                    = ;
                      int AY                    = ;
                      int BY                    = ;
                      int CY                    = ;
                      int N                     = ;
                      int M                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 6: {
                      int AX                    = ;
                      int BX                    = ;
                      int CX                    = ;
                      int AY                    = ;
                      int BY                    = ;
                      int CY                    = ;
                      int N                     = ;
                      int M                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
                      return verify_case(casenum__, expected__, received__, clock()-start__);
                      }*/
              /*      case 7: {
                      int AX                    = ;
                      int BX                    = ;
                      int CX                    = ;
                      int AY                    = ;
                      int BY                    = ;
                      int CY                    = ;
                      int N                     = ;
                      int M                     = ;
                      int expected__            = ;

                      std::clock_t start__      = std::clock();
                      int received__            = TheEmpireStrikesBack().find(AX, BX, CX, AY, BY, CY, N, M);
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
