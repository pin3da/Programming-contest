// http://codeforces.com/contest/18/problem/A

using namespace std;
#include<bits/stdc++.h>

double INF = 1e100;
double EPS = 1e-9;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator < (const PT &o) const {
    if(x == o.x) return y < o.y;
    return x < o.x;
  }
  bool operator != (const PT &o) const {
    return fabs(x-o.x) > EPS or fabs(y-o.y) > EPS;
  }
  
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){

    //cout<<dot(PT(0,0)-PT(1,-1),PT(4,1)-PT(1,-1))<<endl;
    
    PT a,b,c;
    cin>>a.x>>a.y;cin>>b.x>>b.y;cin>>c.x>>c.y;
//    cout<<a<<" "<<b<<" "<<c<<endl;
    if(dot(a-b,c-b) == 0 or dot(b-a,c-a)==0 or dot(a-c,b-c)==0){
        cout<<"RIGHT"<<endl;
        return 0;
    }else{
        vector<PT> p(3); p[0] = a; p[1] = b; p[2] = c;
        sort(p.begin(),p.end());
        do{
            for(int i = 0; i < 4; ++i ){
                PT a(p[0].x + dx[i],p[0].y + dy[i]);
                PT b(p[1]);
                PT c(p[2]);
                if(dot(a-b,c-b) == 0 or dot(b-a,c-a)==0 or dot(a-c,b-c)==0){
                    if(a!=b and b!=c and a!=c){
                        cout<<"ALMOST"<<endl;
                        return 0;
                    }
                }
            }
        
        }while(next_permutation(p.begin(),p.end()));
    }
    cout<<"NEITHER"<<endl;

    return 0;
}