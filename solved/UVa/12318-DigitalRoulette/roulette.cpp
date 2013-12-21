using namespace std;
#include <iostream>
#include <set>
#include <cstring>
#define D(x) cout<< #x " = "<<(x)<<endl

int n,m,k;
int p[11];

int eval(int x){
    long long ans = 0;
    for(int i = k; i > 0; --i){
        ans += p[i];
        ans *= x;
        ans %= n;
    }
    ans += p[0];
    return ans%n;
}

int main(){
    while(cin>>n>>m and (n+m)){
        n++;
        cin>>k;
        set<int> ans;
        for(int i = 0; i <= k; ++i) cin>>p[i];
        for(int i = 0; i <= m; ++i) ans.insert(eval(i));
        cout<<ans.size()<<endl;
    }
    return 0;
}
