using namespace std;
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define MP 1010

int p[MP];

int find_set(int x){return (p[x]==x)? x : p[x] = find_set(p[x]);}
void join(int a, int b){p[find_set(a)]  = find_set(b);}

double distance(double a, double b, double c, double d){
    double x = a - c; 
    double y = b - d;
    return sqrt (x*x + y*y);
}

int main(){
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc; ++tid){
        int n;cin>>n;
        double dist;cin>>dist;
        vector<pair<double, double> > stars(n);
        for(int i = 0;i< n; ++i){
            cin>>stars[i].first>>stars[i].second;
            p[i] = i;
        }
            
        for(int i = 0; i< n; ++i)
            for(int j = 0; j< n; ++j)
                if (distance(stars[i].first,stars[i].second,stars[j].first,stars[j].second) <= dist )
                    join(i,j);
        
        set<int> ans;
        for(int i = 0; i< n; ++i)
            ans.insert(find_set(i));
        cout<<"Case "<<tid<<": "<<ans.size()<<endl;
    }
    return 0;
}
