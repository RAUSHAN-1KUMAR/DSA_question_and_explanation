/*
Switch-case:-
    -- alternate to long if else statement
    -- compilers can optimize switch-case statements more effectively, resulting in potentially faster execution.
    -- switch-case statements are checked at compile time, this can help catch erros early in the development process.
    -- switch case is faster than if else or else if statament, because in case of switch case compiler directly jump to the satisfied case.

Some strictions in case of swith-case:
    -- it requires constant expressions in each case. If you need to evaluate non-constant expressions or complex conditions, if-else statements might be more appropriate.
    -- if you need to check for ranges of values, if-else statements offer more flexibiliry compared to switch-case, which only allows for discrete constant values.
    -- Switch-case statements are not suitable for comparing floating point values due to precision issues. In such cases, if_else statements are preferred.
*/