using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

class AmebaDiv2 {
  public:
    int simulate(vector <int> X, int A) {
      int ans = 0;
      for (int i = 0; i < X.size(); ++i) {
        if (X[i] == A) {
          ans ++;
          A += A;
        }

      }
      return A;
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
			int X[]                   = {2,1,3,1,2};
			int A                     = 1;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {1,4,9,16,25,36,49};
			int A                     = 10;
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {1,2,4,8,16,32,64,128,256,1024,2048};
			int A                     = 1;
			int expected__            = 512;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {817,832,817,832,126,817,63,63,126,817,832,287,823,817,574};
			int A                     = 63;
			int expected__            = 252;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int X[]                   = ;
			int A                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int X[]                   = ;
			int A                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X[]                   = ;
			int A                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = AmebaDiv2().simulate(vector <int>(X, X + (sizeof X / sizeof X[0])), A);
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
