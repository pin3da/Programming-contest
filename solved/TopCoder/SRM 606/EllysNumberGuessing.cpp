/**
 * F*ck*ng WA
 * I'll fix it.  I promise.
 * */

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

long long v(long long num) {
  if (num <= 0 or num > 1000000000)
    return -5;
  return num;
}

class EllysNumberGuessing {
  public:
    int getNumber(vector <int> g, vector <int> ans) {
        int posa = min (v(g[0] - ans[0]),v(ans[0] + g[0]) );
        int posb = max (v(g[0] - ans[0]),v(ans[0] + g[0]) );
        int mio = -1;
        if (1 == g.size()) {
          if (posa == -5 and posb == -5)
            return -1;
          if (-5 == posa)
            return posb;
          if (-5 == posb)
            return posa;
        }
        //D(posa);
        //D(posb);
        int numpos = 0;
        for (int i = 1; i < g.size(); ++i) {
          int a = min ( v(g[i] - ans[i]), v(ans[i] + g[i]));
          int b = max ( v(g[i] - ans[i]), v(ans[i] + g[i]));

          //D(a);
          //D(b);
          if (a == posa and b == posb) {
            if (numpos == 0)
              numpos = 2;
          }else {
            numpos = 1;
            int ok = 0;
            if (a == posa) {
              if (mio != -1 and mio != a) return -2;
              mio = a;
              ok = 1;
            }
            if (b == posb) {
              if (mio != -1 and mio != b) return -2;
              mio = b;
              ok = 1;
            }
            if (a == posb) {
              if (mio != -1 and mio != a) return -2;
              mio = a;
              ok = 1;
            }
            if (b == posa) {
              if (mio != -1 and mio != b) return -2;
              mio = b;
              ok = 1;
            }


            if(!ok) return -2;
          }

        }
        if (2 == numpos) return -1;
        return mio;
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
			int guesses[]             = {600, 594};
			int answers[]             = {6, 12};
			int expected__            = 606;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int guesses[]             = {100, 50, 34, 40};
			int answers[]             = {58, 8, 8, 2};
			int expected__            = 42;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int guesses[]             = {500000, 600000, 700000};
			int answers[]             = {120013, 220013, 79987};
			int expected__            = -2;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int guesses[]             = {500000000};
			int answers[]             = {133742666};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int guesses[]             = {76938260, 523164588, 14196746, 296286419, 535893832, 41243148, 364561227, 270003278, 472017422, 367932361, 395758413, 301278456, 186276934, 316343129, 336557549, 52536121, 98343562, 356769915, 89249181, 335191879};
			int answers[]             = {466274085, 20047757, 529015599, 246925926, 7318513, 501969197, 178651118, 273209067, 71194923, 175279984, 147453932, 241933889, 356935411, 226869216, 206654796, 490676224, 444868783, 186442430, 453963164, 208020466};
			int expected__            = 543212345;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int guesses[]             = {42};
			int answers[]             = {42};
			int expected__            = 84;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int guesses[]             = {999900000};
			int answers[]             = {100001};
			int expected__            = 999799999;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 7: {
			int guesses[]             = {10, 10, 10};
			int answers[]             = {5,5,5};
			int expected__            = -1;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int guesses[]             = ;
			int answers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int guesses[]             = ;
			int answers[]             = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = EllysNumberGuessing().getNumber(vector <int>(guesses, guesses + (sizeof guesses / sizeof guesses[0])), vector <int>(answers, answers + (sizeof answers / sizeof answers[0])));
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
