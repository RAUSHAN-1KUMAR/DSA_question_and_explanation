/* difference array technique

Think of the Difference Array technique as a clever way to make changes to a range in an array without looping through all elements.

Simple Idea:- Instead of updating every number in a range one by one, we just mark the start and end of the change. Then, later, we use a prefix sum to apply all the changes at once.

Example:- array-> 0 0 0 0 0
        -- want to increase values from index 0 to 3 by 3 and 1 to 2 by 2
        -- insteqad of updating every number we do:-
            i) arr[0]+=3 and arr[4]-=3
            ii) arr[1]+=2 and arr[3]-=2
        -- now the array looks like this:- 3 2 0 -2 -3
        -- now we will use prefix sum to get the original array:- 3 5 5 3 0 
        -- now we can see that the range 0 to 3 is increased by 3 and 1 to 2 is increased by 2

        -- TC:-
            Range update:- O(1)
            final Computation(prefix sum): O(n)
*/