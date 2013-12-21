/**
* Manuel Pineda.
* Accepted , 0.535 s
*/

using namespace std;
#include <iostream>
#include <string>
#include <set>

#define MAXN 369000
#define D(x) cout<< #x " = "<<(x)<<endl

int p[MAXN];
int find_set(int x){return x != p[x] ? p[x] = find_set(p[x]) : p[x];}
void merge(int x, int y){p[find_set(y)] = find_set(x);}

int dx[] = {0,0,1,1};
int dy[] = {0,1,1,0};
int n,cols;

int ps(int x,int y){
    return x*cols+y;
}

void join_h(int x, int y, int dir){
    if(dir){
        merge(ps(x,y),ps(x,y+1));
        merge(ps(x+1,y),ps(x+1,y+1));
    }else{
        merge(ps(x,y),ps(x+1,y));
        merge(ps(x,y+1),ps(x+1,y+1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n){
        cols = 2*n+1;
        for(int i = 0; i< MAXN; ++i) p[i] = i;
        for(int i = 0; i< 2*n -1; ++i){
            string line;cin>>line;
            for(int j = 0; j< n; ++j)
                join_h(i, 2*j + (i%2!=0), line[j]=='H');
        }
        set<int> ans;
        for(int i = 1; i< cols ; i+=2 ){
            merge(ps(0,i),ps(0,i+1));
            merge(ps(2*n-1,i),ps(2*n-1,i+1));
        }
        for(int i = 1; i< 2*n ; i+=2 ){
            merge(ps(i,0),ps(i+1,0));
            merge(ps(i-1,2*n),ps(i,2*n));
        }
        for(int i = 0; i< (2*n)*(cols); ++i) ans.insert(find_set(i));
        cout<<ans.size()-1<<endl;
    }
}

