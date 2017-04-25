// http://codeforces.com/contest/359/problem/D

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end
#define MP 300010

int nums[MP];
int ans[MP];

int main(){ ___
    int n;
    while(cin>>n){
        for(int i = 0; i< n; ++i) cin>>nums[i];
              
        int i = 0;
        int left,right;
        int c = 0, old_len = 0;
        
        while(i < n){
            left = right = i;
            while(left>=0 and !(nums[left]%nums[i]) ) --left;
            while(right < n and !(nums[right]%nums[i]) ) ++right;
            int len = right - left -2;
            i = right;
            if(len > old_len) c = 0,old_len = len;
            if(len == old_len) ans[c++] = left + 2;
        }

        cout<<c<<" "<<old_len<<endl;
        for(int i = 0; i < c; ++i){
            if(i)cout<<" ";
            cout<<ans[i];
        }
        cout<<endl;
            
    }
    return 0;
}
