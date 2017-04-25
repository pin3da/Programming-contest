// http://codeforces.com/contest/336/problem/C

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl

int main(){ ___
    
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i< n; ++i) cin>>nums[i];
    
    for(int i = 30; i >= 0; --i){
        int ans = -1;
        for(int  j = 0; j < n; ++j)
            if( (nums[j]&(1<<i)) != 0)
                ans &= nums[j];
        
//        if( ((~(1<<i))&ans) == 0){
        if( (((1<<i)-1)&ans) == 0){
            set<int> answer;
            for(int  j = 0; j< n; ++j)
                if( (nums[j]&(1<<i)) !=0 )
                    answer.insert(nums[j]);
                    
            cout<<answer.size()<<endl;
            foreach(num,answer)
                cout<<(*num)<<" ";
            
            cout<<endl;
            
            return 0;
        }
    }
    
    return 0;
}