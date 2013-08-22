using namespace std;
#include<bits/stdc++.h>
template<class T>
int to_int(T t){stringstream ss;ss<<t;int r;ss>>r;return r;}

int main(){
    string cad;cin>>cad;
    int ans = 0;
    assert(cad.size() == 1000);
    for(int i = 0 ; i < cad.size() -5; ++i){
        int tmp = 1;
        for(int j = 0 ; j < 5; ++j)
            tmp*= to_int(cad[i+j]);
        ans = max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
