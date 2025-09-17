/*
- if they says to find minimum to reach destination, and in logic you think each time you have to pick the smallest one and apply BFS -> then go with Dijkstra

- sometimes, as you see the minimum or lowest and you will direct jump into dijkstra but hold yourself -> if they include that you can only jump to k nodes then 
    1. think for bellman-ford solution
    2. apply dijkstra on jump not distance and if increase is constant then no need of priority queue, we can just use queue
*/