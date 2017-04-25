// http://codeforces.com/contest/361/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end


int main(){ ___

    int n,k;
    while(cin>>n>>k){
        vector<int> ans(n);
        for(int i = 0; i< n; ++i)
            ans[i] = 1+i;
        
        int index = 2;
        int malos = (n-1) - k;
        
        if(n%2 and k==0)index = 1;
        
        if(malos < 0){
            cout<<-1<<endl;
            continue;
        }
        
        while(malos >= 2 and index + 1 < n){
            swap(ans[index],ans[index+1]);
            index += 2;
            malos -= 2;
        }
        if(malos > 1){
            cout<<-1<<endl;
            continue;
        }
        
        if(malos == 1)
            swap(ans[0], ans[1]);
        
        for(int i = 0; i< n; ++i)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}