/*
Question says you to just keep the right most set bit and all zeores
Ex:- 1010100 = 0000100

How:- OrigNum = 1010100
    -- OrigNum - 1 = 1010011(output1)
    -- output1 & OrigNum = 1010000(output2)
    -- output2 ^ OrigNum = 0000100(answer)

    TC:- O(1)

    answer = (num&(num-1))^num
*/