### Topic.

    Bipartite Matching, Max flow, binary search.


### Key idea.

Cool problem (:

The first task is pre compute a matrix c, which keep the cost of match the ghost 'i' with the human 'j'. For this you can perform a bfs from each ghost and calculate the distance, the cost will be distance\*2 + 2.

Then comes the beauty of this problem.
How to assign the ghost to the humans ?
Initially looks like a classic assignment problem which can solve using Min cost matching or the hungarian algorithm.

The crucial difference is that in the assignment problem you must minimize the sum of all c\[i][j] used in the match, however in this problem you must minimize the maximun c\[i][j] used in the assignment.

To achieve this, we can perform a binary search through the answer and check if the assignment is possible with all edges in c\[i][j] which have cost less than or equals to the answer (current value in the binary search).

To check if is possible assign the ghost to the humans with these edges, build a graph with two "columns", place the ghosts in the left side and in the humans in the right side. Make an edge with capacity 1 between the ghost i and human j for all c\[i][j] in accordance with above criteria.
Make an edge between the source and each ghost with capacity 1.
Make an edge between each human and the sink with capacity 1.

Find the max flow between the source and sink. If the max flow is equals to the answer (current value in the binary search) this assignment is possible.

### Useful links.

  [Stanford Team Notebook](http://www.stanford.edu/~liszt90/acm/notebook.html#file2)

### Problem Source.

  [1150 - Ghost!](http://lightoj.com/volume_showproblem.php?problem=1150)

