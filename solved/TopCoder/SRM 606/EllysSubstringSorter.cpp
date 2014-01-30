using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

class EllysSubstringSorter {
  public:
    string getMin(string S, int L) {
      set<string> ans;
      for (int i = 0; i <= S.size() - L; ++i) {
        string tmp = S;
        sort( tmp.begin() + i, tmp.begin() + i + L);
        //D(tmp);
        ans.insert(tmp);
      }
      return (*ans.begin());
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
			string S                  = "TOPCODER";
			int L                     = 4;
			string expected__         = "COPTODER";

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "ESPRIT";
			int L                     = 3;
			string expected__         = "EPRSIT";

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "AAAAAAAAA";
			int L                     = 2;
			string expected__         = "AAAAAAAAA";

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "ABRACADABRA";
			int L                     = 5;
			string expected__         = "AAABCRDABRA";

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "BAZINGA";
			int L                     = 6;
			string expected__         = "ABGINZA";

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int L                     = 21;
			string expected__         = "AAAAAABDDDEEIIIJOOSUWWWWDBPOAWDUISAWDOOPAWD";

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			int L                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int L                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int L                     = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysSubstringSorter().getMin(S, L);
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
