#include<bits/stdc++.h>
using namespace std;

bool sim(int n, int x) {
  list<int> l;
  for(int i = 1; i <= 100; i++) l.push_back(i);
  list<int>::iterator it = l.begin();
  int t = 0;
  while(l.size() > 1) {
    int next = (x % l.size());
    if(next == 0){ next = l.size();}
    for(int i = 0; i < next - 1; i++) {
      if(t) {
        if(it == l.begin()) it = l.end();
        it--;
      }else{
        it++;
        if(it == l.end()) it = l.begin();
      }
    }

    if(*it == n) return 0;
    it = l.erase(it);
    if(t) {
      if(it == l.begin()){
        it = l.end();
      }
      it--;
    }else{
      if(it == l.end()) it = l.begin();
    }
    t ^= 1;
  }
  cout << x << endl;
  return true;
}


int main() {
  int n;
  while(cin >> n && n) {
    for(int i = 1; !(sim(n, i)); i++);
  }
}
