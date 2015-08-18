
### Topic

    Greedy


### Key Idea

Traverse the tree in post-order, for each node chek how many boys you can send 'upward'.
This value can be a positive number if you have enough people to guard this city, or can be
negative if you need boys for that task.

The answer is the total of non-zero movements made in this process, the reason why this works
is because you move each boy through the LCA (lowest common ancestor) between the origin and destination.

### Problem source

[LightOJ](http://lightoj.com/volume_showproblem.php?problem=1219)

[PDF](http://lightoj.com/volume_showproblem.php?problem=1219&language=english&type=pdf)


