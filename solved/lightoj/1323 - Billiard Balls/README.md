### Topic

    Math

### Key idea

Simple yet nice problem.


Firstly look the images to understand how the balls bounce, note that we don't need the position for an specific ball, so we can treat them as indistinguishable elements.

With this in mind we can assume that there are no collisions, (i.e when A and B collide, A follows the B's trajectory and B follows the A's trajectory).

Now let's solve for each ball:
- Handle each coordinate independently
- Look how many times the ball bounces in the wall (the end of the table).
   if this number is odd, the position is ((x + k) % L)
   if this number is even, the position is (L - (abs(x - k) % L))

### Problem source

  [lightoj](http://lightoj.com/volume_showproblem.php?problem=1323)
