/*
* NOT SOLVED
**/

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

long long dp[51][3001][2000];
vector<int> S;
long long total;


long long solve(int index,int lleva,int mmin){
    if(index == S.size()){
        int B = total - lleva;
        D(lleva);
        D(B);
        D(mmin);
        if(lleva > B and (lleva - mmin) < (B + mmin))
            return 1;
        return 0;
    }
    if(dp[index][lleva][mmin] != -1) return dp[index][lleva][mmin];
    return dp[index][lleva][mmin] = solve(index + 1, lleva + S[index], min(mmin,S[index])) + solve(index + 1, lleva,mmin);
}

class YetAnotherTwoTeamsProblem {
	public:
	long long count(vector <int> skill) {
		memset(dp, -1,sizeof dp);
		total = 0;
		int t = -(1<<30);
	    for(int i = 0; i< skill.size(); ++i){
	        total += skill[i];
	        t = max(t,skill[i]);
	    }
	    S = skill;
	    return solve(0,0,t);
	    
	}
};
