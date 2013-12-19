using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> compute_prefix_function(string p){
    vector<int> pi(p.size());
    pi[0]=-1;
    int k=-1;
    for(int i=1;i<p.size();i++){
        while(k>=0 &&  p[k+1]!=p[i]) k=pi[k];
        if (p[k+1]==p[i])k++;
        pi[i]=k;
    }
    return pi;
}

int KMP_Matcher(string p,string t){
    vector<int> pi=compute_prefix_function(p);
    int q=-1;
    int last = q;
    for(int i=0;i<t.size();i++){
        while(q>=0 &&  p[q+1]!=t[i]) q=pi[q];
        if (p[q+1]==t[i]) q++;
        last = q;
        if (q==p.size() - 1){
            q=pi[q];
        }
    }
    return last;
}


int main(){ ___
    int T;
    cin>>T;
    for(int c = 0; c < T; c++){
        string tt ; cin>>tt;
        string patt = tt;
        reverse(patt.begin(),patt.end());
        int useful = KMP_Matcher(patt, tt);
        useful++;
        int toadd = tt.size() - useful;
        printf("Case %d: %d\n", c + 1, tt.size() + toadd);
    }
    return 0;
}
