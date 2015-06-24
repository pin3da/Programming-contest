
### Topic

    Binary search.


### Key Idea

Let's define a function that evaluates if we can solve the problem using at most m
containers with maximum capacity x.

As the vessels must be poured in the same order that the input, we can do this greedily.
Just summing up without reaching the capacity x.

```C++
int f(vector<int> &num, long long cap) {
  long long cur = 0;
  int ans = 1;
  for (int i = 0; i < num.size(); ++i) {
    if (num[i] > cap)
      return 1000000;
    if (cur + num[i] <= cap) {
      cur += num[i];
    } else {
      cur = num[i];
      ans++;
    }
  }
  return ans;
}
```

Note that the function to validate the answer will be monotonic. This is
if with maximum capacity 'x' you can solve the problem using 'm' containers
you can solve it with 'x + 1' as well.

In a similar way, if you can solve the problem with maximum capacity 'x', you will
never solve the problem with 'x - 1'.

So we have a function like.

false, false, false, false, true, true, true, true.

The solution is the first (smaller) value that is true, as the function is monotonic
we can use binary search in order to get that value.

### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1076)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1076&language=english&type=pdf)
