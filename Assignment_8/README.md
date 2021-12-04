## PBL Problem statement
    You are supposed to implement a singly linked list with the following operations: I - check for empty condition AF O - adds first element o AL O - adds last element o RF - removes the first element RL - removes the last element L - returns the last element in the list F - returns the first element in the list REV - reverses the linked list

## Sample Input
    1
    15
    I
    AF 1
    AL 2
    AL 3
    I
    F
    L
    REV
    RF
    RL
    RF
    AL 5
    REV
    RL
    RL

## Output
    true
    1->null
    1->2->null
    1->2->3->null
    false
    1
    3
    3->2->1->null
    2->1->null
    2->null
    null
    5->null
    5->null
    null
    ListEmptyException
    null


