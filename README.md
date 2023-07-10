# The 2D Points - Algorithmic task

## Introduction
This was a college assignment for the willing at my university 2 years ago. The task was
to write a C++ console program that would solve a certain issue, without using any
external libraries. If the program passed all teacher's
tests (unknown to students), its creator was exempted from the exam and had a passing grade for the semester.

## Task specification
We are given a set of 2D points with X and Y coordinates, which are the corners
of a closed polygon. Every side of the polygon is sure to be parallel to either X
or Y axis, which means the sides of the polygon are only at multiple of 90 degrees
to each other. The points are given in a random order and our task is to create a path
of NESW (north-east-south-west) directions, as we would move from one corner to the next along the sides of 
the polygon, starting from the first point given on input. So, the standard input may look
like this:  
  
Z  
X1 X1  
X2 Y2  
X3 Y3  
X4 Y4  
  
where Z is the number of corners, and X/Y are 2D coordinates of these points.  
  
Eg, the following standard input:  
  
4  
1 1  
0 0  
1 0  
0 1  
  
should generate the following standard output:  
  
SWNE  
  
## Solution
An obvious conclusion is that every point is connected to exactly two other points.
One of those connections has to be vertical and the other has to be horizontal. Now, 
lets consider a certain point. We can find the next one horizontally connected to it,
by serching for all points with exactly the same X value, and picking 
the point which is the closest to the considered one - in other words - they have 
the smallest difference between their Y values. Same goes for vertical connections 
and X values. Here comes the tricky part: there may be points on both sides of the
considered point - those with lower X/Y values and those with higher ones - which
means we end up with two points possibly connected to the considered point. 
How do we pick the correct one? By counting the numbers of points on both sides
(those with the higher X/Y values and those with the lower ones) separately, and
checking their parities. The side with an ODD number of points contains the correct
point.

## Conclusions
Solving this task made me realize how irrelevant, in work of a programmer, typing 
the code really is. I spent around 90% of the time spent on solving this task
on: analyzing, designing, debugging, and testing. Typing the code itself was just
a tiny chunk of it.
