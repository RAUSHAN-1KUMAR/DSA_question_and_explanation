/*
postOrder traversal with O(1) space

*/

/*
Appraoch:-
    -- In postOrder traversal we have Left -> right -> node, it means first we have to complete the left part then right part then node which is defficult so what we will do? -> we will reverse the portOrder call i.e, LRN to NRL then find the answer and the mainAnser will be reverse of answer obtained by NRL
*/