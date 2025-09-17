/*
What is back tracking??
    -- Backtracking is a problem-solving algorithmic technique that involves finding a solution incrementally by trying different options and undoing them if they lead to a dead end. 
        It is commonly used in situations where you need to explore multiple possibilities to solve a problem, like searching for a path in a maze or solving puzzles like Sudoku. 
    When a dead end is reached, the algorithm backtracks to the previous decision point and explores a different path until a solution is found or all possibilities have been exhausted.

How backTracking is different form recursion??
    -- Recursion is a general programming technique, while backtracking is a specific algorithmic technique that often uses recursion
    -- A recursive function solves a problem by breaking it down into smaller sub-problems of the same type until it reaches a base case while Backtracking uses recursion to explore all potential solutions. It tries to build a solution incrementally and removes the solution (backtracks) if it determines that the current solution path is not feasible.
    -- recursion can be used for any problem that can be divided into similar sub-problems while backtracking typically used for problems where a solution needs to satisfy certain constraints and involves decision making.
*/

/*
When the flow of execution of recursive calls comes back due to a dead end then we will have to do some operations(like indoin the path) when we comes back, this phenomenon is called backtracking.
*/