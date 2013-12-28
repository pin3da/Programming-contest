### Topic.

    Data Structures, DFS.


### Key idea


This is a nice problem despite its tight time limit.

First use a dfs to label the nodes, and store the left-most and right-most label from the current node to down for each node.

```cpp
void dfs(node){
  label[node] = left[node] = current_id++;
  for(int child : g[node])
    dfs(child);
  right[node] = current_id - 1;
}
```

then use a 'BIT' (or fenwick tree) to get the sum  of the interval left[query], right[query].

### Useful links

[BIT - Fenwick Tree](http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binaryIndexedTrees)

### Problem source

  [3321 - Apple Tree](http://poj.org/problem?id=3321)
