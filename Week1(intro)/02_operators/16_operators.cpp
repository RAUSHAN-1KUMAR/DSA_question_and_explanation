/*
C++ operators
 1. Arithmatic operators
    Ex-> Addition(+), Subtraction(-), Multiplication(*), Division(/), Modulus(%), Increment(++), Decrement(--)
            2+3           2-3               2*3             2/3         3%2 = 1       a++           a--
        
        -- Modulus operator(%) gives remainder.(it is only allowed to use in integer and character data types)
        -- Increment operator(++) increase the value by 1.   ex. a++ => a = a+1 
        -- Decrement operator(--) decrease the value by 1.   ex. a-- => a = a-1
        
 2. Relational operators
    Ex-> is equals to(==), not equals to(!=), greater than(>), less than(<), greater than or equals to(>=), lesser than or equals to(<=)
              4==5             4!=5                5>4            4<5                  9>=5                         5<=5

        -- equals to operator(==) is used to check whether the numbers are equals or not, in sense of true or false.
        -- not equals to operator(!=) is used to check whether one number is equal to other number or not, in sense of true or false.

 3. Logical operators
    -- used to compare two or more expression.
    Ex-> AND(&&), OR(||), NOT(!)

        -- in case of AND operator(&&) both the expression must be true to make the whole system true.
        -- in case of OR operator(||) both the expression must be false to make the whole system false.
        -- NOT operator(!) makes the true statement false and vice versa.

 4. Assignment operators
    -- used to assign value.
    Ex-> =, +=, -=, /=, %=

        --(=), this is used to simply assign a value.
        --(+=), ex. a+=2 => a = a + 2
        --(-=), ex. a-=2 => a = a - 2
        --(/=), ex. a/=2 => a = a / 2
        --(%=), ex. a%=2 => a = a % 2

 5. Bitwise operators 
    Ex-> bitwise compliment(~), left shift(<<), right shift(>>), bitwise OR(|), bitwise AND(&), bitwise exclusive OR(^)

        --(~), as name is compliment.   ex. ~0 = 1 and ~1 = 0 => ~(0101) = 1010, here 0101 is binary representation of 5 and 1010 is B.R. of 10 so 
               it means bitwise compliment of 5 is 10.
        --(<<), ex. 0101<<1 it means every bit in 0101 will shift left by 1 i.e, 1010 or multiply by 2 in actual value of 0101,,  0100<<1 = 1000
        --(>>), ex. 0100>>1 = 0010 i.e value will divide by 2,,
               =>SUMMARISING if a<<b --> a*2^b and if a>>b --> a/2^b

        --(|), its like OR logical operator but the difference is that this works only for bits.  ex. 1|1 -> 1, 1|0 -> 1, 0|1 -> 1, 0|0 -> 0
        --(&), its like AND logical operator but only for bits, like in bitwise OR.
        --(^), ex. 0^0 -> 0, 1^1 -> 0, 1^0 -> 1, 0^1 -> 1

 6. Misc operators
    Ex-> sizeof() operator, Turnery operator, comma(,) operator, Dot(.) and arrow(->) operator, casting operator, address(&) operator, pointer(*) operator
       
        --sizeof(), this print the size in bytes of the data type present in bracket().
        --Turnery operator's syntex is this-> codition?Expression1:Expression2;, Expression1 will executed if condition is true and Expression2 will executed if condition is false.
        --comma(,) operator, int y = 4,3,6; so the value of y is 6.
        --dot(.) operator is used in classes and arrow(->) operator is used in pointer.
        --casting operator, float b = 3.44 and if we write int(b) => b = 3.
        --address(&) operator, it tells the address of value stored.   
        --pointer(*) operator, this is used to point the other variable.   
       
 7. Unary operators
    Ex-> unary plus(+), unary minus(-), increment operator(++), decrement operator(--), logical complement operator(!)
 */