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

const double pi=acos(-1);

struct point{
    int x,y;
    point() {}
    point(int X, int Y) : x(X), y(Y) {}
};

typedef pair<point,point> swaps;


int main(){
    int n;cin>>n;
    int todo[n][n];
    memset(todo,50000,sizeof(todo));
    vector<int> rows(n);
    For(i,n)
        cin>>rows[i];

    For(i,n){
        For(j,rows[i])
            cin>>todo[i][j];
    }
    vector<swaps> ans;
    For(k,n){
        int i, j, key;
        for(j = 1; j < rows[k]; j++){
            key = todo[k][j];
            for(i = j - 1; (i >= 0) && (todo[k][i] > key); i--){
                     todo[k][i+1] = todo[k][i];
                     swaps tmp(point(k,i),point(k+1,i));
                     ans.push_back(tmp);
             }
             todo[k][i+1] = key;
         }
    }

    For(i,ans.size()){
        cout<<ans[i].first.x<<" "<<ans[i].first.y<<" "<<ans[i].second.x<<" "<<ans[i].second.y<<endl;
    }
    
    For(k,rows[0]){
        int i, j, key;
        for(j = 1; j < rows[0]; j++){
            key = todo[j][k];
            for(i = j - 1; (i >= 0) && (todo[i][k] > key); i--){
                     todo[i+1][k] = todo[i][k];
                     swaps tmp(point(k,i),point(k+1,i));
                     ans.push_back(tmp);
             }
             todo[i+1][k] = key;
         }
    }
    D("holaaa")    ;
    /*
    //Debug
    For(i,n){
        For(j,rows[i])
            cout<<todo[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<ans.size()<<endl;
    For(i,ans.size()){
        cout<<ans[i].first.x<<" "<<ans[i].first.y<<" "<<ans[i].second.x<<" "<<ans[i].second.y<<endl;
    }
    
    return 0;
}
