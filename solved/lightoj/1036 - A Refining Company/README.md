
### Topic

    Dynamic programming.


### Key Idea

Let dp(i, j) the maximum ammount of materials you can collect.

if you choose collect Uranium, you add to the answer all the Uranium form the col 0 to the col j on the row i, and your new state will be dp(i - 1, j).
otherwise you add to the answer all the Radium from the row 0 to the row i on the col j, and your new state will be dp(i, j - 1).

For every state dp(i, j) choose the maximum between the two possibilities.


C++ pseudocode without memoization
```C++
int dp(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  return max(dp(i - 1, j) + prefix_sum_a[i][j], dp(i, j - 1) + prefix_sum_b[i][j]);
}
```

### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1036)


[PDF](http://lightoj.com/volume_showproblem.php?problem=1036&language=english&type=pdf)






