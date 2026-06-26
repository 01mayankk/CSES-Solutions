# Weird Algorithm

> **Topic:** Introductory Problems  
> **Difficulty:** Easy  
> **Language:** C++17

---

## Problem Overview

Given a positive integer **n**, repeatedly perform the following operations until **n = 1**:

- If **n** is even, divide it by **2**.
- If **n** is odd, replace it with **3 × n + 1**.

Print every value generated during this process.

This sequence is commonly known as the **Collatz Sequence** or **3n + 1 Sequence**.

---

## Approach

The algorithm follows the rules exactly as stated.

1. Print the current value.
2. If the value is **1**, stop.
3. If the value is even, recursively process **n / 2**.
4. Otherwise, recursively process **3 × n + 1**.

Since every operation only depends on the current number, recursion provides a simple and elegant implementation.

---

## Algorithm

1. Read the integer **n**.
2. Print **n**.
3. If **n == 1**, return.
4. If **n** is even:
   - Call the function with **n / 2**.
5. Otherwise:
   - Call the function with **3 × n + 1**.

---

## Dry Run

### Input

```
3
```

### Execution

```
3  -> odd  -> 3×3+1 = 10
10 -> even -> 5
5  -> odd  -> 16
16 -> even -> 8
8  -> even -> 4
4  -> even -> 2
2  -> even -> 1
```

### Output

```
3 10 5 16 8 4 2 1
```

---

## Correctness

At every step, the algorithm performs exactly one of the two operations specified:

- Even numbers become **n / 2**.
- Odd numbers become **3n + 1**.

Each generated value is printed before moving to the next one, producing the required sequence in order.

The recursion terminates when **n = 1**, which matches the stopping condition.

Therefore, the algorithm correctly simulates the Weird Algorithm.

---

## Complexity Analysis

### Time Complexity

**O(k)**

where **k** is the number of values produced in the sequence.

### Space Complexity

**O(k)**

due to the recursive call stack.

---

## Edge Cases

- Minimum value (**n = 1**)
- Large values close to **10⁶**
- Multiple consecutive even numbers
- Multiple odd transformations

---

## STL Used

- `iostream`

(No STL containers or algorithms are required.)

---

## Key Takeaways

- Basic recursion
- Simulation problems
- Conditional branching
- Recursive termination
- Introduction to the Collatz Conjecture
