using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)

struct point{
    int x,y;
    point(){}
    point(int a,int b): x(a),y(b){}
    
    int cross(point o){
        return x*o.y - y*o.x;
    }
    
    
    point sub(point o){
        return point(x-o.x, y-o.y);
    }
    
    int colinear(point a,point b){
        return this->sub(a).cross(this->sub(b)) == 0;
    }
    
};


int main(){
    int tc;cin>>tc;
    For(tid,tc){
        cout<<"Test case #"<<tid+1<<": ";
        int np;cin>>np;
        vector<point> t(np);
        For(i,np)
            cin>>t[i].x>>t[i].y;
        
        int ans  = 0;
        For(i,np)
            for(int j = i +1; j< np; ++j)
                for(int k = j+1 ; k < np; ++k)
                    if(!t[i].colinear(t[j],t[k]))
                        ans++;
                        
        cout<<ans<<" triangle(s) can be formed."<<endl<<endl;
    }

    return 0;
}
