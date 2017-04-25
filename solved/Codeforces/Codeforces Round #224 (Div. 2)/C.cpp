// http://codeforces.com/contest/382/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100010

int nums[MN];

int main(){ ___

  int n;cin>>n;
  For(i,n)
    cin>>nums[i];

  sort(nums, nums + n);

  if(n==1){
    cout<<-1<<endl;
    return 0;
  }

  if(n == 2){
      int dd = nums[1] - nums[0];
      if((dd)%2==0){
        if(dd == 0){
          cout<<1<<endl;
          cout<<nums[0]<<endl;
          return 0;
        }
        cout<<3<<endl;
        cout<<nums[0] - dd<<" "<<(nums[0] + nums[1])/2<<" "<<nums[1]+dd<<endl;
      }else{
        cout<<2<<endl;
        cout<<nums[0] - dd<<" "<<nums[1]+dd<<endl;
      }
  }else{
    map<int,int > diff;
    int ok = 1;
    int pos;
    for(int i = 1; i < n; ++i){
      int t = nums[i] - nums[i-1];
      if(diff.size() >= 2){
        if( diff.count(t) == 0){
          ok = 0; break;
        }
        diff[t]++;
      }else{
        if(diff.size() == 0) pos = i - 1;
        if(diff.size() == 1){
          if(t > diff.begin()->first)
            pos = i - 1;
        }
        diff[t]++;
      }

    }
    if(!ok){
      cout<<0<<endl;
      return 0;
    }
    if(diff.size() == 2){
      int d[2];
      int t[2];
      int i = 0;
      foreach(it,diff){
        d[i] = it->first;
        t[i] = it->second;
        ++i;
      }

      if(d[0] > d[1]){
        int tt = d[0];
        d[0] = d[1];
        d[1] = tt;

        tt = t[0];
        t[0] = t[1];
        t[1] = tt;
      }

      if(t[1] > 1){
        cout<<0<<endl;
        return 0;
      }

      if(2*d[0] != d[1]){
        cout<<0<<endl;
        return 0;
      }
      cout<<1<<endl;
      //D(d[0]);
      cout<<(nums[pos] + d[0])<<endl;
      return 0;
    }

    int dd = diff.begin()->first;
    if(nums[0] - dd == nums[n-1] + dd){
      cout<<1<<endl;
      cout<<nums[0]<<endl;
      return 0;
    }
    cout<<2<<endl;
    cout<<nums[0] - (diff.begin()->first)<<" "<<(nums[n-1] + (diff.begin()->first))<<endl;

  }

  return 0;
}
