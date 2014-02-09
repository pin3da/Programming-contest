using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)

template<class t> 
int to_int(t r){stringstream ss; ss<<r; int k; ss>>k; return k;}
const double eps = 1e-9;
double m_round(double n){ return floor(1000.0*n + 0.5 + eps) / 1000.0;}
const double pi = 3.14159265;

struct light{
    double x, alpha, i;
    light(){}
    
    double inside(double a,double b){
        double dx = tan((alpha+0.01)*pi/180.0)*b;
        return fabs(a-x) < dx + eps;
    }
    
    double calculate(double a,double b){
        double u = x -a;
        double d = sqrt(u*u + b*b);
        return i/(d*d);
    }
    
};

int main(){
    int tc;cin>>tc;
    For(tid,tc){
        double x,y;cin>>x>>y;
        int n;cin>>n;
        vector<light> lights(n);
        For(i,n)
            cin>>lights[i].x;
        For(i,n)
            cin>>lights[i].alpha;        
        For(i,n)
            cin>>lights[i].i;
        
        double ans = 0;
        For(i,n){
            if(lights[i].inside(x,y))
                ans+= lights[i].calculate(x,y);
        }
        printf("Scene #%d: Spotlight intensity on Stacie is %.3lf\n\n",tid+1,m_round(ans));
    }
    return 0;

}
