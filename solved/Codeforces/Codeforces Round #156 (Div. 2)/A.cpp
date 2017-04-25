// http://codeforces.com/contest/255/problem/A

using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
typedef long long ll;

int t[3];

int main(){
    int n;cin>>n;
    int index = 0;
    int tmp;
    For(i,n){
        cin>>tmp;
        t[index]+=tmp;
        if(index==2)index = 0;
        else index++;
    }
    vector<pair<int,int> > ans;
    For(i,3){
        ans.push_back(make_pair(t[i],i));
    }
    sort(rall(ans));
    if(ans[0].second == 0){
        cout<<"chest"<<endl;
    }else if(ans[0].second == 1)
        cout<<"biceps"<<endl;
    else
        cout<<"back"<<endl;

    return 0; 
}