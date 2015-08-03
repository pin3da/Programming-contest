
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll nums[100005];
int n,k;

ll count(int ans){
  ll tmp = 0,t=0;
  int i=0,j=0;
  while(i<n){
    if(j+1 < n and nums[j+1]-nums[i] <= ans){
      t++;
      j++;
    }else{
      tmp += t;
      t--;
      i++;
    }
  }

  return tmp;
}

void solve(int ans,int kth){
  ll tmp = 0,t=0;
  int i=0,j=0;
  while(i<n){
    if(j+1 < n and nums[j+1]-nums[i] <= ans){
      if(nums[j+1]-nums[i] == ans){
        t++;
        if(t==kth){
          cout<<nums[i]<< " " << nums[j+1] << endl;return;
        }
      }

      j++;
    }else{
      i++;
    }
  }

}

int main(){

  while(cin>>n>>k and n+k){
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums,nums+n);

    int lo = 1,hi = 1000000005;

    while(lo < hi){
      int mid = (lo+hi)>>1;
      ll c = count(mid);
      if(c>=k){
        hi = mid;
      }else{
        lo = mid+1;
      }

    }

    ll kth = k - count(lo-1);
    solve(lo,kth);


  }
}

