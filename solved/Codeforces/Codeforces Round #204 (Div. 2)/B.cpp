// http://codeforces.com/contest/352/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 100010


int main(){ ___
    int n;
    while(cin>>n){
        vector<int> nums[MP];
        int t;
        for(int i = 0; i< n; ++i){
            cin>>t;
            nums[t].push_back(i);
        }
        
        
        vector<pair<int,int> > ans;
        for(int i = 0; i< MP; ++i){
            if(nums[i].size() == 0)continue;
            if(nums[i].size() == 1){
                ans.push_back(make_pair(i,0));
                continue;
            }
            int diff = nums[i][1] - nums[i][0];
            int ok = 1;
            for(int j = 1; j < nums[i].size(); ++j){
                if((nums[i][j] - nums[i][j-1]) != diff){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                ans.push_back(make_pair(i,diff));
            }
            
        }
        
        cout<<ans.size()<<endl;
        foreach(it,ans)
            cout<<it->first<<" "<<it->second<<endl;
    
    }
    return 0;
}