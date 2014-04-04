using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

#define MN 55

string s, a, b;
string mio;

int dp[MN][MN][MN];
int op[MN][MN][MN];

int go (int i, int j, int k) {
  if (i >= s.size()) return true;

  if (dp[i][j][k] != -1) return dp[i][j][k] ;
  int ans = false;
  int n = -1;
  if (j < a.size()) {
    if ((s[i] == a[j]) or (s[i] == '?')) {
      if (go(i+1, j + 1, k)) {
        ans = true;
        n = 0;
        mio[i] = a[j];
      }
    }
  }

  if(k < b.size()) {
    if ((s[i] == b[k]) or (s[i] == '?') ) {
      if (go(i+ 1, j, k + 1)) {
        ans = true;
        if (((n == 0) and (b[k] <= a[j])) or (n == -1)) {
          n = 1;
          mio[i] = b[k];
        }
      }
    }
  }
  op[i][j][k] = n;
  return dp[i][j][k] = ans;
}


class MergeStrings {
  public:
    string getmin(string S, string A, string B) {
      s = S;
      a = A;
      b = B;
      mio = string(S.size(),'0');
      memset(dp, -1, sizeof dp);
      memset(op, -1, sizeof op);

      if (go(0,0,0)) {
        int i = 0, j = 0, k = 0;
        string ans;
        while (i < s.size()) {
          if (op[i][j][k] == 0) {
            ans += a[j]; ++j;++i;
          } else if (op[i][j][k] == 1) {
            ans += b[k]; ++k;++i;
          }
        }
        return mio;
      } else {
        return "";
      }
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
			string S                  = "??CC??";
			string A                  = "ABC";
			string B                  = "BCC";
			string expected__         = "ABCCBC";

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "WHAT?";
			string A                  = "THE";
			string B                  = "WA";
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "PARROT";
			string A                  = "PARROT";
			string B                  = "";
			string expected__         = "PARROT";

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "???????????";
			string A                  = "AZZAA";
			string B                  = "AZAZZA";
			string expected__         = "AAZAZZAAZZA";

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "????K??????????????D???K???K????????K?????K???????";
			string A                  = "KKKKKDKKKDKKDDKDDDKDKK";
			string B                  = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD";
			string expected__         = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK";

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string S                  = "????";
			string A                  = "BB";
			string B                  = "AA";
			string expected__         = "AABB";

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string S                  = ;
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = MergeStrings().getmin(S, A, B);
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
