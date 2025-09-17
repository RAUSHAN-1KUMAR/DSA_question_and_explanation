/*
When it comes to applying DFS or BFS, go straight to the constraint. If n size is like 1000 or greater then apply BFS, or if it is like 100 or lesser then either BFS or DFS or both will give answer

1 BFS:
    - if you want to spread parallely: like in question rotten oranges
    - when they want to reach at destination soon
    - you may sometime confuse between either to apply BFS or Dijkstra
        1. if they says to find minimum to reach destination, and in logic you think each time you have to pick the smallest one and apply BFS -> then go with Dijkstra
        2. if you think no need to pick smallest one first, just applying BFS will work -> then go with BFS only

2.DFS:
    - if you think i need to be go deep and may backtrack will be required
*/