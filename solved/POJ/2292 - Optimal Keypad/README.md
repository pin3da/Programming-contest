### Topic.

    Dynamic programming.


### Key Idea.

  To minimize the average number of keystrokes over all words, just minimize the total number of keystrokes in general (over the frequency of each letter).
  With this in mind we can think in dp in the following way.

  dp(index, k) => minimun number of keystrokes from index and using **exactly** "k" cuts.

  inside the dp, just iterate over all j such that i < j <= (last\_possible\_cut) and choose the minimum one.
  Trace the path between the current state and the next state to re-build the answer.


  ```cpp
    int dp(i,k){
      int cur = inf;
      for(int j = i+1; j < MAX_KEY; ++j)
        cur = min(cur, dp(j,k-1) + cost(i,j));
      return cost;
    }
  ```

  Cost \[i,j) means the cost of group the keys form i until j-1 in the same key

### Problem Source

  [Optimal Keypad](http://poj.org/problem?id=2292)
