# 🔄 push_swap

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Algorithms](https://img.shields.io/badge/Algorithms-Efficiency-red?style=for-the-badge)

An algorithmic project focused on sorting a stack of integers using two stacks (`Stack A` and `Stack B`) and a limited set of instructions, with the goal of minimizing the number of operations.

## 🧠 The Challenge

You have two stacks:
*   **Stack A**: Contains a random list of unique integers.
*   **Stack B**: Initially empty.

The goal is to sort the integers in **Stack A** in ascending order using only the following operations.

Currently, the solution implements a **Bitwise Radix Sort** algorithm, processing numbers bit by bit (base 2).
> [!NOTE]
> 🚧 **Work in Progress**: I am currently developing a new, more optimized sorting algorithm in the `my_alg(in_progress)` branch.

### 🛠️ Operations set
*   `sa`, `sb`, `ss` : **Swap** the first two elements.
*   `pa`, `pb` : **Push** the top element from one stack to another.
*   `ra`, `rb`, `rr` : **Rotate** up (first becomes last).
*   `rra`, `rrb`, `rrr` : **Reverse rotate** down (last becomes first).

## 🚀 Usage

### Compilation
The project uses a Makefile for compilation.
```bash
make        # Compiles push_swap
make bonus  # Compiles the checker
```

### Running push_swap
Pass a list of integers as arguments. The program will output the list of operations to sort them.
```bash
./push_swap 4 67 3 87 23
# Output: pb, ra, pb, ...
```

### Running the Checker
The benchmark tool reads instructions from stdin and validates if the stack is sorted.
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
# Output: OK (or KO)
```

## 🧪 Testing

You can generate random numbers to test:
```bash
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```
