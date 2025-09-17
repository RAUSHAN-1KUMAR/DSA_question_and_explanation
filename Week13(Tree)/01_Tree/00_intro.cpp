/*
Binary Tree: 
    - A Binary Tree is a type of data structure in which:
    - Each node has at most two children.
    - These children are referred to as:
        Left child and Right child
    - Each node can store:
        1. A value (data)
        2. A reference (or pointer) to its left and right child

               1
              / \
             2   3
            / \
           4   5
          /
         6


Full Binary Tree: 
    - Every node has either 0 or 2 children.
    - No node has only one child.

           1
          / \
         2   3
        / \  
       4   5


Perfect Binary Tree:
    - All internal nodes have two children.
    - All leaf nodes are at the same level.

           1
          / \
         2   3
        / \ / \
       4  5 6  7


Complete Binary Tree:
    - All levels are completely filled, except possibly the last.
    - In the last level, all nodes are as left as possible.

           1
          / \
         2   3
        / \  /
       4  5 6


Balanced Binary Tree:
    - The height difference between left and right subtrees of any node is at most 1.
    - Examples: AVL Tree, Red-Black Tree

            10
           /  \
          5    15
         / \   /
        2   7 12


Degenerate (or skewed) Binary Tree:
    - Every node has only one child.
    - Can be:
        1. Left-skewed (like a linked list to the left)
        2. Right-skewed (like a linked list to the right)

            1
             \
              2
               \
                3

*/