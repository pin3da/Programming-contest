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
    string menor="1000";
    string act;cin>>act;
    string t2;
    if(act[0]!='1')act[0]='1';
    else
      for(int i=1;i<4;++i)
        if(act[i]!='1'){
          act[i]='1';
          break;
        }
    
    vector<string> ans;
    ans.push_back(act);
    menor=act;
    For(i,n-1){
      cin>>act;
      string t;
      For(j,4){
        t=act;
        if(t[j]>menor[j]){
          if(t[j]==menor[j]){
            int k=j+1;
            while(t[k]==menor[k])k++;
            t[k]=menor[k];
            if(t<menor){
              int m=k+1;
              while(t[m]==menor[m])m++;
              t[k]=menor[k];
            }
          }
          t[j]=menor[j];

          if(t >= menor)
            break;
          if(t[j]!='9')t[j]++;
          if(t >= menor)
            break;
        }
      }
      act=t;
      if(fail(act)){
        cout<<"No solution"<<endl;
        return 0;
      }
      ans.push_back(act);
      menor=act;
       
    }
    mpr(ans);
  
       return 0;   

}
