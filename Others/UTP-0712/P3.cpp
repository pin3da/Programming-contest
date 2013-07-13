//Not solved !
using namespace std;
#include <bits/stdc++.h>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

typedef long long ll;

int mycmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    vector<pair<int,int> > ans(n);
    For(i,n)
        cin>>nums[i];
    For(i,n){
        int t;cin>>t;
        nums[i]+=t;
        ans[i] = make_pair(nums[i],i);
    }
    
    sort(all(ans),mycmp);
    
    foreach(it,ans){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
    cout<<"---"<<endl;
    vector<pair<int,int> >::iterator it = lower_bound(all(ans),make_pair(x,n),mycmp);
    
    cout<<1<<" "<< n - (it - ans.begin())<<endl;
    
    return 0; 
}
