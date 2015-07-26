#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef  long long ll;

struct frac{
    ll d,n;
    frac(){}
    frac(ll _d, ll _n):d(_d),n(_n){}
    
    bool operator <(const frac &b)const{
        return d*b.n <= b.d*n;
    }
    
    frac operator -(const frac &b)const{
        frac r = frac(abs(d*b.n - n*b.d),n*b.n);
        return r;
    }
    
};



void generarSet(int n,map<int,set<ll > > &s,ll *ss,int *ws){
    for(int i = 1;i< 1<<n;i++){
        ll nu=0;
        int de = 0;
        for(int j=0;j<n;j++){
            if((i & (1<<j)) != 0){
                nu += ss[j]*((ll)ws[j]);
                de += ws[j];
            }
        }
        s[de].insert(nu);
    }
}

void minSet(map<int,set<ll> > &s,frac S,frac H,frac &ansH,frac &ansS){
    for(auto it = s.begin(); it != s.end();it++){
        
        frac anstH,anstS;
        
        for(auto i = it->second.begin();i!= it->second.end();i++){
        
            anstH = frac(*i,it->first) - H;
            anstS = frac(*i,it->first) - S;
            
            ansH = min(ansH,anstH);
            ansS = min(ansS,anstS);
        }

    }
}



int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n,w;
    ll H,S,k;
    
    while(cin>>n>>H>>S){

        ll set1[n/2 +1],set2[n/2 +1];
        int wset1[n/2 +1],wset2[n/2 +1];
        
        frac HH = frac(H,1);
        frac SS = frac(S,1);
        
        for(int i=0;i<n/2;i++)cin>>set1[i]>>wset1[i];
        for(int i=0;i<n/2 + (n%2==1);i++)cin>>set2[i]>>wset2[i];
        
        map<int,set<ll> > s1,s2;
        
        generarSet(n/2,s1,set1,wset1);
        generarSet((n/2)+ (n%2==1),s2,set2,wset2);
        
        frac ansH = frac((ll)1e18,1),ansS = frac((ll)1e18,1);

        minSet(s1, SS,HH,ansH,ansS);
        minSet(s2,SS,HH,ansH,ansS);

        
        for(auto it = s1.begin(); it != s1.end(); it++){
            for(auto i = it->second.begin() ; i != it->second.end(); i++){
                for(auto it2 = s2.begin(); it2 != s2.end(); it2++){
                
                    ll BHguess = abs(((ll)(it->first + it2->first))*H - *i);
                    
                    auto bht = it2->second.lower_bound(BHguess);
                    frac tmpH;
                    
                    if(bht!= it->second.end()){
                        tmpH = frac(*i + *bht,(it->first + it2->first));
                        tmpH = tmpH - HH;
                        ansH = min(ansH,tmpH);
                    }
                    
                    if(bht != it2->second.begin()){
                        bht--;
                        tmpH = frac(*i + *bht,(it->first + it2->first));
                        tmpH = tmpH - HH;
                        ansH = min(ansH,tmpH);
                    }
                    
                    ll BSguess = abs(((ll)(it->first + it2->first))*S - *i);
                    auto bst = it2->second.lower_bound(BSguess);
                    frac tmpS;
                    if(bst!= it2->second.end()){
                        tmpS = frac(*i + *bst,(it->first + it2->first));
                        tmpS = tmpS - SS;
                        ansS = min(ansS,tmpS);
                    }
                    if(bst != it2->second.begin()){
                        bst--;
                        frac tmpS = frac(*i + *bst,(it->first + it2->first));
                        tmpS = tmpS - SS;
                        ansS = min(ansS,tmpS);
                    }
                }
            }
        }   
        if(ansH < ansS && ansS < ansH)  cout<<"Tie"<<endl;
        else if(ansS < ansH)            cout<<"Swans"<<endl;
        else                            cout<<"Hawks"<<endl;         
    }

}
