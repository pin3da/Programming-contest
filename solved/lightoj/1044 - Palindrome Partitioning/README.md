
### Topic

    Dynamic programming.


### Key Idea

We can split the problem in two task.

- Check if a substring from b to e is palindrome.
- Find the minimum number of palindrome partitions starting at i.

With this in mind we can write the following recurrence:


C++ code without memoization:

```c++
int dp(int b) { // Minimum number of palindrome partitions starting at b.
  if (b == line.size())
    return 0;   // Base case.

  int best = inf;
  for (int i = b; i < line.size(); ++i) { // Iterate over all posible partitions.
    if (pal(line, b, i))
      best = min(best, 1 + dp(line, i + 1));
  }
}
```

### Problem source


[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1044)


[PDF](http://lightoj.com/volume_showproblem.php?problem=1044&language=english&type=pdf)
