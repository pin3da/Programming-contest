using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

int d[9];

int menor(string &a, string &b){
    if(a.size()== b.size()){
        int i;
        for(i = 0; i< a.size() and a[i]==b[i]; ++i);
        return a[i] < b[i];
    }else{
        return a.size() < b.size();
    }
}


map<int,string> dp;

/*
string iter(int tengo){
    vector<string> dp(tengo+1);
    dp[0] = "";
    for(int i = 0;i <= tengo;++i){
      string mm = "";
      for(int j = 0; j < 9 ;++j)
        if(i - d[j] >= 0 ){
            string act = ((char)('0'+j+1)) + dp[i-d[j]];
            //mm = max(mm, dp[i-todos[j].p] + todos[j].c);
            if(menor(mm,act))
                mm = act;
        }
      
      dp[i] = mm;
    }
    return dp[tengo];

}
*/

string solve(int tengo){
    if(tengo == 0)return "";
    if(dp.count(tengo)>0) return dp[tengo];
    string ans = "";
    For(i,9){
        if(d[i] <= tengo){
            string tmp = ((char)('0'+i+1)) + solve(tengo - d[i]);
            if(menor(ans,tmp)){
                ans =  tmp;
            }
        }
    }
    return dp[tengo] = ans;
}

int main(){ ___
    int paint;
    while(cin>>paint){
        For(i,9)
            cin>>d[i];
        dp.clear();
        string ans = solve(paint);
        if(ans == "") cout<<-1<<endl;
        else cout<<ans<<endl;
        
    }
    return 0;
}
