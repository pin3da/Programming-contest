using namespace std;
#include<bits/stdc++.h>


class RaiseThisBarn {
	public:
	int calc(string str) {
	    int total = 0;
	    for(int i = 0; i< str.size(); ++i)
	        if(str[i] == 'c')total++;
	    if(total%2)return 0;
	    total>>=1;
	    int t = 0;
	    int ans = 0;
	    for(int i = 0; i< str.size()-1; ++i){
	        if(str[i] == 'c')t++;
	        if(t==total)ans++;
	    }
	    return ans;
	}
};
