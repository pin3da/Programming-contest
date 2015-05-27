
### Topic

    Dynamic programming


### Key Idea

Let's define dp(i) as the number of ways in wich a race with "i" horses can finish.

Suppose we have "i" horses at the race and we will choose k of them for the first place, leaving "i - k" for the second (or higer) place.
The process to count the number of ways to choose horses for the second place is equals to the original problem. This is the reason why we use dp.


```C++
int dp(int i) {
  int ans = 0;
  for (int k = 1; k <= i; ++k)  // Test with all possibles k.
    ans += choose(i, k) * dp(i - k);
  return ans;
}
```

Pay attention to the "choose" function, in fact is the same that the [binomial coefficients (or combination)](http://en.wikipedia.org/wiki/Binomial_coefficient) and it can be computed using dynamic programming as well.

### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1326)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1326&language=english&type=pdf)



