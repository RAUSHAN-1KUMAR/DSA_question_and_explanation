
// infinte number array, we know the start as 0 but so we don't know the end, so we will form our end

/*
Approach:- start is 0;
    -- first we will start with end as 1, then end will be end+end = 2, then end = end+end = 4, then end = end+end = 8, -> 16, 32, 64, so we can see that our search space is increasing exponentially and if number is less than 64th index wala number => start=32 and end=64
*/
