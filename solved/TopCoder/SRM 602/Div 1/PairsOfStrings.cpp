using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl


typedef long long ll;

vector<int> factors(const int &n){
    vector<int> ans;
    int sn = sqrt(n);
    for(int i = 1; i <= sn; ++i){
        if(n%i == 0) {
            ans.push_back(i);
            ans.push_back(n/i);
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(distance(ans.begin(),unique(ans.begin(), ans.end())));
    return ans;
}

int k ;
const ll mod = 1e9 + 7;

ll mod_pow(ll a, int b){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans*a) % mod;
        a = (a * a) % mod;
        b>>=1;
    }
    return ans;
}
map<int, ll> _dp;

ll dp(int n){
    if(_dp.count(n) != 0) return _dp[n];

    if(n==1) return _dp[n] = k;
    vector<int> fac = factors(n);
    ll ans = 0;
    for(int i = 0; i < fac.size() - 1; ++i)
        ans = (ans + dp(fac[i]))%mod;
    ans = mod - ans;
    ll p = mod_pow(k,n);
    return _dp[n] = (p + ans)%mod;
}


class PairsOfStrings {
  public:
    int getNumber(int n, int _k){
        k = _k;
        _dp.clear();
        vector<int> fac = factors(n);
        ll ans = 0;
        for(int i = 0; i< fac.size(); ++i){
            cout<<" "<<fac[i];
        }
        cout<<endl;
        for(int i = 0; i < fac.size(); ++i){
            ans = (ans + ((dp(fac[i]) * (ll)fac[i]) % mod )) % mod;
        }

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
			int n                     = 2;
			int k                     = 2;
			int expected__            = 6;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int k                     = 2;
			int expected__            = 20;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			int k                     = 4;
			int expected__            = 184;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 6;
			int k                     = 2;
			int expected__            = 348;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 100;
			int k                     = 26;
			int expected__            = 46519912;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PairsOfStrings().getNumber(n, k);
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
