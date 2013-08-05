using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,L,W;

struct line{
    int a,b,c;
    line(){}
    line(int x1,int y1,int x2, int y2){
            a = y1 - y2;
            b = x2 - x1;
            c = a*x1 + b*y1;
    }
};

struct point{
    int x,y;
    point(){}
    point(int a): x(a),y(1){}
    point(int a, int b){
        x = a/__gcd(a,b);
        y = b/__gcd(a,b);
    }
    bool operator < (const point &o) const{
        return x*o.y < y*o.x;
    }
    
};

bool intersection(line l1,line l2, point &x,point &y){
    int det = l1.a*l2.b - l2.a*l1.b;
    if(det == 0) // lines are parallel
        return false;
    x = point(l2.b*l1.c - l1.b*l2.c,det);
    y = point(l1.a*l2.c - l2.a*l1.c,det);
    return true;
}



vector<line> lines;

int solve(){
    point minx(0);
    point miny(0);
    point maxx(L);
    point maxy(W);
    int ans = 1;
    for(int i = 0; i< n; ++i){
        set<pair<point,point> > points;
        for(int j = 0; j< i; ++j){
            point x,y;
            if(intersection(lines[i],lines[j],x,y)){
                if(minx < x and x < maxx and miny < y and y < maxy)
                    points.insert(make_pair(x,y));
            }
        }
        ans += points.size() + 1;
    }
    return ans;
}

int main(){
    int tc;cin>>tc;
    int a,b,c,d;
    for(int tid = 1; tid <= tc; ++tid){
        cin>>n>>L>>W;
        lines.clear();
        for(int i = 0 ; i< n; ++i){
            cin>>a>>b>>c>>d;
            lines.push_back(line(a,b,c,d));
        }
        printf("Case %d: %d\n",tid,solve());
    
    }

    return 0;
}
