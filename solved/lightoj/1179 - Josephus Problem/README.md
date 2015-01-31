### Topics

    Math, recursion

### Key idea

Very nice problem

Could be solved recursively in linear time as follow

```C++
    int josephus(int n, int k) {
      if (n == 0) return 1;
      return (josephus(n - 1, k) + k) % n;
    }
```

### Problem source.

  [lightOJ](http://lightoj.com/volume_showproblem.php?problem=1179)
