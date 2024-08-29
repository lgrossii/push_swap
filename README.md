# Push Swap

## A Brief Summary

You start with two empty stacks: `a` and `b`. You are given a random list of integers via command line arguments that will fill stack `a`.

Only these moves are allowed to sort the stack:

- **`sa`**: *swap a* — Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no elements.
- **`sb`**: *swap b* — Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no elements.
- **`ss`**: *sa and sb* — Perform `sa` and `sb` at the same time.
- **`pa`**: *push a* — Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
- **`pb`**: *push b* — Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
- **`ra`**: *rotate a* — Shift up all elements of stack `a` by 1. The first element becomes the last one.
- **`rb`**: *rotate b* — Shift up all elements of stack `b` by 1. The first element becomes the last one.
- **`rr`**: *ra and rb* — Perform `ra` and `rb` at the same time.
- **`rra`**: *reverse rotate a* — Shift down all elements of stack `a` by 1. The last element becomes the first one.
- **`rrb`**: *reverse rotate b* — Shift down all elements of stack `b` by 1. The last element becomes the first one.
- **`rrr`**: *rra and rrb* — Perform `rra` and `rrb` at the same time.

At the end, stack `b` must be empty and all integers must be in stack `a`, sorted in ascending order. The list of moves needed to sort the stack will be printed on the screen.

---

## How to Run the Program

To run the program:

1. Clone the repository:
   ```shell
   git clone <https://github.com/onetrainn/push_swap>
2. Build the project by running 'make' from the command line:
   ```shell
	cd <repository-directory>
	make
3. Execute the program with the command ./push_swap, followed by a list of integers you want to sort, or a string containing them:
   ```shell
	./push_swap 3 1 4 1 5 9 2 6 5 3 5
Alternatively:
```shell
	./push_swap "3 1 4 1 5 9 2 6 5 3 5"
