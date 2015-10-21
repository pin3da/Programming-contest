
### Topic

    Topological sort, dfs.


### Key Idea

Let r[i] be the list of all reachable nodes from  i.

Let tid[i] be the 'timestamp' of i in the topological sort.

Then, for all node i, let's sort the outgoing edges by their tid.

After that, we can compute all the reachable nodes from i after processing j edges.
When we add the edge number 'j + 1' we have two options.

(let 'to' be the node from i using the edge number 'j + 1').

- 'to' is reachable from i (using a path through the previous edges).
  In this case we can throw away the edge because there is a longer path (we can prove that thanks to the topological order).
- 'to' is not reachable from i.
  In this case we *need* to add that edge to the final answer.


### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1390)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1390&language=english&type=pdf)
