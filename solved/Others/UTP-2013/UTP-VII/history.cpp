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


void mpr(vector<string> v){
  For(i,v.size())
    cout<<v[i]<<endl;
}

int fail(string a){
  return a < "1000" or a >"2011";
}

int main(){
    int n;cin>>n;
    vector<string> todos(n);
    For(i,n)
      cin>>todos[i];
    
    
    vector<string> ans(n);
    vector<string> ans2(n);
    int c1=1;
    int c2=2;
    ans = todos;
    ans2 = todos;
    ans[0][0]='1';
    For(i,n-1){
      string t=ans[i+1];
      if(ans[i+1]<ans[i]){
        For(j,4){
          t= ans[i+1];
          t[j]=ans[i][j];
          if(t>=ans[i])break;
          if(t[j]!='9')t[j]++;
          if(t>=ans[i])break;
        }
      }else if(fail(ans[i+1])){
        For(j,4){
          t= ans[i-1];
          t[j]=ans[i][j];
          if(t<=ans[i])break;
          if(j!=0)
            if(t[j]!='0')t[j]--;
          else
            if(t[j]!='0' and t[j]!='1' )t[j]--;          
          if(t<=ans[i])break;
        }
      }
      ans[i+1]=t;
      if(ans[i+1]<ans[i] or fail(ans[i+1]) or fail(ans[i])){
         c1 = 0;
         break;
      }
    }
    ans2[n-1][0]='2';
    if(fail(ans2[n-1]))ans2[n-1][0]='1';
    for(int i=n-1;i>0;--i){
      string t=ans2[i-1];
      if(ans2[i-1]>ans2[i]){
        For(j,4){
          t= ans2[i-1];
          t[j]=ans2[i][j];
          if(t<=ans2[i])break;
          if(j!=0)
            if(t[j]!='0')t[j]--;
          else
            if(t[j]!='0' and t[j]!='1' )t[j]--;          
          if(t<=ans2[i])break;
        }
      }else if(fail(ans2[i-1])){
        For(j,4){
          t= ans2[i+1];
          t[j]=ans2[i][j];
          if(t>=ans2[i])break;
          if(t[j]!='9')t[j]++;
          if(t>=ans2[i])break;
        }
      
      }
      ans2[i-1]=t;
      if(ans2[i-1] > ans2[i] or fail(ans2[i-1]) or fail(ans2[i]) ){
         c2 = 0;
         break;
      }
    }
    if(c1)
      mpr(ans);
    else if(c2)
      mpr(ans2);
    else
      cout<<"No solution"<<endl;
    return 0;   

}
