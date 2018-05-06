class Solution {

  public:
    int consecutiveNumbersSum(int N) {
      vector<int> divs;
      for (int i = 1; i * i <= N; i++) {
        if (N % i)
          continue;
        divs.push_back(i);
        if (i != (N / i)) {
          divs.push_back(N / i);
        }
      }
      int ans = 0;
      for (auto it : divs) {
        if (it & 1) ans++;
      }
      ans -= 1;
      return ans + 1;
    }
};
