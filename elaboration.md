# ELABORATION

For this quiz, I had to complete 3 functions.

For the first function, I had to dynamically allocate data to store a set amount of student structs. To make every student, I created memory for a student-sized object and stored it in a temporary pointer variable. If it were the first iteration, I would store that pointer to the head of the linked list. For each subsequent node, I would attach it to the "next" pointer of the previous one to link them together.

For the get length function, I iterated through every node counting 1 each time while stopping at a NULL pointer. I then returned the count.

For the third function, I started by creating a do-while loop. This loop would make sure the list was fully sorted. If a swap was made anywhere inside the do-while, then the do-while would iterate again to check if the nodes were actually sorted. If no swaps were made, then the do-while won't iterate again because the list should be fully sorted. Inside this loop, I had a while loop that iterated through the list of nodes, swapping whenever a swap was necessary. I made sure to make a conditional statement that checked if the list needed to be sorted in ascending or descending order. For the swap part of the code, I created a "swap node" function that obviously swapped the nodes when needed. I also made sure to account for the case of the head node being swapped as it requires a bit of variation in the algorithm.


