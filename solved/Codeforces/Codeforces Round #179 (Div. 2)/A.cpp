// http://codeforces.com/contest/296/problem/A

using namespace std;
#include<bits/stdc++.h>


int main(){
    int n;
    while(cin>>n){
        vector<int> nums(1001,0);
        for(int i = 0; i< n; ++i){
            int k;cin>>k;
            nums[k]++;
        }

        int paila = 0;
        for(int i = 0; i< 1001; ++i){
            int tmp = 0;
            for(int j = 0; j< 1001; ++j)
                if(i!=j)tmp += nums[j];
            if(nums[i] - 1 > tmp)paila = 1;
        }
        if(paila)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}