### Topic

    Math

### Key idea

Let's to solve the problem for an specific hour, for instance at 8 with symmetry line at 6.

So the answer will be 8 hours + X seconds; To find X we need to think in how many degrees is moved the hour hand in X seconds, this will give us the position for the minute hand which is (20 * 60 - X) (due to symmetry) [20 * 60 represents the position in seconds for number 4 in the clock].

So, we have:

    X * hour_hand_speed = (20 * 60 - X) * minute_hand_speed;

therefore

    X = ((20 * 60) * minute_hand_speed ) / (hour_hand_speed + minute_hand_speed)

The problem now is compute the "symmetric time" (20 * 60 seconds in this case).
For this just compute the distance between the symmetry line and the specific hour, then subtract this from the symmetry line and compute how many seconds are required to reach this distance.

### Problem source

  [LightOJ](http://lightoj.com/volume_showproblem.php?problem=1430)
