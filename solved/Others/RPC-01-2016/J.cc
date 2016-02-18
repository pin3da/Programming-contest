// By @c4rias
#include<bits/stdc++.h>
using namespace std;

bool cmp(int &i, int &j) { return i <= j ; }

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        string sol = string(s.size(), ' ');

        vector<int> rep(255,0);
        int it = 0, last = 0, sum = s.size();
        for(int i = 0; i < s.size(); i++){
            rep[s[i]]++;
        }
        bool ok = true;

        while(it < s.size()){
            vector<int>::iterator maxi = max_element(rep.begin(), rep.end(), cmp);
            int dis = distance(rep.begin(), maxi);

            if(sum - *maxi + 1 < *maxi){
                ok = false;
                break;
            }

            if(sum - *maxi + 1 == *maxi && last != dis){
                sol[it++] = char(dis);
                rep[dis]--;
                last = dis;
                sum--;
            }else{
                int ot = 0;
                for(int i = 'a'; i <= 'z'; i++){
                    if(rep[i] && i != last){
                        ot = i;
                        break;
                    }
                }

                sol[it++] = char(ot);
                rep[ot]--;
                sum --;
                last = ot;
            }

        }
        if(ok)
            cout << sol << endl;
        else
            cout << "IMPOSSIBLE" << endl;

    }
}
