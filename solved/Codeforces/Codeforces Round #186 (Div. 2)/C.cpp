// http://codeforces.com/contest/313/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout<< #x " = " <<(x)<<endl

long long factor[20];

int log4(int a){
    int r = 0;
    while(a){
        r++;
        a>>=2;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<long long> nums(n);
    for(int i = 0; i< n; ++i)
        cin>>nums[i];
    
    sort(nums.rbegin(),nums.rend());
    int m  = log4(n);
    
    factor[0] = 1;
    factor[1] = 3;
    for(int i = 2; i< 11; ++i)
        factor[i] = factor[i-1]*4;
    
    long long ans = 0;
    int index = 0;
    for(int i = m; i > 0; --i){
        for(int j = factor[m-i]-1; j>=0;j--)
            ans+= nums[index+j]*(long long)i;
        
        index+=factor[m-i];
    }
    cout<<ans<<endl;
    
    return 0;
}