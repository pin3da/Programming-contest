using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

class LongLongTripDiv2 {
  public:
    string isAble(long long D, int T, int B) {

      int lo = 0, hi = T;
      while (lo < hi) {
        long long b = (lo + hi ) / 2;
        long long a = T - b;
        //D(lo);
        //D(hi);
        //D(a + b*B);
        if (D <= (a + b*B)) {
          hi = b;
        } else {
          lo = b + 1;
        }
      }
      long long b = lo;
      long long a = T - b;
      if (D == (a + b*B))
        return "Possible";
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
			long long D               = 10;
			int T                     = 6;
			int B                     = 3;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long D               = 10;
			int T                     = 5;
			int B                     = 3;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long D               = 50;
			int T                     = 100;
			int B                     = 2;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long D               = 120;
			int T                     = 10;
			int B                     = 11;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long D               = 10;
			int T                     = 10;
			int B                     = 9999;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long D               = 1000;
			int T                     = 100;
			int B                     = 10;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			long long D               = 1000010000100001LL;
			int T                     = 1100011000;
			int B                     = 1000000000;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			long long D               = ;
			int T                     = ;
			int B                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long D               = ;
			int T                     = ;
			int B                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			long long D               = ;
			int T                     = ;
			int B                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = LongLongTripDiv2().isAble(D, T, B);
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
