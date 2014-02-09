using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)

const double eps = 1e-10;


double area(double r){
    return 3.14159*r*r;
}

double m_round(double n){
    return floor(100.0*n + 0.5 + eps) / 100.0;

}

int main(){
    double R,r1,r2;
    
    int tc;cin>>tc;
    For(tid,tc){
        cin>>R>>r1;
        r2 = R - r1;    
        double A = area(R), a1 = area(r1), a2 = area(r2);
        double shared = (A - a1- a2)*0.5;
        printf("Taijitu #%d: yin %.2lf, yang %.2lf\n\n", tid+1, m_round(shared + a2),m_round( shared + a1));
    }

//    printf("%lf %lf\n",m_round(1.274),m_round(1.275));
    return 0;
    
}
