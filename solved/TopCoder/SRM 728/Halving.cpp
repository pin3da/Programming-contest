#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

map<int, int> comp_dist(int a) {
  map<int, int> ans;
  deque<int> q;
  q.push_back(a);
  ans[a] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop_front();
    if (cur == 1) continue;
    int x = cur >> 1;
    int y = cur - x;
    if (ans.count(x) == 0) {
      q.push_back(x);
      ans[x] = ans[cur] + 1;
    }
    if (ans.count(y) == 0) {
      q.push_back(y);
      ans[y] = ans[cur] + 1;
    }
  }
  return ans;
}

class Halving {
  public:
    int minSteps( vector <int> a ) {
      vector<map<int, int>> dist(a.size());
      set<int> possible;
      for (int i = 0; i < int(a.size()); i++) {
        dist[i] = comp_dist(a[i]);
        for (auto &it : dist[i])
          possible.insert(it.first);
      }

      int best = INT_MAX;
      for (auto it : possible) {
        int cur = 0, ok = true;
        for (int i = 0; i < int(a.size()) && ok; i++) {
          if (dist[i].count(it)) {
            cur += dist[i][it];
          } else {
            ok = false;
          }
        }
        if (ok)
          best = min(best, cur);
      }
      return best;
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
			int a[]                   = {11, 4};
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a[]                   = {1000000000, 1000000000, 1000000000, 1000000000};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a[]                   = {1, 2, 3, 4, 5, 6, 7};
			int expected__            = 10;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a[]                   = {13, 13, 7, 11, 13, 11};
			int expected__            = 11;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a[]                   = {1, 1};
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
      int a[] = {161759726, 372966909, 968408861, 158547942, 434845570, 562224979, 302879663, 213262253, 925351570, 549820520, 660401030, 925865638, 507538150, 640098097, 998395820, 325674617, 268505489, 839051089, 862164061, 903749105, 665006429, 681383204, 786641551, 930615984, 583822536, 601545853, 876469638, 242092338, 911322474, 407881094, 701194962, 892507684, 244685601, 705917892, 126730912, 212926546, 50437238, 527062338, 169060241, 419226109, 45559538, 856755804, 368702284, 453598633, 517284095, 106964172, 682770248, 975607891, 636701893, 904847275};
			int expected__            = 1360;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int a[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a[]                   = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Halving().minSteps(vector <int>(a, a + (sizeof a / sizeof a[0])));
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
