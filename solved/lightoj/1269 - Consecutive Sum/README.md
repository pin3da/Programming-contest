
### Topic

    Trie.


### Key Idea

Supose that you have an array p, where p[i] is the "accumulative xor" up to i (i.e a[0] ^ a[1] ^ ... a[i]).

For all possible a[i], we can check all the previous a[j], (j < i) in the array "p" and compute the maximum and minimum value of a[i] ^ a[j].

```C++
  p.push_back(0);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    cur ^= t;
    for (int j = 0; j < p.size(); ++j) {
      mmin = min(mmin, p[j] ^ cur);
      mmax = max(mmax, p[j] ^ cur);
    }
    p.push_back(cur);
  }
```

See the [brute force](./brute.cc) solution for details.

This approach lead us to solve the problem, but is not fast enough.

In order to make the solution faster, we need to introduce a [trie](http://en.wikipedia.org/wiki/Trie).

In this trie, we will to save all the prefixes using them binary representation. Use the standard algorithm for that.

If we look the previous solution, this is the equivalent to insert 'mask' in the array 'p'.

```C++
  void add(int mask) {
    int cur = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] == -1) {
        t[cur][next] = nodes;
        nodes++;
      }
      cur = t[cur][next];
    }
  }
```


Then we need to think about how to search the minimum (and the maximum) value that we could get if we perform the xor
operation between a mask and all values in the tree. For this, we can make a kind of tree traversal.

The key idea here is : If I'm checking the ith bit of mask and I need the minimum possible value, I will try to advance in the
tree using the edge which is equals to the ith bit of the mask in order to get 0 in the result (because we are looking for mask ^ some_number_in_the_tree).

If there is no such edge, I will advance using the other egde.

These words could be confusing, but the code is simpler.

```C++
  int get_min(int mask) {
    int cur = 0, ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (mask >> i) & 1;
      if (t[cur][next] != -1) {
        ans <<= 1;
        cur = t[cur][next];
      } else {
        cur = t[cur][next ^ 1];
        ans <<= 1;
        ans++;
      }
    }
    return ans;
  }
```

The get_max function is quite similar.


### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1269)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1269&language=english&type=pdf)


