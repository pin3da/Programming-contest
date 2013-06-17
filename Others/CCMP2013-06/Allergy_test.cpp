/**
* Manuel Pineda - UTP
*/
using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>

int n, duration[20];
int dp[1<<20][7];

/**
*   state: bitmask, indicates which allergens are not applied yet.
*   r: live duration of actual allergen.
*/

int solve(int state, int r){
	if (state == 0) return 0;
	if (dp[state][r] != -1) return dp[state][r];
	int ans = (1<<30);
	for(int i = 0; i < n; ++i) {
		if (!(state&(1<<i))) continue; // already applied
		int b =  max(duration[i], r+1); // Number of days the last allergen is the only one active
		ans = min(ans, b - r + solve(state ^ (1<<i), b - r -1));
	}
	return dp[state][r] = ans;
}

int main(){
	while(cin >> n and n){
	    for(int i=0;i<n;i++) cin >> duration[i];
	    memset(dp,-1,sizeof(dp));
	    cout<<solve((1<<n)-1, 0)<<endl;
	}
	return 0;
}
