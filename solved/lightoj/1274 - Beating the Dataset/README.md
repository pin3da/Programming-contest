### Topics

    Dynamic Programming, Expected value

### Key idea

Let's denote *X* as the number of "NO" files and *Y* as the number of "YES" files.

In order to compute *X*  and *Y* we have a system of equations with 2 unknowns:

    2X + 3Y = M
     X +  Y = N

Therefore

    X = 3N - M
    y = M - 2N
    
Now, let's think in a dynamic programming approach:

    dp(n, y, a) => Computes the answer to n datasets, with y (amount) of 'YES' and using a as the previous answer in the sequence

Will be something like this: 
```C++
double dp(int n, int y, int a) {
  if (n == 0) // There are no options to choose
    return 0;
  double p_no  = (n - y) / (double) n;
  double p_yes = y / (double) n;
  double ans = 0;
  if (y < n)
    ans += (dp(n - 1, y, 0) + (a != 0)) * p_no;
  if (y > 0)
    ans += (dp(n - 1, y - 1, 1) + (a != 1)) * p_yes;
  return ans;
}
```

The most interesting part comes when we need to compute *p_no* and *p_yes*. We can see (It was not easy for me :( ...) that the number of correct sequences with *n* datasets and *y* "YES" is given by *Comb(n, y)*

So the probability of reach "NO" in the following state is:

    Comb(n - 1, y) / Comb(n, y) = (n - y) / n

And the probability of reach "YES" in the following state is:

    Comb(n - 1, y - 1) / Comb(n, y) = y / n

Pretty cool :D


#### Notes

The problem becomes a little harder because we can not save all states of dp.

In this case, we need to use a bottom up approach and solve the queries offline.


### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1274)
