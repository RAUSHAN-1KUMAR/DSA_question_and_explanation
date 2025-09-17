/*
Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules: 
    1. Only one disk can be moved at a time.
    2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    3. No disk may be placed on top of a smaller disk.
*/


/*
Appraoch:- recursion DnC
    - Let say we have three rod -> 
        source helper destination
    - now we have four disk 1,2,3,4 on rod source, smallest on top and highest on bottom
        source  helper  destination
           1
           2
           3
           4
    - my ultimate goal is to put all the disk in destination rod w.r.t the rule given, so ham kya krengen ki
        1. Chaar disk ko destination m le jana h, to source is source_rod and destination is destination_rod. So free rod is helper rod, so sabse pehle step -> uper ke teen(4-1) rod ko free wale rod i.e, helper m bhejo and then rod 4th ko destination rod m.
            - now our problem is devided into subproblem i.e., uper ke teen rod ko helper rod m bhejo
        2. so now we have:
            source  helper  destination
               1
               2
               3
        3. teen disk ko helper rod m le jana h, to source is source_rod and destination is helper_rod. So free rod is destination rod, so sabse pehle step -> uper ke do(3-1) rod ko free wale rod i.e, destination_rod m bhejo and then rod 3rd ko helper_rod m.
            - now our sub problem is divided into sub-sub problem i.e, uper ke do ko destination rod m bhejo.
        4. so now we have:
            source  helper  destination
              1
              2
        5. do disk ko destination_rod m le jana h, to source is source_rod and destination is destination_rod. So free rod is helper rod, so sabse pehle step -> uper ke ek(2-1) rod ko free wale rod i.e., helper m bhejo and then rod 2 ko destination m.
            - now our problem is divided intoo sub-problem i.e. uper ke ek ko helper rod m bhejo.

So ham kya observe kiye, ki ager sarre disk(n) ko kahi bhejna h to 
    1. uper ke saare (n-1)disk ko free rod m bhejo, which is basically a new sub-problem, and then 
    2. nth disk ko wanha bhejo janha bhejna chahte the saare n disk ko.
    3. and the last step is, (n-1)disk jo phele step m free rod m bheje the to ab unn sabko wanha se utha ke bhej dengen janha bhejna chahte the (remember, this 3rd step will agian follow the 1st, 2nd, and 3rd step becuase phir se hamare pass n-1 disk h to 
            step1:- (n-1)-1 disk ko free rod m bhejo
            step2:- (n-1)th rod ko janha bhejna chahte the
            step3:- (n-1)-1 disk ko free rod se janha bhejna chahte the
    )
*/

#include<bits/stdc++.h>
using namespace std;

/*
Source rod -> 1
Helper rod -> 2
Dest   rod -> 3
*/

void hanoiHelper(int N, int source, int helper, int dest)
{
    // so our source is source_rod and destination is dest_rod and free rod is helper_rod

    if(N==1)
    {
        cout << "Move Disk " << N << " from source rod " << source << " to destination rod " << dest << endl;
        return;
    }


    hanoiHelper(N-1, source, dest, helper);// sabse pehle n-1 disks  ko source rod se free wale rod i.e., helper(new dest) m bhejo

    cout << "Move Disk " << N << " from source rod " << source << " to destination rod " << dest << endl; // nth rod ko destination_rod m bhejdo

    hanoiHelper(N-1, helper, source, dest);// ab jo n-1 disks pehle call p free wale rod i.e., helper rod m gye the, ab un sab ko janha bhjna tha wanha bhej do i.e., source->helper_rod and dest->dest_rod
}

long long hanoi(int N, int source, int helper, int dest)
{
    hanoiHelper(N, source, helper, dest);

    return pow(2,N)-1;
}


int main()
{
    int n = 3;
    cout << "Total " << hanoi(n, 1, 2, 3) << " steps." << endl;
    return 0;
}