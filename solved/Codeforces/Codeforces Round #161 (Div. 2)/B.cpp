// http://codeforces.com/contest/263/problem/B

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

const double pi=acos(-1);
typedef long long int lli;

struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};

int main(){
    int n,k;cin>>n>>k;
    vector<int> nums(n);
    For(i,n)cin>>nums[i];
    sort(rall(nums));
    if(k>nums.size())
        cout<<"-1\n";
    else
        cout<<nums[k-1]<<" "<<nums[k-1]<<endl;
    
  
    return 0;
}
