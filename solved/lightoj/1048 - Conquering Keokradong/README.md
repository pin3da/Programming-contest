
### Topic

    Binary search, greedy.


### Key Idea

Using binary search try to find the smallest value C (representing the maximum distance covered in a day) which is valid.

To check if a value C is valid, just take as much as possible from the begining of array without exceeding C.
If you exceed, then you need to split and create a new group ("amount of walking done in a single day", in terms of the problem).

Finally, if you used at most K groups the value C is valid.

NOTE: I added two files, 'input.ext' and 'output.ext' collecting all the examples in the forum. This was very useful to me.

### Problem source

[LightOJ](http://www.lightoj.com/volume_showproblem.php?problem=1048)

[PDF](http://www.lightoj.com/volume_showproblem.php?problem=1048&language=english&type=pdf)



