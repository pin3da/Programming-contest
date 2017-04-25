// http://codeforces.com/contest/334/problem/B

using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

class point{

public:
    int x,y;
    point(){}
    point(int a, int b): x(a), y(b){}
    
    bool operator < (const point &o) const{
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
   
};

int cx[] = {0,0,0,1,1,2,2,2};
int cy[] = {0,1,2,0,2,0,1,2};

void mapping(vector<point> &p){
    map<int,int> mx,my;
    
    int index = 0;
    for(int i = 0; i< 8; ++i){
        if(mx.count(p[i].x) == 0){
            mx[p[i].x] = index++;
        }
        p[i].x = mx[p[i].x];
    }
    
    index = 0;
    for(int i = 0; i< 8; ++i){
        if(my.count(p[i].y) == 0){
            my[p[i].y] = index++;
        }
        p[i].y = my[p[i].y];
    }
}

int main(){
    vector<point> points(8);
    for(int i = 0; i< 8; ++i)
        cin>>points[i].x>>points[i].y;
    
    sort(points.begin(),points.end());
    
    mapping(points);    
    
    int ok = 1;
    for(int i = 0; i< 8; ++i)
        if(points[i].x != cx[i] or points[i].y != cy[i])
            ok = 0;
        
    cout<<((ok)? "respectable" : "ugly")<<endl;
    
    
    return 0;
}