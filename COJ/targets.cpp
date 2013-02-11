using namespace std;
#include<iostream>
#include<cmath>
#include<cctype>
#include<string>
#include<vector>

#define D(x) cout<< #x " = "<<x<<endl

struct recta{
    int x1,x2,y1,y2;
    
    recta(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){}
    
    bool inside(int x,int y){
        if((x1<=x and x2>=x) and (y1<=y and y2>=y)) return true;
        return false;
    }

};

struct circle{
    int x,y,r;
    
    circle(int a,int b,int c):x(a),y(b),r(c){}
    
    bool inside(int a,int b){
        int dist = (a-x)*(a-x);
        int disty = (b-y)*(b-y);
        if(dist+disty <= r*r) return true;
        return false;
    }

};


int main(){
    string cad;
    int num;cin>>num;
    vector<recta> recs;
    vector<circle> circles;
    
    while(num--){
        cin>>cad;
        if(cad=="rectangle"){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            recs.push_back(recta(a,b,c,d));
        }else{
            int a,b,r;
            cin>>a>>b>>r;
            circles.push_back(circle(a,b,r));
        }
    }
   /* for(int i=0;i<recs.size();++i){
        D(recs[i].x1);
        D(recs[i].y1);
        D(recs[i].x2);
        D(recs[i].y2);
    }*/
    int query;cin>>query;
    while(query--){
        int ans=0;
        int x,y;cin>>x>>y;
        for(int i=0;i<recs.size();++i)
            if(recs[i].inside(x,y))ans++;
        for(int i=0;i<circles.size();++i)
            if(circles[i].inside(x,y))ans++;
        cout<<ans<<endl;
    }
    
    
    return 0;
}






