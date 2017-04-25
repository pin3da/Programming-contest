// http://codeforces.com/contest/55/problem/B

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

vector<lli> numm(4);
vector<char> ops(3);

lli solve(int op,vector<lli> nums){
    if(op==2)return ((ops[2]=='*')?nums[0]*nums[1]:nums[0]+nums[1]);
    sort(all(nums));
    lli ans = 1LL<<60;
    do{
        vector<lli> otro;
        otro.push_back(((ops[op]=='*')?nums[0]*nums[1]:nums[0]+nums[1]));
        For(i,nums.size()-2)otro.push_back(nums[i+2]);
        ans = min(ans,solve(op+1,otro));
    }while(next_permutation(all(nums)));
    return ans;
}

int main(){
    For(i,4)cin>>numm[i];
    For(i,3)cin>>ops[i];
    cout<<solve(0,numm)<<endl;
    return 0;
}