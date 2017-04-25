// http://codeforces.com/contest/369/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010

int n,k,l,r,sa,sk;

void print_a(const vector<int> &ans){
  
  for(int i = 0; i< ans.size(); ++i){
    if(i)cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
}

int main(){ ___


    while(cin>>n>>k>>l>>r>>sa>>sk){
        vector<int> ans(n);
        
        int remain = sk % k;
        for(int i = 0; i < k; ++i){
          ans[i] = sk / k;
          ans[i] += (remain > 0)? 1: 0;
          remain--;
        }
        
        if(n == k){
          print_a(ans);
          continue;
        }
        int j = k;
        sk = sa - sk;
        k = n - k;
        remain = sk % (k);
        
        for(int i = j;  i < n; ++i){
            ans[i] = sk / k;
            ans[i] += (remain > 0)? 1: 0;
            remain--;
        }

        print_a(ans);
        

    }
    return 0;
}