# Two Sets

## Problem Information

- **Problem:** Two Sets
- **Category:** Introductory Problems
- **Difficulty:** Easy
- **Language:** C++

---

## Problem Statement

Given the numbers from **1 to n**, divide them into **two sets having equal sum**.

If such a division is possible, print one valid partition; otherwise print **NO**.

---

## Approach

### Observation

The total sum of numbers from **1 to n** is

\[
\frac{n(n+1)}{2}
\]

If this sum is **odd**, it is impossible to divide it into two equal halves.

Otherwise,

- Target Sum = Total Sum / 2

Now we only need to construct one subset whose sum equals the target.

---

### Greedy Strategy

Start from the largest number.

For every number from **n down to 1**

- If it can still fit into the required target sum
  - Put it into the first set.
  - Reduce the remaining target.
- Otherwise
  - Put it into the second set.

Choosing larger numbers first minimizes the remaining target quickly and always constructs a valid solution whenever one exists.

---

## Algorithm

1. Compute total sum.
2. If total sum is odd
   - Print **NO**.
3. Otherwise
   - Target = Total Sum / 2.
4. Traverse from **n → 1**
   - If current number ≤ remaining target
     - Add it to Set 1.
     - Subtract it from target.
   - Else
     - Add it to Set 2.
5. Print both sets.

---

## Correctness

Initially we need exactly **Target = TotalSum / 2**.

At every step:

- If the current largest number can contribute toward the remaining target, we must take it.
- Otherwise, taking it would exceed the target, so it safely belongs to the second set.

Since we always decrease the remaining target without exceeding it, eventually the target becomes zero.

Thus:

- Sum(Set1) = Target
- Sum(Set2) = TotalSum − Target

Both sets therefore have equal sum.

---

## Complexity Analysis

### Time Complexity

O(n)

Only one traversal from **n** to **1** is performed.

### Space Complexity

O(n)

Two vectors store all numbers.

---

## Edge Cases

- n = 1
- Odd total sum
- Very large n (10^6)
- Remaining target becomes zero before traversal ends

---

## STL Used

- vector

---

## Key Concepts

- Greedy Algorithm
- Mathematical Formula
- Simulation
