// http://codeforces.com/contest/350/problem/C

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) (x).begin(),(x).end()
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> string to_str(const T &x){ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x){ stringstream s; s << x; int r; s >> r; return r; }

struct pos{
    int x,y;
    pos(){}
    pos(int a,int b): x(a),y(b){}
    bool operator < (const pos &o) const {
        if(abs(x) == abs(o.x)) return abs(y) < abs(o.y);
        return abs(x) < abs(o.x);
    }
};

struct inst{
    int a,b;
    char c;
    inst(){}
    inst(int x, int y, int z ): a(x),b(y),c(z){}
};

int main(){ ___
    int n;
    while(cin>>n){
        vector<pos> bombs(n);
        For(i,n)cin>>bombs[i].x>>bombs[i].y;
        
        sort(all(bombs));
        
        vector<inst> ans;
        For(i,n){
            pos &b = bombs[i];
            inst c1(-1,-1,-1),c2(-1,-1,-1);
            if(b.x!=0){
                if(b.x > 0){
                    ans.push_back(inst(1,b.x,'R'));
                    c1 = inst(1,b.x,'L');
                }
                else{
                    ans.push_back(inst(1,-b.x,'L'));
                    c1 = inst(1,-b.x,'R');
                }
            }
            if(b.y != 0){
                if(b.y > 0){
                    ans.push_back(inst(1,b.y,'U'));
                    c2 = inst(1,b.y,'D');
                }else{
                    ans.push_back(inst(1,-b.y,'D'));
                    c2 = inst(1,-b.y,'U');
                }
            }
            ans.push_back(inst(2,0,0));
            if(c1.a != -1) ans.push_back(c1);
            if(c2.a != -1) ans.push_back(c2);
            ans.push_back(inst(3,0,0));
        }
        cout<<ans.size()<<endl;
        For(i,ans.size()){
            
            if(ans[i].a == 1){
                cout<<ans[i].a<<" "<<ans[i].b<<" "<<ans[i].c<<endl;
            }else{
                cout<<ans[i].a<<endl;
            }
        }
    }
    
    return 0;   
}