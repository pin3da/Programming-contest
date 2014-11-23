using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct entry{
  int votes;
  int id;
  string name;
  entry(){votes  = 0;}
  
  bool operator < (const entry & o) const {
    if (votes == o.votes) {
      return id < o.id;
    }
    return votes > o.votes;
  }
};

int main() {

  int a, b;
  cin >> a >> b;
  vector<entry> all(a);
  for (int i = 0; i < a; ++i) {
    cin >> all[i].name;
    all[i].id = i;
  }
  
  string line;
  int invalids = 0;
  for (int i = 0; i < b; ++i) {
    cin >> line;
    int vote;
    int count = 0;
    for (int j = 0; j < line.size(); ++j) {
      if (line[j] == 'X') {
        count++;
        vote = j;
      }
    }
    if (count == 1) {
      all[vote].votes++;
    } else {
      invalids++;
    }
  }
  
  sort(all.begin(), all.end());
  for (int i = 0; i < a; ++i) {
    printf("%s %.2lf\%\n", all[i].name.c_str() , (all[i].votes * 100.0 / double(b)) + 1e-9);
  }
  printf("Invalid %.2lf\%\n", (invalids * 100.0 / double(b)) + 1e-9);
  
  return 0;
}
